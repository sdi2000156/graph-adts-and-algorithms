#include <stdlib.h>
#include <stdio.h>
#include "List.h"

struct list {
	ListNode head;	
	int size;  /*keep size of list in variable size for convenience*/
};

struct list_node {
	int data;
	ListNode next;		
};

List createList(){
	List list=malloc(sizeof(*list)); 
	list->size = 0;    /*an empty lists has size = 0*/
	list->head = NULL;/*there is no node in an empty list so head = NULL*/
	return list;
}

int get_data(ListNode m){

	return m->data;

}

int size(List list){
	return list->size;
}

int isEmpty(List list){
	/*list is empty when head = NULL*/
	
	return (list->head==NULL);
 
}


ListNode getFirst(List list){
	if (isEmpty(list)){
		printf("\nList is empty.\n");
		return NULL;
	}
	else{
		return list->head;
	}
}

// ListNode getLast(List list){
// 	if (isEmpty(list)){
// 		printf("\nList is empty.\n");
// 		return NULL;
// 	}
// 	else{
// 		return list->tail;
// 	}
// }

// ListNode getPrev(List list,int data){ 
// 	ListNode current = list->tail; /*starting from the end of the list*/
// 	if(list->size == 1){
// 		printf("There is only one node in the list.\n");
// 		return NULL;
// 	}
// 	while(current->prev != NULL){   /*we may search till the end*/
// 		if(current->data == data){
// 			return current->prev;
// 		}
// 		current= current->prev;
// 	}
// 	printf("Coudnt find previous node.\n");
// 	return NULL; /*coudnt find the node ,return NULL*/
// }

// ListNode getNext(List list,int data){
// 	ListNode current=list->head;
// 	if(list->size == 1){
// 		printf("There is only one node in the list.\n");
// 		return NULL;
// 	}
// 	while(current->next != NULL) {   /*we may search till the end*/
// 		if(current->data == data){
// 			return current->next;
// 		}
// 		current = current->next;
// 	}
// 	printf("Coudnt find next node.\n");
// 	return NULL; /*coudnt find the node ,return NULL*/
// }

// void addBefore(List list,int z_data,int v_data){
// 	if (isEmpty(list)){   /*check if lists is empty*/
// 		printf("ERROR list is empty.\n");
// 		return;
// 	}
// 	else{
// 		ListNode z=malloc(sizeof(z));
// 		list->size++;
// 		z->data = z_data;
// 		ListNode v=list->tail; /*start from the end of the lists*/
// 		int counter=0;
// 		while(counter!=list->size){  /*we may search till the end of the list*/
// 			if(v->data == v_data){
// 				if(size(list)==1 || v->prev == NULL){
// 					list->head = z;
// 					z->prev = NULL;
// 					z->next = v;
// 					v->prev = z;
// 					return;
// 				}
// 				else{
// 					ListNode temp = v->prev;
// 					v->prev = z;
// 					z->next = v;
// 					z->prev = temp;
// 					temp->next = z;
// 					return;
// 				}
// 			}
// 			v=v->prev;
// 			counter++;
// 		}
// 	}
// }

// void addAfter(List list,int z_data,int v_data){
// 	if (isEmpty(list)){   /*check if lists is empty*/
// 		printf("ERROR list is empty.\n");
// 		return;
// 	}
// 	else{
// 		ListNode z=malloc(sizeof(z));
// 		list->size++;
// 		z->data = z_data;
// 		ListNode v=list->head; 
// 		int counter=0;
// 		while(counter!=size(list)){  /*we may search till the end of the list*/
// 			if(v->data == v_data){
// 				if(size(list)==1 || v->next == NULL ){ /*if v is the only node of the list*/
// 					list->tail = z;
// 					z->prev = v;
// 					z->next = NULL;
// 					v->next = z;
// 					return;
// 				}
// 				else{
// 					ListNode temp = v->next;
// 					v->next = z;
// 					z->next = temp;
// 					z->prev = v;
// 					temp->prev = z;
// 					return;
// 				}
// 			}
// 			v=v->next;
// 			counter++;
// 		}
// 	}
// }

void addFirst(List list,int data){

	/*create edge*/
	ListNode new=malloc(sizeof(new));
	new->data=data;

	list->size++;
	if(isEmpty(list)){
		list->head = new;
		new->next = NULL;
		
	}
	else{
		ListNode temp=list->head;
		list->head = new;
		new->next = temp;
	}
}

// void Remove(List list,int data){
// 	if(isEmpty(list)){   /*check if list is empty*/
// 		printf("ERROR list is empty");
// 		return;
// 	}
// 	else{
// 		ListNode node=list->head;
// 		int counter=0;
// 		while(counter != list->size){
// 			if(node->data == data){
// 				if(list->size == 1){  /*if its the only node*/
// 					list->size =0;
// 					list->head = NULL;
// 					list->tail = NULL;
// 					free(node);
// 					return;
// 				}
// 				else if(node->prev == NULL){  /*if its the first node*/
// 					list->head = node->next;
// 					node->next->prev = NULL;
// 					list->size--;
// 					free(node);
// 					return;
// 				}
// 				else if(node->next == NULL){   /*if its the last node*/
// 					list->tail = node->prev;
// 					node->prev->next = NULL;
// 					list->size--;
// 					free(node);
// 					return;
// 				}
// 				else{
// 					node->prev->next = node->next;
// 					node->next->prev = node->prev;
// 					list->size--;
// 					free(node);
// 					return;
// 				}
// 			}
// 			node=node->next;
// 			counter++;
// 		}
// 	}
// 	printf("coudnt find node.\n");
// 	return;
// }

void printList(List list){
	if(isEmpty(list)){ /*check if list is empty*/
		printf("No edges.\n");
	}
	ListNode current=list->head;
	int counter = 0;
	while(counter!=list->size){
		if(counter == list->size-1){
			printf("%d",current->data);
			
		}
		else{
			printf("%d<---",current->data);
		}
		current = current->next;
		counter++;
	}
	printf("\n");
}