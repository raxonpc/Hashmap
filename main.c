#include "Hashmap.h"

Error scanPerson(Person *head, Person **out)
{
    Error err = ERROR_SUCCESS;
    printf("Enter your name: ");
    char buffer[256];
    scanf("%s", buffer);
    printf("Enter your age: ");
    int age = 0;
    scanf("%d", &age);
    err = allocate_person(out, buffer, age, NULL);
    if(err != ERROR_SUCCESS)
    {
        return err;
    }
    if(head)
    {
        err = insert_person(&head, *out);
    }
    return ERROR_SUCCESS;
}

int main() {
    Hashmap map = {0};
    for(;;)
    {
        Person *person = NULL;
        Error err = scanPerson(NULL, &person);
        if(err != ERROR_SUCCESS)
            return 1;
        err = insert_list(&map, person);
        if(err)
            return 1;
        err = display_map(&map);
        if(err)
            return 1;
    }


    return 0;
}
