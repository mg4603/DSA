#include<bits/stdc++.h>
using namespace std;

void nullifyRow(vector<vector<int>> &matrix, int i){
    for(int j(0); j < matrix[0].size(); j++){
        matrix[i][j] = 0;
    }
}

void nullifyCol(vector<vector<int>> &matrix, int i){
    for(int j(0); j < matrix.size(); j++){
        matrix[j][i] = 0;
    }
}

void zeroMatrix(vector<vector<int>> &matrix){
    bool rowHasZero(false), colHasZero(false);
    //first column
    for(int i(0); i < matrix.size(); i++){
        if(matrix[i][0] == 0)
            colHasZero=true;
    }
    //for row
    for(int i(0); i < matrix[0].size(); i++){
        if(matrix[0][i] == 0)
            rowHasZero=true;
    }
    

    for(int i(0); i < matrix.size(); i++){
        for(int j(0); j < matrix[0].size(); j++){
            if(matrix[i][j] == 0){
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }            
        }
    }


    for(int i(0); i < matrix.size(); i++){
        if(matrix[i][0] == 0){
            nullifyRow(matrix, i);
        }
    }
    for(int i(0); i < matrix[0].size(); i++){
        if(matrix[0][i] == 0){
            nullifyCol(matrix, i);
        }
    }
    if(rowHasZero)
        nullifyRow(matrix, 0);
    if(colHasZero)
        nullifyCol(matrix, 0);
}

template<typename T>
void display2DMatrix(vector<vector<T>> &matrix){
    for(int i(0); i < matrix.size(); i++){
        if(matrix[0].size())
        for(int j(0); j < matrix[0].size(); j++){
            if(j>0)cout<<" ";
            cout<<matrix.at(i).at(j);
        }
        cout<<endl;
    }
}
int main(){
    vector<vector<int>> matrix = {
        {1,2,3},{4,0,6},{7,8,9}};
    zeroMatrix(matrix);
    display2DMatrix(matrix);
    return 0;
}