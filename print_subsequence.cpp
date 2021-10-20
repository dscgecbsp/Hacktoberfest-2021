#include<iostream>
 
using namespace std;

void printSubs(string input,string output=""){
    if(input.empty()){
        cout<<output<<endl;
        return ;
    }
    printSubs(input.substr(1),output);
     printSubs(input.substr(1),output+input[0]);
}

int main(){
    string input;
    cin>>input;
    printSubs(input);
    return 0;
}