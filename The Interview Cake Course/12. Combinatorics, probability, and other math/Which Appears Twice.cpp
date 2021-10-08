/* I have a vector of n + 1 numbers. 
Every number in the range 1..n appears once except for one number that appears twice. */

// Solution
/*   First, we sum all numbers 1..n. We can do this using the equation: (n+1)*n/2

    Second, we sum all numbers in our input vector, which should be the same as our other sum but with our repeat number added in twice. 

    So the difference between these two sums is the repeated number!*/

 unsigned int findRepeat(const vector<unsigned int>& numbers)
{
    if (numbers.size() < 2) {
        throw std::invalid_argument("Finding duplicate requires at least two numbers");
    }

    unsigned int n = static_cast<unsigned int>(numbers.size() - 1);
    unsigned int sumWithoutDuplicate = (n * n + n) / 2;
    unsigned int actualSum = accumulate(numbers.begin(), numbers.end(), 0U);

    return actualSum - sumWithoutDuplicate;
}

/* Complexity
    O(n) time. We can sum all the numbers 1..n in O(1) time using the fancy formula, 
    
    but it still takes O(n) time to sum all the numbers in our input vector.

    O(1) additional space—the only additional space we use is for numbers to hold the sums with and without the repeated value. */

/* Bonus
    If our vector contains huge numbers or is really long, our sum might be so big it causes an integer overflow.

    What are some ways to protect against this? */
