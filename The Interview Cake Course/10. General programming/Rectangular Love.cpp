/* Write a function to find the rectangular intersection of two given love rectangles.

As with the example above, love rectangles are always "straight" and never "diagonal." 
More rigorously: each side is parallel with either the x-axis or the y-axis. */

/* Breakdown
    Let's break this problem into subproblems. How can we divide this problem into smaller parts?

    We could look at the two rectangles’ "horizontal overlap" or "x overlap" separately from their "vertical overlap" or "y overlap."

    Lets start with a helper function findXOverlap(). 

    Need help finding the x overlap? 

    Since we’re only working with the x dimension, we can treat the two rectangles' widths as ranges on a 1-dimensional number line.

    What are the possible cases for how these ranges might overlap or not overlap? Draw out some examples!

    There are four relevant cases:

    1) The ranges partially overlap:

    2) One range is completely contained in the other:

    3) The ranges don't overlap:

    4) The ranges "touch" at a single point:

    Let's start with the first 2 cases. How do we compute the overlapping range?

    One of our ranges starts "further to the right" than the other. 

    We don't know ahead of time which one it is, but we can check the starting points of each range to see which one has the highestStartPoint. 

    That highestStartPoint is always the left-hand side of the overlap, if there is one.

    Similarly, the right-hand side of our overlap is always the lowestEndPoint. 

    That may or may not be the end point of the same input range that had the highestStartPoint—compare cases (1) and (2).

    This gives us our x overlap! So we can handle cases (1) and (2). How do we know when there is no overlap?

    If highestStartPoint > lowestEndPoint, the two rectangles do not overlap.

    But be careful—is it just greater than or is it greater than or equal to?


    It depends how we want to handle case (4) above.

    If we use greater than, we treat case (4) as an overlap. 

    This means we could end up returning a rectangle with zero width, which ... may or may not be what we're looking for. You could make an argument either way.

    Let's say a rectangle with zero width (or zero height) isn't a rectangle at all, so we should treat that case as "no intersection."

    Can you finish findXOverlap()? */

class XOverlap
{
private:
    int startPoint_;
    int width_;

public:
    XOverlap() :
        startPoint_(0),
        width_(0)
    {
    }

    XOverlap(int startPoint, int width) :
        startPoint_(startPoint),
        width_(width)
    {
    }

    int getStartPoint() const
    {
        return startPoint_;
    }

    int getWidth() const
    {
        return width_;
    }

    bool overlapExists() const
    {
        return width_ > 0;
    }

    bool operator==(const XOverlap& other) const
    {
        return
            startPoint_ == other.startPoint_
            && width_ == other.width_;
    }

    bool operator!=(const XOverlap& other) const
    {
        return !(*this == other);
    }
};

XOverlap findXOverlap(int x1, int width1, int x2, int width2)
{
    // find the highest ("rightmost") start point and lowest ("leftmost") end point
    int highestStartPoint = max(x1, x2);
    int lowestEndPoint = min(x1 + width1, x2 + width2);

    // return null overlap if there is no overlap
    if (highestStartPoint >= lowestEndPoint) {
        return XOverlap();
    }

    // compute the overlap width
    int overlapWidth = lowestEndPoint - highestStartPoint;

    return XOverlap(highestStartPoint, overlapWidth);
}
    
/* How can we adapt this for the rectangles’ ys and heights?
    
    Can we just make one findRangeOverlap() function that can handle x overlap and y overlap?

    Yes! We simply use more general parameter names:*/

class RangeOverlap
{
private:
    int startPoint_;
    int length_;

public:
    RangeOverlap() :
        startPoint_(0),
        length_(0)
    {
    }

    RangeOverlap(int startPoint, int width) :
        startPoint_(startPoint),
        length_(width)
    {
    }

    int getStartPoint() const
    {
        return startPoint_;
    }

    int getLength() const
    {
        return length_;
    }

    bool overlapExists() const
    {
        return length_ > 0;
    }

    bool operator==(const RangeOverlap& other) const
    {
        return
            startPoint_ == other.startPoint_
            && length_ == other.length_;
    }

    bool operator!=(const RangeOverlap& other) const
    {
        return !(*this == other);
    }
};


RangeOverlap findRangeOverlap(int point1, int length1, int point2, int length2)
{

    // find the highest start point and lowest end point.
    // the highest ("rightmost" or "upmost") start point is
    // the start point of the overlap.
    // the lowest end point is the end point of the overlap.
    int highestStartPoint = max(point1, point2);
    int lowestEndPoint = min(point1 + length1, point2 + length2);

    // return null overlap if there is no overlap
    if (highestStartPoint >= lowestEndPoint) {
        return RangeOverlap();
    }

    // compute the overlap length
    int overlapLength = lowestEndPoint - highestStartPoint;

    return RangeOverlap(highestStartPoint, overlapLength);
}

/* We've solved our subproblem of finding the x and y overlaps! Now we just need to put the results together. */

#include <iostream>

// C++11 lest unit testing framework
#include "lest.hpp"

using namespace std;

class Rectangle
{
private:
    // coordinates of bottom left corner
    int leftX_;
    int bottomY_;

    // dimensions
    int width_;
    int height_;

public:
    Rectangle() :
        leftX_(0),
        bottomY_(0),
        width_(0),
        height_(0)
    {
    }

    Rectangle(int leftX, int bottomY, int width, int height) :
        leftX_(leftX),
        bottomY_(bottomY),
        width_(width),
        height_(height)
    {
    }

    int getLeftX() const
    {
        return  leftX_;
    }

    int getBottomY() const
    {
        return  bottomY_;
    }

    int getWidth() const
    {
        return  width_;
    }

    int getHeight() const
    {
        return  height_;
    }

    bool operator==(const Rectangle& other) const
    {
        return
            leftX_ == other.leftX_
            && bottomY_ == other.bottomY_
            && width_ == other.width_
            && height_ == other.height_;
    }

    bool operator!=(const Rectangle& other) const
    {
        return !(*this == other);
    }
};

ostream& operator<<(ostream& os, const Rectangle& rect)
{
    os  << "(leftX: " << rect.getLeftX() << ", bottomY: " << rect.getBottomY()
        << ", width: " << rect.getWidth() << ", height: " << rect.getHeight() << ")";
    return os;
}

class RangeOverlap
{
private:
    int startPoint_;
    int length_;

public:
    RangeOverlap() :
        startPoint_(0),
        length_(0)
    {
    }

    RangeOverlap(int startPoint, int width) :
        startPoint_(startPoint),
        length_(width)
    {
    }

    int getStartPoint() const
    {
        return startPoint_;
    }

    int getLength() const
    {
        return length_;
    }

    bool overlapExists() const
    {
        return length_ > 0;
    }

    bool operator==(const RangeOverlap& other) const
    {
        return
            startPoint_ == other.startPoint_
            && length_ == other.length_;
    }

    bool operator!=(const RangeOverlap& other) const
    {
        return !(*this == other);
    }
};


RangeOverlap findRangeOverlap(int point1, int length1, int point2, int length2)
{

    // find the highest start point and lowest end point.
    // the highest ("rightmost" or "upmost") start point is
    // the start point of the overlap.
    // the lowest end point is the end point of the overlap.
    int highestStartPoint = max(point1, point2);
    int lowestEndPoint = min(point1 + length1, point2 + length2);

    // return null overlap if there is no overlap
    if (highestStartPoint >= lowestEndPoint) {
        return RangeOverlap();
    }

    // compute the overlap length
    int overlapLength = lowestEndPoint - highestStartPoint;

    return RangeOverlap(highestStartPoint, overlapLength);
}

// tests

const lest::test tests[] = {
    {CASE("Overlap along both axes") {
        const Rectangle rect1(1, 1, 6, 3);
        const Rectangle rect2(5, 2, 3, 6);
        const Rectangle expected(5, 2, 2, 2);
        const Rectangle actual = findRectangularOverlap(rect1, rect2);
        EXPECT(actual == expected);
    }},
    {CASE("One rectangle inside another") {
        const Rectangle rect1(1, 1, 6, 6);
        const Rectangle rect2(3, 3, 2, 2);
        const Rectangle expected(3, 3, 2, 2);
        const Rectangle actual = findRectangularOverlap(rect1, rect2);
        EXPECT(actual == expected);
    }},
    {CASE("Both rectangles the same") {
        const Rectangle rect1(2, 2, 4, 4);
        const Rectangle rect2(2, 2, 4, 4);
        const Rectangle expected(2, 2, 4, 4);
        const Rectangle actual = findRectangularOverlap(rect1, rect2);
        EXPECT(actual == expected);
    }},
    {CASE("Touch on horizontal edge") {
        const Rectangle rect1(1, 2, 3, 4);
        const Rectangle rect2(2, 6, 2, 2);
        const Rectangle expected(0, 0, 0, 0);
        const Rectangle actual = findRectangularOverlap(rect1, rect2);
        EXPECT(actual == expected);
    }},
    {CASE("Touch on vertical edge") {
        const Rectangle rect1(1, 2, 3, 4);
        const Rectangle rect2(4, 3, 2, 2);
        const Rectangle expected(0, 0, 0, 0);
        const Rectangle actual = findRectangularOverlap(rect1, rect2);
        EXPECT(actual == expected);
    }},
    {CASE("Touch at a corner") {
        const Rectangle rect1(1, 1, 2, 2);
        const Rectangle rect2(3, 3, 2, 2);
        const Rectangle expected(0, 0, 0, 0);
        const Rectangle actual = findRectangularOverlap(rect1, rect2);
        EXPECT(actual == expected);
    }},
    {CASE("No overlap") {
        const Rectangle rect1(1, 1, 2, 2);
        const Rectangle rect2(4, 6, 3, 6);
        const Rectangle expected(0, 0, 0, 0);
        const Rectangle actual = findRectangularOverlap(rect1, rect2);
        EXPECT(actual == expected);
    }},
};

int main(int argc, char** argv)
{
    return lest::run(tests, argc, argv);
}

/* Complexity
    O(1) time and O(1) space. */

/* Bonus
    1. What if we had a vector of rectangles and wanted to find all the rectangular overlaps between all possible pairs of two rectangles within the vector? 
    Note that we'd be returning a vector of rectangles.

    2. What if we had a vector of rectangles and wanted to find the overlap between all of them, if there was one? 
    Note that we'd be returning a single rectangle. */

/* What We Learned
    This is an interesting one because the hard part isn't the time or space optimization—it's getting something that works and is readable.

    For problems like this, I often see candidates who can describe the strategy at a high level but trip over themselves when they get into the details.

    Don't let it happen to you. To keep your thoughts clear and avoid bugs, take time to:

****Think up and draw out all the possible cases. Like we did with the ways ranges can overlap.
****Use very specific and descriptive variable names. */