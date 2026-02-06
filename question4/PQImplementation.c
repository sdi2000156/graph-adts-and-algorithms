/* This code is from the book*/

#include <stdio.h>
#include <stdlib.h>
#include "PQInterface.h"

/* Now we give all the details of the functions */
/* declared in the interface file together with */
/* local private functions.                     */

void Initialize(PriorityQueue *PQ)
{
   PQ->Count=0;
   PQ->ItemList=NULL;
}

int Empty(PriorityQueue *PQ)
{
   return(PQ->Count==0);
}


int Full(PriorityQueue *PQ)
{
   return(PQ->Count==MAXCOUNT);
}

PQListNode *SortedInsert(PQItem Item, PQListNode *P)
{
   PQListNode *N;

   if ((P==NULL)||(Item >=P->NodeItem)){
      N=(PQListNode *)malloc(sizeof(PQListNode));
      N->NodeItem=Item;
      N->Link=P;
      return(N);
   } else {
      P->Link=SortedInsert(Item, P->Link);
      return(P);
   }
}


void Insert(PQItem Item, PriorityQueue *PQ)
{
   if (!Full(PQ)){
     PQ->Count++;
     PQ->ItemList=SortedInsert(Item, PQ->ItemList);
   }
}

PQItem Remove(PriorityQueue *PQ)
{
   PQItem temp;
   if (!Empty(PQ)){
     temp=PQ->ItemList->NodeItem;
     PQ->ItemList=PQ->ItemList->Link;
     PQ->Count--;
     return(temp);
   }
}

void PriorityQueueSort(SortingArray A){
	
   int i;
   PriorityQueue PQ;

   Initialize(&PQ);
   for (i=0; i<MAXCOUNT; ++i) Insert(A[i], &PQ);
   for (i=MAXCOUNT-1; i>=0; --i) A[i]=Remove(&PQ);
}