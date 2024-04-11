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
