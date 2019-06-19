#include <cassert>
#include <iostream>
#include <string>
#include <vector>
#include <numeric>


/// Function to find the proper divisors of a number
std::vector<int> getProperDivisors(const int &value)
{
    std::vector<int> proper_divisors;

    if (is_perfect == -1 && value == 2)
    {
        proper_divisors.push_back(1);
    }
    else if (is_perfect == -1 && value > 2)
    {
        for (int denominator=1; denominator!=value-1; ++denominator)
        {
            if (value % denominator == 0)
            {
                proper_divisors.push_back(denominator);
            }
        }
    }
}


/// Function to determine if a number is perfect
bool isPerfect(const int &value) noexcept
{

    // A perfect number must be positive
    if (value > 0) {

        // Get the proper divisors of the number
        const std::vector<int> properDivisors = getProperDivisors(value);

        // Sum the proper divisors
        const int sumProperDivisors = std::accumulate(properDivisors.begin(), properDivisors.end(), 0);

        // Is the sum of proper divisors equal to the initial number?
        return value == sumProperDivisors;

    }

    return false;

}


/// Function to run the program
int doMain(const std::vector<std::string> &args)
{
    try
    {

        // Check number of arguments
        if (args.size() != 2u) throw std::runtime_error("Error: Invalid number of arguments.");

        // Convert argument into a number
        const int value{std::stoi(args[1])};

        // Is this a perfect number?
        // -1: unknown
        //  0: false
        //  1: true

        // Determine if the number is perfect
        const bool isNumberPerfect = isPerfect(value);

        // Display the result
        isNumberPerfect ? std::cout << "true\n" : std::cout << "false\n";

    }
    catch (const std::runtime_error &err)
    {
        std::cout << err.what() << '\n';
        return 1;
    }
    catch (const std::invalid_argument&)
    {
        std::cout << "Error: Argument is not an integer.\n";
        return 1;
    }
    catch (const std::out_of_range&)
    {
        std::cout << "Error: Number too big for an integer.\n";
        return 1;
    }
    return 0;
}


/// Program to determine if a number is perfect
int main(int argc, char* argv[])
{

    // Preparation
    const std::vector<std::string> args(argv, argv + argc);

    // Run the program
    return doMain(args);

}
