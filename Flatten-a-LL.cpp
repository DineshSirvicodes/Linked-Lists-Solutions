// Brute Sol - O(N*M) + O(N*M log(N*M)) + O(N*M)  , where N is the horizontal(next) node length size and M is the vertical (child)node length
// SC - O(N*M) + O(N*M)
 Node* convertArr2LL(vector<int> ans){
	 Node* head = new Node(ans[0]);
	 Node* temp = head;

	 for(int i = 1 ;i<ans.size(); i++){
		 Node* newNode = new Node(ans[i]);
		 temp->child = newNode;
		 temp = temp->child;
	 }
	 return head;
 }

Node* flattenLinkedList(Node* head) 
{
	// Write your code here
	vector<int> arr;
	Node* temp = head;
	while(temp!=NULL){
		Node* t2 = temp;
		while(t2!=NULL){
			arr.push_back(t2->data);
			t2 = t2->child;
		}
		temp = temp->next;
		
	}
	sort(arr.begin(),arr.end());
	Node* newhead = convertArr2LL(arr);
	return newhead;
}

// Optimal Sol - TC - O( N*(2M) ) => nearly O(2 N*M) Sc = O(1) but recursive stack space = O(N)
Node* merge2Lists(Node* list1,Node* list2){
    Node* dummyNode = new Node(-1);
    Node* res = dummyNode;
    while(list1!=NULL && list2!=NULL){
        if(list1->data < list2->data){
            res->bottom = list1;
            res = list1;
            list1 = list1->bottom;
        }
        else{
            res->bottom = list2;
            res = list2;
            list2 = list2->bottom;
        }
        res->next = NULL;
    }
    if(list1) res->bottom = list1;
    else res->bottom = list2;
    return dummyNode->bottom;
}

Node *flatten(Node *head)
{
   // base case
   if(head == NULL || head->next==NULL){
       return head;
   }
   Node* mergedHead = flatten(head->next);
   head = merge2Lists(head,mergedHead);
   return head;
   
}
