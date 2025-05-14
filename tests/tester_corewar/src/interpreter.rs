use crate::Test;
use std::fs;
use std::path::Path;

fn read_tests_from_json(file_path: &str) -> Result<Vec<Test>, serde_json::Error> {
    let data = fs::read_to_string(file_path).expect("Failed to read file");
    let tests: Vec<Test> = serde_json::from_str(&data)?;
    Ok(tests)
}

fn read_tests_from_directory(directory: &str) -> Vec<Test> {
    let mut tests = Vec::new();

    if let Ok(entries) = fs::read_dir(directory) {
        for entry in entries.filter_map(Result::ok) {
            if entry.path().extension().and_then(|e| e.to_str()) == Some("json") {
                let file_tests =
                    read_tests_from_json(entry.path().to_str().unwrap()).unwrap_or_default();
                tests.extend(file_tests);
            }
        }
    }

    tests
}

pub fn collect_tests(test_file_or_directory: &str) -> Vec<Test> {
    if Path::new(test_file_or_directory).is_dir() {
        read_tests_from_directory(test_file_or_directory)
    } else {
        read_tests_from_json(test_file_or_directory).unwrap_or_default()
    }
}
