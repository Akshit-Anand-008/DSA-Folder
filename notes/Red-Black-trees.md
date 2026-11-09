# Ideal Scenario:
Every path should be in +-1 of every other path.
Very difficult to maintain
# Slack allowed
every path should be in a factor of 2 every other path.
enough to guarantee h = log(n)

If some leaf has depth h, every other node will have depth >= h/2
therefore there will be a complete binary tree of depth h/2 with 2^{h/2}-1 nodes

# Properties:
- Every node is either black or red.
- The root is black.
- Red nodes can't have red children.
- Every path from the node to the descendant leaves should have the same no. of black nodes.
- All leaves(Nil nodes) are black.

* Black-height : The no of black nodes in the path from the node to a leaf.

If the invariants hold:
1. Depth of any leaf >= black-height of root
2. Depth of any leaf <= 2*(black-height of root)

# 234-tree
# Insertion in a 234-tree:
In a 2-3-4 tree insertion always take place at the bottom.
Even if we have space in the internal nodes, we don't use that.

If the current node(temp) is a 4 node, then that node is split in following steps
1. Erase the mid value(X) of the node
2. Now split the 3_node one into two 2_nodes
3. If temp was the root of the tree, then create another root(a 2_node) with the value X with newly split nodes as it's children.
4. Otherwise, add the value of X in the parent node
5. Arrange the two 2_nodes accordingly with the parent node.

# Deletion
Deletion is also always done on the leaf.
If the node is already a leaf: done.
Else: Find the successor and swap the 2, and then delete.
* Underflowed nodes borrow nodes from siblings to maintain balance.
* n-ary node has n children(not n keys)

# Translation:
A 2-ary node(single key) corresponds to a black node in a red-black tree

## Insertion:
When you insert another node, it is equivalent of adding a red-node to a black node.

## Splitting:
Splitting a 4-ary node in 234 tree pushes one of the key as the parent
A 4ary node is represented by a black node with 2 red children.
Splitting translates to recoloring instead of any physical transformation.

## Deletion:
If after a deletion, a node get's empty and can't lend from siblings as they themselves are 2-ary.
It resorts to merging.
It pulls the separating key from the parent down to merge and to form a 3ary node(not 4-ary as one of the node is empty).
And if the parent becomes empty(it had only one key), the merged child is promoted to the status of the parent.

# Rotation:
It promotes one of the children to parent and demotes the parent to a child(changing parent-child relationship)
Without changing the in-order sequence.
