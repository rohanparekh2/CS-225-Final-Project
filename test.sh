#!/bin/bash

# This is a shell script to run all tests sequentially.

TEST_POKEMON="test-pokemon"
TEST_GRAPH="test-graph"

echo "Testing Pokemon"
cd pokemon_testing/src
make pokemon
cd ..
./$TEST_POKEMON
cd ..

echo "Testing Graph"
cd graph_testing/src
make graph
cd ..
./$TEST_GRAPH
cd ..
