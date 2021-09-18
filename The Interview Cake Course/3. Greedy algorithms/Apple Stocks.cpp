/* Solution
We’ll greedily ↴ walk through the vector to track the max profit and lowest price so far.

For every price, we check if:
    we can get a better profit by buying at minPrice and selling at the currentPrice
    we have a new minPrice

To start, we initialize:
    1. minPrice as the first price of the day
    2. maxProfit as the first profit we could get

We decided to return a negative profit if the price decreases all day and we can't make any money. 
We could have thrown an exception instead, but returning the negative profit is cleaner, 
makes our function less opinionated, and ensures we don't lose information. */

/* Complexity
    O(n) time and O(1) space. We only loop through the vector once. */

#include <iostream>
#include <vector>

// C++11 lest unit testing framework
#include "lest.hpp"

using namespace std;

// calculate the max profit
int getMaxProfit(const vector<int>& stockPrices)
{
    if (stockPrices.size() < 2) {
        throw invalid_argument("Getting a profit requires at least 2 prices");
    }

    // we'll greedily update minPrice and maxProfit, so we initialize
    // them to the first price and the first possible profit
    int minPrice = stockPrices[0];
    int maxProfit = stockPrices[1] - stockPrices[0];

    // start at the second (index 1) time
    // we can't sell at the first time, since we must buy first,
    // and we can't buy and sell at the same time!
    // if we started at index 0, we'd try to buy *and* sell at time 0.
    // this would give a profit of 0, which is a problem if our
    // maxProfit is supposed to be *negative*--we'd return 0.
    for (size_t i = 1; i < stockPrices.size(); ++i) {
        int currentPrice = stockPrices[i];

        // see what our profit would be if we bought at the
        // min price and sold at the current price
        int potentialProfit = currentPrice - minPrice;

        // update maxProfit if we can do better
        maxProfit = max(maxProfit, potentialProfit);

        // update minPrice so it's always
        // the lowest price we've seen so far
        minPrice = min(minPrice, currentPrice);
    }

    return maxProfit;
}

// tests
const lest::test tests[] = {
    {CASE("price goes up then down") {
        const int actual = getMaxProfit({1, 5, 3, 2});
        const int expected = 4;
        EXPECT(actual == expected);
    }},

    {CASE("price goes down then up") {
        const int actual = getMaxProfit({7, 2, 8, 9});
        const int expected = 7;
        EXPECT(actual == expected);
    }},

    {CASE("big increase then small increase") {
        const int actual = getMaxProfit({2, 10, 1, 4});
        const int expected = 8;
        EXPECT(actual == expected);
    }},

    {CASE("price goes up all day") {
        const int actual = getMaxProfit({1, 6, 7, 9});
        const int expected = 8;
        EXPECT(actual == expected);
    }},

    {CASE("price goes down all day") {
        const int actual = getMaxProfit({9, 7, 4, 1});
        const int expected = -2;
        EXPECT(actual == expected);
    }},

    {CASE("price stays the same all day") {
        const int actual = getMaxProfit({1, 1, 1, 1});
        const int expected = 0;
        EXPECT(actual == expected);
    }},

    {CASE("exception with empty prices") {
        EXPECT_THROWS(getMaxProfit({}));
    }},

    {CASE("exception with one price") {
        EXPECT_THROWS(getMaxProfit({1}));
    }},
};

int main(int argc, char** argv)
{
    return lest::run(tests, argc, argv);
}

/* What We Learned
This one's a good example of the greedy approach in action. 
Greedy approaches are great because they're fast (usually just one pass through the input). 
But they don't work for every problem.

How do you know if a problem will lend itself to a greedy approach? 
    Best bet is to try it out and see if it works. 
    Trying out a greedy approach should be one of the first ways you try to break down a new question.

To try it on a new problem, start by asking yourself:
    "Suppose we could come up with the answer in one pass through the input, 
    by simply updating the 'best answer so far' as we went. 
    What "additional" values would we need to keep updated as we looked at each item in our input, 
    in order to be able to update the 'best answer so far' in constant time?"

In this case:
    The "best answer so far" is, of course, the max profit that we can get based on the prices we've seen so far.

    The "additional value" is the minimum price we've seen so far. 
    If we keep that updated, we can use it to calculate the new max profit so far in constant time. The max profit is the larger of:
        1. The previous max profit
        2. The max profit we can get by selling now (the current price minus the minimum price seen so far)

Try applying this greedy methodology to future questions. */

