# Job Sequencing with Deadlines

Maximize the total profits earned from completing jobs, given that each job  
must be completed before it's deadline.

* Each job can only be completed once.
* If a job is completed after it's deadline it doesn't contribute to the profit

## Types:
1. **Deadline-constraint Job Sequencing Problem:** Each job has a deadline   
before which it must be completed. The goal is to find the subset of jobs that  
maximize profits while adhering to the deadlines.
2. **Profit-Constraint Job Sequencing Problem:** Choose the subset of jobs that  
maximizes profits, given that the maximum number of jobs that can be chosen is  
constrained.

## Solution
* sort the jobs in decreasing order of profits
* place the jobs in slots that are non-empty starting from deadline
* prioritizes jobs with higher profits and fits them into the earliest available
slot