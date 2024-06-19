/*
Problem 314: Binary Tree Vertical Order traversal
*/

#include<iostream>
#include<queue>
#include<vector>
#include<climits>
#include<map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<vector<int>> verticalOrder(TreeNode* root) {
    vector<vector<int>> result;
    map<int, vector<int>> hindices_map;
    queue<pair<TreeNode*, int>> bfs_queue;
    if (root) {
        bfs_queue.push({root, 0});
        bfs_queue.push({NULL, INT_MAX});
        while (!bfs_queue.empty()) {
            pair<TreeNode*, int> curr_elem = bfs_queue.front();
            if (curr_elem.first != NULL && curr_elem.second != INT_MAX) {
                hindices_map[curr_elem.second].push_back(
                    (curr_elem.first)->val);
                if (curr_elem.first->left) {
                    bfs_queue.push(
                        {curr_elem.first->left, curr_elem.second - 1});
                }

                if (curr_elem.first->right) {
                    bfs_queue.push(
                        {curr_elem.first->right, curr_elem.second + 1});
                }
                bfs_queue.pop();
            } else {
                bfs_queue.pop();
                if (!bfs_queue.empty()) {
                    bfs_queue.push({NULL, INT_MAX});
                }
            }
        }

        for (auto iter : hindices_map) {
            result.push_back(iter.second);
        }
    }
    return result;
}

int main(int argc, char *argv[]){
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    verticalOrder(root);
    return 0;
}
