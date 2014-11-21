#ifndef CONSUMER_DATABASE_H
#define CONSUMER_DATABASE_H
/*
 * consumer-database.h
 */

#include <stdlib.h>
#include <errno.h>
#include <malloc.h>
#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

struct consumer_struct {
	char *category;
	pthread_mutex_t mutex;
	pthread_cond_t empty;
	pthread_cond_t full;
	struct queue *q;
};
typedef struct consumer_struct ConsumerStruct;

struct consumer_struct_array {
	int numCons;
	int size;
	ConsumerStruct *consumerdata;
};
typedef struct consumer_struct_array* CSA;

//int binarySearch(CSA csa, char *key, int low, int high);

int consumercomp(const void *a, const void *b);

CSA CSACreate();

int CSADestroy(CSA csa);

int CSAInsert(CSA csa, char *category);

#endif