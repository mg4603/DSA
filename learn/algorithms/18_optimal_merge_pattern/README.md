# Optimal Merge Pattern

The optimal order of merges to merge multiple sorted sequences into a single  
sorted sequence, with a minimum number of comparisons or operations.

## Algorithm:
**Idea:** Merge the smallest sequences sequentially, resulting in a minimum  
number of comparisons.  

    Algorithm(sequence_length):
        1. create a priority-queue of sequence lengths
        2. While the priority queue contains more than 1 element:
            2.1 remove the two smallest sequence lengths from the priority-queue
            2.2 sum up the two smallest length, representing the merge of the two
                smallest sequences
            2.3 push the sum back, onto the priority queue

