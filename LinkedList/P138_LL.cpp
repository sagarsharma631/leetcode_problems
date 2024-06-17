/*

Problem - 138 Copy linked list with random pointer.

*/
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* node,
                             unordered_map<Node*, Node*>& hash_map) {
        if (!node) {
            return NULL;
        }

        Node* new_node = new Node(node->val);
        hash_map[node] = new_node;

        Node* next_new_node = copyRandomList(node->next, hash_map);

        // Set the next pointer for the new node now.
        new_node->next = next_new_node;

        // Set the random pointer for the new node now.
        new_node->random = hash_map[node->random];

        return new_node;
    }

    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> hash_map;
        return copyRandomList(head, hash_map);
    }
};
