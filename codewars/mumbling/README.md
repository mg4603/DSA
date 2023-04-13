## Mumbling

The examples below show you how to write function accum:

## Examples:

    accum("abcd") -> "A-Bb-Ccc-Dddd"
    accum("RqaEzty") -> "R-Qq-Aaa-Eeee-Zzzzz-Tttttt-Yyyyyyy"
    accum("cwAt") -> "C-Ww-Aaa-Tttt"

The parameter of accum is a string which includes only letters from a..z and A..Z.


## Sol:

- take input string
- iterate through input string and repeat letter by position number of
  times, separating letter sequences by '-' and making the first letter
  of each sequence upper case.
