## Remove-Erase idiom

    std::vector<T> &vec = myVec;
    vec.erase(std::remove(vec.begin(), vec.end(), val_to_remove), vec.end());

- The remove compacts the elements that differ from the value to be removed
    ```val_to_remove``` in the beginning of the vector and returns 
    the iterator to the first element after that range.
- The erase removes these values.

![https://stackoverflow.com/questions/347441/erasing-elements-from-a-vector](Answer on stackoverflow)