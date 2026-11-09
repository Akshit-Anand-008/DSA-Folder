# Properties:
- Every node is either black or red.
- The root is black.
- Red nodes can't have red children.
- Every path from the node to the descendant leaves should have the same no. of black nodes.
- All leaves(Nil nodes) are black.

* Black-height : the no of black nodes in the path from the root to the node.

# Ideal Scenario:
Every path should be in +- of every other path.
Very difficult to maintain
# Slack allowed
every path should be in a factor of every other path.
