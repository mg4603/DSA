#include <iostream>
#include <assert.h>

#include <vector>

class SubrectangleQueries {
    std::vector<std::vector<int>> rectangle;
public:
    SubrectangleQueries(std::vector<std::vector<int>>& rectangle) {
        this->rectangle = rectangle;
    }
    
    void updateSubrectangle(int row1, int col1, int row2, 
                            int col2, int newValue) {
        for(int i = row1; i <= row2; i++) {
            for(int j = col1; j <= col2; j++) {
                rectangle[i][j] = newValue;
            }
        }
    }
    
    int getValue(int row, int col) {
        return rectangle[row][col];
    }
};

int main()
{
    return 0;
}