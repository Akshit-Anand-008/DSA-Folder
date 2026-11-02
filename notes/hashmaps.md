Advantageous when the no of keys actually stored is actually small then the total no. of keys present.

# Hashing:
Method of generating a small sized output from a large index that can be used for indexing.
for storage in a data structure known as **hash table**.

2 types:
1. Hash set: unordered_set in cpp
2. Hash map: unordered_map in cpp

* Components of Hashing:
1. key: string or anything fed to determine the location where we need to store it
2. Hash function: Receives the input and then outputs the index in the data structure

Properties of a good hash function:
1. Deterministic: Same output for the same input
2. Fixed output size: Output should have same size regardless of the size of the input
3. Uniformity: Should distribute the hash values uniformly to avoid collision
4. Pre-image resistance: It should be computationally unfeasible to get the input given the hash function

 <!-- Listen to imagine dragon songs boy. -->

# Two stage hash fucntions
H(key) = gm(h(key))

## Collision reduction methods:
1. **Separate chaining**
If multiple items are hashed to the same index then these elements are inserted into a singly-linked list also known as a chain.

2. **Open addressing**
All the elements are stored in the hash table itself and therefore the size of the hash table at any point should be >= the no of indices.

```
index = hash(key) % capacity

if table[index] is occupied:
    try another index (probing)
```

## Probing
1. Linear Probing:
Suppose that we want to insert a key `k` into a hash table of size `n`.
Let the hash function be `index = k%n`
If index is already occupied, it will search for the next empty slot linearly;
i.e. Linear probing moves sequentially to:
```
(index + 1) % n
(index + 2) % n
(index + 3) % n
```
i.e 
`i, i+1, i+2 ..`

2. Quadritic Probing:
`i, i + 1^2, i + 2^2 , i + 3^2 ..`








# Vocabulary
Probe: to explore
