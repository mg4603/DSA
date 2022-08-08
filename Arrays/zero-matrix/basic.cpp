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
    vector<bool> rows = vector<bool>(matrix.size(), false);
    vector<bool> cols = vector<bool>(matrix[0].size(), false);

    for(int i(0); i < matrix.size(); i++){
        for(int j(0); j < matrix[0].size(); j++){
            if(matrix[i][j] == 0){
                rows.at(i) =  true;
                cols.at(j) = true;
            }
        }
    }
    for(int i(0); i < matrix.size(); i++){
        if(rows[i]) nullifyRow(matrix, i);
    }
    for(int j(0); j < matrix[0].size(); j++){
        if(cols[j]) nullifyCol(matrix, j);
    }
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