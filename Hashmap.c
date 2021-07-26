#include "Hashmap.h"
#include <string.h>

/* sample hash function (bad) */
Error hash(const char *string, int *index)
{
    if(!string || !index)
    {
        return ERROR_NULL;
    }

    int l_index = 0;
    for(size_t i = 0; i < strlen(string); ++i)
    {
        l_index = (0xC0CC & string[i] + 2137) % HASH_TABLE_SIZE;
    }
    *index = l_index;
    return ERROR_SUCCESS;
}

Error insert_list(Hashmap *hashMap, Person *person)
{
    if(!hashMap || !person)
    {
        return ERROR_NULL;
    }
    int index = 0;
    Error err = hash(person->m_name, &index);
    if(err != ERROR_SUCCESS)
    {
        return err;
    }
    err = insert_person(hashMap->m_table[index], person);
    if(err != ERROR_SUCCESS)
    {
        return err;
    }
    return ERROR_SUCCESS;
}