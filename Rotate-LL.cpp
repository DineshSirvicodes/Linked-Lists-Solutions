// TC - O(2N) SC - O(1)
// Approach, connect the last node to the head of the LL
// find k as k % len to make the values of k as small. 
// find the  Len - K th Node which will be the new Tail
class Solution {
public:
    ListNode* findNthNode(ListNode* temp,int k){
        int cnt = 1;
        while(temp!=NULL){
            if(cnt == k) return temp;
            cnt++;
            temp = temp->next;
        }
        return temp;
    }
    ListNode* rotateRight(ListNode* head, int k) {
       if(head==NULL || k == 0) return head;
       int len = 1;
       ListNode* tail = head;
       while(tail->next!=NULL){
            len++;
            tail = tail->next;
       } 
       // if k == 5,10,15... then len is 5 then the rotation we be same as original LL
       if(k%len == 0) return head;
       k = k % len; // making bigger k to small
       // k = 13 => 13%5 => k = 3
       // next point tail back to head
       tail->next = head;

       ListNode* newTail = findNthNode(head,len-k);
       head = newTail->next;// head will be changed to the rotated node
       newTail->next = NULL;
       return head;

    }
};
