#include <bits/stdc++.h>
using namespace std;

//Print vector
void print(vector<vector<char> > v){
    for(auto i : v){
        for(auto j : i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}

bool isSafe(vector<vector<char> > v,int row,int col){

    // check rows with passed col
    for(int i=0;i<row;i++){
        if(v[i][col] == 'Q'){
            return false;
        }
    }

    //Upper Left

    for(int i = row,j=col ; i>=0 && j>=0 ; i--,j--){
        if(v[i][j] == 'Q'){
            return false;
        }
    }

    //Upper right

    for(int i = row,j = col ; i>=0 && j<v.size() ; i--,j++){
        if(v[i][j] == 'Q'){
            return false;
        }
    }
    return true;
}

bool queen(vector<vector<char> > &v,int i){
    if(i == v.size()){
        print(v);
        return true;
    }


    for(int j = 0;j<v.size();j++){
        if(isSafe(v,i,j)){
            v[i][j] = 'Q';


            if(queen(v,i+1)){
                return true;
            }

            v[i][j] = '0';
        }
    }
    return false;
}


int main(){
   
    int n = 4;
    vector<vector<char> > v(n,vector<char>(n,'0'));
    queen(v,0);

    return 0;
}