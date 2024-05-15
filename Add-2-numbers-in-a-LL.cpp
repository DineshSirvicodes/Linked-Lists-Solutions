// TC - O(max(N1,N2)) , SC - O(max(N1,N2)) where N1 = l1->size and N2 = l2->size
// we are only storing the values and not doing any operations
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       int carry = 0;
       ListNode* dummyNode = new ListNode(-1);
       ListNode* curr = dummyNode;
       while(l1!=NULL || l2!=NULL){
            int sum = carry;
            if(l1){
                sum = sum+l1->val;
            }
            if(l2){
                sum = sum + l2->val;
            }
            ListNode* SumListNode = new ListNode(sum%10);// will give remainder
            carry = sum/10; // quotient, 3+7 = 10 , so 0 is new node and 1 is carry added next
            curr->next = SumListNode;
            curr = curr->next;
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
       }
       if(carry){ // if still carry remains , create new node and add to it
            ListNode* newNode = new ListNode(carry);
            curr->next = newNode;
       }
       return dummyNode->next;// new head
    }
};
