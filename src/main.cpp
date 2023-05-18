#define CATCH_CONFIG_RUNNER

#include "test/catch.hpp"
#include "Sentiment_Analyzer.h"

using namespace std;

int main(int argc, char** argv) {
    // check number of program arguments
    if (argc > 1) {
        Sentiment_Analyzer p1(argv[1], argv[2], nullptr, nullptr);

        // training phase
        p1.read_training_file();
        p1.make_classifier();

        // testing phase
        p1.read_testing_file();

    } else {
        Catch::Session().run();
    }

    return 0;
}