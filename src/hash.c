/*
 * hash.c
 *
 *  Created on: Jun 1, 2014
 *      Author: Benjamin
 */
#include <stdlib.h>
#include <stdio.h>
#include "includes/hash.h"

struct Hash initialize(int hashsize) {
	struct Hash h;
	int i;
	h.hashsize = hashsize;
	h.pairs = (struct LinkedList *) malloc(hashsize * sizeof(struct LinkedList));
	for(i = 0; i < hashsize; i++) {
		*(h.pairs + i) = initll();
	}
	return h;
}

void insert(int key, int value, struct Hash * h) {
	int res = hash(key, h);
	struct LinkedList preexisting = getlist(key, h);
	push(key, value, &preexisting);
	*(h->pairs + res) = preexisting;
}

void * find(int key, struct Hash * h) {
	struct LinkedList found = getlist(key, h);
	return searchForEntry(key, &found).value;
}



void printhash(struct Hash * h) {
	int i;
	for(i = 0; i < h->hashsize; i++) {
		printlist((h->pairs + i));
	}
}

struct LinkedList getlist(int key, struct Hash * h) {
	int hashval = hash(key, h);
	return *(h->pairs + hashval);
}

int prehash(void * obj) {
	return sizeof(obj);
}

int hash(int key,  struct Hash * h ) {
	return (key % h->hashsize);
}
