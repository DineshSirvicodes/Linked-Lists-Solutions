// Brute Sol- TC-O(N/2 + N/2) = O(2N) SC - O(N), Using an extra space array
// firstly store values according to the conditions mentioned, into the array then replace the node's values at each step from start

Node* evenOdd(Node* head){
  int arr[];
  // for odd 
  Node* temp = head; // considering head to be an odd index
  while(temp!=NULL && temp->next !=NULL){
      arr.add(temp->data)
      temp = temp->next->next;
  }
  // if odd length array is there, we would miss the last element due to conditon temp ->next !=NULL, so manually add the last element to the array
  if(temp) arr.add(temp->data)
  // for even
  Node* temp = head->next;
  while(temp!=NULL && temp->next !=NULL){
      arr.add(temp->data)
      temp = temp->next->next;
  }
  // if even length array is there, we would miss the last element due to conditon temp ->next !=NULL, so manually add the last element to the array
  if(temp) arr.add(temp->data)
  temp = head;
  int i = 0; // traversing in the arrayw
  while(temp!->NULL){
      temp->data = arr[i];
      i++;
      temp = temp->next;
  }
  return head;  
}


// Optimal Sol - Taking pointers , marking odd at head, even at head->next. Connecting links to oddd->next->next and similary for even, even->next->next
// lastly odd->next will be connected to even node by using another pointer evenHead which was pointing to head->next;
// TC - O(N) SC - O(1)
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = head->next;
        while(even!=NULL && even->next!=NULL){
            odd->next = odd->next->next;// connecting head to 3rd element and so on
            even->next = even->next->next;// connecting head->next to next 3rd ele and so on
            odd = odd->next;
            even = even->next;
        }
        odd->next = evenHead;
        return head;
    }
};
//
