// Brute Force TC - O(N * 2(logn/1)) SC - O(N)
// unordered_map best case constant, or worst case logn
Node *firstNode(Node *head)
{
    //    Write your code here.
    unordered_map<Node*, int> mpp;
    Node* temp = head;
    while(temp!=NULL){
        if(mpp.find(temp) != mpp.end()){
            return temp;
        }
        mpp[temp] = 1;
        temp = temp->next;
    }
    return NULL;
}
// Optimal SOl - Tortoise and Hare Pointer Sol
// Firstly move slow and fast pointers until they meet again at same node that means a loop is detected
// Secondly move slow/fast , one of the pointer(slow to the head) and move slow and fast again by one step each till they meet again
// that point will be the starting point of the loop
// TC - O(N) Sc - O(1)
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        // also handles the case of linear LL (odd and even sized) using the while loop condition checks
        while(fast!= NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                slow = head; // loop detected , next step to move slow and fast by one to 
                // get the starting point of the loop
                while(slow != fast){
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow; // or return fast, as both points to same location
            }
        }
        return NULL;
    }
};
