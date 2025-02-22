#include <cassert>
#include <iostream>
#include <string>
#include <vector>
#include <numeric>


/// Function to find the proper divisors of a number
std::vector<int> getProperDivisors(const int &value) noexcept
{

    std::vector<int> properDivisors;

    // Loop through divisors
    for (int divisor = 1; divisor != value / 2 + 1; ++divisor)
    {
        if (value % divisor == 0)
        {
            properDivisors.push_back(divisor);
        }
    }

    return properDivisors;
}


/// Function to determine if a number is perfect
bool isPerfect(const int &value) noexcept
{

    // If a number is negative, it cannot be perfect
    if (value < 1) return false;

    // Get the proper divisors of the number
    const std::vector<int> properDivisors = getProperDivisors(value);

    // If there are no proper divisors, the number is not perfect
    if (properDivisors.empty()) return false;

    // Sum the proper divisors
    const int sumProperDivisors = std::accumulate(properDivisors.begin(), properDivisors.end(), 0);

    // Is the sum of proper divisors equal to the initial number?
    return value == sumProperDivisors;

}


/// Function to run the program
int doMain(const std::vector<std::string> &args) noexcept
{
    try
    {

        // Check number of arguments
        if (args.size() != 2u) throw std::runtime_error("Error: Invalid number of arguments.");

        // Convert argument into a number
        const int value{std::stoi(args[1])};

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


/// Function to test the task performing behavior of the program
void testUse() noexcept
{
    assert(doMain( { "is_perfect", "1"} ) == 0);
    assert(doMain( { "is_perfect", "2"} ) == 0);
    assert(doMain( { "is_perfect", "3"} ) == 0);
    assert(doMain( { "is_perfect", "6"} ) == 0);
    assert(doMain( { "is_perfect", "-1"} ) == 0);
    assert(doMain( { "is_perfect", "100"} ) == 0);
}


/// Function to test the error handling behavior of the program
void testAbuse() noexcept
{
    assert(doMain( { "is_perfect", "nonsense"} ) == 1);
    assert(doMain( { "is_perfect", "123456789123456789"} ) == 1);
    assert(doMain( { "is_perfect", "1", "7"} ) == 1);
    assert(doMain( { "is_perfect"} ) == 1);
}


/// Function to test the program
void test() noexcept
{
    testUse();
    testAbuse();
}


/// Program to determine if a number is perfect
int main(int argc, char* argv[])
{

    // Preparation
    const std::vector<std::string> args(argv, argv + argc);
    
    // Test the program
    test();
    
    // Run the program
    return doMain(args);

}
