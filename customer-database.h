#ifndef CUSTOMER_DATABASE_H
#define CUSTOMER_DATABASE_H
/*
 * customer-database.h
 */

#include "queue.h"
#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

struct sorder {
	char *bname;
	double price;
	double updatedbalance;
	struct sorder *next;
};
typedef struct sorder SOrder;

struct rorder {
	char *bname;
	double price;
	struct rorder *next;
};
typedef struct rorder ROrder;

struct customer {
	pthread_mutex_t queue_mutex;
	char *name;
	long id;
	double balance;
	char *address;
	char *state;
	char *zip;
	struct sorder *slist;
	struct sorder *slistback;
	struct rorder *rlist;
	struct rorder *rlistback;
};
typedef struct customer Customer;

struct customerdatabase {
	pthread_mutex_t revenuemutex;
	double revenue;
	int numCust;
	int dbSize;
	struct customer *dbarray;
};
typedef struct customerdatabase* CDB;

int binarySearch(CDB cdb, long key, int low, int high);

int customercomp(const void *a, const void *b);

int SLDestroy(SOrder *front);

int RLDestroy(ROrder *front);

CDB CDCreate();

int CDDestroy(CDB cdb);

int CDInsert(CDB cdb, struct customer *cust);

int CDUpdate(CDB cdb, QNode *order, int indx);

void PrintDB(CDB cdb);

void printCustomer(Customer *dude);

#endif

