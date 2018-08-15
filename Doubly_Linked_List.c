#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct node{
	int d;
	struct node* right;
	struct node* left;
}node;

node* head = NULL;
node* tail = NULL;
int length=0;

void append(int d, int flg){
	//appends d to front end of the list if the flag is 0
	//appends d to rear end of the list if the flag is 1
	node* p = (node*)malloc(sizeof(node));
	p->d = d;
	if(flg==0){
		p->right = head;
		p->left = NULL;
		head->left = p;
		head = p;
	}
	else{
		p->left = head;
		p->right=NULL;
		tail->right = p;
		tail = p;
	}

}

void insert(int d, int pos){
	//inserts d to the pos-th position of the list
	node* p = (node*)malloc(sizeof(node));
	p->d = d;
	int i = 0;
	node* t = head;
	node* q = NULL;
	while(t->right!=NULL){
		if(pos==i){
			q->right = p;
			p->left = q;
			p->right = t;
			t->left = p;
			break;
		}
		q = t;
		t = t->link;
		i++;
	}
}

void delete(int d){
	//finds and deletes d from the list
	node* temp;
	temp=head;
	
	if(temp->d==d)
	{
		head=head->right;
		printf("element deleted\n");
		free(temp);
		temp=null;
	}
	else
	{
		int flag=0;
		temp=temp->next;
		while(temp->right!=null)
		{
			if(temp->d==d)
			{
				temp->left->right=temp->right;
				temp->right->left-temp->left;
				free(temp);
				temp=null;
				flag=1;
				break;
				printf("element deleted\n");
			}
			temp=temp->right;
		}
		if(flag==0)
		{
			if(temp->d==d)
			{
				temp->left=null;
				tail=temp->left;
				free(temp);
				temp=null;
				printf("element deleted\n");
			}
		}
			
	}
}

int search(int d){
	//returns the position of the element d
	int pos = 0;
	node* temp;
	temp=head;
	while(temp->right!=null);
	{
		pos++;
		if(temp->d==d)
		{
			return pos;
		}
		temp=temp->right;
	}
	if(temp->d==d)
		return (pos+1);
	else
		return(-1);
	
}

void traverse(int flg){
	//traverses the list from head to tail if flg=0
	//traverses the list from tail to head if flg=1
	node* temp;
	temp=head;
	
	if(flg==0)
	{
		temp=head;
		printf("List traversal in forward direction is:\n");
		while(temp->right!=null)
		{
			printf("%d\t",temp->d);
			temp=temp->right;
		}
		printf("%d\t",temp->d);
		
	}
	if(flg==1)
	{
		temp=tail;
		printf("List traversal in backward direction is:\n");
		while(temp->left!=null)
		{
			printf("%d\t",temp->d);
			temp=temp->left;
		}
		printf("%d\t",temp->d);
	}
	else
	{
		printf("Invalid option chosen\n");
	}
		
}

int main(){
	int exit=1;
	head = (node*)malloc(sizeof(node));
	tail = head;
	head->right=NULL;
	head->left=NULL;

	do{
		int c;
		printf("1. Append an Element\n2. Insert an Element\n3. Delete an Element\n4. Search for an Element\n5.Print the List\n6. Print the Listin reverse\n7. Exit");
		printf("Enter your choice:\n");
		scanf("%d",&c);
		switch(c){
			case 1:
				int d;
				if(length==0){
					printf("Enter element:\n");
					scanf("%d",&d);
					head->d=d;
					length++;
				}
				else{
					int flg;
					printf("Enter element:\n");
					scanf("%d",&d);
					printf("Front(0) or Rear(1):\n");
					scanf("%d",&flg);
					length++;
					append(d,flg);
				}
				break;
			case 2:
				int d;
				if(length==0){
					printf("Enter element:\n");
					scanf("%d",&d);
					head->d=d;
					length++;
				}
				else{
					int pos;
					printf("Enter element:\n");
					scanf("%d",&d);
					printf("Enter position to insert:\n");
					scanf("%d",&pos);
					if(pos<0){
						printf("Invalid position\n");
						break;
					}
					if(pos==0 || pos==length)
						append(d,pos/(length-1));
					else
						insert(d,pos);
				}
				break;
			case 3:
				printf("Enter the element to be deleted:\n");
				scnaf("%d",&d);
				delete(d);
				break;
			case 4:
				printf("Enter the element you want to search:\n");
				scanf("%d",&d);
				int pos = search(d);
				break;
			case 5:
				traverse(0);
				break;
			case 6:
				traverse(1);
				break;
			case 7:
				exit=0;
				break;
			default:
				printf("Invalid choice...Please try again!\n");
		}
	}while(exit)
	return 0;
}
