// Brute Sol - TC - O(N) + O(N) + O(Nlogn) , SC - O(N)
// logic is taking extra space and sort it and again override the ll 
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        vector<int> ans;
        ListNode* temp = head;
        while(temp!=NULL){
            ans.push_back(temp->val);
            temp = temp->next;
        }
        sort(ans.begin(),ans.end());
        temp = head;
        int i = 0;
        while(temp!=NULL){
            temp->val = ans[i];
            temp = temp->next;
            i++;
        }
        return head;
    }
};

// Optimal sol - TC -  O(N*logN)*O(N+N/2) = O(NLogN)*N Sc - O(1)
// using mergesort technqiue to sort the ll , in array we take an extra temp array but now we do the operation on the ll itself
class Solution {
public:
    ListNode* findMiddle(ListNode* head){
        // using hare and tortoise algo, with little change at fast, which initally
        // points to head but now points to head->next
        // cuz for even sized LL , there will be 2 middle , so first middle would point 
        // to second middle but now middle will point to first middle
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* mergeTwoLL(ListNode* list1, ListNode* list2){
        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp = dummyNode;
        while(list1!=NULL && list2!=NULL){
            if(list1->val < list2->val){
                temp->next = list1;
                temp = list1;
                list1=list1->next;
            }
            else{
                temp->next = list2;
                temp = list2;
                list2 = list2->next;
            }
            // if still comparison is left from both left and right LL
            if(list1) temp->next = list1;
            if(list2) temp->next = list2;
        }
        return dummyNode->next;
    }
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head; // base case
        }
        ListNode* middle = findMiddle(head); // mid
        ListNode* right = middle->next; // mid+1
        middle->next = nullptr; // break the ll into 2 separate ll
        ListNode* left = head; // low

        left = sortList(left); // left portion of the ll from head to middle
        right = sortList(right); // right portion from middle->next to last
        return mergeTwoLL(left,right);// merging left halves and right halves
    }
};
