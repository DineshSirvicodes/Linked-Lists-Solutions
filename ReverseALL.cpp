// Brute Force Sol - TC - O(2N) , SC - O(N) , use of stack to store the elements in a LIFO manner
Node* reverseLinkedList(Node *head)
{
    stack<int> st;
    Node* temp = head;
    while(temp!=NULL){
        st.push(temp->data);
        temp = temp->next;
    }
    temp = head;
    while (temp != NULL) {
        temp->data = st.top();
        st.pop();
        temp = temp->next;
    }
    return head;
}
//Optimal Sol 1 - Swapping Links  Tc - O(N) SC - O(1)
ListNode* reverseList(ListNode* head) {
        ListNode* temp = head;
        ListNode* prev = NULL;
        while(temp!=NULL){
            ListNode* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return prev; 
        // at end the prev will point to last element, while temp & front will point to NULL
    }

// Optimal SOl 2 - Recursive sol TC - O(N) Sc - O(n) ( recursive stack space )
ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head; // Base case
        }
        ListNode* newHead = reverseList(head->next);
        ListNode* front = head->next;
        front->next = head;
        head->next = NULL;
        return newHead;
     }
