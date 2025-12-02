class Solution {
public:
    TreeNode* helper(vector<int>&pre,vector<int>&in,unordered_map<int,int>&mp,int preS,int preE,int inS,int inE){
        if(preS>preE) return nullptr;
       int r=pre[preS];
       TreeNode*root=new TreeNode(r);
       int i=mp[r];
       int x=i-inS;
       
       root->left=helper(pre,in,mp,preS+1,preS+x,inS,i-1);
       
       root->right=helper(pre,in,mp,preS+x+1,preE,i+1,inE);
       return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(!preorder.size()) return nullptr;
        unordered_map<int,int>mp;
        int n=preorder.size()-1;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        return helper(preorder,inorder,mp,0,n,0,n);
    }
};
