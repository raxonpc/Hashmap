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
            insert_person(&head, &next);

            THEN("It should be added at the end of list") {
                REQUIRE(*head.m_next == next);
            }
        }
    }
}