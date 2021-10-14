# Note

- Some of the **terms** in this chapter can **vary slightly** across different textbooks and other sources.
  - If you're used to a different definition, that's fine.
  - **_Make sure to clear up any ambiguity with your interviewer_**.

## Trees

- The tree _cannot_ contain _cycles_.
- The nodes may or may not be in a particular order, they could have _any data type_ as _values_, and they _may or may not_ have _links back_ to their _parent_ nodes.

- Tree and graph questions are rife with ambiguous details and incorrect assumptions.
- Be sure to **_watch_** out for the following **_issues_** and **_seek clarification when necessary_**.

  - _Trees vs. Binary Trees_
  - _Binary Tree vs. Binary Search Tree_

    - all left descendents <= n < all right descendents.
    - **Note**: The definition of a binary search tree can vary slightly with respect to equality.
    - Under some defi­nitions, the tree cannot have duplicate values.
    - In others, the duplicate values will be on the right or can be on either side.
    - All are valid definitions, but you should clarify this with your interviewer.

  - _Balanced vs. Unbalanced_

    - Ask your interviewer for clarification here.

    - Note that balancing a tree does not mean the left and right subtrees are exactly the same size.
    - One way to think about it is that a "balanced" tree really means something more like "not terribly imbal­anced:'
    - It's balanced enough to ensure _O(logn)_ times for _insert_ and _find_, but it's not necessarily as balanced as it could be.

  - _Complete Binary Trees_
  - _Full Binary Trees_
  - _Perfect Binary Trees_

### Binary Heaps (Min-Heaps and Max-Heaps)

- A _min-heap_ is a _complete binary tree_ (that is, totally filled other than the rightmost elements on the last level)
- where _each node_ is _smaller_ than its _children_. The root, therefore, is the minimum element in the tree.

### Tries (Prefix Trees)

- A trie is a variant of an n-ary tree in which characters are stored at each node. Each path down the tree may represent a word.

- Very commonly, a **_trie_** is used to store the entire (English) language for **_quick prefix lookups_**.
- While a **_hash table_** can **_quickly look up_** whether a **_string is a valid word_**, it cannot tell us if a string is a prefix of any valid words. A trie can do this very quickly.
  - How quickly?
    - A **trie** can check if a string is a valid prefix in **O(K)** time, where K is the length of the string.
    - This is actually the same runtime as a hash table will take. Although we often refer to hash table lookups as being O(1) time, this isn't entirely true.
    - **_A hash table must read through all the characters in the input, which takes O (K) time in the case of a word lookup_**.

## Graphs

- _Bidirectional Search_
  - Bidirectional search is used to find the shortest path between a source and destination node.
  - It operates by essentially running two simultaneous breadth-first searches, one from each node. When their searches collide, we have found a path.
