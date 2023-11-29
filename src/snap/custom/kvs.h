//kvs.h
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define hash_size 200000

struct node {
	char key[100];
	char* value;
	struct node* next;
};	
typedef struct node node_t;

struct kvs{
	struct node* db[hash_size]; // database
	int items; // number of data
};
typedef struct kvs kvs_t; 


kvs_t* open_kvs();
int close_kvs(kvs_t* kvs); // free all memory space 
int set(kvs_t* kvs, const char* key, const char* value); // return -1 if failed.
char* get(kvs_t* kvs, const char* key); // return NULL if not found. 
int hash(const char *str);

int do_snapshot(kvs_t* kvs);
int do_recovery();