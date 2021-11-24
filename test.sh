#!/bin/bash

# This is a shell script to run all tests sequentially.

TEST_PARSING="tests"

echo "Testing Parsing"
cd tests/
./$TEST_PARSING
cd ..
