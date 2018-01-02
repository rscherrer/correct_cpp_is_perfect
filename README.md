# correct_cpp_is_perfect

Branch|[Travis CI](https://travis-ci.org)|[Codecov](https://www.codecov.io)
---|---|---
master|[![Build Status](https://travis-ci.org/richelbilderbeek/correct_cpp_is_perfect.svg?branch=master)](https://travis-ci.org/richelbilderbeek/correct_cpp_is_perfect)|[![codecov.io](https://codecov.io/github/richelbilderbeek/correct_cpp_is_perfect/coverage.svg?branch=master)](https://codecov.io/github/richelbilderbeek/correct_cpp_is_perfect/branch/master)

[Correct C++](https://github.com/richelbilderbeek/correct_cpp) chapter 'is_perfect'.

## Goal

 * Refactor an application to lower cyclomatic complexity

## Prerequisites

 * Understand [how this course works](https://github.com/richelbilderbeek/correct_cpp/blob/master/how_this_course_works.md)
 * Have written [a correct 'int_to_word' program](https://github.com/richelbilderbeek/correct_cpp_int_to_word)

## Exercise

Write a command-line interface (CLI) program that determines if a number is a perfect number (see 'What is a perfect number?').

Here are the outputs and exit statuses the program should give:

Call to `hello_cli`|Output|Exit status
---|---|---
`./is_perfect`|Any|1
`./is_perfect X`, where X is a number that is not perfect|`false` (with newline)|0
`./is_perfect Y`, where Y is a number that is perfect|`true` (with newline)|0
`./is_perfect nonsense`|Any|1
`./is_perfect 6 28`|Any|1

In this exercise, you start with the code below. Yes, that code works perfectly. 

```c++
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

int main(int argc, char* argv[])
{
  if (argc != 2) return 1;
  try
  {
    const int i{std::stoi(argv[1])};
    if (i == 0)
    {
      std::cout << "false\n";
      return 0;
    }
    //Collect the proper divisors
    std::vector<int> v;
    if (i < 2)
    {
      //v is okay as it is
    }
    else if (i == 2)
    {
      v.push_back(1);
    }
    else
    {
      for (int j=1; j!=i-1; ++j)
      {
        if (i % j == 0)
        {
          v.push_back(j);
        }
      }
    }
    //sum the proper divisors
    int sum{0};
    for (const int j: v) { sum += j; }
    //is it perfect?
    const bool is_perfect{sum == i};
    //show
    if (is_perfect)
    {
      std::cout << "true\n";
    }
    else
    {
      std::cout << "false\n";
    }
  }
  catch (const std::exception&)
  {
    return 1;
  }
}
```

 * The code has a too high cyclomatic complexity. Simplify it. See [how to lower cyclomatic complexity](https://github.com/richelbilderbeek/correct_cpp/blob/master/how_to_lower_cyclomatic_complexity.md). 
   Tips:
     * the comments tell what is happening, create functions with those names
     * a possible function prototype: `std::vector<int> collect_proper_divisors(const int i) noexcept`
     * a possible function prototype: `int sum(const std::vector<int>& v) noexcept`
     * a possible function prototype: `bool is_perfect(const int i) noexcept`
 * Your code needs to have 100% code coverage, regardless how it is called (that is, with zero, one or more arguments), 
   see [how to get 100 percent code coverage](https://github.com/richelbilderbeek/correct_cpp/blob/master/how_to_get_100_percent_code_coverage.md)

## What is a perfect number?

Any number is a perfect number if the sum of its proper divisors equals itself.
A number's divisors are those value the number can be divided by without leaving a remainer.
A number's proper divisors are those divisors different from the number itself.

For example:
 * 6 has divisors 1,2,3 and 6
 * 6 has proper divisors 1,2 and 3
 * 6 is perfect, as 1+2+3=6

## External links

 * [Wikipedia's page about perfect numbers](https://en.wikipedia.org/wiki/Perfect_number)

