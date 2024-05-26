// Brute SOl - TC is nearly O(N^2) not exactly, SC = O(1)
// Simple traversal using two pointers and checking each pair if the sum is == target, also optimizing it using condition check
// that is first + second <= sum then only move ahead , rather than iterating the entire DLL
class Solution
{
public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
    {
        vector<pair<int,int>> ans;
        Node* temp = head;
        while(temp!=NULL){
            Node* iterate = head->next;
            while(iterate!=NULL && temp->data + iterate->data <= target){
                if(temp->data + iterate->data == target){
                    ans.push_back({temp->data,iterate->data});
                    iterate = iterate->next;
                }
            }
            temp = temp->next;
        }
        return ans;
    }
};
// Optimal SOl - Two pointers TC - O(N) Sc = O(1)
// Two pointers - left on head , right at the end of the DLL , tail
// using the help of the given DLL, as it is sorted. 
// Do left + right == target -> if left + right > target , decrease right,
// or left + sum < target , increase left
// if pair if found , increase left and decrease right
class Solution
{
public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
    {
        vector<pair<int,int>> ans;
        Node* left = head;
        Node* right = head;
        while(right->next!=NULL){
            right = right->next;
        }
        while(left->data < right->data){
            if(left->data + right->data == target){
                ans.push_back({left->data,right->data});
                left = left->next;
                right = right->prev;
            }
            else if(left->data + right->data > target){
                right = right->prev;
            }
            else{
                left = left->next;
            }
        }
        return ans;
    }
};
