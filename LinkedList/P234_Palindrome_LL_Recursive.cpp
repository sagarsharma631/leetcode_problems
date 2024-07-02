#include<iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

bool isPalindrome(ListNode* curr, ListNode** head, bool& can_continue) {
    if (curr->next == NULL) {
        if (curr->val == (*head)->val) {
            *head = (*head)->next;
            return true;
        } else {
            return false;
        }
    }
    bool result = isPalindrome(curr->next, head, can_continue);
    if (result && can_continue) {
        if (*head == curr || (*head)->next == curr) {
            can_continue = false;
        }
        if(curr->val == (*head)->val){
            if(can_continue){
                *head = (*head)->next;
            }
        }
        else{
            result = false;
        }
    }
    return result;
}

bool isPalindrome(ListNode* head) {
    bool result = true;
    result = isPalindrome(head, &head, result);
    return result;
}

int main(int argc, char *argv[]){
    struct ListNode* root = new struct ListNode(1);
    root->next = new struct ListNode(1);
    /*root->next->next = new struct ListNode(1);
    root->next->next->next = new struct ListNode(3);
    root->next->next->next->next = new struct ListNode(2);
    root->next->next->next->next->next = new struct ListNode(1);*/
    isPalindrome(root);
    return 0;
}
