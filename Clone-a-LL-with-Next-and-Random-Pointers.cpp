// Brute sol - using a hashmap TC = O(2N*1) where 2 while loops will take O(N) and map will take O(1) or O(logn) depending on the map used.
//SC - O(N) and O(N) for storing and returning the answer
// we create a hashmap of <Node*,Node*> in which we store the original LL node's value as key and copying it to create a copy of the original node as value
// we then traverse the LL and store the key(original LL) and value(copy LL) 
// then we again traverse the LL ,and wherever the node is pointing to , now the copy will also point to it, as the copy nodes are already created without any connetions earlier,
class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* temp = head;
        unordered_map<Node*,Node*> mpp;
        while(temp!=NULL){
            Node* newNode = new Node(temp->val);
            mpp[temp] = newNode; // creating a copy with temp->val
            temp = temp->next;
        }
        temp = head;
        while(temp!=NULL){
            Node* copyNode = mpp[temp]; // accessing copy node
            copyNode->next = mpp[temp->next];//assign the next and random pointers, by 
            // taking the temp's connection and assign the connections to the copy nodes
            copyNode->random = mpp[temp->random];
            temp = temp->next;
        }
        return mpp[head];// temp's key head value-> copy head 
    }
};

// Optimal Sol -  TC - O(3N) Sc - O(N)
// Algorithm

// Step 1: Traverse the original node and create a copy of each node and insert it in between the original node and the next node.

// Step 2: Traverse this modified list and for each original node that has a random pointer, set the copied node’s random pointer to the corresponding copies random node. If the original node’s random pointer is full, set the copied node’s random pointe to null as well.

// Step 3: RecursionTraverse the modified list again and extract the coped nodes by breaking the links between the original nodes and the copied nodes. Revert the original list to its initial state by fixing the next pointers.

// Step 4: Return the head of the deep copy obtained after extracting the copied nodes from the modified list.
class Solution {
public:
    // inserting copy nodes in between each nodes 
    void insertCopyInBetween(Node* head){
        Node* temp = head;
        while(temp!=NULL){
            Node* copyNode = new Node(temp->val);
            copyNode->next = temp->next;
            temp->next = copyNode;
            temp = temp->next->next;
        }
    }
    // connecting random pointers
    void connectRandomPointers(Node* head){
        Node* temp = head;
        while(temp!=NULL){
            Node* copyNode = temp->next;
            if(temp->random){ // is not null
                // copyNode->random will go to temp->random and next of it, ie copy
                copyNode->random = temp->random->next; // ie copyNode's random again
            }
            else{ // NULL
                copyNode->random = NULL;
            }
            temp = temp->next->next;// avoiding going to copy Nodes
        }

    }
    // disconecting the temp->next connections to copyNodes and instead point to temp->next->next ie 
    // creating the original ll back
    Node* getCopyList(Node* head){
        Node* temp = head;
        Node* dummyNode = new Node(-1);
        Node* res = dummyNode;
        while(temp!=NULL){
            res->next = temp->next;// linking the dummy to copy
            res = res->next;
            temp->next = temp->next->next;// delinking the link to the copynode
            temp = temp->next;
        }
        return dummyNode->next;
    }
    Node* copyRandomList(Node* head) {
        insertCopyInBetween(head);
        connectRandomPointers(head);
        return getCopyList(head);
    }
};
