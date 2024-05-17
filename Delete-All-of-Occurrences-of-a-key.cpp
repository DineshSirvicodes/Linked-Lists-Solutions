//TC - O(N) Sc - O(1)
void deleteAllOccurOfX(Node* head, int x) {
        // Write your code here
        Node* temp = head;
        while(temp!=NULL){
            if(temp->data == x){
                //if temp == head, ie head holds the x value. then head must be moved ahead
                // otherwise it would get deleted
                if(temp == head){
                    head = head->next;
                }
                Node* nextNode = temp->next;
                Node* prevNode = temp->prev; // inital - > NULL
                // if nextNode exists then only, do the links change,
                // ie if nextNode is NULL, then NULL->prev will give error, this can occur 
                // at lastNode when nextNode is NULl
                if(nextNode) nextNode->prev = prevNode;
                //same goes to prevNode , if prevNode is NULL, then NULL->next will throw error
                // so check if it exists, occurs at firstNode
                if(prevNode) prevNode->next = nextNode;
                free(temp);
                temp = nextNode;
            }
            else{
                temp = temp->next;
            }
        }
        return;
    } 
