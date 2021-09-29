/* Given information about active users on the network, 
find the shortest route for a message from one user (the sender) to another (the recipient). Return a vector of users that make up this route.*/

/* Gotchas
    We can find the shortest route in O(N+M) time, where N is the number of users and M is the number of connections between them.

    It's easy to write code that can get caught in an infinite loop for some inputs! Does your code always finish running?

    What happens if there's no way for messages to get to the recipient?

    What happens if the sender tries to send a message to themselves? */

/* Breakdown
    Users? Connections? Routes? What data structures can we build out of that? 
    Let's run through some common ones and see if anything fits here.

    Vectors? Nope—those are a bit too simple to express our network of users.
    Unordered maps? Maybeee.
    Graphs? ↴ Yeah, that seems like it could work! 
    
    Is our graph directed or undirected? ↴ Weighted or unweighted? ↴
    
    Okay, how do we start looking around our graph to find the shortest route from one user to another?

    Or, more generally, how do we find the shortest path from a start node to an end node in an unweighted, undirected graph?
    
    Remember: both BFS and DFS will eventually find a path if one exists. The difference between the two is:

        BFS always finds the shortest path.
        DFS usually uses less space.*/

/* let's start with a standard implementation of breadth-first search: */
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include<deque>
#include<algorithm>
using namespace std;

void bfs(const unordered_map<string, vector<string>>& graph,
         const string& startNode, const string& endNode)
{
    deque<string> nodesToVisit;
    nodesToVisit.push_back(startNode);

    // keep track of what nodes we've already seen
    // so we don't process them twice
    unordered_set<string> nodesAlreadySeen;
    nodesAlreadySeen.insert(startNode);

    while (!nodesToVisit.empty()) {
        string currentNode = move(nodesToVisit.front());
        nodesToVisit.pop_front();

        // stop when we reach the end node
        if (currentNode == endNode) {
            // found it!
            break;
        }

        for (const auto& neighbor : graph.find(currentNode)->second) {
            if (nodesAlreadySeen.count(neighbor) == 0) {
                nodesAlreadySeen.insert(neighbor);
                nodesToVisit.push_back(neighbor);
            }
        }
    }
}

/*  1. Look at the nodesAlreadySeen unordered set—that's really important and easy to forget. 
    If we didn't have it, our algorithm would be slower (since we'd be revisiting tons of nodes) and it might never finish (if there's no path to the end node).

    2. We're using a deque instead of a vector because we want an efficient first-in-first-out (FIFO) structure with O(1) inserts and removes. 
    If we used a vector, appending would be O(1), but removing elements from the front would be O(n). */

/* But we're still missing an important piece: we didn't actually store our path anywhere. 
    We need to reconstruct the path we took. How do we do that? */

vector<string> bfsGetPath(const unordered_map<string, vector<string>>& graph,
                               const string& startNode, const string& endNode)
{
    deque<string> nodesToVisit;
    nodesToVisit.push_back(startNode);

    // keep track of what nodes we've already seen
    // so we don't process them twice
    unordered_set<string> nodesAlreadySeen;
    nodesAlreadySeen.insert(startNode);

    // keep track of how we got to each node
    // we'll use this to reconstruct the shortest path at the end
    unordered_map<string, string> howWeReachedNodes;
    howWeReachedNodes.emplace(startNode, "");

    while (!nodesToVisit.empty()) {
        string currentNode = move(nodesToVisit.front());
        nodesToVisit.pop_front();

        // stop when we reach the end node
        if (currentNode == endNode) {
            vector<string> path;

            // somehow reconstruct the path here
            return path;
        }

        for (const auto& neighbor : graph.find(currentNode)->second) {
            if (nodesAlreadySeen.count(neighbor) == 0) {
                nodesAlreadySeen.insert(neighbor);
                nodesToVisit.push_back(neighbor);

                // keep track of how we got to this node
                howWeReachedNodes.emplace(neighbor, currentNode);
            }
        }
    }

    return vector<string>();
}

/* But, before we're done, let's think about edge cases and optimizations.

    What are our edge cases, and how should we handle them?

    What happens if there isn't a route from the sender to the recipient? 

    What about if either the sender or recipient aren't in our user network?*/

/* So, let's talk about optimizations. Can we make our algorithm run faster or take less space? 

    One thing that stands out is that we have two data structures— nodesAlreadySeen and howWeReachedNodes—that are updated in similar ways. 
    In fact, every time we add a node to nodesAlreadySeen, we also add it to howWeReachedNodes. 
    Do we need both of them?*/

/* Solution */

  vector<string> reconstructPath(const unordered_map<string, string>& previousNodes,
                               const string& startNode, const string& endNode)
{
    vector<string> reversedShortestPath;

    // start from the end of the path and work backwards
    string currentNode = endNode;

    while (!currentNode.empty()) {
        reversedShortestPath.push_back(currentNode);
        currentNode = previousNodes.find(currentNode)->second;
    }

    // reverse our path to get the right order
    // by flipping it around, in place
    reverse(reversedShortestPath.begin(), reversedShortestPath.end());
    return reversedShortestPath;  // no longer reversed
}

vector<string> bfsGetPath(const unordered_map<string, vector<string>>& graph,
                           const string& startNode, const string& endNode)
{
    if (graph.count(startNode) == 0) {
        throw invalid_argument("Start node not in graph");
    }
    if (graph.count(endNode) == 0) {
        throw invalid_argument("End node not in graph");
    }

    deque<string> nodesToVisit;
    nodesToVisit.push_back(startNode);

    // keep track of how we got to each node
    // we'll use this to reconstruct the shortest path at the end
    // we'll ALSO use this to keep track of which nodes we've
    // already visited
    unordered_map<string, string> howWeReachedNodes;
    howWeReachedNodes.emplace(startNode, "");

    while (!nodesToVisit.empty()) {
        string currentNode = move(nodesToVisit.front());
        nodesToVisit.pop_front();

        // stop when we reach the end node
        if (currentNode == endNode) {
            return reconstructPath(howWeReachedNodes, startNode, endNode);
        }

        for (const auto& neighbor : graph.find(currentNode)->second) {
            if (howWeReachedNodes.count(neighbor) == 0) {
                nodesToVisit.push_back(neighbor);
                howWeReachedNodes.emplace(neighbor, currentNode);
            }
        }
    }

    // if we get here, then we never found the end node
    // so there's NO path from startNode to endNode
    return vector<string>();
}

/* Complexity
Our solution has two main steps. First, we do a breadth-first search of the user network starting from the sender. 
Then, we use the results of our search to backtrack and find the shortest path.

How much work is a breadth-first search? 

    In the worst case, we'll go through the BFS loop once for every node in the graph, since we only ever add each node to nodesToVisit once (we check howWeReachedNodes to see if we've already added a node before). 
    Each loop iteration involves a constant amount of work to dequeue the node and check if it's our end node. If we have n nodes, then this portion of the loop is O(N).

    But there's more to each loop iteration: we also look at the current node's neighbors. Over all of the nodes in the graph, checking the neighbors is O(M), 
    since it involves crossing each edge twice: once for each node at either end.

    Putting this together, the complexity of the breadth-first search is O(N+M).

****BFS and DFS are common enough that it's often acceptable to just state their complexity as O(N+M). 
    Some interviewers might want you to derive it though, so definitely be ready in case they ask.
    
    What about backtracking to determine the shortest path? O(N + N) = O(N)
    So, overall complexity = O(M+N)
    
    What about space complexity? 
    The queue of nodes to visit, the mapping of nodes to previous nodes, and the final path ... they all store a constant amount of information per node. 
    So, each data structure could take up to O(N) space if it stored information about all of our nodes. 
    That means our overall space complexity is O(N).*/

/* Bonus
    1. In our solution, we assumed that if one user (Min) could transmit a message to another (Jayden), then Jayden would also be able to transmit a message to Min. 
    Suppose this wasn't guaranteed—maybe Min's cell phone transmits over shorter distances than Jayden's. How would our graph change to represent this? Could we still use BFS?
    
    2. What if we wanted to find the shortest path? Assume we're given a GPS location for each user. 
    How could we incorporate the distance between users into our graph? How would our algorithm change?
    
    3. In our solution, we assumed that users never moved around. 
    How could we extend our algorithm to handle the graph changing over time? */

/* What We Learned
    The tricky part was backtracking to assemble the path we used to reach our endNode. 
    In general, it's helpful to think of backtracking as two steps:

        1. Figuring out what additional information we need to store in order to rebuild our path at the end (howWeReachedNodes, in this case).
        2. Figuring out how to reconstruct the path from that information.

    And in this case, something interesting happened after we added howWeReachedNodes—it made nodesAlreadySeen redundant! So we were able to remove it. 
****A good reminder to always look through your variables at the end and see if there are any you can cut out. */