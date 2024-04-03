# Introductory C++ Exercises - Part 2

Compile your code via

```shell
mkdir build -p && cd build
cmake ..
make -j8  # use 8 processor cores when compiling
```

Execute the tests via

```shell
build/${TASK_NAME}_tests
```

## Task 1 - `sum_to`
The task is to write a program
that implements the function `uint64_t sum_to(uint32_t n)`
which adds up all integers
between 0 and a user-defined upper limit `num`,
i.e. `0 + 1 + 2 + 3 + ... + num`. The upper limit has to be integral and must
be included in the sum.

Write your code in `sum_to.cpp`.

### Test Cases
For the task at hand, `25` is used as a common case for the
upper limit. `26` is also used to have at least one common
case of an even number for the upper limit. The edge cases for the problem at
hand include `0` (the smallest unsigned integer) and
`4294967295` (the largest 32 bit unsigned integer).
Expected results for these are `325`, `351`, `0` and
`9223372034707292160`.
In addition, `500000000` is used as input
(expected result `125000000250000000`) as `4294967295` does
not terminate at all when students fall for a common programming mistake.

After compiling your solution, experiment with the test-runner provided by
Catch2 via

```shell
./sum_to_test --help
./sum_to_test --list-tests  # list all available tests
./sum_to_test [sum_to]  # or ./run_tests "sum_to must calculate correctly"
./sum_to_test [sum_to] --section "corner cases"
```

## Task 2 - Spherical Cap
Implement functions that compute the surface and volume of a
[spherical cap](https://en.wikipedia.org/wiki/Spherical_cap).

Write your code in `spherical_cap.cpp`.

## Task 3 - Even numbers
Write a function `even_squares(uint32_t limit)` that returns a
`vector<uint32_t>` containing the squares of
all even numbers starting with 0 up to the value
passed as an argument to the function. If the function argument is the square
of an even number, it has to be included in the result vector.
For example:

* `even_squares(5)` must return a vector containing `{0, 4}`
* `even_squares(36)` must return a vector containing `{0, 4, 16, 36}`

Write your code in `even_squares.cpp`.

## Task 4 - ROT13
[ROT13](http://en.wikipedia.org/wiki/Rot13) is a simple substitution cipher .
It is built on the fact that each character has an integer ordinal.
Implement the functions `std::string rot13::encrypt(std::string)` and
`std::string rot13::decrypt(std::string)`.
The implementation has to be case sensitive (work with both lower and upper
case characters without changing their case). Characters that are not part
of the ascii alphabet should be passed unmodified to the returned string.

For example, running `rot13::encrypt("apt-get moo")` must return
the string `"ncg-trg zbb"`, where the characters `'-'` and `' '` are returned
unmodified.

Write your code in `rot13.cpp`.
