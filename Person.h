#ifndef PERSON_H
#define PERSON_H

#include <stdlib.h>
#include "Error.h"

/* struct representing Person */
struct Person
{
    const char *m_name;
    int m_age;
    struct Person *m_next;  /* Pointer to the next element in the list */
};
typedef struct Person Person;

/* allocates Person on the heap and initializes its fields */
Error allocate_person(Person*, const char*, int, Person*);

/* inserts Person at the end of the list */
Error insert_person(Person*, Person*);

#endif /* PERSON_H */
