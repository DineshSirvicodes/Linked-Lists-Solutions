// Insertion at the beginning of the LL
/**
 * Definition of linked list
 * class Node {
 *
 * public:
 *     int data;
 *     Node* next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node* next) : data(x), next(next) {}
 * };
 */

Node* insertAtFirst(Node* list, int newValue) {
    Node* temp = new Node(newValue,list); // temp contains element to be added with next pointer to head
    return temp;
}
//n =  5
// 4 3 2 1
// 5-> temp->data and temp->next = head (ie list)

// Insertion in a LL with given an element and k as the postion where the element is to be put
// Insertion at the tail of the linkedlist
Node* insertTail(Node* head, int val){
    if(head == NULL){
        return new Node(val);// with pointer to null
    }
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    // temp is at last position
    Node* newNode = new Node(val);
    temp->next = newNode;
    return head;
}

// Insertion in a LL with given an element and a postion k
Node* insertK(Node* head, int el , int k){
    if(head == NULL){
        if(k == 1){
            return new Node(el); // no element earlier in the LL, now k will be 1st position as no one is there
        }
        else return NULL;
    }
    if(k == 1){
        Node* temp = new Node(el,head);
        return temp;
    }
    int cnt = 0;
    Node* temp = head;
    while(temp!=NULL){
        cnt++;
        if(cnt == k-1){
            Node* x = new Node(el); // element node with pointer to NUll at the moment
            x->next = temp->next; // first connect the node->next with temp->next otherwise no reference later
            temp->next = x; 
            break;
        }
        temp = temp->next;
    }
    return head;
}
// Insertion in a LL where element is given and val is given, the element is to be put before val (where val is present in the LL)
// 12 5 8 7
// el = 10 , val = 5
// o/p = 12 10 5 8 7
Node* insertBeforeValue(Node* head,int el,int val){
    if(head == NULL){ // if LL is empty then not feasible to put anything before Nothing
        return NULL;
    }
    if(head->data == val){ // if val is to put before head at first position
        return new Node(el,head);
    }
    Node* temp = head;
    // loop will go until the second last position to check the temp->next->data
    while(temp->next != NULL){
        if(temp->next->data == val){
            Node*x = new Node(el,temp->next);
            temp->next = x;
            break;
        }
        temp = temp->next;
    }
    return head;
}
