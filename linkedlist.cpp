#include<iostream>
using namespace std;
struct Node{
	int data;
	Node* next;
	
	 Node(int x){
	 	data=x;
	 	next=NULL;
	 }
};
void display(Node* root){
	Node* curr=root;
	while(curr!=NULL){
		cout<<curr->data<<" ";
		curr=curr->next;
	}
	cout<<endl;
}
void recursive_disp(Node* root){
	if(root==NULL){
		cout<<endl;
		return;
	}
	else
	{
		cout<<root->data<<" ";
		recursive_disp(root->next);
	}
}
Node* insert_begin(Node* root,int x){
	Node* temp=new Node(x);
	if(root==NULL) return temp;
	else{
		temp->next=root;
		root=temp;
		return temp;
	}
}
Node* insert_end(Node* root,int x){
	Node* temp=new Node(x);
	if(root==NULL) return temp;
	else{
		Node* curr=root;
		while(curr->next!=NULL){
			curr=curr->next;
		}
		curr->next=temp;
		return root;
	}
}
Node* del_begin(Node* root){
	if(root==NULL)return NULL;
	else if (root->next==NULL){
		delete(root);
		return NULL;
	} 
	else{
		Node* temp=root;
		root=root->next;
		delete(temp);
		return root;
	}
}
Node* del_end(Node* root){
	if(root==NULL)return NULL;
	else if(root->next==NULL){
		delete(root);
		return NULL;
	}
	else{
		Node* curr=root;
		while(curr->next->next!=NULL){
			curr=curr->next;
		}
		delete(curr->next);
		curr->next=NULL;
		return root;
	}
}

Node* insert_pos(Node* root,int val,int pos){
	Node* prev=root;
	Node* curr=root;
	int i;
	if(pos==1)return insert_begin(root,val);
	for(i=2;curr->next!=NULL;i++){
		prev=curr;
		curr=curr->next;
		if(i==pos){
			Node* temp=prev->next;
			prev->next=new Node(val);
			prev->next->next=temp;
			return root;
		}
		
	}
	if(i-1!=pos){
		return insert_end(root,val);
	}
}
Node* recursive_search(Node* root,int x){
	if(root==NULL|| root->data==x){
		return root;
	}
	else recursive_search(root->next,x);
}
Node* iterative_search(Node* root,int x){
	Node* curr=root;
	while(curr!=NULL && curr->data!=x){
		curr=curr->next;
	}
	return curr;
}
int main(){
	Node* head=new Node(10);
	head->next=new Node(20);
	display(head);
	head=insert_begin(head,5);
	display(head);
	head=insert_end(head,30);
	display(head);
	head=del_begin(head);
	display(head);
	head=del_end(head);
	display(head);
	head=insert_pos(head,1,1);
	display(head);
	head=insert_pos(head,30,4);
	display(head);
	head=insert_pos(head,5,2);
	display(head);
	head=insert_pos(head,15,4);
	display(head);
	Node* res=recursive_search(head,15);
	if(res==NULL)cout<<"Element not found"<<endl;
	else{
		cout<<res->data<<" found!"<<endl;
	}
	Node* res1=iterative_search(head,1);
	if(res1==NULL)cout<<"Element not found"<<endl;
	else{
		cout<<res1->data<<" found!"<<endl;
	}
	return 0;
}
