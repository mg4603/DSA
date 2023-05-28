## Ease the StockBroker

Clients place orders to a stockboker as strings. The order can be simple or multiple or empty.  

### Format of a simple order: 
    Quote/white-space/Quantity/white-space/Pice/white-space/Status  

where,
* Quote is formed of non-whitespace character
* Quantity is an int
* Price a double (with mandatory decimal point ".")
* Status is represented by the letter B(buy) or the letter S(sell).  

### Example:
    "GOOG 300 542.0 B"

A multiple order is the concatenation of simple order with a comma between each.  

### Example:
    "ZNGA 1300 2.66 B, CLH15.NYM 50 56.32 B, OWW 1000 11.623 B, OGG 20 580.1 B"

**or**

    "ZNGA 1300 2.66 B,CLH15.NYM 50 56.32 B,OWW 1000 11.623 B,OGG 20 580.1 B"

### Task:
* produce a string of type

        "Buy: b Sell: s"
    where,
    * b: total price of bought stocks
    * s: total price of sold stocks
    
* For badly formed orders:

        "Buy: b Sell: s; Badly formed nb: badly-formed 1st simple order ;...badly-formed nth simple oder"
    
    where,
    * nb: number of badly formed simple orders
    * b: total price of bought stocks
    * s: total price of sold stocks

### Examples:

    "Buy: 263 Sell: 11802; Badly formed 2: CLH16.NYM 50 56 S ;OWW 1000 11 S ;"

    "Buy: 100 Sell: 56041; Badly formed 1: ZNGA 1300 2.66 ;"