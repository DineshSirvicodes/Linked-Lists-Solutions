// Brute force sol - TC - O(N+N/2) SC - O(1) , returns the middle of the LL by using the (n/2) + 1 method
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int n = 0; // calculating the size of the LL
        ListNode* temp = head;
        while(temp!=NULL){
            n++;
            temp=temp->next;
        }
        int middle = (n/2)+1; // middle node size
        temp = head;
        while(temp!=NULL){
            middle = middle-1;
            if(middle == 0){
                break;
            }
            temp = temp->next;
        }
        return temp;
    }
};
//Optimal Sol - Tortoise & Hare Algorithm TC - O(n/2) Sc = O(1)
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!= NULL && fast->next!=NULL){
          // for even sized LL - the fast will point to Null eventually then stop
            // for odd sized LL - the fast will point to last node , therfore the next will be null, so stop
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};
