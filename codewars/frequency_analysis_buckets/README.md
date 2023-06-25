## Frequency Analysis With Buckets

Given an input array (arr) of positive integers, the objective is to return an  
output array where each index represents the amount of times an element appeared  
in the input array. 

More specifically, the element at each index of the output array will be an  
array(bucket) containing integers that appeared index-amount of times. 

A valid array will always be provided.  

### Example:
    bucketize([1, 2, 3, 4, 4, 5, 5, 5])  ==> [null, [1,2,3],[4],[5], null,  
                                                null, null, null, null].


    bucketize({2,2,4,4,6,6,9,9,9,9}) ===> {NULL, NULL, {2,4,6}, NULL, {9}, 
                                            NULL, NULL, NULL, NULL, NULL, NULL};

    bucketize({3,3,3,3,2}) =============> {NULL, {2}, NULL, NULL, {3}, NULL};

    bucketize({5,5,5,5,5}) =============> {NULL, NULL, NULL, NULL, NULL, {5}};

    bucketize({77,3,40,40,40}) =========> {NULL, {3,77}, NULL, {40}, NULL, NULL};

    bucketize({16,7,5,3,6,23}) =========> {NULL, {3,5,6,7,16,23}, NULL, NULL, 
                                                            NULL, NULL, NULL};
    