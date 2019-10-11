#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct node {
	int val;
	struct node *next;
}NODE_t;

void AddingELementsAtStart(NODE_t **head, int val){
	NODE_t *Temp = (struct node *)malloc(sizeof(NODE_t));
	
	Temp->val = val;
	Temp->next = *head;
	*head = Temp;
	
}

void PrintLinkedList(NODE_t *head){
	while(head != NULL){
		printf("%d\n",head->val);
		head = head->next; 
	}
}

void AddingSuccessiveElements(NODE_t **head, int val){
	NODE_t *link = NULL, *temp = NULL;
	
	link =  (struct node *)malloc(sizeof(NODE_t));    // return type of a malloc is void * so typedef is neceessary
	if(link == NULL)
		return;
		
	temp = *head;
	if(*head == NULL){
		AddingELementsAtStart(head, val);
		return;
	}
	while(temp->next != NULL){
		temp = temp->next;
	}
	link->val = val;
	link->next = NULL;
	temp->next = link;
}

int FindingASpecificElementFromaLinkedList(NODE_t *head, int n){
	NODE_t *temp = NULL;
	int i = 0;
	
	temp = head;
	if(n == 0)
	{
		printf("%d\n",temp->val);
		return temp->val;
	}
	for(i = 0; i < (n - 1); i++){
		if(temp->next == NULL)
			return 0;
		temp = temp->next;
	}
	temp = temp->next;
	printf("Value Found %d\n",temp->val);
}

void DeleteFirstElementFromList(NODE_t **head){
	NODE_t *link = NULL;
	
	link = (*head)->next;
	printf("Deleted Element from list %d\n",(*head)->val);
	free(*head);
	*head = link;
}

void DeleteSpecificElementFromList(NODE_t **head, int ElementNo){
	NODE_t *link = NULL;
	int i = 0;
	
	if(ElementNo == 0){
		DeleteFirstElementFromList(head);
		return;
	}	
	link = *head;
	for(i = 0;i < (ElementNo - 2); i++){
		if(link->next == NULL){
			printf("Element Not Found in delete\n");
			return;
		}
		link = link->next;	
	}
	printf("Deleted Element in search %d\n",link->next->val);
	link->next = link->next->next;
	
}

int main(){
	NODE_t *node_s = NULL;
/*	AddingELementsAtStart(&node_s, 1 );
	PrintLinkedList(node_s);
	AddingELementsAtStart(&node_s, 2 );
	PrintLinkedList(node_s);*/
	AddingSuccessiveElements(&node_s, 3);
//	PrintLinkedList(node_s);
	AddingSuccessiveElements(&node_s, 2 );
	AddingSuccessiveElements(&node_s, 4 );
	AddingSuccessiveElements(&node_s, 5 );
	PrintLinkedList(node_s);
	DeleteSpecificElementFromList(&node_s,3);
//	DeleteFirstElementFromList(&node_s);
	PrintLinkedList(node_s);
	FindingASpecificElementFromaLinkedList(node_s,2);
}
