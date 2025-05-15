use serde::{Deserialize, Serialize};
use std::fs::{File, OpenOptions};
use termcolor::{ColorChoice, StandardStream};

mod interpreter;
mod tests_execution;

use interpreter::collect_tests;
use tests_execution::run_all_tests;

#[derive(Deserialize, Serialize, Debug)]
pub struct Test {
    id: u32,
    name: String,
    command: String,
    expected_return: i32,
    expected_output: Option<String>,
}

fn print_summary(total: usize, passed: usize, failed: usize) {
    println!("\n\x1b[1mTest Summary:\x1b[0m Total: {} | \x1b[32mPassed: {}\x1b[0m | \x1b[31mFailed: {}\x1b[0m", total, passed, failed);

    if failed > 0 {
        println!("\x1b[1mCheck the errors log in 'errors.txt' for detailed error reports.\x1b[0m");
    }
}

fn open_errors_file(path: &str) -> File {
    OpenOptions::new()
        .write(true)
        .create(true)
        .truncate(true)
        .open(path)
        .expect("Failed to open or create error log file")
}

fn parse_args() -> (String, String) {
    let args: Vec<String> = std::env::args().collect();
    if args.len() < 3 || args.len() > 4 {
        eprintln!(
            "Usage: {} <tests_file_or_directory> <corewar_binary>",
            args[0]
        );
        std::process::exit(1);
    }
    (args[1].clone(), args[2].clone())
}

fn main() {
    let (test_file_or_directory, corewar_binary) = parse_args();
    let mut color_output = StandardStream::stdout(ColorChoice::Always);
    let mut errors_file = open_errors_file("errors.txt");

    let tests = collect_tests(&test_file_or_directory);

    let (total_tests, passed_tests, failed_tests) =
        run_all_tests(&tests, &corewar_binary, &mut color_output, &mut errors_file);

    print_summary(total_tests, passed_tests, failed_tests);
}
