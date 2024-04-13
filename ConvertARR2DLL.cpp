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
    print(head);
    return 0;
}
