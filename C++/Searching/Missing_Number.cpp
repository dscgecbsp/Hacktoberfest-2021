//Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.

//Using Binay Search

class Solution {
public:
    int missingNumber(vector<int>& nums)
      { 
        int n =nums.size();
        int count=0;
        for(int i=0;i<n;i++){
          count+=nums[i]; 
        }
        int res = 0;
        res=(n*(n+1))/2-count;
        return res;
      
        
    }
};
