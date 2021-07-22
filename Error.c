#include "Error.h"

/* array with string representation of Error enum values */
static const char *errorStrings[] = {"success", "null_error",
                                     "out_of_range_error"};

const char *get_error_string(Error error) {
    if (error < 0 || error >= MAX_ERROR) {
        return "invalid_error_value";
    }
    return errorStrings[error];
}
