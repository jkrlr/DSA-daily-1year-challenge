/* Write a recursive function for generating all permutations of an input string. Return them as a set.

    Don't worry about time or space complexity—if we wanted efficiency we'd write an iterative version.

    To start, assume every character in the input string is unique.

    Your function can have loops—it just needs to also be recursive. */

/* Breakdown
    Let's break the problem into subproblems. 

    How could we re-phrase the problem of getting all permutations for "cats" in terms of a smaller but similar subproblem? 

    Let's make our subproblem be getting all permutations for all characters except the last one. 
    If we had all permutations for "cat," how could we use that to generate all permutations for "cats"?

    We could put the "s" in each possible position for each possible permutation of "cat"!

    Now that we can break the problem into subproblems, we just need a base case and we have a recursive algorithm!*/

// Solution
#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

unordered_set<string> getPermutations(const string& inputString)
{
    unordered_set<string> permutations;

    // base case
    if (inputString.length() <= 1) {
        permutations.insert(inputString);
        return permutations;
    }

    string allCharsExceptLast = inputString.substr(0, inputString.length() - 1);
    char lastChar = inputString[inputString.length() - 1];

    // recursive call: get all possible permutations for all chars except last
    const auto permutationsOfAllCharsExceptLast = getPermutations(allCharsExceptLast);

    // put the last char in all possible positions for each of the above permutations
    for (const string& permutationOfAllCharsExceptLast : permutationsOfAllCharsExceptLast) {
        for (size_t position = 0; position <= allCharsExceptLast.length(); ++position) {
            string permutation = permutationOfAllCharsExceptLast.substr(0, position)
                    + lastChar + permutationOfAllCharsExceptLast.substr(position);
            permutations.insert(permutation);
        }
    }

    return permutations;
}

/* Bonus
    How does the problem change if the string can have duplicate characters?

    What if we wanted to bring down the time and/or space costs?*/

/* What We Learned
    This is one where playing with a sample input is huge. 
    Sometimes it helps to think of algorithm design as a two-part process: 
    first figure out how you would solve the problem "by hand," as though the input was a stack of paper on a desk in front of you. 
    Then translate that process into code. */