#include<bits/stdc++.h>
using namespace std;

void rotateMatrix(vector<vector<int>> &mat, int n){
    
}

template <typename T>
void display2DMatrix(vector<vector<T>> &mat, int n){
    for(int i(0); i < n; i++){
        for(int j(0); j < n; j++){
            if(j>0) cout<<" ";
            cout<<mat.at(i).at(j);
        }
        cout<<endl;
    }
}

int main(){
    vector<vector<int>> mat = {{1,2,3},{4,5,6},{7,8,9}};
    int n(3);
    rotateMatrix(mat, n);
    display2DMatrix(mat, n);
    
    
    
    
    
    
    

    return 0;
}