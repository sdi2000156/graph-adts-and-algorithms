typedef struct list* List;
typedef struct list_node* ListNode;

/*creates an empty list*/
List createList();

int get_data(ListNode m);

/*returns list size*/
int size(List list);

/*returns "1" if list is empty else returns "0" */
int isEmpty(List list);

/*returns first node of the list*/
ListNode getFirst(List list);

// /*returns last node of the list*/
// ListNode getLast(List list);

// /*takes as second parametre data of a node and returns previous node*/       
// ListNode getPrev(List list,int data);

// /*takes as second parametre data of a node and returns next node*/            
// ListNode getNext(List list,int data);

/*takes as second parametre data of a new node , as third parametre data
of α node and adds the first node before the second*/       
void addBefore(List list,int z_data,int v_data);

// /*takes as second parametre data of a new node , as third parametre data
// of a node and adds the first node after the second*/  
// void addAfter(List list,int z_data,int v_data);

/*takes as second parametre data of a new node and adds it at the begginig 
of the list */     
void addFirst(List list,int data);

/*takes as second parametre data of a new node and adds it at the end of the list*/      
void addLast(List list,int data);

// /*takes as second parametre data of a node and removes it from the list */     
// void Remove(List list,int data);

/*prints all nodes data*/
void printList(List list);

