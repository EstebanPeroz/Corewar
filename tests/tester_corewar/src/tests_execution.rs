use crate::Test;
use ansi_term::Colour::{Green, Red};
use std::fs::File;
use std::io::Write;
use std::process::{Command, Stdio};

fn log_error(test: &Test, output: &str, return_code: i32, errors_file: &mut File) {
    writeln!(errors_file, "===========Test ID {}===========", test.id).unwrap();
    writeln!(errors_file, "Test: {}", test.name).unwrap();
    writeln!(errors_file, "Expected:").unwrap();
    writeln!(errors_file, "  Return code: {}", test.expected_return).unwrap();
    if let Some(expected_output) = &test.expected_output {
        writeln!(errors_file, "  Output: {}", expected_output).unwrap();
    }
    writeln!(errors_file, "Got:").unwrap();
    writeln!(errors_file, "  Return code: {}", return_code).unwrap();
    writeln!(errors_file, "  Output: {}", output).unwrap();
    writeln!(errors_file, "\n").unwrap();
}

fn execute_program(program_path: &str, command: &str) -> std::process::Output {
    Command::new(program_path)
        .args(command.split_whitespace())
        .stdout(Stdio::piped())
        .stderr(Stdio::piped())
        .spawn()
        .expect("Failed to execute process")
        .wait_with_output()
        .expect("Failed to wait on child")
}

fn compare_results(output: &std::process::Output, test: &Test) -> (bool, bool) {
    let return_code = output.status.code().unwrap_or(-1);
    let test_passed = return_code == test.expected_return;

    let output_str = String::from_utf8_lossy(&output.stdout);
    let test_failed = test_passed
        && test.expected_output.is_some()
        && output_str != test.expected_output.as_deref().unwrap_or("");

    (test_passed, test_failed)
}

fn display_result(test: &Test, test_passed: bool, test_failed: bool) {
    if test_passed && !test_failed {
        println!(
            "\x1b[32m✓ Test {} {} {}\x1b[0m",
            Green.bold().paint((test.id).to_string()),
            Green.bold().paint(("passed : ").to_string()),
            Green.paint((test.name).to_string())
        );
    } else {
        println!(
            "\x1b[31m✗ Test {} {} {}\x1b[0m",
            Red.bold().paint((test.id).to_string()),
            Red.bold().paint(("failed: ").to_string()),
            Red.paint((test.name).to_string())
        );
    }
}

fn run_test(test: &Test, program_path: &str, errors_file: &mut File) -> bool {
    let output = execute_program(program_path, &test.command);
    let (test_passed, test_failed) = compare_results(&output, test);

    display_result(test, test_passed, test_failed);

    if !test_passed || test_failed {
        log_error(
            test,
            &String::from_utf8_lossy(&output.stdout),
            output.status.code().unwrap_or(-1),
            errors_file,
        );
    }

    test_passed && !test_failed
}

pub fn run_all_tests(
    tests: &[Test],
    corewar_binary: &str,
    errors_file: &mut File,
) -> (usize, usize, usize) {
    let mut total_tests = 0;
    let mut passed_tests = 0;
    let mut failed_tests = 0;

    for test in tests {
        total_tests += 1;
        if run_test(test, corewar_binary, errors_file) {
            passed_tests += 1;
        } else {
            failed_tests += 1;
        }
    }
    (total_tests, passed_tests, failed_tests)
}
