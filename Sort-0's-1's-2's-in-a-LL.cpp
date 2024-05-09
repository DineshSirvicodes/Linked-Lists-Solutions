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
