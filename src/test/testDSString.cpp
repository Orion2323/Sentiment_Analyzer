#include "catch.hpp"
#include "../DSString.h"

TEST_CASE("DSString class", "[DSString]") {
    DSString test[10];

    test[0] = DSString("This is a string");
    test[1] = DSString("This is another string");
    test[2] = DSString();

    char* str1 = "This is a c_string";
    test[3] = DSString(str1);

    char* str2 = "This is another c_string";
    test[4] = DSString(str2);

    test[5] = DSString(test[0]);
    test[6] = DSString(test[5]);
    test[7] = DSString("Yet another string");
    test[8] = DSString(test[7]);
    test[9] = DSString(test[8]);

    SECTION("Equality operator== & Non Equality operator!=") {
        REQUIRE(test[0] == "This is a string");
        REQUIRE(test[1] == "This is another string");

        DSString dummy = DSString();
        REQUIRE(test[2] == dummy);

        REQUIRE(test[3] != test[4]);

        REQUIRE(test[5] == "This is a string");

        DSString dummy2("This is a string");
        REQUIRE(test[6] == dummy2);

        REQUIRE(test[9] != "Yet another strin");

        char* str3 = "Yet another string";
        REQUIRE(test[8] == str3);

        REQUIRE(test[8] == test[7]);
        REQUIRE(test[7] == test[9]);
    }

    SECTION("Greater than operator> & Less than Operator<") {
        REQUIRE(test[1] > test[0]);

        REQUIRE(test[1] > test[2]);

        REQUIRE(test[3] < test[4]);
        REQUIRE((test[0] > test[6]) == 0);

        REQUIRE((test[7] < test[9]) == 0);

        DSString dummy = DSString();
        REQUIRE((test[2] < dummy) == 0);

        REQUIRE(test[0] < test[1]);

        DSString dummy2("1");
        DSString dummy3("2");
        REQUIRE(dummy2 < dummy3);

        REQUIRE(test[7] > "Apple");
        REQUIRE((test[8] < test[9]) == 0);
    }
}