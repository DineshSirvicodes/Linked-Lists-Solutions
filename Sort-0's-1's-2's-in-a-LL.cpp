// Brute sol - TC - O(Nlogn) * O(N) Sc = O(N)
class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
        vector<int> ans;
        Node* temp = head;
        while(temp!=NULL){
            ans.push_back(temp->data);
            temp = temp->next;
        }
        sort(ans.begin(),ans.end());
        temp = head;
        int i = 0;
        while(temp!=NULL){
            temp->data = ans[i];
            i++;
            temp = temp->next;
        }
        return head;
        
    }
};
// Brute Sol - TC- O(2N) SC - O(1)
class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
        int cntzero = 0, cntone = 0 , cnttwo = 0 ;
        Node* temp = head;
        while(temp!=NULL){
            if(temp->data == 0){
                cntzero++;
            }
            else if(temp->data == 1){
                cntone++;
            }
            else{
                cnttwo++;
            }
            temp = temp->next;
        }
        temp = head;
        while(temp!=NULL){
            if(cntzero){
                temp->data = 0;
                cntzero--;
            }
            else if(cntone){
                temp->data = 1;
                cntone--;
            }
            else{
                temp->data = 2;
                cnttwo--;
            }
            temp = temp->next;
        }
        return head;
    }
};

// Optimal Sol - TC -O(N) Sc - O(1) , using 3 dummy Nodes to store the 0's,1's,and 2's
class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
        // Add code here
        if(head == NULL || head->next == NULL){
            return head;
        }
        // dummy nodes
        Node* zeroHead = new Node(-1);
        Node* oneHead = new Node(-1);
        Node* twoHead = new Node(-1);
        Node* zero = zeroHead;// pointer to move across the dummy node, and connect to 1 and then to 2
        Node* one = oneHead;
        Node* two = twoHead;
        Node* temp = head;
        while(temp!=NULL){
            if(temp->data == 0){
                zero->next = temp;
                zero = temp; // move ahead, or zero = zero->next
            }
            else if(temp->data == 1){
                one->next = temp;
                one = temp;
            }
            else{
                two->next = temp;
                two = temp;
            }
            temp = temp->next;
        }
        //connecting zero at present last to onehead->next ie 1 then to 2
        // if 1s are present then connect to onehead->next otherwise twohead->next
        zero->next = (oneHead->next)?oneHead->next:twoHead->next;
        one->next = twoHead->next;
        two->next = NULL;// two present at the last
        Node* newHead = zeroHead->next; 
        return newHead;
    }
};

