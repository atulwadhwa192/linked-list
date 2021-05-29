#include<iostream>
#include<stdlib.h>
using namespace std;
struct Node{
	int data;
	struct Node* next;
};
void traversal(struct Node* head){
	while(head!=NULL){
		cout<<head->data<<endl;
		head=head->next;
	}
}
struct Node* insert_at_first(struct Node *head,int data){
	struct Node* ptr= (struct Node*) malloc (sizeof(struct Node));
	ptr->data=data;
	ptr->next=head;
	return ptr;	
}
void insert_at_index(struct Node* head,int index,int data){
	struct Node* ptr= (struct Node*) malloc (sizeof(struct Node));
	struct Node* p=head;
	ptr->data=data;
	for(int i=0;i<index-1;i++){
		p=p->next;
	}	
	ptr->next=p->next;
	p->next=ptr;
}
void insert_at_last(struct Node* head,int data){
	struct Node *ptr = (struct Node*) malloc(sizeof(struct Node));
	struct Node *p= head;
	ptr->data=data;
	while(p->next!=NULL){
		p=p->next;
	}
	p->next=ptr;
	ptr->next=NULL;
}
struct Node* del_at_first(struct Node* head){
	struct Node* ptr=head;
	head=head->next;
	free(ptr);
	return head;
}
void del_at_index(struct Node* head,int index){
	struct Node* ptr=head;
	for(int i=0;i<index-1;i++){
		ptr=ptr->next;
	}
	struct Node* q=ptr->next;
	ptr->next=q->next;
	free(q);
}
void del_at_last(struct Node* head){
	struct Node* p= head;
	struct Node* q=p->next;
	while(q->next!=NULL){
		p=p->next;
		q=q->next;
	}
	p->next=NULL;
	free(q);
}
struct Node* del_val(struct Node* head,int value){
	if(head->data!=value){
		struct Node* ptr=head;
		struct Node* q;
	 	while(ptr->data!=value && ptr->next!=NULL){
	 		q=ptr;
	 		ptr=ptr->next;
	 	}
		if(ptr->data==value){
			q->next=ptr->next;
	 		free(ptr);
	 		return head;
		}
		else{
			cout<<"Element Not Found"<<endl;
			return head;
		}		
	}
	else{
		struct Node* p=head;
		head=p->next;
		free(p);
		return head;
	}
	
}
int main(){
	struct Node* head= NULL;
	int input;
	int insert_option;
	int delete_option;
	while(1){
		cout<<"----------------------LINKED LIST PROGRAMME-------------------------"<<endl;
		cout<<"1. Insert"<<endl;
		cout<<"2. Delete"<<endl;
		cout<<"3. Display"<<endl;
		cout<<"4. Exit"<<endl;
		cin>>input;
		switch(input){
			case 1:
				{
					cout<<"1. Insert at the begining"<<endl;
					cout<<"2. Insert at an index"<<endl;
					cout<<"3. Insert at the end"<<endl;
					cin>>insert_option;
					if(insert_option==1){
						cout<<"Enter Data"<<endl;
						int data;
						cin>>data;
						if(head!=NULL){
							head=insert_at_first(head,data);
						}
						else{
							head= (struct Node*) malloc(sizeof(struct Node));
//							head=insert_at_first(head,data);
							head->data=data;
							head->next=NULL;
						}
						
//						traversal(head);
					}
					else if(insert_option==2){	
						cout<<"Enter Data"<<endl;
						int data;
						cin>>data;
						cout<<"Enter index"<<endl;
						int index;
						cin>>index;
						if(index!=0){
						insert_at_index(head,index,data);
						}
						else{
							if(head!=NULL){
								head=insert_at_first(head,data);
							}
							else{
								head=(struct Node*) malloc(sizeof(struct Node));
								head->data=data;
								head->next=NULL;
							}
						}
					}
					else if(insert_option ==3 ){
						cout<<"Enter Data"<<endl;
						int data;
						cin>>data;
						if(head!=NULL){
								insert_at_last(head,data);
							}
							else{
								head=(struct Node*) malloc (sizeof(struct Node));
								head->data=data;
								head->next=NULL;
							}
						}
					else{
							cout<<"Invalid option "<<endl;
					}
					}
				break;
			case 2:
				{
					cout<<"1. Delete at the begining"<<endl;
					cout<<"2. Delete at an index"<<endl;
					cout<<"3. Delete at the end"<<endl;
					cout<<"4. Delete a node at a given value (at first occurance)"<<endl;
					cin>>delete_option;
					if(delete_option==1){
						if(head!=NULL){
						head=del_at_first(head);	
						}
						else{
							cout<<"Underflow Condition"<<endl;
						}
					}
					else if(delete_option==2){
						cout<<"Enter index"<<endl;
						int index;
						cin>>index;
						if(head==NULL){
							cout<<"Underflow Condition"<<endl;
						}
						else if(index==0){
							head=del_at_first(head);	
						}
						else{
							del_at_index(head,index);
						}
					}
					else if(delete_option ==3 ){
						if(head==NULL){
							cout<<"Underflow Condition"<<endl;
						}
						else{
							del_at_last(head);
						}
					}
					else if(delete_option==4){
						if(head==NULL){
							cout<<"Underflow Condition"<<endl;
						}
						else{
							cout<<"Enter Data"<<endl;
							int data;
							cin>>data;
							head=del_val(head,data);
						}	
					}
					else{
						cout<<"Invalid option "<<endl;
					}
				}
				break;
			case 3:
				{
					if(head==NULL){
						cout<<"LINKED LIST EMPTY "<<endl;
					}
					else{
						traversal(head);
					}
				}
				break;
			case 4:
				{
					exit(0);	
				}
				break;
			default:
				{
					cout<<"Invalid option "<<endl;
				}
		}
//	if(head==NULL){
//		head= (struct Node*) malloc(sizeof(struct Node));
//		head->data=20;
//		head->next=NULL;
//		cout<<"HEAD"<<endl;
//		cout<<head->data;
////		cout<<head->next;
//	}
//	else{
//		cout<<'a';
//	}
		
	}

}
