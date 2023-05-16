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
    /** Constructors
     *
     * first: default
     *
     * second:
     * @param: trainFile char* holding training file path
     * @param testFile char* holding testing file path
     * @param ansKey char* holding answer key path
     * @param outFile char* holding output file path
     */
    explicit Sentiment_Analyzer();
    explicit Sentiment_Analyzer(char* trainFile, char* testFile, char* ansKey, char* outFile);

    /** Reading training file method
     * 
     * Reads contents of training file
     */
    void read_training_file();
};

#endif //SENTIMENT_ANALYZER_SENTIMENT_ANALYZER_H