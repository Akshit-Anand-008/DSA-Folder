The input is the same.
For each slot in the vector.
It is just that if we k bits to generate random numbers, then we have 2^k cases and therefore for the same input the time measured is a vector.
Skip lists:
BST implemented with linked-lists.
As each upper element contains the median, each insertion or deletion may require rearrangement for the whole upper portion.

# Bloom filter:
How much data is required to store n items in a universe of N items.
No of combinations = C(N,n). To know which combination I am storing I have C(N,n) values.
And log_2(C(N,n)) bits for that, which is equal to n*log(N/n).

If we allow an error of e, we can store in n*log(1/e) bits which is independent of N.
Now even if we have used very little space, querying is very inefficient as we have to search through the dictionary, to look for the entire representation.

Bloom filter solution:
Some weird thing that;
can (with probability e) say that an item is there when it is not.(false positives)
When says an item is not there, it is definitely not there.(false negatives)

* Initialization:
Initialize an m-bit array with all bits set to 0
choose k hash functions h_i : Z -> {0,.., m-1} where Z is the universe of elements
* Insertion(of x):
Set `A[h_i(x)]` == 1 for all i
* Checking (for x):
All the bits `A[h_i(x)]` should be 1 to return 1(x is present).
If any one bit is 0, then it is not present.
