// Brute sol - TC - O(N1*logN) + O(N2*logn) or O(N1*1) + O(N2*1)
//SC - O(N1) or we could stored O(N2) second ll
//using hashing to store the remembering of the node , if found again it is the common point, not found means the ll are not having anything in common
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map<ListNode*,int> mpp;
        ListNode* temp = headA;
        while(temp!=NULL){
            mpp[temp] = 1;
            temp = temp->next;
        }
        temp = headB;
        while(temp!=NULL){
            // if temp is found again
            if(mpp.find(temp)!= mpp.end()){
                return temp; // first common point
            }
            temp = temp->next;
        }
        return NULL;
    }
};

// Brute Optimized , without using space TC = O(N1) + O(N2) + O(N2-N1) + O(N1) = O(N1 + 2 N2), SC = O(1)
// logic: moves d steps ahead in the ll which is larger and compare if they have common node

class Solution {
public:
    ListNode* collisionPoint(ListNode* t1,ListNode* t2,int steps){
        while(steps){
            steps--;
            t2 = t2->next; // moving the larger ll (Steps ahead)
        }
        while(t1!=t2){
            t1 = t1->next;
            t2 = t2->next;
        }
        return t1; // or t2 as if common node found they will point to same node
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* t1 = headA;
        int N1 = 0; // for calculating size of headA
        ListNode* t2 = headB;
        int N2 = 0; // for headB
        while(t1!=NULL){
            N1++;
            t1 = t1->next;
        }
        while(t2!=NULL){
            N2++;
            t2 = t2->next;
        }
        // second ll is greater->headB, move it N2-N1 steps ahead to match till they are of same len
        if(N1<N2){
                            //. smaller, greater
            return collisionPoint(headA,headB,N2-N1);
        }
        // if headA is greater or equal then move N1-N2 steps ahead to match len
        else{
            return collisionPoint(headB,headA,N1-N2);
        }
        return NULL;
    }
};

// Optimal Sol - TC = O(N1+N2) , SC= O(1)
// worst case = both pointers t1 and t2 will traverse each node of both ll , and reaches null
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL) return NULL;
        ListNode* t1 = headA;
        ListNode* t2 = headB;
        // t1!=t2 will never execute as they initially would not point to same node
        while(t1!=t2){
            t1 = t1->next;
            t2 = t2->next;
            // collision point
            if(t1 == t2){
                return t1; // or t2
            }
            // if anyone of the points t1,t2 reaches NULL move them to their opp.heads
            if(t1 == NULL) t1 = headB;
            if(t2 == NULL) t2 = headA;
        }
        return t1; // if no collision t1 == t2 will return null as they would move till null
    }
};
