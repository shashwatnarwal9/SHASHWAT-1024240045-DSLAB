#include <bits/stdc++.h>
class Solution {
public:
    int helper(TreeNode* root,bool flag){
        if(!root) return 0;
        if(!root->left && !root->right){
            if(flag) return root->val;
            else return 0;
        }
        int n1=helper(root->left,true);
        int n2=helper(root->right,false);
        return n1+n2;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        return helper(root,false);
    }
};
