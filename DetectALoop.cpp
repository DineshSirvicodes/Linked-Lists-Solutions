// Brute Force Sol - TC - O(N * 2(logn/ 1) )- unordered-1) - O(N*2Logn) SC - O(N) 
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_map<ListNode*,int> mpp;
        ListNode* temp = head;
        while(temp!=NULL){
            if(mpp.find(temp) != mpp.end()){
                return true; // if temp is pointing to end iterator, that means no loop (temp element)is found
            }
            mpp[temp] = 1; // marking 1 as found
            temp = temp->next;
        }
        return false;
    }
};

// Optimal SOl - TC - O(N) SC - O(1) Tortoise & Hare Pointer Algorithm
// Tortoise- Slow moves by 1 , Hare - fast moves by 2
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        // fast!=NULL and fast->next!=NULl means linear LL no loop
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                return true; // loop detected
            }
        }
        return false; // no loop detected
    }
};
