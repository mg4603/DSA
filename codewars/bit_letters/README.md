## Bit Letters

    0           0       0       0  0  0  0  0
    [punctuation]   [capital]   [letter index]

### Punctuation
* 0 = null
* 1 = space
* 2 = comma
* 3 = dot

### Capital
* 0 = lowercase
* 1 = uppercase

### Letter index
0-26

### Example:
    'a'  = 0B00000000 = 0   (a)
    'A'  = 0B00100000 = ‭32‬  (A)
    " a" = 0B01000000 = 64  (space + a)
    "A," = 0B10100000 = ‭160‬ (a + comma)
    "a." = 0B11000000 = ‭192‬ (a + dot)


    { 39,4,11,11,142,86,14,17,11,195 } ==> "Hello, world."