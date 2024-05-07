// Brute sol - O(Len) + O(len-N) where Len is the length of the LL and n is the nth node to be deleted , SC - O(1)
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int cnt = 0;
        ListNode* temp = head;
        while(temp!=NULL){
            cnt++;
            temp = temp->next;
        }
        if(cnt == n){ // the head is to be deleted, if cnt= 5 and n is 5 ie 5th 
        // element from last will be head
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }
        temp = head;
        int res = cnt-n;
        while(temp!=NULL){
            res--;
            if(res == 0){
                break;
            }
            temp = temp->next;
        }
        // temp will stop one previous to the node to be deleted
        ListNode* delNode = temp->next;
        temp->next = temp->next->next;
        delete delNode;
        return head;
    }
};


// Optimal Sol - TC - O(N) SC - O(1)
// First take fast pointer and move it n steps ahead 
// check first if fast reahes 
// take second pointer slow pointer and now move fast and slow simultaneously until fast->next == null
// take slow>next as delnode and connect slow->next to slow->next->next
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        for(int i = 0; i<n ; i++){
            fast = fast->next;// move n steps fast ahead
        }
        // first check if fast == NULL ie the n steps made fast to go till NULL
        // ie head to be deleted 
        if(fast == NULL){
            //ListNode* newHead = head->next;
            //return newHead;
            return head->next;
        }
        ListNode* slow = head;
        // now move slow and fast simultaneously
        while(fast->next!= NULL){
            slow = slow->next;
            fast = fast->next;
        }
        // now slow reaches the point before the node to be deleted
        
        ListNode* delNode = slow->next;
        slow->next = slow->next->next;
        delete delNode;
        return head;
    }
};
