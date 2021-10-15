## Recursion

- A good hint that a _problem is recursive_ is that it can be _built off of subproblems_.

- When you hear a **problem beginning** with the following **_statements_**, it's often (though not always) a **good candidate** for **_recursion_**: "Design an algorithm to compute the **_nth_** .. :; "Write code to list the **_first n_** .. :; "Imple­ment a method to **_compute all_**..:; and so on.

### How to Approach

- Recursive solutions, by definition, are _built off of solutions to subproblems_.

- Many times, this will mean simply to **compute f(n)** by **_adding_** something, **_removing_** something, or otherwise **_changing_** the **_solution_** for **_f(n-1)_**.

- In other cases, you might **solve** the problem _for_ the **_first half_** of the data set, then the **_second half_**, and then **_merge_** those **_results_**.

- There are many **ways** you might **divide** a problem into **subproblems**.
  - Three of the most common approaches to develop an algorithm are **_bottom-up_**, **_top-down_**, and **_half-and-half_**.

#### Recursive vs. Iterative Solutions

- Recursive algorithms can be very space inefficient.

- _Before diving into recursive code, ask yourself how hard it would be to implement it iteratively_, and **_discuss the tradeoffs with your interviewer_**.
