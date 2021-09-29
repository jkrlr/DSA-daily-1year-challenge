/* Given an undirected graph ↴ with maximum degree ↴ D, find a graph coloring ↴ using at most D+1 colors. */

/* Graphs are represented by a vector of N node objects, each with a label, an unordered set of neighbors, and a color: */

/* Gotchas
    D+1 colors is always enough. Does your function ever need more colors than that?

    Does your function go through every color for every node? You can do better. You don't want N∗D in your final runtime.

    We can color a graph in linear ↴ time and space (on the number of nodes, edges and/or the maximum degree).

    What if the input graph has a loop ↴ ? Does your function handle that reasonably? */

/* Breakdown
    Let's take a step back. Is it always possible to find a legal coloring with D+1 colors?

    Let's think about it. Each node has at most D neighbors, and we have D+1 colors. 
    So, if we look at any node, there's always at least one color that's not taken by its neighbors.

    So yes—D+1 is always enough colors for a legal coloring.

    Still not convinced? We can prove this more formally using induction. ↴

    Okay, so there is always a legal coloring. Now, how can we find it?

    A brute force ↴ approach would be to try every possible combination of colors until we find a legal coloring. Our steps would be:

        - For each possible graph coloring,
        - If the coloring is legal, then return it
        - Otherwise, move on to the next coloring 
        
    This would work. But what's the complexity?

    Here we'd try 4^{12} combinations (every combination of 4 colors for 12 nodes). In general, we'll have to check O(D^N) colorings. 
    And that's not all—each time we try a coloring, we have to check all M edges to see if the vertices at both ends have different colors. So, our runtime is O(M*D^N).
    That's exponential time since N is in an exponent.
    
****Since this algorithm is so inefficient, it's probably not what the interviewer is looking for. With practice, it gets easier to quickly judge if an approach will be inefficient. 
    Still, sometimes it's a good idea in an interview to briefly explain inefficient ideas and why you think they're inefficient. It shows rigorous thinking.
    
    How can we color the graph more efficiently?

    Well, we're wasting a lot of time trying color combinations that don't work. 
    If the first 2 nodes are neighbors, we shouldn't try any combinations where the first 2 colors are the same.

    Instead of assigning all the colors at once, what if we colored the nodes one by one?

    We could assign a color to the first node, then find a legal color for the second node, then for the third node, and keep going node by node.
    
    */

/*Using this tighter analysis, we've taken our runtime from N*(D+D+1) down to N∗(D+1)+M. That's O((N∗D)+M) time. 

void colorGraph(const vector<GraphNode*>& graph, const vector<string>& colors)
{
    for (auto node : graph) {

        // get the node's neighbors' colors, as a set so we
        // can check if a color is illegal in constant time
        unordered_set<string> illegalColors;
        for (const auto neighbor : node->getNeighbors()) {
            if (neighbor->hasColor()) {
                illegalColors.insert(neighbor->getColor());
            }
        }

        unordered_set<string> legalColors;
        for (const auto& color : colors) {
            if (illegalColors.find(color) == illegalColors.cend()) {
                legalColors.insert(color);
            }
        }

        // assign the first legal color
        node->setColor(*legalColors.begin());
    }
} */

/*void colorGraph(const vector<GraphNode*>& graph, const vector<string>& colors)
{
    for (auto node : graph) {

        // get the node's neighbors' colors, as a set so we
        // can check if a color is illegal in constant time
        unordered_set<string> illegalColors;
        for (const auto neighbor : node->getNeighbors()) {
            if (neighbor->hasColor()) {
                illegalColors.insert(neighbor->getColor());
            }
        }

        // assign the first legal color
        for (const auto& color : colors) {
            if (illegalColors.find(color) == illegalColors.cend()) {
                node->setColor(color);
                break;
            }
        }
    }
} */

/* Before we're done, what about edge cases?

    For graph problems in general, edge cases are:

        nodes with no edges
        cycles
        loops               */

#include <iostream>
#include <memory>
#include <algorithm>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class GraphNode
{
private:
    string label_;
    unordered_set<GraphNode*> neighbors_;
    string color_;

public:
    GraphNode(const string& label) :
        label_(label),
        neighbors_(),
        color_()
    {
    }

    const string& getLabel() const
    {
        return label_;
    }

    const unordered_set<GraphNode*> getNeighbors() const
    {
        return neighbors_;
    }

    void addNeighbor(GraphNode& neighbor)
    {
        neighbors_.insert(&neighbor);
    }

    bool hasColor() const
    {
        return !color_.empty();
    }

    const string& getColor() const
    {
        if (hasColor()) {
            return color_;
        }
        else {
            throw logic_error("GraphNode is not marked with color");
        }
    }

    void setColor(const string& color)
    {
        color_ = color;
    }
};

void colorGraph(const vector<GraphNode*>& graph, const vector<string>& colors)
{
    for (auto node : graph) {
        const auto& neighbors = node->getNeighbors();

        if (neighbors.find(node) != neighbors.end()) {
            ostringstream errorMessage;
            errorMessage << "Legal coloring impossible for node with loop: "
                    << node->getLabel();
            throw invalid_argument(errorMessage.str());
        }

        // get the node's neighbors' colors, as a set so we
        // can check if a color is illegal in constant time
        unordered_set<string> illegalColors;
        for (const auto neighbor : neighbors) {
            if (neighbor->hasColor()) {
                illegalColors.insert(neighbor->getColor());
            }
        }

        // assign the first legal color
        for (const auto& color : colors) {
            if (illegalColors.find(color) == illegalColors.cend()) {
                node->setColor(color);
                break;
            }
        }
    }
}

/* Solution
    We go through the nodes in one pass, assigning each node the first legal color we find.

    How can we be sure we'll always have at least one legal color for every node? In a graph with maximum degree D, each node has at most D neighbors.
    That means there are at most DD colors taken by a node's neighbors. And we have D+1 colors, so there's always at least one color left to use.

    When we color each node, we're careful to stop iterating over colors as soon as we find a legal color. */


/* Complexity
    O(N+M) time where N is the number of nodes and M is the number of edges.

    The runtime might not look linear ↴ because we have outer and inner loops. 
    The trick is to look at each step and think of things in terms of the total number of edges (M) wherever we can:
        
        We check if each node appears in its own unordered set of neighbors. 
        Checking if something is in an unordered set is O(1), so doing it for all N nodes is O(N).
        
        When we get the illegal colors for each node, we iterate through that node's neighbors. 
        So in total, we cross each of the graphs MM edges twice: once for the node on either end of each edge. O(M) time.

        When we assign a color to each node, we're careful to stop checking colors as soon as we find one that works. 
        In the worst case, we'll have to check one more color than the total number of neighbors. 
        Again, each edge in the graph adds two neighbors—one for the node on either end—so there are 2*M neighbors. 
        So, in total, we'll have to try O(N+M) colors.
        
        Putting all the steps together, our complexity is O(N+M).
    
    What about space complexity? The only thing we're storing is the illegalColors unordered set. 
    In the worst case, all the neighbors of a node with the maximum degree (D) have different colors, 
    so our unordered set takes up O(D) space.*/

/* Bonus
    1. Our solution runs in O(N+M) time but takes O(D) space. Can we get down to O(1) space?
    2. Our solution finds a legal coloring, but there are usually many legal colorings. 
        What if we wanted to optimize a coloring to use as few colors as possible? */

/* What We Learned
    We used a greedy ↴ approach to build up a correct solution in one pass through the nodes.

    This brought us close to the optimal runtime, 
    but we also had to take that last step of iterating over the colors only until we find a legal color. 
    Sometimes stopping a loop like that is just a premature optimization that doesn't bring down the final runtime, 
    but here it actually made our runtime linear! */