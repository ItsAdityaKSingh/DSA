#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node * link;
};

struct node* root = NULL;

//print function
void print(){
	struct node* p = root;
	while(p -> link != NULL) {
		printf("%d  ",p->data);
		p = p -> link;
	}
	printf("%d  ",p->data);
	printf("\n");
}

// length function
int length() {
	struct node* p = root;
	int len = 0;
	while(p -> link != NULL) {
		len++;
		p = p -> link;
	}
	printf("\n");
	return len+1;
}
// append function
void append(int n){
	struct node* temp;
	temp = (struct node*)malloc(sizeof(struct node));
	temp -> data = n;
	temp -> link = NULL;
	if(root == NULL) {
		root = temp;
	} else {
		struct node* p = root;
		while(p -> link != NULL) {
			p = p -> link;
		}
		p->link = temp;
	}
}

// addAtBegin function
void addAtBegin(int n) {
	struct node* temp;
	temp = (struct node*)malloc(sizeof(struct node));
	temp -> data = n;
	temp -> link = NULL;
	if(root == NULL) {
		root = temp;
	} else {
		temp -> link = root;
		root = temp;
	}
}

int main() {
	int n, temp;
	scanf("%d",&n);
	int x = n;
	while(n--) {
		append(n - n|(n-2) + n^(n-3) - n&(n-4));
	}
	// append(2);
	// append(3);
	// append(7);
	// append(0);
	print();
	printf("%d\n",length());
	return 0;
}