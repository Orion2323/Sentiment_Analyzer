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

    SECTION("Subscript operator[]") {
        DSString dummy1("DSString");

        REQUIRE(dummy1[0] == 'D');
        REQUIRE(dummy1[2] == 'S');
        REQUIRE(dummy1[dummy1.getSize() - 1] == 'g');
        REQUIRE(dummy1[4] == 'r');
        REQUIRE(dummy1[5] == 'i');

        DSString dummy2(" ");
        REQUIRE(dummy2[0] == ' ');

        DSString dummy3("A D S S T R I N G");
        REQUIRE(dummy3[1] == ' ');
        REQUIRE(dummy3[dummy3.getSize() - 2] == ' ');
        REQUIRE(dummy3[dummy3.getSize() - 5] == 'I');
        REQUIRE(dummy3[6] == 'S');
    }

    SECTION("Plus operator+ & substr() method") {
        DSString dummy1 = test[0].substr(0, 4);
        DSString dummy2 = test[0].substr(5, 2);
        DSString dummy3 = test[0].substr(10, 6);

        DSString dummy4("string");

        REQUIRE(dummy1 == "This");
        REQUIRE(dummy2 == "is");
        REQUIRE(dummy3 == dummy4);

        DSString dummy5;
        REQUIRE(dummy5 == nullptr);

        DSString dummy6("     A DSString");
        DSString dummy7 = dummy6.substr(0,5);
        DSString dummy8 = dummy6.substr(5, 10);

        REQUIRE(dummy7 == "     ");
        REQUIRE(dummy8 == "A DSString");

        DSString dummy9(test[7]);
        REQUIRE(dummy9.substr(0, 3) == "Yet");
        REQUIRE(dummy9.substr(0,0) == "");
        REQUIRE(dummy9.substr(4, 7) == "another");
        REQUIRE(dummy9.substr(12, 6) == "string");
    }
}