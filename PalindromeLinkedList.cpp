// Brute force - used stack to store the elements and later compared the stack top with each element if they are same
// TC - O(2*N) - we traversed two times, temp. node pointer
// SC - O(N) - stack space
bool isPalindrome(ListNode* head) {
        stack<int> st;
        ListNode* temp = head;
        while(temp!=NULL){
            st.push(temp->val);
            temp = temp->next;
        }
        temp = head;
        while(temp!=NULL){
            if(st.top() == temp->val){
                temp = temp->next;
                st.pop();
            }
            else{
                return false;
            }
        }
        return true;
    }

// Optimal sol - TC- O(2*N) - twice linkelist traversal - SC - O(1)
// First using Tortoise and hare algo, find the node(slow) from where we compare the elements on reversal- reversal will happen on slow->next
// Second reverse the node from second->next till last, and compare the first and the newHead and move ahead
// for even cases - fast should be moving till second last only cuz there are 2 midpoints, so only the first is considered
// for odd cases the fast->next ie fast should be till last position, next will be null
class Solution {
public:
    ListNode* ReverseList(ListNode* head){
        ListNode* temp = head;
        ListNode* prev = NULL;
        while(temp!=NULL){
            ListNode* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;         
        }
        return prev;

    }
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return true;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* first = head;
        // for even fast should stop at second last
        // for odd the fast should stop at last
        while(fast->next !=NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* newHead = ReverseList(slow->next);
        ListNode* second = newHead;
        while(second!=NULL){
            if(first->val != second->val){
                ReverseList(newHead);
                return false;
            }
            first = first->next;
            second = second->next;
        }
        ReverseList(newHead);
        return true;
    }
};
