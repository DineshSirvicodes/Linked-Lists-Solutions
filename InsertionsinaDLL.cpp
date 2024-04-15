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

Node* insertBeforeHead(Node* head,int val){
    Node* newHead = new Node(val,head,nullptr); // next will point to head and back will point to null
    head->back = newHead;
    return newHead;
}

Node* insertAfterTail(Node* head,int val){
    Node* temp = head;
    while(temp->next!=nullptr){
        temp = temp->next;
    }
    Node* newTail = new Node(val,nullptr,nullptr);
    temp->next = newTail;
    newTail->back = temp;
    return head;
}

Node* insertBeforeTail(Node* head,int val){
    if(head->next == NULL){ // ie only single element
        return insertBeforeHead(head,val);
    }
    Node* tail = head;
    while(tail->next!= nullptr){
        tail = tail->next;
    }
    // tail reaches the end of the Dll
    Node* prev = tail->back;
    Node* newNode = new Node(val,tail,prev);
    prev->next = newNode;
    tail->back = newNode;
    return head;
}

Node* insertBeforeKthNode(Node* head,int k,int val){
    if(k == 1){
        return insertBeforeHead(head,val);
    }
    Node* temp = head;
    int cnt = 0;
    while(temp->next!=NULL){
        cnt++;
        if(cnt == k) break;
        temp = temp->next;
    }
    Node* prev = temp->back;
    Node* newNode = new Node(val,temp,prev);
    prev->next = newNode;
    temp->back = newNode;
    return head;

}

void insertBeforeNode(Node* node,int val){
    Node* prev = node->back;
    Node* newNode = new Node(val,node,prev);
    prev->next = newNode;
    node->back = newNode;
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
    //head = insertBeforeHead(head,10);
    //head = insertAfterTail(head,10);
    // head = insertBeforeTail(head,10);
    //head = insertBeforeKthNode(head,4,10);
    insertBeforeNode(head->next->next,1000);
    print(head);


}   
