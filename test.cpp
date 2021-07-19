#include "catch_amalgamated.hpp"
#include <unordered_map>

extern "C"
{
    #include "Error.h"
}

static std::unordered_map<Error, std::string> errorStrings
{
    { ERROR_SUCCESS, "success"}, { ERROR_NULL, "null_error"},
    { ERROR_OUT_OF_RANGE, "out_of_range_error"}
};


SCENARIO("Should convert Error to string", "[error][string]")
{
    GIVEN("An error enum")
    {
        auto error = GENERATE(ERROR_SUCCESS, 
                              ERROR_NULL,
                              ERROR_OUT_OF_RANGE);
        WHEN("get_error_string is called on it")
        {
            std::string string = get_error_string(error);

            THEN("It should return the corresponding string")
            {
                REQUIRE(string == errorStrings.at(error));
            }
        }
    }
}

