typedef struct list* List;
typedef struct list_node* ListNode;

/*creates an empty doubly linked list*/
List create();

ListNode createHeadNode(int );

ListNode createNode(int );

int get_data(ListNode m);

/*returns list size*/
int size(List list);

/*returns "1" if list is empty else returns "0" */
int isEmpty(List list);

/*returns first node of the list*/
ListNode getFirst(List list);

/*takes as second parametre data of a new node and adds it at the begginig 
of the list */     
void init(List list,int data);

/*takes as second parametre data of a node and removes it from the list */     
void Remove(List list,int data);

/*prints all nodes data*/
void print(List list);


int randLevel();

ListNode search(List list,int data);

List merge_lists1(List l1 ,List l2);

List merge_lists2(List l1 ,List l2);