//Leetcode question : 863. All Nodes Distance K in Binary Tree
// Question Link : https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/

// Method 1:

class Solution {
public:

  bool dfs(TreeNode* root, TreeNode* target, vector<TreeNode*> &v){
    if(root == NULL){
      return false;
    }

    if(root == target){
      v.push_back(root);
      return true;
    }

    bool res = dfs(root->left, target, v) || dfs(root->right, target, v);
    if(res){
      v.push_back(root);
    }

    return res;
  }

  void printKDown(TreeNode* root, int k, TreeNode* blockNode, vector<int> &ans){

    if(root == blockNode || root == NULL || k < 0) return;

    if(k == 0){
      ans.push_back(root->val);
      return;
    }

    printKDown(root->left, k-1, blockNode, ans);
    printKDown(root->right, k-1, blockNode, ans);

  }

  vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    vector<TreeNode*> nodeToRootPath;
    dfs(root, target, nodeToRootPath);

    vector<int> ans;
    printKDown(nodeToRootPath[0], k, NULL, ans);

    for(int i=1;i<nodeToRootPath.size();i++){
      printKDown(nodeToRootPath[i], k-i, nodeToRootPath[i-1], ans);
    }

    return ans;
  }
};

// Method 2: Space Optimised, in terms of nodeToRootPath array.


class Solution {
public:

  void kDown(TreeNode* root,int k,TreeNode* blockNode, vector<int> &ans){
    if(root == NULL || k < 0 || root == blockNode){
      return;
    }

    if(k == 0){
      ans.push_back(root->val);
      return;
    }

    kDown(root->left, k-1, blockNode, ans);
    kDown(root->right, k-1, blockNode, ans);
    return;
  }

  int distanceK(TreeNode* root, TreeNode* target, int k, vector<int> &ans){
    if(root == NULL){
      return -1;
    }

    if(root == target){
      kDown(root, k, NULL, ans);
      return 1;
    }

    int leftDistance = distanceK(root->left, target, k, ans);
    if(leftDistance != -1){
      kDown(root, k - leftDistance, root->left, ans);
      return leftDistance + 1;
    }

    int rightDistance = distanceK(root->right, target, k, ans);
    if(rightDistance != -1){
      kDown(root, k - rightDistance, root->right, ans);
      return rightDistance + 1;
    }

    return -1;
  }

  vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    vector<int> ans;
    distanceK(root, target, k, ans);
    return ans;
  }
};
