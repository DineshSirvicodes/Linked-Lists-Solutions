// Optimal Sol 1  - TC - O(3N) SC = O(1) ,Iterative Sol - Swapping links 
// logic is to revere the LL
// then take carry as 1 to be added to the LL , if carry is 0 then break and reverse the LL again and return the LL
// if carry is still 1, means a new Node is to be added to the LL
class Solution
{
    public:
  // swapping links
    Node* reverseLL(Node* head){
        Node* prev = NULL;
        Node* temp = head;
        while(temp!=NULL){
            Node* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }
    Node* addOne(Node *head) 
    {
        head = reverseLL(head);// reverse the original LL 1->4->9 to 9->4->1
        Node* temp = head;
        int carry = 1;
        while(temp!=NULL){
            temp->data = temp->data + carry; // adding 1 to the LL
            if(temp->data < 10){ // no carry is there
                carry = 0;
                break; // break the loop as no carry is present, rest of the Ll is unaffected
            }
            else{ // overflow - 9 + 1 = 10
                temp->data = 0;
                carry = 1;
            }  
            temp = temp->next;
        }
        // still carry remains ie a new node is to be added to the head
        // 9->9->9  + 1 => 1->0->0->0 , 1 is to be added to the head
        if(carry == 1){
            Node* newHead = new Node(1);
            head = reverseLL(head);// reverse the LL to get back the original LL
            newHead->next = head;// add 1 to head to get the desired LL if overflow arise
            return newHead;
        }   
        // carry is 0
        head = reverseLL(head);
        return head;
    }
};

// Optimal Sol 2 - Recursive Sol - (Backtracking) TC - O(N) Sc = O(N)
class Solution
{
    public:
                    // head
    int addHelper(Node* temp){
        if(temp == NULL){ // base case
            return 1; // from last, take carry as 1 and add to previous function call
        }
        int carry = addHelper(temp->next);
        temp->data = temp->data + carry; 
        if(temp->data < 10){
            return 0; // no carry is present
        }
        // if carry is present
        temp->data = 0;
        return 1; // carry = 1 for previous call
    }
    Node* addOne(Node *head) 
    {
        int carry = addHelper(head);
        if(carry == 1){ // overflow arise, a new node is created with value 1 point to head
            Node* newNode = new Node(1);
            newNode->next = head;
            return newNode;
        }
        // carry == 0
        return head;
    }
}; 
// screenshots - 
// https://drive.google.com/drive/folders/1tyzQ-V-yMcZ2UzmQrta4-geVlen5CVNy?usp=drive_link
