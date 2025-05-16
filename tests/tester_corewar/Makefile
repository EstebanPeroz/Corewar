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

showtest:
	@echo "Usage: make showtest ID=504"

TEST_ID = $(subst showtest-,,$@)

showtest-%:
	@awk 'BEGIN {bold = "\033[1m"; reset = "\033[0m"} \
	     /=+Test ID $(TEST_ID)=+/ {flag=1; print bold $$0 reset; next} \
	     /=+Test ID/ {flag=0} \
	     flag' errors.txt | head -n -2
