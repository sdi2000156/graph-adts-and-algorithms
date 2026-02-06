/* This code is from the book*/

#define MAXCOUNT 10

typedef int PQItem;

typedef struct PQNodeTag {
           PQItem   NodeItem;
           struct PQNodeTag *Link;
        } PQListNode;

typedef struct {
           int Count;
           PQListNode *ItemList;
        } PriorityQueue;

typedef PQItem SortingArray[MAXCOUNT];
/* Note: MAXCOUNT is 10 */
