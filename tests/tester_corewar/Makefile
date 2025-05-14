##
## EPITECH PROJECT, 2025
## Corewar
## File description:
## My_RUST_Makefile
##

.PHONY: all build run test clean

all: build

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
