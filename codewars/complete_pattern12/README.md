## Complete The Pattern #12

### Task:
You have to write a function pattern which returns the following Pattern  
(upto 2n-1) rows.

### Parameters:
* $n \in (-\infty, 100]$ : term upto which this pattern should be created.

### Notes:
* If n < 1, return an empty string
* The length of each line is the same(2n-1).


### Examples: 
* pattern(5):

          1       1
           2     2 
            3   3  
             4 4   
              5    
             4 4   
            3   3  
           2     2 
          1       1
 
  
* pattern(10):

      1                 1
       2               2 
        3             3  
         4           4   
          5         5    
           6       6     
            7     7      
             8   8       
              9 9        
               0         
              9 9        
             8   8       
            7     7      
           6       6     
          5         5    
         4           4   
        3             3  
       2               2 
      1                 1

* pattern(15):

      1                           1
       2                         2 
        3                       3  
         4                     4   
          5                   5    
           6                 6     
            7               7      
             8             8       
              9           9        
               0         0         
                1       1          
                 2     2           
                  3   3            
                   4 4             
                    5              
                   4 4             
                  3   3            
                 2     2           
                1       1          
               0         0         
              9           9        
             8             8       
            7               7      
           6                 6     
          5                   5    
         4                     4   
        3                       3  
       2                         2 
      1                           1