#ifndef HASHMAP_H
#define HASHMAP_H

#define HASH_TABLE_SIZE 100

#include "Person.h"

struct Hashmap
{
    Person* m_table[HASH_TABLE_SIZE];
};
typedef struct Hashmap Hashmap;

/* insert Person list to the hash table */
Error insert_list(Hashmap*, Person*);

#endif /* HASHMAP_H */