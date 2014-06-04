/*
 ============================================================================
 Name        : HashTable.c
 Author      : benjaminliu
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "includes/hash.h"

int main(void) {

	testHash();
	return EXIT_SUCCESS;

}

void testHash() {
	struct Hash h = initialize(3);
		insert(4, 5, &h);
		insert(7, 8, &h);
		insert(0, 12, &h);
		insert(2, 19, &h);
		printf("key=%d, value=%d\n", 7, find(7, &h));
	//	insert(5, 4, &h);
}

void testList() {
	struct LinkedList ll = initll();
	push(6, 8, &ll);
	push(3, 4, &ll);
	push(4, 5, &ll);
	push(11, 18, &ll);
	printlist(&ll);
	reverse(&ll);
	printlist(&ll);
	printf("EXIT_SUCCESS, searchfor = %d", searchForEntry(6, &ll).key);
}
