/*
Problem 2130: Maximum Twin Sum of a Linked List
Suppose there is a linked list: 1 -> 1 -> 1 -> 3 -> 2 -> 1 -> NULL
The result should be 4 (Sum of 2 elements 3rd from start and 3rd from end)
*/
#include<iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

int pairSum(ListNode* tail, ListNode** head){
    int result = 0;
    if(tail->next == NULL){
        result = tail->val + (*head)->val;
    }
    else{
        result = max(pairSum(tail->next, head), tail->val + (*head)->val);
    }
    *head = (*head)->next;
    return result;
}

int pairSum(ListNode* head) {
    int result = pairSum(head, &head);
    cout<<result;
    return result;
}

int main(int argc, char *argv[]){
    struct ListNode* root = new struct ListNode(1);
    root->next = new struct ListNode(1);
    root->next->next = new struct ListNode(1);
    root->next->next->next = new struct ListNode(3);
    root->next->next->next->next = new struct ListNode(2);
    root->next->next->next->next->next = new struct ListNode(1);
    pairSum(root);
    return 0;
}
