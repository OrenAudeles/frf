#ifndef DATATYPES_H_
#define DATATYPES_H_

#include <gc.h>
#include <stdio.h>
#include <stdbool.h>
#include "sglib.h"
#include "sds.h"


#define str_eq( a, b ) ( sdscmp( (a), (b) ) == 0)


typedef struct ilist {
    int i;
    struct ilist *next_ptr;
} iListType;

#define ILIST_COMPARATOR(e1, e2) (e1->i - e2->i)

SGLIB_DEFINE_SORTED_LIST_PROTOTYPES(iListType, ILIST_COMPARATOR, next_ptr)

#define slist_hash_size 32768

typedef struct slist
{
    sds s;
    size_t data;
    struct slist *next_ptr;
} sListType;

struct slist* alloc_slist();

unsigned int slist_hash_function(sListType *e);

#define SLIST_COMPARATOR(e1, e2) (sdscmp((e1->s), (e2->s) ))
SGLIB_DEFINE_SORTED_LIST_PROTOTYPES(sListType, SLIST_COMPARATOR, next_ptr)

SGLIB_DEFINE_HASHED_CONTAINER_PROTOTYPES(sListType, slist_hash_size, slist_hash_function )


#endif