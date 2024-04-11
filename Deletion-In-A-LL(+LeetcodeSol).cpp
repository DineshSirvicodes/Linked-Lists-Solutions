// Deletion of the tail of the LL
/**
 * Definition for singly-linked list.
 * class Node {
 * public:
 *     int data;
 *     Node *next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node *next) : data(x), next(next) {}
 * };
 */

Node *deleteLast(Node *list){
    Node* head = new Node(list[0]);
    if(head == NULL || head->next == NULL){
        return NULL;
    }
    Node*temp = head;
    while(temp->next->next !=NULL){
        temp = temp->next; // move temp until second last element as the last ele will point to NULL
    }
    // currently temp is at second last position, so now the temp->next will be last ele
    free(temp->next); // removes the last element
    temp->next = nullptr;
    return head;
}
// LEETCODE Solution 
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = (node->next)->val;
        node->next = node->next->next;
        return;
    }
};

// 4 -> 5 -> 1 - >9
// so node->val = 5 , so node->next->val means node->next ie 5 will be 1
// so 4->1->1->9
// afte that node->next ie 1 at 2nd index will connect to node->next->next ie 9
// so 4->1->9
