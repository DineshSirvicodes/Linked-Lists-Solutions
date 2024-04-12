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

