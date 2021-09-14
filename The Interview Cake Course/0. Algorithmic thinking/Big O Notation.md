# Big O Notation

- Big O notation we express the runtime in terms of:

  1. how **quickly the runtime grows**
  2. **relative to the input**
  3. as the **input gets arbitrarily large**

- We're usually talking about the "worst case".Often this "worst case" stipulation is implied. But sometimes you can impress your interviewer by saying it explicitly.

- Sometimes the worst case runtime is significantly worse than the best case runtime:

        bool contains(const vector<int>& haystack, int needle)
        {
            // does the haystack contain the needle?
            for (int n : haystack) {
                if (n == needle) {
                    return true;
                }
            }

            return false;
        }
        In general we'd say this is O(n)runtime and the "worst case" part would be implied.
        But to be more specific we could say this is worst case O(n) and best case O(1) runtime

## Space complexity

- Sometimes we want to optimize for using less memory instead of (or in addition to) using less time.
- For Space complexity, We simply look at the total size (relative to the size of the input) of any new variables we're allocating.

### Big O analysis is awesome except when it's not:

- Big O ignores constants, but sometimes the constants matter.
- If we have a script that takes 5 hours to run, an optimization that divides the runtime by 5 might not affect big O, but it still saves you 4 hours of waiting.

- Beware of premature optimization. Sometimes optimizing time or space negatively impacts readability or coding time.
- For a young startup it might be more important to write code that's easy to ship quickly or easy to understand later, even if this means it's less time and space efficient than it could be.

- You should develop the skill to see time and space optimizations,as well as the **wisdom** to judge if those **optimizations** are **worthwhile**.
