#include "Error.h"
#include <stdio.h>

int main()
{
    printf("Error test: %s\n", get_error_string(ERROR_OUT_OF_RANGE));
    return 0;
}
