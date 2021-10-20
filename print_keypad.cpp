#include<iostream>
 
using namespace std;

string charsForKeypad(int n){
    string s;
    switch(n){
        case 2 : s="abc";
                break;
        case 3 : s="def";
                break;
        case 4 : s="ghi";
                break;
        case 5 : s="jkl";
                break;
        case 6 : s="mno";
                break;
        case 7 : s="pqrs";
                break;
        case 8 : s="tuv";
                break;
        case 9 : s="wxyz";
                break;
    }
    return s;
}

void printKeypad(int n,string output=" "){
    if(n==0){
        cout<<output<<endl;
        return;
    }
    string str=charsForKeypad(n%10);
    for(int i=0;i<str.size();++i){
        printKeypad(n/10, str[i]+output);
    }
}


int main(){
    int n;
    cin>>n;
    printKeypad(n);
    return 0;
}