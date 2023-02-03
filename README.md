# ntest

A simple and lightweight library for testing in C++20.

Table of contents:
- [Features](#features)
- [Getting Started](#getting-started)
- [Documentation](#documentation)

## Features

- No 3rd party dependencies, just the STL
- No complicated build system, just 2 files and a C++20 compiler
- Simple but useful markdown reports
- Built-in assertion functions for:
  - integral types:
    - `bool`
    - `int8_t`, `uint8_t`
    - `int16_t`, `uint16_t`
    - `int32_t`, `uint32_t`
    - `int64_t`, `uint64_t`
  - containers:
    - `char*` strings
    - `std::string`
    - `T[]`
    - `std::vector`
    - `std::array`
  - text and binary files
  - exceptions

## Getting Started

To learn the basics of ntest, see the [simple example](/simple-example/) provided. After that, check out the [advanced example](/advanced-example/) to see all the features in practice.
