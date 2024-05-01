// Brute force - used stack to store the elements and later compared the stack top with each element if they are same
// TC - O(2*N) - we traversed two times, temp.
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

// Optimal sol - 
