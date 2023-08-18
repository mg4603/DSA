# Huffman Coding

* A variable length encoding scheme, based on symbol frequency, used to compress  
data.
* More frequent symbols are assigned shorter codes, while less frequent symbols  
are assigned longer codes.

## Overview
    1. Count the frequency of each symbol to be encoded
    2. Create a priority-queue of nodes, each containing a symbol and it's  
        frequency.
    3. Sequentially remove the two nodes with the lowest frequency  
        3.1 Create a new node with these two nodes as children, with frequency  
            equal to the sum of frequencies of it's children
        3.2 Insert the new node back into the priority queue
        3.3 Repeat step 3 until the priority queue has only one node
    4. Traverse the huffman tree from the root to each leaf node. Assign a binary  
        code to each leaf node based on the path taken to reach it, with left  
        corresponding to 0 and right corresponding to 1.

### Encoding:
Replace each symbol in the input data with its corresponding huffman code.

### Decoding:
1. Start from the root and traverse the huffman tree based on the encoded bits.
2. When you reach a leaf, output the corresponding symbol
3. Repeat steps 1 and 2 until there are no more encoded bits.