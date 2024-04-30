// Brute force - hashing TC - O(N * 2(logn)) or O(N * 1) depening on which map ds is used, SC - O(N)
int lengthOfLoop(Node *head) {
    unordered_map<Node*,int> mpp;
    Node* temp = head;
    int timer = 1;
    while(temp!=NULL){
        // check if the temp was already present in the map
        if( mpp.find(temp) != mpp.end()){
            int value = mpp[temp]; // accessing the timer=> key
            return (timer-value);
        }
        // each timer temp moves timer increases its count
        mpp[temp] = timer;
        timer++;
        temp = temp->next;
    }
    // no loop is present
    return 0;
}
// Optimal Sol - Hare && Tortoise Rule - with slight modification, when the slow and fast collide, keep a counter and move fast/ slow by one
// when the fast is bound to reach slow again, the counter will store the length of the loop
// TC - O(N) SC - O(1)
int findLength(Node* slow, Node* fast){
    int cnt = 1;
    fast = fast->next;
    while(slow!=fast){
        cnt++;
        fast=fast->next;
    }
    return cnt;
}

int lengthOfLoop(Node *head) {
    // Write your code here
    Node* slow = head;
    Node* fast = head;
    while(fast != NULL && fast->next !=NULL){
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                return findLength(slow,fast);
            }
    }
    return 0;
}
