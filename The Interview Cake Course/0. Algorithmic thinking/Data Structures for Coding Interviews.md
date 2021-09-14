# Data Structures for Coding Interviews

## Random Access Memory (RAM)

- When a computer is running code, it needs to keep track of variables (numbers, strings, arrays, etc.).
- Variables are stored in random access memory (**RAM**). We sometimes call RAM "working memory" or just "memory."
- we call it Random Access Memory (RAM)—we can Access the bits at any Random address in Memory right away due to direct connections of memory controller to RAM. That means we can read the stuff at any given memory address in O(1) time.
  [See Image](https://www.interviewcake.com/images/svgs/cs_for_hackers__ram_cache.svg?bust=209)

## Fixed-width integers

- In big O notation, we say **fixed-width integers take up constant space or O(1) space**.

- And because they have a constant number of bits, **most simple operations on fixed-width integers (addition, subtraction, multiplication, division) take constant time (O(1) time)**.

- So fixed-width integers are very space efficient and time efficient.

## Arrays

- Tradeoff :
  - Although Arrays have fast lookups (O(1) time), but each item in the array needs to be the **same size**, and you need a big block of **uninterrupted free memory** to store the array.

## Strings

- This mapping of numbers to characters is called a **character encoding**. One common character encoding is "ASCII".
  - A: 01000001, B: 01000010,..., Z: 01011010
  - a: 01100001, b: 01100010,..., z: 01111010
- we can express characters as 8-bit integers, we can express strings as arrays of 8-bit ~~numbers~~ characters.

## Pointers

- Pointers fixes both the disadvantages of arrays:

  - The items don't have to be the same length—each string can be as long or as short as we want.
  - We don't need enough uninterrupted free memory to store all our strings next to each other—we can place each of them separately, wherever there's space in RAM.

- Remember how the memory controller sends the contents of nearby memory addresses to the processor with each read? And the processor caches them? So reading sequential addresses in RAM is faster because we can get most of those reads right from the cache?

### New tradeoff is?

  - This pointer-based array requires less uninterrupted memory and can accommodate elements that aren't all the same size, But the **pointers in this array make it not cache-friendly**, because the baby names are scattered randomly around RAM.

        This slowdown isn't reflected in the big O time cost. Lookups in this pointer-based array are still O(1) time.

## Dynamic arrays

- When you allocate a dynamic array, your dynamic array implementation makes an underlying static array. The starting size depends on the implementation.

- When we do m appends, the appends themselves cost m, and the doubling costs 2m. Put together, we've got a cost of 3m, which is O(m). So on average, each individual append is O(1). m appends cost us O(m).[See Image](https://www.interviewcake.com/images/svgs/amortized_analysis_m_over_8.svg?bust=209)

- Remember : even though the **amortized cost** of an append is O(1), the **worst case** cost is still O(n). Some appends will take a long time.

- In industry we usually wave our hands and say dynamic arrays have a time cost of O(1) for appends, even though strictly speaking that's only true for the average case or the **amortized cost**.

- In an interview, if we were worried about that O(n)-time worst-case cost of appends, we might try to use a normal, non-dynamic array.

### Tradeoff

  - **The advantage of dynamic arrays over arrays is that you don't have to specify the size ahead of time, but the disadvantage is that some appends can be expensive.**

## Linked lists

- The first node of a linked list is called the **head**, and the last node is usually called the **tail**.

      Confusingly, some people prefer to use "tail" to refer to everything after the head of a linked list. In an interview it's fine to use either definition. Briefly say which definition you're using, just to be clear.

- It's important to have a pointer variable referencing the head of the list—otherwise we'd be unable to find our way back to the start of the list!

- We'll also sometimes keep a pointer to the tail.

- **Linked lists** have **worst-case O(1)**-time **appends**, which is **better** than the **worst-case O(n)** time of **dynamic arrays**.

      That worst-case part is important. The average case runtime for appends to linked lists and dynamic arrays is the same: O(1).

- Linked lists have faster **prepends** (O(1) time) than dynamic arrays (O(n) time).

- So if linked lists are so great, why do we usually store strings in an array? **Because arrays have O(1)-time lookups.** But **linked lists** have **O(i)**-time lookups and walking down a linked list is **not cache-friendly**.

### Tradeoff

  - Linked lists have faster prepends and faster appends than dynamic arrays, but they have slower lookups.

## Hash tables

- Quick lookups are often really important. For that reason, we tend to use arrays (O(1)-time lookups) much more often than linked lists (O(i)-time lookups).

- The modulus operation (also called **modulo** or mod or **%**) is commonly **used** to **force a number into a certain range**. For example, any number, when modded by 3 gives us an integer in the range 0..2

- In our hash table, the counts are the **values** and the words ("lies," etc.) are the **keys** (analogous to the indices in an array). The process we used to translate a key into an array index is called a **hashing function**.[See Image](https://www.interviewcake.com/images/svgs/cs_for_hackers__hash_tables_lies_key_labeled.svg?bust=209)

      Note that our quick lookups are only in one direction—we can quickly get the value for a given key, but the only way to get the key for a given value is to walk through all the values and keys.

      Same thing with arrays—we can quickly look up the value at a given index, but the only way to figure out the index for a given value is to walk through the whole array.

- One problem—what if two keys hash to the same index in our array? Look at "lies" and "foes". So our hashing function gives us the same answer for "lies" and "foes." This is called a **hash collision**. There are a few different strategies for dealing with them.

  - A common one: instead of storing the actual values in our array, let's have each array slot hold a pointer to a linked list holding the counts for all the words that hash to that index.

  - One problem—how do we know which count is for "lies" and which is for "foes"? To fix this, we'll store the word as well as the count in each linked list node.[See Image](https://www.interviewcake.com/images/svgs/cs_for_hackers__hash_tables_hash_collision_key_val.svg?bust=209)

  - "But wait!" you may be thinking, "Now lookups in our hash table take O(n) time in the worst case, since we have to walk down a linked list." That's true! You could even say that in the worst case every key creates a hash collision, so our whole hash table degrades to a linked list.

- In industry though, we usually wave our hands and say **collisions are rare enough that on average lookups in a hash table are O(1) time**. And there are fancy algorithms that keep the number of collisions low and keep the lengths of our linked lists nice and short.

### Tradeoff

- You get fast lookups by key...except some lookups could be slow. And of course, you only get those fast lookups in one direction—looking up the key for a given value still takes O(n) time.

---

## Summary

- **Each data structure has tradeoffs**. You can't have it all.

- So you have to know what's important in the problem you're working on. What does your data structure need to do quickly? Is it lookups by index? Is it appends or prepends?

- Once you know what's important, you can pick the data structure that does it best.
