# TRIES
## Intro
- n-ary tree
- characters are stored at each node
- \* nodes are used to denote complete words
- \* nodes may be implemented as:
    - TerminatingTrieNode that inherit from TrieNode
    - Boolean flag
- Each node can have 1 to ALPHABET_SIZE+1 children (or 0 to ALPHABET_SIZE children
if it uses a boolean flag)

### Use Case:
- store entire english language for quick prefix lookup
- problems that involve lists of valid words use tries as optimizations

