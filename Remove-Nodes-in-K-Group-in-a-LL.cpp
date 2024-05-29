// TC = O(2N) SC = O(1)
// ReverseLL - O(N) , Finding KthNode -> O(N) = O(2N) , SC = O(1) , const
// Idea to find KthGroup Node if it exists, then cut the LL into individual parts and reverse them
// later connect this part to next , LL which will be also reverse and so onclass Solution {
public:
    ListNode* ReverseLL(ListNode* temp){
        ListNode* prev = NULL;
        while(temp!=NULL){
            ListNode* nextNode = temp->next;
            temp->next = prev;
            prev = temp;
            temp = nextNode;
        }
        return temp;
    }
    ListNode* getKthGroup(ListNode* temp,int k){
        k-=1;
        while(temp!=NULL && k>0){
            k--;
            temp = temp->next;
        }
        return temp;// get kth node group
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevNode = NULL;
        while(temp!=NULL){
            ListNode* KthNode = getKthGroup(temp,k);
            if(KthNode == NULL){// no group can be formed
                if(prevNode) prevNode->next = temp; // if prevNode exists then only connect
                break;
            }
            ListNode* nextNode = KthNode->next;
            KthNode->next = NULL;
            ReverseLL(temp);
            if(temp == head){ // first Kth group
                head = KthNode; // making sure the first node will be head again
            }
            else{
                prevNode->next = KthNode;
            }
            prevNode = temp; 
            temp = nextNode;
        }
        return head;
    }
};
