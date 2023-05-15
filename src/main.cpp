#define CATCH_CONFIG_RUNNER

#include <iostream>

#include "test/catch.hpp"
#include "DSString.h"

using namespace std;

int main(int argc, char** argv) {
    Catch::Session().run();

    DSString dummy1("This is a string");
    DSString dummy2("This is another string");

    //cout << (dummy1 < dummy2) << endl;

    return 0;
}