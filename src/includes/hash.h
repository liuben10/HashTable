/*
 * hash.h
 *
 *  Created on: Jun 1, 2014
 *      Author: Benjamin
 */

#ifndef HASH_H_
#define HASH_H_


struct KVPair {
	int key;
	void * value;
};

struct Node {
	struct KVPair data;
	struct Node * next;
};

struct LinkedList {
	struct Node * hp;
	int size;
};

struct Hash {
	struct LinkedList * pairs;
	int hashsize;
};

struct Hash initialize();

int hash();

void insert(int key, int value, struct Hash * h);

struct LinkedList initll(void);

void push(int key, int value, struct LinkedList * ll);

int getsize(struct LinkedList * ll);

struct Node pop(struct LinkedList * ll);

struct LinkedList getlist(int key, struct Hash * h);

struct KVPair searchForEntry(int key, struct LinkedList * ll);

void printlist(struct LinkedList * ll);

void printhash(struct Hash * h);

void reverse(struct LinkedList * ll);

#endif /* HASH_H_ */
