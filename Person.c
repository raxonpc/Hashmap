#include "Person.h"

#include <assert.h>
#include <string.h>

Error allocate_person(Person **dest, const char *name, int age, Person *next) {
    if (!name || !dest) /* Check for NULL */
    {
        assert(0 && "Passed null pointers to allocate_person");
        return ERROR_NULL;
    }
    *dest = malloc(sizeof(Person)); /* allocate Person on the heap */

    (*dest)->m_name = malloc(strlen(name) + 1); /* allocate name */
    strcpy((*dest)->m_name, name);              /* and copy it from the argument */

    (*dest)->m_age = age;
    (*dest)->m_next = next;
    return ERROR_SUCCESS;
}

Error insert_person(Person **head, Person *person) {
    if (!person) {
        return ERROR_NULL;
    }

    if(!*head)
    {
        *head = person;
        return ERROR_SUCCESS;
    }
    while ((*head)->m_next) {
        head = &(*head)->m_next;
    }
    (*head)->m_next = person;
    return ERROR_SUCCESS;
}

void display_list(Person *person)
{
    while(person)
    {
        printf("(%s, %d)", person->m_name, person->m_age);
        if(person->m_next)
        {
            printf(" -> ");
        }
        person = person->m_next;
    }
    putchar('\n');
}