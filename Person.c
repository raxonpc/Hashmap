#include "Person.h"

#include <assert.h>
#include <string.h>

Error allocate_person(Person *dest, const char *name, int age, Person *next) {
    if (!name || !dest) /* Check for NULL */
    {
        assert(0 && "Passed null pointers to allocate_person");
        return ERROR_NULL;
    }
    dest = malloc(sizeof(Person)); /* allocate Person on the heap */

    dest->m_name = malloc(strlen(name) + 1); /* allocate name */
    strcpy(dest->m_name, name);              /* and copy it from the argument */

    dest->m_age = age;
    dest->m_next = next;
    return ERROR_SUCCESS;
}

Error insert_person(Person *head, Person *person) {
    if (!head || !person) {
        return ERROR_NULL;
    }

    while (head->m_next) {
        head = head->m_next;
    }
    head->m_next = person;
    return ERROR_SUCCESS;
}
