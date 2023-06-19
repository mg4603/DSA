## Financing a purchase

The fixed monthly payments for a fixed rate mortgage is the amount paid by the  
borrower every month that ensures that the load is paid off in full with  
interest at the end of its term.  

The monthly payment formula is based on the annuity formula. The monthly payment  
c depends on :
* rate - the monthly interest rate is expressed as a decimal, not a percentage.  
The monthly rate is simply the given yearly percentage rate divided by 100 and  
then by 12.
* term - the number of monthly payments, called the loan's term. 
* principal - the amount borrowed.  

### Formulas:
$$c = \frac{n}{d}$$
where,
* $n = r \times balance$
* $d = 1 - (1 + r)^{-term}$
$$c = princ + int$$
$$new balance = old balance - princ$$
$$int = \frac{bal \times (n-1) \times rate} {100 \times12}$$

 ### Task:
 Given parameters
 * rate: annual rate as percent
 * bal: original balance
 * term: number of monthly payments
 * num_payment: rank of considered month (from 1 to term)

Create a function amort that returns a string:

    "num_payment %d c %.0f princ %.0f int %.0f balance %.0f"

### Examples:
    amort(6, 100000, 360, 1) ->
    "num_payment 1 c 600 princ 100 int 500 balance 99900"
    
    amort(6, 100000, 360, 12) ->
    "num_payment 12 c 600 princ 105 int 494 balance 98772"