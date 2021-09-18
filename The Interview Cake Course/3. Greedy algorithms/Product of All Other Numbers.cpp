/* Gotchas
    Does your function work if the input vector contains zeroes? Remember—no division.

    We can do this in O(n) time and O(n) space!

    We only need to allocate one new vector of size n. */

/* Breakdown
    A brute force approach would use two loops to multiply the integer at every index by the integer at every nestedIndex, unless index == nestedIndex.

    This would give us a runtime of O(n^2). Can we do better? 
    
    Well, we’re wasting a lot of time doing the same calculations. As an example, let's take:

    // input array
    [1, 2, 6, 5, 9]

    // array of the products of all integers
    // except the integer at each index:
    [540, 270, 90, 108, 60]  // [2 * 6 * 5 * 9,  1 * 6 * 5 * 9,  1 * 2 * 5 * 9,  1 * 2 * 6 * 9,  1 * 2 * 6 * 5]
    
    Can we break our problem down into subproblems so we can use a greedy approach? */

/* Solution
    To find the products of all the integers except the integer at each index, we'll go through our vector greedily ↴ twice.
    First we get the products of all the integers before each index, and then we go backwards to get the products of all the integers after each index.

    When we multiply all the products before and after each index, we get our answer—the products of all the integers except the integer at each index! */

/* Complexity
    O(n) time and O(n) space. 
    We make two passes through our input a vector, and the vector we build always has the same length as the input vector. */

#include <iostream>
#include <vector>

// C++11 lest unit testing framework
#include "lest.hpp"

using namespace std;

  vector<int> getProductsOfAllIntsExceptAtIndex(const vector<int>& intVector)
{
    if (intVector.size() < 2) {
        throw invalid_argument("Getting the product of numbers at"
            " other indices requires at least 2 numbers");
    }

    // we make an array with the length of the input array to
    // hold our products
    vector<int> productsOfAllIntsExceptAtIndex(intVector.size());

    // for each integer, we find the product of all the integers
    // before it, storing the total product so far each time
    int productSoFar = 1;
    for (size_t i = 0; i < intVector.size(); ++i) {
        productsOfAllIntsExceptAtIndex[i] = productSoFar;
        productSoFar *= intVector[i];
    }

    // for each integer, we find the product of all the integers
    // after it. since each index in products already has the
    // product of all the integers before it, now we're storing
    // the total product of all other integers
    productSoFar = 1;
    for (size_t i = intVector.size(); i > 0; --i) {
        size_t j = i - 1;
        productsOfAllIntsExceptAtIndex[j] *= productSoFar;
        productSoFar *= intVector[j];
    }

    return productsOfAllIntsExceptAtIndex;
}

// tests

const lest::test tests[] = {
    {CASE("small vector") {
        const auto actual = getProductsOfAllIntsExceptAtIndex({1, 2, 3});
        const auto expected = vector<int> {6, 3, 2};
        EXPECT(actual == expected);
    }},

    {CASE("longer vector") {
        const auto actual = getProductsOfAllIntsExceptAtIndex({8, 2, 4, 3, 1, 5});
        const auto expected = vector<int> {120, 480, 240, 320, 960, 192};
        EXPECT(actual == expected);
    }},

    {CASE("vector has one zero") {
        const auto actual = getProductsOfAllIntsExceptAtIndex({6, 2, 0, 3});
        const auto expected = vector<int> {0, 0, 36, 0};
        EXPECT(actual == expected);
    }},

    {CASE("vector has two zeros") {
        const auto actual = getProductsOfAllIntsExceptAtIndex({4, 0, 9, 1, 0});
        const auto expected = vector<int> {0, 0, 0, 0, 0};
        EXPECT(actual == expected);
    }},

    {CASE("one negative number") {
        const auto actual = getProductsOfAllIntsExceptAtIndex({-3, 8, 4});
        const auto expected = vector<int> {32, -12, -24};
        EXPECT(actual == expected);
    }},

    {CASE("all negative numbers") {
        const auto actual = getProductsOfAllIntsExceptAtIndex({-7, -1, -4, -2});
        const auto expected = vector<int> {-8, -56, -14, -28};
        EXPECT(actual == expected);
    }},

    {CASE("error with empty vector") {
        EXPECT_THROWS(getProductsOfAllIntsExceptAtIndex({}));
    }},

    {CASE("error with one number") {
        EXPECT_THROWS(getProductsOfAllIntsExceptAtIndex({1}));
    }},
};

int main(int argc, char** argv)
{
    return lest::run(tests, argc, argv);
}

/* Bonus
    What if you could use division? Careful—watch out for zeroes! */

/* What We Learned
    Another question using a greedy ↴ approach. The tricky thing about this one: we couldn't actually solve it in one pass.
     But we could solve it in two passes!

    This approach probably wouldn't have been obvious if we had started off trying to use a greedy approach.

    Instead, we started off by coming up with a slow (but correct) brute force solution and trying to improve from there. 
    We looked at what our solution actually calculated, step by step, and found some repeat work. 
    Our final answer came from brainstorming ways to avoid doing that repeat work.

So that's a pattern that can be applied to other problems:

    Start with a brute force solution, look for repeat work in that solution, and modify it to only do that work once. */