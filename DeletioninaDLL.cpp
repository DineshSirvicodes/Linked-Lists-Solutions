#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* back;

    public:
    Node(int data1,Node* next1, Node*back1){
        data = data1;
        next = next1;
        back = back1;
    }
    
    public:
    Node(int data1){
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

Node* convertArr2DLL(vector<int> arr){
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for(int i = 1; i<arr.size(); i++){
        Node* temp = new Node(arr[i],nullptr,prev);// firstly new node is created and the next pointer is null
        // and previous pointer is prev initially pointing to head (backwards connection)
        prev->next = temp; // prev->next which is initially at head is pointing to new node temp next (forwards connection)
        prev = temp; // moving prev ahead to temp location
        // again the temp creates new node within the loop
    }
    return head;
}

// Deletion of the head in a DLL
Node* deletehead(Node* head){
    if(head == NULL || head->next == NULL){ // head->next == null means ll has only one element
            return NULL; // after deletion nothing remains
    }
    Node* prev = head;
    head = head->next;
    head->back = nullptr;
    prev->next = nullptr;
    delete prev;
    return head;
}

Node* deleteTail(Node* head){
    Node* tail = head;
    while(tail->next != NULL){
        tail = tail->next; // move tail till not null ie last element
    }
    Node* prev = tail->back; // tail's back connection
    tail->back = nullptr; // tails back connection is null
    prev->next = nullptr; // second last element connection to last is null
    delete tail;
    return head;
}

// Deletion of the kth element (given is position)
Node* deleteKthElement(Node* head,int k){
    if(head == NULL){
        return NULL;
    }
    int cnt = 0;
    Node* temp = head;
    while(temp!=NULL){
        cnt++;
        if(cnt == k) break;
        temp = temp->next; // till cnt == k temp will move ahead and cnt number and temp location will be same
    }
    Node* prev = temp->back;// will be one before temp
    Node* front = temp->next;// will be one ahead of temp
    // Case1(prev is NUll and front is null)
    if(prev == NULL && front == NULL){ // single element 
            delete temp;
            return NULL;
    }
    // case 2 - ( only prev is null ) temp is at head 
    else if(prev == NULL){
        return deletehead(head);
    }
    // case 3 - (front is null ) temp is at last element
    else if(front == NULL){
        return deleteTail(head);
    }
    // case 4 - temp has both prev and front connections
    else{
        prev->next = front;
        front->back = prev;
        temp->next = nullptr;
        temp->back  = nullptr;
        delete temp;
        return head;
    }
}

void print(Node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
}

int main(){
    vector<int> arr;
    arr.push_back(12);
    arr.push_back(5);
    arr.push_back(8);
    arr.push_back(7);
    Node* head = convertArr2DLL(arr);
    //head = deletehead(head);
   // head = deleteTail(head);
    head = deleteKthElement(head,2);
    print(head);
    return 0;
}
