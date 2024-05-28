// TC - O(N) SC = O(1)
// take temp as head , and temp->next to be nextNode . move nextNode
class Solution
{
public:

    Node * removeDuplicates(struct Node *head)
    {
        // Your code here
        Node* temp = head;
        while(temp!=NULL && temp->next!=NULL){
            Node* nextNode = temp->next;
            while(nextNode!=NULL && nextNode->data == temp->data){
                Node* duplicate = nextNode;
                nextNode = nextNode->next;
                free(duplicate);
                // move nextNode till it find unique value
                // if duplicate then move ahead
            }
            // now nextnode if exists will point to a unique node after passing
            // duplicate values
            temp->next = nextNode;
            if(nextNode) nextNode->prev = temp;
            // if nextnode is exists, then point back to temp
            temp = temp->next;
            
        }
        return head;
        
    }
};
