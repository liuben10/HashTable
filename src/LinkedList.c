/*
 * LinkedList.c
 *
 *  Created on: Jun 3, 2014
 *      Author: Benjamin
 */

#include <stdio.h>
#include <stdlib.h>
#include "includes/hash.h"


struct LinkedList initll(void) {
	struct Node * root = (struct Node * ) malloc(sizeof(struct Node));
	root->next = 0;
	struct LinkedList foo;
	foo.hp = root;
	foo.size = 0;
	return foo;
}

int isEmptyLL(struct LinkedList * ll) {
	return ll->size == 0;
}
//
void push(int key, int value, struct LinkedList * ll) {
	struct KVPair kvp;
	kvp.key = key;
	kvp.value = (int *) value;
	struct Node * newnode = (struct Node *) malloc(sizeof(struct Node));
	newnode->data = kvp;
	newnode->next = ll->hp;
	ll->hp = newnode;
	ll->size += 1;
}

struct Node pop(struct LinkedList * ll) {
	if (isEmptyLL(ll)) {
		struct Node dud;
		printf("POP FROM EMPTY LIST");
		return dud;
	}
	struct Node root = *ll->hp;
	ll->size -= 1;
	*(ll->hp) = *(ll->hp)->next;
	return root;
}

struct KVPair searchForEntry(int key, struct LinkedList * ll) {
	struct Node iterator = *ll->hp;
	int cnt = 0;
	while (iterator.next != 0) {
		if (iterator.data.key == key) {
			return iterator.data;
		}
		iterator = *iterator.next;
		cnt += 1;
	}
	struct KVPair notfound;
	notfound.key = -1;
	notfound.value = -1;
	return notfound;
}

void reverse(struct LinkedList * ll) {
	struct Node prev;
	prev.next = 0;
	struct Node hp = *ll->hp;
	while(hp.next != 0) {
		struct Node tmp = hp;
		hp = *hp.next;
		*tmp.next = prev;
		prev = tmp;
	}
	*ll->hp = prev;
}


int getsize(struct LinkedList * ll) {
	return ll->size;
}
//
//
void printlist(struct LinkedList * ll) {
	struct Node iterator = *ll->hp;
	printf("{");
	while(iterator.next != 0) {
		printf("{k=%d, v=%d}, ", iterator.data.key, iterator.data.value);
		iterator = *iterator.next;
	}
	printf("}\n");
}
