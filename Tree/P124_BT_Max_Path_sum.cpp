/*
124. Binary Tree Maximum Path Sum
*/

#include<iostream>
#include<algorithm>
#include<climits>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
    right(right) {}
};

int maxPathSumUtil(TreeNode* root, int& result) {
    if (!root)
        return 0;

    int left_path_sum = maxPathSumUtil(root->left, result);

    int right_path_sum = maxPathSumUtil(root->right, result);

    result =
        max({result, left_path_sum + root->val + right_path_sum,
             max(left_path_sum, right_path_sum) + root->val, root->val});

    return max(max(left_path_sum, right_path_sum) + root->val, root->val);
}

int maxPathSum(TreeNode* root) {
    int result = INT_MIN;
    maxPathSumUtil(root, result);
    return result;
}

int main(int argc, char *argv[]){
    TreeNode* root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    cout<<maxPathSum(root)<<endl;
    return 0;
}
