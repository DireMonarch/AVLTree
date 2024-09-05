# AVL Balanced Binary Search Tree
 
An AVL tree (named after inventors Adelson-Velsky and Landis) is a self-balancing binary search tree.

In an AVL tree, the heights of the two child subtrees of any node differ by at
most one; if at any time they differ by more than one, rebalancing is done to
restore this property.

Lookup, insertion, and deletion all take O(log n) time in both the
average and worst cases, where n is the number of nodes in the tree prior to
the operation. Insertions and deletions may require the tree to be rebalanced
by one or more tree rotations.

### TKey
Generic type representing the key used for sorting. Must implement <, =, and >.

### TValue
Generic type representing the data being stored.
