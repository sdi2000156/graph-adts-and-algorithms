#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "SL.h"



#define NULLItem -1

static int r=0;/*for calling srand only one time*/

struct list {
	ListNode head;	
	ListNode tail;
	int size;  /*keep size of list in variable size for convenience*/
};

struct list_node {
	int data;
	ListNode next;		
	ListNode prev;
	int num;   /*number of levels*/
	ListNode *level;
};

List create(){

	if(!r){
		srand(time(NULL));
		r=1;
	}

	List list=malloc(sizeof(*list)); 
	list->size = 0;    /*an empty lists has size = 0*/
	list->head = createHeadNode(NULLItem);/*there is no node in an empty list so head and tail = NULL*/
	list->tail = NULL;
	return list;
}

ListNode createHeadNode(int data){

	ListNode new=malloc(sizeof(*new));
	new->data=data;
	new->num=-1;
	new->level=malloc(sizeof(List)*30);
	for(int i=0;i<30;i++){
		new->level[i]=NULL;
	}

	return new;
}

ListNode createNode(int data){

	ListNode new=malloc(sizeof(*new));
	new->data=data;
	new->num=-1;
	new->level=malloc(sizeof(List)*30);
	//initialize all levels to NULL
	for (int i = 0; i < 30; i++)
	{
		new->level[i] = NULL;
	}

	return new;
}

int get_data(ListNode m){

	return m->data;

}

int size(List list){
	return list->size;
}

int isEmpty(List list){
	/*list is empty when size is 0*/
	if(list->size==0){
		return 1;
	}
	else{
		return 0;
	}
	
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

void init(List list,int data){

	ListNode new=createNode(data);
	ListNode current = list->head->next;
	int counter = 0;
	ListNode temp_search;
	int tmp = 0;

	if(isEmpty(list)){
		list->head->next = new;
		list->tail = new;
		new->prev = list->head;
		new->next = NULL;
		list->size++;
	}
	else{
		list->size++;
		ListNode swap;
		while (current != NULL){
			if (current->data >= new->data){
				// insert new node before current
				if (counter == 0){
					// if the new node is the first node of the list
					new->prev = list->head;
					new->next = current;
					list->head->next = new;
					current->prev = new;
					break;
				}
				else{
					// if the new node is not the first node of the list
					new->prev = current->prev;
					new->next = current;
					current->prev->next = new;
					current->prev = new;
					break;
				}
			}
			current = current->next;
			counter++;
		}
		// if the new node is the last node of the list
		if (current==NULL){
			new->prev = list->tail;
			list->tail->next = new;
			list->tail = new;
			new->next = NULL;
		}
	}

	/*Find the node that its data is bigger than the new node and its 
	prev node data is smaller than the new node*/

	/*Randomization : while randLevel returns 1 keep adding levels to node*/
	int i=0;
	while(randLevel() && i<29){  /*up to 30 levels*/
		new->num++;
		/*searchig for the first node with the same level as the new node*/
		int flag=0;
		current=new->next;
		while(current!=NULL){
			if(current->num>=new->num ){
				flag=1;
				new->level[new->num]=current;
				list->head->level[new->num]=new;
				break;
			}
			current = current->next;
		}
		if(flag==0){
			//no node with the same level as the new node
			if(new->num>list->head->num){
				list->head->num=new->num;
			}
			if(list->head->level[new->num]==NULL ){	//slot is empty
				list->head->level[new->num]=new;
			}
			else{    //slot is not empty
				new->num--;
				break;
			}
		}
		i++;
	}

}

int randLevel(){

	/*50% posibility for randLevel to return 1 or 0*/
	if(rand()%2==0){
		return 1;
	}
	else{
		return 0;
	}

}

//getting index of the node that its data is smaller than the data we are searching for
int skip(ListNode node, int data){
	
	int result = 0;
	for (int i=0;i<node->num;i++){	
		// if the node's level is not null and its data is smaller than the data we are searching for
		if (node->level[i]!=NULL && node->level[i]->data <=data){
			result = i;
		}
	}
	return result;
}

ListNode search(List list,int data){

	if(isEmpty(list)){ /*check if list is empty*/
		printf("ERROR list is empty.\n");
	}
	
	ListNode current=list->head->next;

	while(current!=NULL){
		if(current->data==data){
			return current;
		}

		int skip_index=skip(current,data);
		if(skip_index!=0){
			current=current->level[skip_index];
		}
		else{
		current=current->next;
		}
	}

	return NULL;

}

void Remove(List list,int data){

	if(isEmpty(list)){   /*check if list is empty*/
		printf("ERROR list is empty");
		return;
	}
	else{
		ListNode node=list->head->next;
		int counter=0;
		while(counter != list->size){
			if(node->data == data){
				if(list->size == 1){  /*if its the only node*/
					list->size =0;
					list->head = createHeadNode(NULLItem);
					list->tail = NULL;
					free(node);
					return;
				}
				else if(node->prev == list->head){  /*if its the first node*/
					if(list->head->num==node->num){
						int i=list->head->num;
						for(i;i>=0;i--){
							if(node->level[i]==NULL){
								list->head->num--;
							}
							list->head->level[i]=node->level[i];
						}
					}
					list->head->next = node->next;
					node->next->prev = list->head;
					list->size--;
					free(node);
					return;
				}
				else if(node->next == NULL){   /*if its the last node*/
					int i=list->head->num;
					while(list->head->level[i]==node){
						list->head->num--;
						i--;
					}
					list->tail = node->prev;
					node->prev->next = NULL;
					list->size--;
					free(node);
					return;
				}
				else{
					for(int i=node->num;i>0;i--){
						if(node->level[i]==NULL){
							list->head->num--;
						}
						list->head->level[i]=node->level[i];
					}
					node->prev->next = node->next;
					node->next->prev = node->prev;
					list->size--;
					free(node);
					return;
				}
			}
			node=node->next;
			counter++;
		}
	}
	printf("coudnt find node.\n");
	return;
}

void print(List list){

	if(isEmpty(list)){ /*check if list is empty*/
		printf("List is empty.\n");
	}
	
	ListNode current=list->head;

	while(current!=NULL){
		printf("NumerOfLevels:%d , ",current->num+1);
		if(current->level!=NULL){
			for(int i=current->num+1;i>=0;i--){
				printf("%d-->",current->data);
			}
			printf("\n");
		}
		else{
			printf("%d-->",current->data);
		}
		current = current->next;
	}

}


List merge_lists1(List l1 ,List l2){

    List result=create();
    ListNode current1=l1->head->next;
    ListNode current2=l2->head->next;

    while(current1!=NULL || current2!=NULL){
        if(current1!=NULL && current1->data<current2->data){
            init(result,current1->data);
            current1=current1->next;
        }
        else{
            if(current2!=NULL){
				init(result,current2->data);
				current2=current2->next;
            }
        }
    }
    return result;
}

List merge_lists2(List l1,List l2){

	int levelCap=30; /*up to 30 levels*/
	ListNode update[levelCap];
	int unflipped=1;


	List l3=create();
	l3->size=(l1->size > l2->size) ? l1->size : l2->size;

	ListNode current1=l1->head->next;
    ListNode current2=l2->head->next;

	while(current1!=NULL && current2!=NULL){

		int key1=current1->data;
		int key2=current2->data;

		if (key1 > key2){
            ListNode tempNode=current1;
            current1=current2;
            current2=tempNode;
            
            int tempKey=key1;
            key1=key2;
            key2=tempKey;
            
            unflipped=!unflipped;
        }
		int lvl=1;
		while (lvl<=l3->size && current1->level[lvl]!=NULL && current1->level[lvl]->data<=key2) {
            update[lvl]=current1;
            lvl++;
        }
        lvl--;

		ListNode x=current1->level[lvl];

		for (int i=lvl; i>=1; i--){
            while (x->level[i]!=NULL && x->level[i]->data<=key2){
                x = x->level[i];
            }
            update[i]=x;
        }
		if(x!=NULL){
			current1->level[lvl]=x->level[lvl];
		}
        x=x->level[lvl];
		if(key2==x->data) {
            if(unflipped){
                x->data=current2->level[0]->data;
            }
            
            ListNode y=current2->level[0];
            for (int i=1; i<=y->num; i++) {
                current2->level[i]=y->level[i];
            }
            
            free(y);
        }
	}	
	List leftover=(current2->level[0]==NULL) ? l1 : l2;
	for (int i=1; i<=leftover->size; i++) {
        update[i]->level[i]=leftover->head->level[i];
    }
    
    for (int i=leftover->size+1; i<=l3->size; i++){
        update[i]->level[i] = NULL;
    }
    
    while (l3->head->level[l3->size]==NULL && l3->size>1){
        l3->size--;
    }
    
    free(l1);
    free(l2);
    
    return l3;

}