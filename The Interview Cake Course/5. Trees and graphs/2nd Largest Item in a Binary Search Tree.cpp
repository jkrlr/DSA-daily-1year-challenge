/* Gotchas
****Our first thought might be to do an in-order traversal of the BST and return the second-to-last item. 
    This means looking at every node in the BST. That would take O(n) time and O(h) space, 
    where h is the max height of the tree (which is lg(n) if the tree is balanced, but could be as much as n if not).

    We can do better than O(n) time and O(h) space.

    We can do this in one walk from top to bottom of our BST. 
    This means O(h) time (again, that's O(lgn) if the tree is balanced, O(n) otherwise).

****A clean recursive implementation will take O(h) space in the call stack, 
    but we can bring our algorithm down to O(1) space overall. */

/* Breakdown
****Let's start by solving a simplified version of the problem and see if we can adapt our approach from there.
    How would we find the largest element in a BST?

****A reasonable guess is to say the largest element is simply the "rightmost" element.

    So maybe we can start from the root and just step down right child pointers until we can't anymore (until the right child is false). 
    At that point the current node is the largest in the whole tree.
    
    How would we formalize getting the "rightmost" element in code?

****Okay, so we can find the largest element. 
****How can we adapt this approach to find the second largest element?*/

/* Solution
    We start with a function for getting the largest value. The largest value is simply the "rightmost" one, 
    so we can get it in one walk down the tree by traversing rightward until we don't have a right child anymore: 
    
    With this in mind, we can also find the second largest in one walk down the tree. 
    At each step, we have a few cases:
        1. If we have a left subtree but not a right subtree
        2. If we have a right child, but that right child node doesn't have any children
        3. Else, we have a right subtree with more than one element*/

#include <iostream>

using namespace std;

int findLargest(const BinaryTreeNode* rootNode)
{
    const BinaryTreeNode* current = rootNode;
    while (current->right_) {
        current = current->right_;
    }
    return current->value_;
}

int findSecondLargest(const BinaryTreeNode* rootNode)
{
    if (!rootNode || (!rootNode->left_ && !rootNode->right_)) {
        throw invalid_argument("Tree must have at least 2 nodes");
    }

    const BinaryTreeNode* current = rootNode;

    while (true) {

        // case: current is largest and has a left subtree
        // 2nd largest is the largest in that subtree
        if (current->left_ && !current->right_) {
            return findLargest(current->left_);
        }

        // case: current is parent of largest, and largest has no children,
        // so current is 2nd largest
        if (current->right_ &&
                !current->right_->left_ &&
                !current->right_->right_) {
            break;
        }

        // step to the right
        current = current->right_;
    }

    return current->value_;
}

/* Complexity
    We're doing one walk down our BST, which means O(h) time, 
    where h is the height of the tree (again, that's O(lgn) if the tree is balanced, O(n) otherwise). O(1) space. */

/* What We Learned
****Here we used a "simplify, solve, and adapt" strategy.

    The question asks for a function to find the second largest element in a BST, 
    so we started off by simplifying the problem: we thought about how to find the first largest element.

****Once we had a strategy for that, we adapted that strategy to work for finding the second largest element. 
    
    It may seem counter-intuitive to start off by solving the wrong question. 
    But starting off with a simpler version of the problem is often much faster, 
    because it's easier to wrap our heads around right away.
    
    One more note about this one:

****Breaking things down into cases is another strategy that really helped us here.

    Notice how simple finding the second largest node got when we divided it into two cases:
        1.The largest node has a left subtree.
        2.The largest node does not have a left subtree.

****Whenever a problem is starting to feel complicated, try breaking it down into cases.

    It can be really helpful to actually draw out sample inputs for those cases. 
    This'll keep your thinking organized and also help get your interviewer on the same page.*/