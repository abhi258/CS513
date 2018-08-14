#include<stdio.h>
#include<conio.h>

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
}

void insert(int d, int pos){
	//inserts d to the pos-th position of the list
}

void delete(int d){
	//finds and deletes d from the list
}

int search(int d){
	//returns the position of the element d
	int pos = 0;
	return pos;
}

void traverse(){
	//traverses the list from head to tail
}
void rev_traverse(){
	//traverses the list from tail to head
}

int main(){
	int exit=1;
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
					append(d,0);
				}
				else{
					int flg;
					printf("Enter element:\n");
					scanf("%d",&d);
					printf("Front(0) or Rear(1):\n");
					scanf("%d",&flg);
					append(d,flg);
				}
				break;
			case 2:
				insert(d,pos);
				break;
			case 3:
				delete(d);
				break;
			case 4:
				int pos = search(d);
				break;
			case 5:
				traverse();
				break;
			case 6:
				rev_traverse();
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