// Brute force - TC - O(2N) SC - O(N)
#include<stack>

Node* reverseDLL(Node* head)
{   
    stack<int> st;
    Node* temp = head;
    while(temp!=NULL){
        st.push(temp->data);
        temp= temp->next;
    }  
    temp = head;
    while(temp!=NULL){
        temp->data = st.top();
        st.pop();
        temp = temp->next;
    }
    return head;
}
// Optimal Sol - TC - O(N) SC - O(1)
// Technique is swapping of the links , current->next is swapped with current->back.
// initially current->back was null and now current->next = null
Node* reverseDLL(Node* head)
{   
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node* last = NULL;
    Node* current = head;
    while(current){
         last = current->prev;
         current->prev = current->next;
         current->next = last;
         current = current->prev;
    }
    return last->prev;
}
