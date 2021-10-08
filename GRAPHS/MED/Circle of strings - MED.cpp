/*
Circle of strings 

Medium Accuracy: 36.85% Submissions: 8417 Points: 4
Given an array of lowercase strings A[] of size N, determine if the strings can be chained together to form a circle.
A string X can be chained together with another string Y if the last character of X is same as first
character of Y. If every string of the array can be chained, it will form a circle.

For example, for the array arr[] = {"for", "geek", "rig", "kaf"} the answer will be Yes as the given strings can be chained as "for", "rig", "geek" 
and "kaf"


Example 1:

Input:
N = 3
A[] = { "abc", "bcd", "cdf" }
Output:
0
Explaination:
These strings can't form a circle 
because no string has 'd'at the starting index.
Example 2:

Input:
N = 4
A[] = { "ab" , "bc", "cd", "da" }
Output:
1
Explaination:
These strings can form a circle 
of strings.

Your Task:
You don't need to read input or print output. Your task is to complete the function isCircle() which takes the length of the array N and the array A 
as input parameters and returns 1 if we can form a circle or 0 if we cannot.


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)


Constraints: 
1 = N = 104
1 = Length of strings = 20
*/

// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
class Solution
{
    public:
    int isCircle(int n, vector<string> A)
    {
        unordered_map<char,int> mp;
        
        for(int i=0;i<n;i++){
            string s=A[i];
            int size=s.size()-1;
            mp[s[0]]++;
            mp[s[size]]++;
        }
        
        int even=0;
        int odd=0;
        
        for(auto it:mp){
            if(it.second%2==0){
                even++;
            }else{
                odd++;
            }
        }
        
        if(n%2==0){
            if(odd==0) return 1;
            else return 0;
        }
        
        if(n%2){
            if(odd==1) return 1;
            else return 0;
        }
        
    }
};
// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<string> A;
        string s;
        
        for(int i = 0;i < N; i++)
        {
            cin>>s;
            A.push_back(s);
        }
        
        Solution ob;
        cout<<ob.isCircle(N, A)<<endl;
    }
    return 0;
}  // } Driver Code Ends
 
 
