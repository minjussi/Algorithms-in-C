# Merge Sorting

## Source Code Explanation

1. Node* merge(Node *a, Node *b): Create dummy node for new sorted list. The new sorted list starts with dummy node. Then, comparing key attributes with strcmp(const char *str1, const char *str2) function. strcmp function compares two strings with ASCII value and returns integer value. Writing conditional expression as if (strcmp (a->key, b->key) <= 0) to order elements in ascending order, and it guarantees keeping same order if the key is equal. Finally, if any sorted list is left, then append it to the new sorted list. 


2. Node* merge_sort(Node *head): To find the midpoint, normally the two pointers are used; slow and fast pointers. Slow pointer moves forward by 1 node, and fast pointer moves forward by 2 nodes. When the fast pointer reaches the end, slow pointer points to the midpoint. After finding the midpoint, split the list into two halves making the last element NULL. 

## Performance Analysis
The overall time complexity of the program is O(n log n), which is dominated by the Merge Sort algorithm.

First, the merge sort function divides the linked list recursively. The recursion tree reaches a maximum depth of O(log n). At each level of the recursion tree, the merge function recombines split lists, which takes O(n) time in all lists at that level. Multiplying the recursion depth by the work done per level yields a total time complexity of O(n log n).

Second, the file handling and linked list construction in the main function operate in O(n) time. Although there is a nested loop for extracting key attributes, the inner loop iterates only over the length of a single row, which is a constant value independent of n, so the time complexity is O(n).

Finally, an efficient insertion strategy is applied using both head and tail pointers. By maintaining the tail pointer, appending new node takes O(1) per record. Without the tail pointer, traversing from head to the end of the list would take O(n) per insertion and causing O(n2) time complexity during list construction. Therefore, the tail pointer ensures the total construction time remains O(n).

In conclusion, the combined time complexity is **O(n log n) + O(n) = O(n log n)**.

## Loop Invariant
**Statement**: Before the iteration starts, the new linked list connected from dummy.next to curr is in a sorted state containing processed nodes from original lists a and b. Also, all remaining nodes in a and b have key values greater than or equal to curr->key. 

**Initialization**: When the curr points to a dummy node, and dummy.next is NULL, there’s no elements in linked list, so the statement holds true before the first iteration. 

**Maintenance**: In each iteration, the algorithm compares a->key and b->key and links the smaller or equal node to curr->next. Since a and b are already sorted, the selected node is greater than or equal to curr->key and smaller than or equal to all remaining nodes in a and b. 

**Termination**: The loop terminates when either list a or b becomes NULL. The remaining non-empty list is in sorted order, so appending this list completes sorted merged list. 
