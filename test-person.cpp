#include "catch_amalgamated.hpp"

extern "C" {
#include "Person.h"
}

bool operator==(const Person& person1, const Person& person2) {
    return !strcmp(person1.m_name, person2.m_name) &&
           person1.m_age == person2.m_age && person1.m_next == person2.m_next;
}

SCENARIO("Should insert Person at the end of the list", "[person][insert]") {
    GIVEN("A single element list") {
        Person head{"Szymon", 17, nullptr};

        WHEN("Inserting another Person") {
            Person next{"Linus", 30, nullptr};
            auto err = insert_person(&head, &next);

            THEN("It should be added at the end of list") {
                REQUIRE(err == ERROR_SUCCESS);
                REQUIRE(*head.m_next == next);
            }
        }
    }
}

SCENARIO("Should return ERROR_NULL when inserting nullptr", "[person][insert][error]")
{
    GIVEN("A Person nullptr")
    {       
        Person* head = nullptr;

        WHEN("Inserting Person")
        {
            Person next{"Linus", 30, nullptr};
            auto err = insert_person(head, &next);
            
            THEN("It should return ERROR_NULL")
            {
                REQUIRE(err == ERROR_NULL);
            }
        }
    }

    GIVEN("A single element list")
    {
        Person head{ "Szymon", 17, nullptr};

        WHEN("Inserting nullptr")
        {
            Person* next = nullptr;

            auto err = insert_person(&head, next);

            THEN("It should return ERROR_NULL")
            {
                REQUIRE(err == ERROR_NULL);
            }
        }
    }
}