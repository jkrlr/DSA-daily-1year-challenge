/* Gotchas
    Watch out for index out of bounds errors! Will your function ever try to grab the 0th item from an empty vector, or the nth
    item from a vector with nn elements (where the last index would be n−1)?

    We can do this in O(n)time and O(1) additional space.

    Did you come up with a recursive solution? 
    Keep in mind that you may be incurring a hidden space cost (probably O(n)) in the call stack! 
    You can avoid this using an iterative approach. */

/* Breakdown
    How can we re-phrase this problem in terms of smaller subproblems?

    Breaking the problem into smaller subproblems will clearly involve reducing the size of at least one of our lists of customer order numbers. 
    So to start, let's try taking the first customer order out of servedOrders.

    What should be true of this customer order number if my service is first-come, first-served?

    If my cake cafe is first-come, first-served, then the first customer order finished (first item in servedOrders) 
    has to either be the first take-out order entered into the system (takeOutOrders[0]) or the first dine-in order entered into the system (dineInOrders[0]).

    Once we can check the first customer order, how can we verify the remaining ones?

    Let's "throw out" the first customer order from servedOrders as well as the customer order it matched with from the beginning of takeOutOrders or dineInOrders. 
    That customer order is now "accounted for."

    Now we're left with a smaller version of the original problem, which we can solve using the same approach! 
    So we keep doing this over and over until we exhaust servedOrders. If we get to the end and every customer order "checks out," we return true. */

vector<int> removeFirstOrder(const vector<int>& orders)
{
    return vector<int>(++orders.begin(), orders.end());
}

bool isFirstComeFirstServed(const vector<int>& takeOutOrders,
                            const vector<int>& dineInOrders,
                            const vector<int>& servedOrders)
{
    // base case
    if (servedOrders.empty()) {
        return true;
    }

    // if the first order in servedOrders is the same as the
    // first order in takeOutOrders
    // (making sure first that we have an order in takeOutOrders)
    if (!takeOutOrders.empty() && takeOutOrders[0] == servedOrders[0]) {

        // take the first order off takeOutOrders and servedOrders and recurse
        return isFirstComeFirstServed(removeFirstOrder(takeOutOrders), dineInOrders,
                removeFirstOrder(servedOrders));
    }

    // if the first order in servedOrders is the same as the first
    // in dineInOrders
    else if (!dineInOrders.empty() && dineInOrders[0] == servedOrders[0]) {

        // take the first order off dineInOrders and servedOrders and recurse
        return isFirstComeFirstServed(takeOutOrders, removeFirstOrder(dineInOrders),
                removeFirstOrder(servedOrders));
    }

    // first order in servedOrders doesn't match the first in
    // takeOutOrders or dineInOrders, so we know it's not first-come, first-served
    else {
        return false;
    }
}

/* This solution will work. But we can do better.

    Before we talk about optimization, note that our inputs are probably pretty small. 
    This function will take hardly any time or space, even if it could be more efficient. 
    In industry, especially at small startups that want to move quickly, optimizing this might be considered a "premature optimization." 
    Great engineers have both the skill to see how to optimize their code and the wisdom to know when those optimizations aren't worth it. 
    At this point in the interview I recommend saying, 
    "I think we can optimize this a bit further, although given the nature of the input this probably won't be very resource-intensive anyway...should we talk about optimizations?"

    Suppose we do want to optimize further. What are the time and space costs to beat? 
    This function will take O(n^2) time and O(n^2) additional space.

    Whaaaaat? Yeah. Take a look at this snippet:

    vector<int> removeFirstOrder(const vector<int>& orders)
    {
        return vector<int>(++orders.begin(), orders.end());
    }

    return isFirstComeFirstServed(removeFirstOrder(takeOutOrders), dineInOrders, removeFirstOrder(servedOrders)); */

/* We can do better than this O(n^2) time and space cost. 
One way we could to that is to avoid slicing and instead keep track of indices in the vector: */

bool isFirstComeFirstServed(const vector<int>& takeOutOrders,
                            const vector<int>& dineInOrders,
                            const vector<int>& servedOrders,
                            size_t servedOrdersIndex = 0,
                            size_t takeOutOrdersIndex = 0,
                            size_t dineInOrdersIndex = 0)
{

    // base case we've hit the end of servedOrders
    if (servedOrdersIndex == servedOrders.size()) {
        return true;
    }

    // if we still have orders in takeOutOrders
    // and the current order in takeOutOrders is the same
    // as the current order in servedOrders
    if ((takeOutOrdersIndex < takeOutOrders.size())
            && (takeOutOrders[takeOutOrdersIndex] == servedOrders[servedOrdersIndex])) {
        ++takeOutOrdersIndex;
    }

    // if we still have orders in dineInOrders
    // and the current order in dineInOrders is the same
    // as the current order in servedOrders
    else if ((dineInOrdersIndex < dineInOrders.size())
            && (dineInOrders[dineInOrdersIndex] == servedOrders[servedOrdersIndex])) {
        ++dineInOrdersIndex;
    }

    // if the current order in servedOrders doesn't match
    // the current order in takeOutOrders or dineInOrders, then we're not
    // serving in first-come, first-served order.
    else {
        return false;
    }

    // the current order in servedOrders has now been "accounted for"
    // so move on to the next one
    ++servedOrdersIndex;
    return isFirstComeFirstServed(takeOutOrders, dineInOrders, servedOrders,
            servedOrdersIndex, takeOutOrdersIndex, dineInOrdersIndex);
}

/* So now we're down to O(n)time, but we're still taking O(n) space in the call stack ↴ because of our recursion. 
    We can rewrite this as an iterative function to get that memory cost down to O(1).

    What's happening in each iteration of our recursive function? 
    Sometimes we're taking a customer order out of takeOutOrders and sometimes we're taking a customer order out of dineInOrders, but we're always taking a customer order out of servedOrders.

    So what if instead of taking customer orders out of servedOrders 1-by-1, we iterated over them?

    That should work. But are we missing any edge cases?

    What if there are extra orders in takeOutOrders or dineInOrders that don't appear in servedOrders? Would our kitchen be first-come, first-served then?

    Maybe.

    It's possible that our data doesn't include everything from the afternoon service. 
    Maybe we stopped recording data before every order that went into the kitchen was served. 
    It would be reasonable to say that our kitchen is still first-come, first-served, since we don't have any evidence otherwise.

    On the other hand, if our input is supposed to cover the entire service, 
    then any orders that went into the kitchen but weren't served should be investigated. We don't want to accept people's money but not serve them!

When in doubt, ask! 
This is a great question to talk through with your interviewer and shows that you're able to think through edge cases.

    Both options are reasonable. 
    In this writeup, we'll enforce that every order that goes into the kitchen (appearing in takeOutOrders or dineInOrders) should come out of the kitchen (appearing in servedOrders). 
    How can we check that?

    To check that we've served every order that was placed, we'll validate that when we finish iterating through servedOrders, 
    we've exhausted takeOutOrders and dineInOrders. */

/* Solution
 We walk through servedOrders, seeing if each customer order so far matches a customer order from one of the two registers. To check this, we:

    1. Keep pointers to the current index in takeOutOrders, dineInOrders, and servedOrders.
    2. Walk through servedOrders from beginning to end.
    3. If the current order in servedOrders is the same as the current customer order in takeOutOrders, increment takeOutOrdersIndex and keep going. 
      This can be thought of as "checking off" the current customer order in takeOutOrders and servedOrders, reducing the problem to the remaining customer orders in the vectors.
    4. Same as above with dineInOrders.
    5. If the current order isn't the same as the customer order at the front of takeOutOrders or dineInOrders, 
      we know something's gone wrong and we're not serving food first-come, first-served.
    6. If we make it all the way to the end of servedOrders, we'll check that we've reached the end of takeOutOrders and dineInOrders. 
      If every customer order checks out, that means we're serving food first-come, first-served.*/

#include <iostream>
#include <vector>

// C++11 lest unit testing framework
#include "lest.hpp"

using namespace std;

/* Complexity
    O(n) time and O(1) additional space. */
bool isFirstComeFirstServed(const vector<int>& takeOutOrders,
                            const vector<int>& dineInOrders,
                            const vector<int>& servedOrders)
{
    auto takeOutOrdersIter = takeOutOrders.cbegin();
    auto dineInOrdersIter = dineInOrders.cbegin();

    for (int order : servedOrders) {

        // if we still have orders in takeOutOrders
        // and the current order in takeOutOrders is the same
        // as the current order in servedOrders
        if (takeOutOrdersIter != takeOutOrders.cend() && order == *takeOutOrdersIter) {
            ++takeOutOrdersIter;
        }

        // if we still have orders in dineInOrders
        // and the current order in dineInOrders is the same
        // as the current order in servedOrders
        else if (dineInOrdersIter != dineInOrders.cend() && order == *dineInOrdersIter) {
            ++dineInOrdersIter;
        }

        // if the current order in servedOrders doesn't match the current
        // order in takeOutOrders or dineInOrders, then we're not serving first-come,
        // first-served
        else {
            return false;
        }
    }

    // check for any extra orders at the end of takeOutOrders or dineInOrders
    if (dineInOrdersIter != dineInOrders.cend() || takeOutOrdersIter != takeOutOrders.cend()) {
        return false;
    }

    // all orders in servedOrders have been "accounted for"
    // so we're serving first-come, first-served!
    return true;
}


// tests

const lest::test tests[] = {
    {CASE("both registers have same number of orders") {
        const vector<int> takeOutOrders {1, 4, 5};
        const vector<int> dineInOrders {2, 3, 6};
        const vector<int> servedOrders {1, 2, 3, 4, 5, 6};
        const auto result = isFirstComeFirstServed(takeOutOrders, dineInOrders, servedOrders);
        EXPECT(result == true);
    }},
    {CASE("registers have different lengths") {
        const vector<int> takeOutOrders {1, 5};
        const vector<int> dineInOrders {2, 3, 6};
        const vector<int> servedOrders {1, 2, 6, 3, 5};
        const auto result = isFirstComeFirstServed(takeOutOrders, dineInOrders, servedOrders);
        EXPECT(result == false);
    }},
    {CASE("one register is empty") {
        const vector<int> takeOutOrders;
        const vector<int> dineInOrders {2, 3, 6};
        const vector<int> servedOrders {2, 3, 6};
        const auto result = isFirstComeFirstServed(takeOutOrders, dineInOrders, servedOrders);
        EXPECT(result == true);
    }},
    {CASE("served orders is missing orders") {
        const vector<int> takeOutOrders {1, 5};
        const vector<int> dineInOrders {2, 3, 6};
        const vector<int> servedOrders {1, 6, 3, 5};
        const auto result = isFirstComeFirstServed(takeOutOrders, dineInOrders, servedOrders);
        EXPECT(result == false);
    }},
    {CASE("served orders has extra orders") {
        const vector<int> takeOutOrders {1, 5};
        const vector<int> dineInOrders {2, 3, 6};
        const vector<int> servedOrders {1, 2, 3, 5, 6, 8};
        const auto result = isFirstComeFirstServed(takeOutOrders, dineInOrders, servedOrders);
        EXPECT(result == false);
    }},
    {CASE("one register has extra orders") {
        const vector<int> takeOutOrders {1, 9};
        const vector<int> dineInOrders {7, 8};
        const vector<int> servedOrders {1, 7, 8};
        const auto result = isFirstComeFirstServed(takeOutOrders, dineInOrders, servedOrders);
        EXPECT(result == false);
    }},
    {CASE("one register has unserved orders") {
        const vector<int> takeOutOrders {55, 9};
        const vector<int> dineInOrders {7, 8};
        const vector<int> servedOrders {1, 7, 8, 9};
        const auto result = isFirstComeFirstServed(takeOutOrders, dineInOrders, servedOrders);
        EXPECT(result == false);
    }},
    {CASE("order numbers are not sequential") {
        const vector<int> takeOutOrders = {27, 12, 18};
        const vector<int> dineInOrders = {55, 31, 8};
        const vector<int> servedOrders = {55, 31, 8, 27, 12, 18};
        const auto result = isFirstComeFirstServed(takeOutOrders, dineInOrders, servedOrders);
        EXPECT(result == true);
    }}
};

int main(int argc, char** argv)
{
    return lest::run(tests, argc, argv);
}

/* Bonus
    1. This assumes each customer order in servedOrders is unique. 
       How can we adapt this to handle vectors of customer orders with potential repeats?
    2. Our implementation returns true when all the items in dineInOrders and takeOutOrders are first-come first-served in servedOrders and false otherwise. 
       That said, it'd be reasonable to throw an exception if some orders that went into the kitchen were never served, or orders were served but not paid for at either register. 
       How could we check for those cases?
    3. Our solution iterates through the customer orders from front to back. 
       Would our algorithm work if we iterated from the back towards the front? 
       Which approach is cleaner? */

/* What We Learned
    If you read the whole breakdown section, you might have noticed that our recursive function cost us extra space.

    Be careful of the hidden space costs from a recursive function's call stack! 
    If you have a solution that's recursive, see if you can save space by using an iterative algorithm instead. */