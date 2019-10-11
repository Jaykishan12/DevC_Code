#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdint.h>

typedef struct node{
	int val;
	struct node *next;
}NODE;

typedef enum NODE_TYPE
{
	FIRST_ELEMENT_ADD = 0, SUCCESSIVE_ELEMENT_ADD,
}NODE_ADD_TYPE_t;


void InsertingElements(NODE **Head, int val, NODE_ADD_TYPE_t n){
	
	NODE *link = (struct node *)malloc(sizeof(NODE));
	NODE *Temp = NULL;
	link->val = val;
	if(n == FIRST_ELEMENT_ADD || (*Head == NULL)){
		link->next = *Head;
		*Head = link;
		return;
	}
	else if(n == SUCCESSIVE_ELEMENT_ADD){
		link->next = NULL;
	}
	Temp = *Head;
	while(Temp->next != NULL){
		Temp = Temp->next;
	}
	Temp->next = link;
}

void FindSpecificElementFrom_List(NODE *Head, int ElementNo){
	uint8_t i = 0;
	NODE *link = NULL;
	link = Head;
	int8_t retval = 1;
	do{
		if(ElementNo == 1){
			if(link != NULL){
				retval = 1;
				break;
			}else{
				retval = -1;
			}
		}
		for(i = 0;i < (ElementNo - 1); i++){
			if(link->next != NULL){
			   link = link->next;
			}
			else {
				retval = -1;
				break;
			}
		}
//		if(retval != -1){
//			link = link->next;
//		}
		break;
	}while(0);
	if(retval == 1)
		printf("ElementNo %d is %d\n",ElementNo, link->val);
	else
		printf("Element Not Found");
//	printf("Element Found %d",link->val);
}

int8_t DeleteFirstNode(NODE **head){
	NODE *link = NULL;
	int8_t retval = 1;
	
	if(*head == NULL)
	{
		retval = -1;
		return retval;
	}
	link = (*head)->next;
	printf("Deleted Element from list %d\n",(*head)->val);
	free(*head);
	*head = link;
	return retval;
}

void DeletingSpecificNode(NODE **Head,int ElementNo){
	NODE *Temp = NULL, *Node = NULL;
	int8_t retval = 0, i = 0;
	do{
		if(ElementNo == 1){
			retval = DeleteFirstNode(Head);
			break;
		}
		Temp = *Head;
		for(i = 0; i < (ElementNo - 2);i++)
		{
			if(Temp->next == NULL)
			{
				retval = -1;
				break;
			}
			Temp = Temp->next;
		}
		if(Temp->next == NULL){
			retval = -1;
		}
		if(retval != -1){
			Node = Temp->next->next;
			printf("Deleted Node is %d at %d location\n", Temp->next->val, ElementNo);
			Temp->next = Node;
		}else{
			printf("Delete Node not found\n");
		}
	}while(0);
}

void PrintingLinkedList(NODE *Head)
{
	int i = 0;
	while(Head != NULL){
		i++;
		printf("%d loc has val %d\n",i,Head->val);
		Head = Head->next;
	}
}

int main(){
	NODE *Head = NULL;
	InsertingElements(&Head, 5,SUCCESSIVE_ELEMENT_ADD);
	InsertingElements(&Head, 4,SUCCESSIVE_ELEMENT_ADD);
	InsertingElements(&Head, 3,SUCCESSIVE_ELEMENT_ADD);
	InsertingElements(&Head, 2,SUCCESSIVE_ELEMENT_ADD);
	InsertingElements(&Head, 1,SUCCESSIVE_ELEMENT_ADD);
	PrintingLinkedList(Head);
	FindSpecificElementFrom_List(Head,4);	
	DeletingSpecificNode(&Head,1);
	PrintingLinkedList(Head);
}
