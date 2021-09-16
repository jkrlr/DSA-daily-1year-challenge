// Optimized for runtime over memory

// Brute Force : O(n^2) time, and O(1) space.
// Next Optimization : O(nLogn) time, and O(1)or O(n) space.
// Further Optimization : O(n) time, and O(n) space.

bool canTwoMoviesFillFlight(const vector<int>& movieLengths, int flightLength)
{
    // movie lengths we've seen so far
    unordered_set<int> movieLengthsSeen;

    for (int firstMovieLength : movieLengths) {
        int matchingSecondMovieLength = flightLength - firstMovieLength;
        if (movieLengthsSeen.find(matchingSecondMovieLength) != movieLengthsSeen.end()) {
            return true;
        }
        movieLengthsSeen.insert(firstMovieLength);
    }

    // we never found a match, so return false
    return false;
}

/* Bonus:
What if we wanted the movie lengths to sum to something close to the flight length (say, within 20 minutes)?
    Ans = Use Modified Binary Search, Time = O(nLogn), Space = O(n)- if we create copy of current aray for sorting, else Space = O(1)

What if we wanted to fill the flight length as nicely as possible with any number of movies (not just 2)?
    Ans = For each element use Modified Binary Search until we getting (num<=requiredLength) , 
        Time = O(k*nLogn), Space = O(n)- if we create copy of current aray for sorting, else Space = O(1)
                k = fligthLength/min(moviesLength[i]),i = 0 -> moviesLength.size() - 1
        In worst case - if all moviesLengths are equal and flightLenght is equal to the sum of all the movies,
        Then in that case k = n, Time = O(n^2Logn), which is even worse then our Brute fore O(n^2),
        But, In real life in flight and movies system it doesn't likely to happen at big scale, even though in case of web series episodes, it doesn't happen
        So, this case is never arises in case of movies.

What if we knew that movieLengths was sorted? Could we save some space and/or time? 
    Ans = No we can't save space/time - because for unordered_set it doesn't matter to be elements are shorted or not. */

/* What We Learned:
The trick was to use an unordered set to access our movies by length, in O(1) time.

Using hash-based data structures, like unordered maps or unordered sets, is so common in coding challenge solutions, 
it should always be your first thought. 
Always ask yourself, right from the start: "Can I save time by using an unordered map?" */