## Binary Tree

    class BinaryTreeNode
    {
    public:
        int value_;
        BinaryTreeNode* left_;
        BinaryTreeNode* right_;

        BinaryTreeNode(int value) :
            value_(value),
            left_(nullptr),
            right_(nullptr)
        {
        }

        ~BinaryTreeNode() {
            delete left_;
            delete right_;
        }
    };

- Binary trees have a few interesting properties when they're perfect:

  - Property 1: the number of total nodes on each "level" **doubles** as we move down the tree. [See Image](https://www.interviewcake.com/images/svgs/binary_tree__depth_5_with_number_of_nodes_labelled.svg?bust=209)

  - Property 2: the number of **nodes** on the **last level** is equal to the **sum** of the number of **nodes** on **all other levels (plus 1)**. In other words, about half of our nodes are on the last level.

  - The relationship between height and total nodes in a perfect binary tree is :

        n = 2^h - 1
        log2(n+1) = h

## Graph

- **Strengths**:

  - **Representing links**. Graphs are ideal for cases where you're working with things that connect to other things. Nodes and edges could, for example, respectively represent cities and highways, routers and ethernet cables, or Facebook users and their friendships.

- **Weaknesses**:

  - **Scaling challenges**. Most graph algorithms are O(n\*lg(n)) or even slower. Depending on the size of your graph, running algorithms across your nodes may not be feasible.

- **Legal coloring**
  - A graph coloring is when you assign colors to each node in a graph. A legal coloring means no adjacent nodes have the same color. [See Image](https://www.interviewcake.com/images/svgs/graph_coloring__legal_and_illegal_coloring.svg?bust=209)

### **Representations** [Example graph](https://www.interviewcake.com/images/svgs/graph_coloring__example_graph.svg?bust=209)

- **Edge list**: A list of all the edges in the graph

      vector<vector<int>> graph = {{0, 1}, {1, 2}, {1, 3}, {2, 3}};

  - Sometimes it's helpful to pair our edge list with a list of all the nodes. For example, what if a node doesn't have any edges connected to it? It wouldn't show up in our edge list at all!

- **Adjacency list**: A list where the index represents the node and the value at that index is a list of the node's neighbors:

        vector<vector<int>> graph = {
        {1},
        {0, 2, 3},
        {1, 3},
        {1, 2}
        };

  - Since node 3 has edges to nodes 1 and 2, graph[3] has the adjacency list {1, 2}.

  - We could also use an **unordered map** where the **keys** represent the **node** and the **values** are the **lists of neighbors**.

        unordered_map<int, vector<int>> graph {
        {0, {1}},
        {1, {0, 2, 3}},
        {2, {1, 3}},
        {3, {1, 2}}
        };

    - This would be useful if the **nodes** were represented by **strings, objects**, or otherwise **didn't map** cleanly to **vector indices**.

- **Adjacency matrix**: A matrix of 0s and 1s indicating whether node x connects to node y (0 means no, 1 means yes).
  vector<vector<int>> graph {
  {0, 1, 0, 0},
  {1, 0, 1, 1},
  {0, 1, 0, 1},
  {0, 1, 1, 0},
  };

### **Algorithms**

- BFS and DFS

  - **Is there a path between two nodes in this undirected graph?** Run DFS or BFS from one node and see if you reach the other one.

  - **What's the shortest path between two nodes in this undirected, unweighted graph?** Run BFS from one node and backtrack once you reach the second. Note: BFS always finds the shortest path, assuming the graph is undirected and unweighted. DFS does not always find the shortest path.

  - **Can this undirected graph be colored with two colors?** Run BFS, assigning colors as nodes are visited. Abort if we ever try to assign a node a color different from the one it was assigned earlier.

  - **Does this undirected graph have a cycle?** Run BFS, keeping track of the number of times we're visiting each node. If we ever visit a node twice, then we have a cycle.

- **Advanced graph algorithms**

  - **Dijkstra's Algorithm**: Finds the shortest path from one node to all other nodes in a weighted graph.

  - **Topological Sort**: Arranges the nodes in a directed, acyclic graph in a special order based on incoming edges.

  - **Minimum Spanning Tree**: Finds the cheapest set of edges needed to reach all nodes in a weighted graph.

## Breadth-First Search (BFS)

- **Advantages**:

  - A BFS will find the **shortest path** between the starting point and any other reachable node.
  - A depth-first search will not necessarily find the shortest path.

- **Disadvantages**

  - A BFS on a binary tree generally requires more memory than a DFS.

        More specifically, BFS uses O(branchingFactor^maxDepth) or O(maxWidth) memory, where-as DFS only uses O(maxDepth).

    - If maxWidth < maxDepth, BFS should use less memory (assuming you use similar representations for both), but this is rarely true.

    - The difference gets a lot worse as the tree goes larger (as long as it stays fairly full).

    - For example, in a (balanced) tree with 1023 nodes the DFS has to keep track of 10 nodes, while the BFS has to keep track of 512 nodes.

    - So depth-first search will only use **O(log(n))** memory and breadth-first search will use **O(n)**. For balanced k-ary trees; for other cases different results are possible (but for most common graphs diameter will still be significantly less than circumference).

## Depth-First Search (DFS)

- **Advantages**:

  - Depth-first search on a binary tree generally requires less memory than breadth-first.
  - Depth-first search can be easily implemented with recursion.
    Disadvantages

- **Disadvantages**

  - **DFS doesn't necessarily find the shortest path to a node**, while breadth-first search does.
