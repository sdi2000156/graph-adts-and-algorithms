#include <stdio.h>
#include <stdlib.h>
#include "SL.h"

int main(){

	List l=create();

	init(l,23);
	init(l,5);
	init(l,2);
	init(l,20);
	init(l,10);
	init(l,17);
	init(l,6);
	init(l,13);
	init(l,8);
	

	printf("\n\tSkip List 1\n\n");
	print(l);
	printf("\n");

	List l2=create();

	init(l2,24);
	init(l2,6);
	init(l2,3);
	init(l2,21);
	init(l2,11);
	init(l2,18);
	init(l2,7);
	init(l2,14);
	init(l2,9);
	

	printf("\n\tSkip List 2\n\n");
	print(l2);
	printf("\n");

	List l3=merge_lists1(l,l2);

	printf("\n\tMerge\n\n");
	print(l3);
	printf("\n");

	if(search(l3,8)!=NULL){
		printf("8 : found\n");
	}
	else{
		printf("Data NOT found\n");
	}

	if(search(l3,9)!=NULL){
		printf("Data found\n");
	}
	else{
		printf("9 : NOT found\n");
	}

	printf("\nDeleting 8\n");
	Remove(l3,8);

	printf("\n\tSkip List after\n\n");
	print(l3);
	printf("\n");

	return 0;
}