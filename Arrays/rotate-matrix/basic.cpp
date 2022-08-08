#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> rotateMatrix(vector<vector<int>> mat, int n){
    vector<vector<int>> res;
    for(int i(0); i < n; i++){
        vector<int> temp;
        for(int j(2); j >= 0; j--){
            temp.push_back(mat.at(j).at(i));
        }
        res.push_back(temp);
    }
    return res;
}
// 1 2 3
// 4 5 6
// 7 8 9

// (0,0) -> (0,2)
// (0,1) -> (1,2)
// (0,2) -> (2,2)

// (1,0) -> (0,1)
// (1,1) -> (1,1)
// (1,2) -> (2,1)

// (2,0) -> (0,0)
// (2,1) -> (1,0)
// (2,2) -> (2,0)

// 7 4 1 
// 8 5 2
// 9 6 3
int main(){
    vector<vector<int>> mat = {{1,2,3},{4,5,6},{7,8,9}};
    int n(3);
    mat = rotateMatrix(mat,n);
    for(int i(0); i < n; i++){
        for(int j(0); j < n; j++){
            if(j > 0) cout<<" ";
            cout<<mat.at(i).at(j);
        }
        cout<<endl;
    }
    return 0;
}