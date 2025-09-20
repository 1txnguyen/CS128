CXX=clang++
CXX_FLAGS=-std=c++20 -Iincludes -Wall -Wextra -O0 -gdwarf-4

exec: bin/exec
tests: bin/tests

bin/exec: ./src/driver.cc ./includes/solution.hpp ./src/solution.cc
	$(CXX) $(CXX_FLAGS) ./src/driver.cc ./src/solution.cc -o $@

bin/tests: ./tests/tests.cc ./includes/solution.hpp  ./src/solution.cc
	$(CXX) $(CXX_FLAGS) ./tests/tests.cc ./src/solution.cc -o $@



.DEFAULT_GOAL := exec
.PHONY: exec tests

clean:
	rm -rf bin/*