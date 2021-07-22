#ifndef ERROR_H
#define ERROR_H

enum Error {
    ERROR_SUCCESS,
    ERROR_NULL,
    ERROR_OUT_OF_RANGE,
    MAX_ERROR,
};
typedef enum Error Error;

/* returns corresponding string of Error enum */
const char *get_error_string(Error);

#endif /* ERROR_H */
