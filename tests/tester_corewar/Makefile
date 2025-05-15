##
## EPITECH PROJECT, 2025
## Corewar
## File description:
## My_RUST_Makefile
##

.PHONY: all build run test clean

all: build

execute:
	@$(MAKE) --no-print-directory build
	@./target/release/tester_corewar functional_tests/ ../../corewar
	@$(MAKE) --no-print-directory clean > /dev/null 2>&1

build:
	cargo build --release

run:
	cargo run --release -- $(ARGS)

test:
	cargo test

clean:
	cargo clean

clean-all: clean
	rm -rf errors.txt

format:
	cargo fmt

lint:
	cargo clippy -- -D warnings
