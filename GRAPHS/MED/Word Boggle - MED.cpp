/*
Word Boggle 

Medium Accuracy: 48.98% Submissions: 15781 Points: 4
Given a dictionary of distinct words and an M x N board where every cell has one character. Find all possible words from the dictionary that can be
formed by a sequence of adjacent characters on the board. We can move to any of 8 adjacent characters, but a word should not have multiple instances 
of the same cell.


Example 1:

Input: 
N = 1
dictionary = {"CAT"}
R = 3, C = 3
board = {{C,A,P},{A,N,D},{T,I,E}}
Output:
CAT
Explanation: 
C A P
A N D
T I E
Words we got is denoted using same color.
Example 2:

Input:
N = 4
dictionary = {"GEEKS","FOR","QUIZ","GO"}
R = 3, C = 3 
board = {{G,I,Z},{U,E,K},{Q,S,E}}
Output:
GEEKS QUIZ
Explanation: 
G I Z
U E K
Q S E 
Words we got is denoted using same color.

Your task:
You don’t need to read input or print anything. Your task is to complete the function wordBoggle() which takes the dictionary contaning N 
space-separated strings and R*C board as input parameters and returns a list of words that exist on the board in lexicographical order.


Expected Time Complexity: O(N*W + R*C^2)
Expected Auxiliary Space: O(N*W + R*C)


Constraints:
1 = N = 15
1 = R, C = 50
1 = length of Word = 60
Each word can consist of both lowercase and uppercase letters.
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t; cin>>t;
	while(t--){
	    int n;cin>>n;
	    vector<string>s(n);
	    for(int i=0;i<n;i++) cin>>s[i];
	    int a,b;cin>>a>>b;
	    vector<char>c(a*b);
	    for(int i=0;i<(a*b);i++) cin>>c[i];
	    map<char,int>m1,m2;
	    for(int i=0;i<(a*b);i++)m1[c[i]]++;
	    m2=m1;
	    
// 	  for(auto x:m1)cout<<x.first<<" "<<x.second<<endl;
// 	  cout<<m1['c']<<endl;
	    int j;
	    int cnt=0;
	    set<string>str;
	    
	    for(int k=0;k<n;k++){
	      string p=s[k];
	      cnt=0;
	      for(int i=0;i<p.length();i++){
	          if(m1.find(p[i])!=m1.end() &&  m1[p[i]]>0){cnt++;m1[p[i]]--;}
	          else {break;}
	       }
	       m1=m2;
	      if(cnt==p.length()) str.insert(p);
	    }
	    if(!str.empty())
	    for(auto i=str.begin();i!=str.end();i++) cout<<*i<<" ";
	    else 
	       cout<<-1;
	    cout<<endl;
	}
	return 0;
}

/*another solution

class Solution
{
    bool dfsRec(
                    vector<vector<char>> &board, 
                    string word, 
                    vector<vector<bool>> &visited, 
                    int row, 
                    int col, 
                    int wordIndex
                )
    {
        if(wordIndex == word.size())
        {
            return true;
        }
        
        if(
                row >= 0 and row < board.size() and 
                col >= 0 and col < board[0].size() and 
                visited[row][col] == false and
                board[row][col] == word[wordIndex]
            )
        {
            visited[row][col] = true;
            
            if(
                    dfsRec(board, word, visited, row - 1, col - 1, wordIndex + 1) or
                    dfsRec(board, word, visited, row - 1, col + 0, wordIndex + 1) or
                    dfsRec(board, word, visited, row - 1, col + 1, wordIndex + 1) or
                    dfsRec(board, word, visited, row + 0, col - 1, wordIndex + 1) or
                    dfsRec(board, word, visited, row + 0, col + 1, wordIndex + 1) or
                    dfsRec(board, word, visited, row + 1, col - 1, wordIndex + 1) or
                    dfsRec(board, word, visited, row + 1, col + 0, wordIndex + 1) or
                    dfsRec(board, word, visited, row + 1, col + 1, wordIndex + 1)
                )
                {
                    return true;
                }
            
            visited[row][col] = false;
        }
        
        return false;
    }
    
    bool findWords(vector<vector<char>> &board, string word)
    {
        int m = board.size();
        int n = board[0].size();
        
        vector<vector<bool>> visited(m, vector<bool> (n, false));
        
        int wordIndex = 0;
        
        for(int row = 0; row < m; row++)
        {
            for(int col = 0; col < n; col++)
            {
                if(board[row][col] == word[wordIndex])
                {
                    if(dfsRec(board, word, visited, row, col, wordIndex) == true)
                    {
                        return true;
                    }
                }
            }
        }
        
        return false;
    }
    
    public:
    vector<string> wordBoggle(vector<vector<char>> &board, vector<string> &dictionary) 
    {
        vector<string> res;
        
        for(auto x: dictionary)
        {
            if(findWords(board, x))
            {
                res.push_back(x);
            }
        }
        
        return res;
    }
};
*/

