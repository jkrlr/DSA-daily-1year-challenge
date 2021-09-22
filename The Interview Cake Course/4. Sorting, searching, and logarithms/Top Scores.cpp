/* Top Scores
    Efficiently sort numbers in an array, where each number is below a certain maximum. */

/* Write a function that takes:

    1. a vector of unsortedScores
    2. he highestPossibleScore in the game
    and returns a sorted vector of scores in less than O(nlgn) time. */

/* Gotchas
    Multiple players can have the same score! 
     If 10 people got a score of 90, the number 90 should appear 10 times in our output vector.

    We can do this in O(n) time and space.*/

/* Breakdown
    O(nlgn) is the time to beat. 
    Even if our vector of scores were already sorted we'd have to do a full walk through the vector to confirm that it was in fact fully sorted. 
    So we have to spend at least O(n) time on our sorting function. If we're going to do better than O(nlgn), we're probably going to do exactly O(n).

    What are some common ways to get O(n) runtime? 
    
    One common way to get O(n) runtime is to use a greedy algorithm. ↴
        But in this case we're not looking to just grab a specific value from our input set (e.g. the "largest" or the "greatest difference")—we're looking to reorder the whole set. 
        That doesn't lend itself as well to a greedy approach.
        
    Another common way to get O(n) runtime is to use counting. ↴
        Counting is a common pattern in time-saving algorithms. 
        It can often get you O(n) runtime, but at the expense of adding O(n) space.

        The idea is to define an unordered map or vector (call it e.g. counts) 
        where the keys/indices represent the items from the input set and the values represent the number of times the item appears. 
        In one pass through the input you can fully populate counts:

        unorderd_map<int, size_t> counts;

        for (int item : theVector) {
            if ( counts.find(item) == counts.end() ) {
                counts[item] = 1;
            }
            else {
                ++counts[item];
            }
        }

        Once you know how many times each item appears, it's trivial to:
        - generate a sorted vector
        - find the item that appears the most times
          etc.
          
****We can build a vector scoreCounts where the indices represent scores and the values represent how many times the score appears. 
    Once we have that, can we generate a sorted vector of scores?

    What if we did an in-order walk through scoreCounts. 
    Each index represents a score and its value represents the count of appearances. 
    So we can simply add the score to a new vector sortedScores as many times as count of appearances.*/

/* Solution
    We use counting sort.*/

vector<int> sortScores(const vector<int>& unorderedScores, int highestPossibleScore)
{
    // vector of 0s at indices 0..highestPossibleScore
    vector<size_t> scoreCounts(highestPossibleScore + 1);

    // populate scoreCounts
    for (int score : unorderedScores) {
        ++scoreCounts[score];
    }

    // populate the final sorted array
    vector<int> sortedScores(unorderedScores.size());
    size_t currentSortedIndex = 0;

    // for each item in scoreCounts
    for (int score = highestPossibleScore; score >= 0; --score) {
        size_t count = scoreCounts[score];

        // for the number of times the item occurs
        for (size_t occurrence = 0; occurrence < count; ++occurrence) {
            // add it to the sorted array
            sortedScores[currentSortedIndex] = score;
            ++currentSortedIndex;
        }
    }

    return sortedScores;
}

/* Complexity
*****O(n) time and O(n) space, where n is the number of scores.

        Wait, aren't we nesting two loops towards the bottom? So shouldn't it be O(n^2)time? 
        Notice what those loops iterate over. The outer loop runs once for each unique number in the vector. The inner loop runs once for each time that number occurred.

        So in essence we're just looping through the n numbers from our input vector, except we're splitting it into two steps: 
        (1) each unique number, and (2) each time that number appeared.

        Here's another way to think about it: in each iteration of our two nested loops, 
        we append one item to sortedScores. How many numbers end up in sortedScores in the end? 
        Exactly how many were in our input vector! n.

****If we didn't treat highestPossibleScore as a constant, 
    we could call it k and say we have O(n+k) time and O(n+k) space. */

/* Bonus
    Note that by optimizing for time we ended up incurring some space cost! 
    What if we were optimizing for space?

    We chose to generate and return a separate, sorted vector. Could we instead sort the vector in place? 
    Does this change the time complexity? The space complexity? 
        Ans = We can use inplace sorting like inplace-mergeSort or quickSort and achieve it O(nlogn) time and O(1) Space.*/
