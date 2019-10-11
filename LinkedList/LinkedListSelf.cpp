// Linked list Examples

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node * next;
} node_t;


/*struct node{
	int val;
	struct node * next;
};*/

int CreatingLinkedList(node_t *head,int val){
	node_t *nextnode = NULL;
	node_t *tempnode = NULL;
	
	if(head == NULL){
		return 0;
	}
	tempnode = (struct node *)malloc(sizeof(node_t));
	nextnode = head;
	while(nextnode->next != NULL){
		nextnode = nextnode->next;
	}
	tempnode->val = val;
	tempnode->next = NULL;
	nextnode->next = tempnode;// (struct node *)malloc(sizeof(node_t));
//	nextnode->next->val = val;
//	nextnode->next->next = NULL;
	head = nextnode;
//	free(tempnode);
	return 1;
}

int PrintingLinkedListElements(node_t *head){
//	node_t * current = head;
	while(head != NULL){
		printf("%d\n",head->val);
		head = head->next;
	}
	return 1;
}

int FindingElement(node_t *head,int n)    // n is from 0 to n - 1
{
	node_t *nextnode = NULL;
	node_t *temp_node = NULL;
	int i = 0;
	
	nextnode = head;
	if(n == 0){
		if(nextnode == NULL)
			return 0;
	} 
	for(i = 0;i < (n - 1);i++){
		if(nextnode->next == NULL){
			return 0;
		}
		nextnode = nextnode->next;	
	}
	temp_node = nextnode->next;
	printf("%d\n\n",temp_node->val);
}

int RemovingLastItemFromList(node_t *head){
	node_t *nextnode = NULL;
	int retval = 0;
	
	 if (head->next == NULL) {
        retval = head->val;
        free(head);
        printf("%d\n\n",retval);
//        printf("Deleted val: %d\n"retval);
        return retval;
    }
	nextnode = head;
	while(nextnode->next->next != NULL){
		nextnode = nextnode->next;
	}
	retval = nextnode->next->val;
    free(nextnode->next);
	nextnode->next = NULL;
	printf("Deleted Last Element %d\n\n",retval);
//	printf("Deleted val: %d\n"retval);
	return retval;
}

int RemovingFirstItemFromList(node_t **head){
	node_t *nextnode = NULL;
	int retval = 0;
	
	if(*head == NULL){
		return -1;
	}
	
	nextnode = (*head)->next;
	retval = (*head)->val;
	free(*head);
	*head = nextnode;
	printf("Deleted First Element %d\n\n",retval);
}

int FindAndDeleteSpecificElementInList(node_t **head,int n){
	node_t *nextnode = NULL;
	node_t *tempnode = NULL;
	int i = 0;
	
	if(n == 0){
		RemovingFirstItemFromList(head);
		return 1;
	}
	nextnode = *head;
	for(i = 0; i < (n - 1); i++){
		if(nextnode->next == NULL){
			printf("Element Not Found");
			return 0;
		}
		nextnode = nextnode->next;
	}
	tempnode = nextnode->next;
	printf("Search ItemDeleted %d",tempnode->val);
	printf("nextNode ItemDeleted %d\n",nextnode->val);
	nextnode->next = tempnode->next;
	printf("nextNode ItemDeleted %d\n",nextnode->val);
	free(tempnode);
	
}

int InsertFirstElementInList(node_t **head,int val){
	node_t *nextnode = NULL;
	nextnode = (struct node *)malloc(sizeof(node_t));
	
	if((*head) == NULL){
		nextnode->val = val;
		nextnode->next = NULL;
		*head = nextnode;
		printf("First Element in th list added1 %d\n",(*head)->val);
	}else{
		nextnode->val = val;
		nextnode->next = *head;
		*head = nextnode;
		printf("First Element in th list added %d\n",(*head)->val);
	}
}

/*void print_list(node_t * head) {
    node_t * current = head;

    while (current != NULL) {
        printf("%d\n", current->val);
        current = current->next;
    }
}
int main(){

	
	node_t * head = NULL;
	head = (struct node *)malloc(sizeof(node_t));
	if (head == NULL) {
   		return 1;
   	}
   	head->val = 1;
	head->next = NULL;
	print_list(head);
	return 1;
}*/

void insertFirst(node_t **head, int data) {
   //create a link
   node_t *link = (struct node*) malloc(sizeof(node_t));
   
   link->val = data;
//	if(*head != NULL)
   //point it to old first node
    link->next = *head;
	
   //point first to new first node
   *head = link;
}

int main(){
	node_t *head = NULL;
	
//	insertFirst(&head,10,10);
/*	head = (struct node *)malloc(sizeof(node_t));
	if (head == NULL) {
   		return 1;
   	}
   	head->val = 1;
	head->next = NULL;*/
//	PrintingLinkedListElements(head);

	insertFirst(&head,1);
	//InsertFirstElementInList(&head,1);
	CreatingLinkedList(head,100);
	CreatingLinkedList(head,10);
	CreatingLinkedList(head,11);
	FindingElement(head,0);
	PrintingLinkedListElements(head);
	RemovingLastItemFromList(head);
	PrintingLinkedListElements(head);
	RemovingFirstItemFromList(&head);
	PrintingLinkedListElements(head);
	InsertFirstElementInList(&head,1);
	PrintingLinkedListElements(head);
	CreatingLinkedList(head,11);
	PrintingLinkedListElements(head);
	FindAndDeleteSpecificElementInList(&head,2);
	PrintingLinkedListElements(head);
//	free(head);
	return 1;
//	CreatingLinkedList(&head,10);
//	PrintingLinkedListElements(head);
}


