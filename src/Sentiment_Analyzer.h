#ifndef SENTIMENT_ANALYZER_SENTIMENT_ANALYZER_H
#define SENTIMENT_ANALYZER_SENTIMENT_ANALYZER_H

#include <iostream>
#include <vector>

#include "Tweet.h"

class Sentiment_Analyzer {
private:
    char* trainFile;
    char* testFile;
    char* ansKey;
    char* outFile;
public:
    explicit Sentiment_Analyzer();
    explicit Sentiment_Analyzer(char* trainFile, char* testFile, char* ansKey, char* outFile);

    void read_training_file();
};

#endif //SENTIMENT_ANALYZER_SENTIMENT_ANALYZER_H