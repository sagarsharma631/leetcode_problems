/*
1485. Clone Binary Tree With Random Pointer
*/

#include<iostream>
#include<unordered_map>

using namespace std;

struct Node {
    int val;
    Node *left;
    Node *right;
    Node *random;
    Node() : val(0), left(nullptr), right(nullptr), random(nullptr) {}
    Node(int x) : val(x), left(nullptr), right(nullptr), random(nullptr) {}
    Node(int x, Node *left, Node *right, Node *random) : val(x), left(left), right(right), random(random) {}
};

struct NodeCopy {
    int val;
    NodeCopy *left;
    NodeCopy *right;
    NodeCopy *random;
    NodeCopy() : val(0), left(nullptr), right(nullptr), random(nullptr) {}
    NodeCopy(int x) : val(x), left(nullptr), right(nullptr), random(nullptr) {}
    NodeCopy(int x, NodeCopy *left, NodeCopy *right, NodeCopy *random) : val(x), left(left), right(right), random(random) {}
};

NodeCopy*
copyRandomBinaryTree(Node* root,
                     unordered_map<Node*, NodeCopy*>& old_to_new_map) {
    if (!root) {
        return NULL;
    }

    NodeCopy* new_root = new NodeCopy(root->val);
    old_to_new_map[root] = new_root;
    new_root->left = copyRandomBinaryTree(root->left, old_to_new_map);
    new_root->right = copyRandomBinaryTree(root->right, old_to_new_map);
    return new_root;
}

void set_random_pointers(Node* root,
                         unordered_map<Node*, NodeCopy*>& old_to_new_map) {
    if (!root) {
        return;
    }
    old_to_new_map[root]->random = old_to_new_map[root->random];
    set_random_pointers(root->left, old_to_new_map);
    set_random_pointers(root->right, old_to_new_map);
    return;
}

NodeCopy* copyRandomBinaryTreeSinglePass(
    Node* root, unordered_map<Node*, NodeCopy*>& old_to_new_map) {

    if (!root) {
        return NULL;
    }

    if(old_to_new_map.find(root) != old_to_new_map.end()){
        return old_to_new_map[root];
    }

    NodeCopy* new_node = new NodeCopy(root->val);
    old_to_new_map[root] = new_node;
    new_node->left = copyRandomBinaryTreeSinglePass(root->left, old_to_new_map);
    new_node->right = copyRandomBinaryTreeSinglePass(root->right, old_to_new_map);
    new_node->random = copyRandomBinaryTreeSinglePass(root->random, old_to_new_map);
    return new_node;
}

NodeCopy* copyRandomBinaryTree(Node* root) {
    unordered_map<Node*, NodeCopy*> old_to_new_map;
    
    /* 2 pass clone starts */
    /*NodeCopy* cloned_tree = copyRandomBinaryTree(root, old_to_new_map);
    set_random_pointers(root, old_to_new_map);*/
    /* 2 pass clone ends */
    
    NodeCopy* cloned_tree = copyRandomBinaryTreeSinglePass(root, old_to_new_map);
    return cloned_tree;
}

int main(int argc, char *argv[]){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right = new Node(3);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    copyRandomBinaryTree(root);
}
