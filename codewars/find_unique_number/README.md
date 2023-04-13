## Find the unique number
There is an array with some numbers. All numbers are equal except for one.
<br>
Try to find it!

    find_uniq(std::vector<float>{1, 1, 1, 2, 1, 1});  // --> 2
    find_uniq(std::vector<float>{0, 0, 0.55, 0, 0});  // --> 0.55

It’s guaranteed that array contains at least 3 numbers.

The tests contain some very huge arrays, so think about performance.