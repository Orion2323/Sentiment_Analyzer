#ifndef SENTIMENT_ANALYZER_SENTIMENT_ANALYZER_H
#define SENTIMENT_ANALYZER_SENTIMENT_ANALYZER_H

#include <iostream>
#include <map>
#include <set>

#include "Tweet.h"

class Sentiment_Analyzer {
private:
    char* trainFile;
    char* testFile;
    char* ansKey;
    char* outFile;

    std::map<DSString, int> classifier;
    std::map<Tweet, DSString> prediction_map;

    std::vector<Tweet> tweetList;
    std::vector<std::pair<DSString, DSString>> answers;
    std::vector<DSString> wrongTweets;
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

    /** read_training_file method
     *
     * Reads contents of training file
     */
    void read_training_file();

    /** make_classifier method
     *
     * Creates a map of DSStrings with assignment positive or negative values
     */
    void make_classifier();

    /** classifier_check method
     * Checks if DSString should go in classifier
     *
     * @param dstr DSString to be checked
     * @return bool determining if DSString should be included in classifier
     */
    bool classifier_check(DSString& dstr);

    /** reading_testing_file method
     *
     *  Reads contents of testing file
     */
    void read_testing_file();

    /** make_predictions method
     *
     * Make predictions from testing dataset
     *
     */
    void make_predictions();

    /** read_answer_key_file method
     *
     * Read contents of answer key file
     */
    void read_answer_key_file();

    /** accuracy_check method
     *
     * Calculate accuracy of sentiment analyzer program
     */
    void accuracy_check();

    /** print_classifier method
     *
     * Prints classifier to terminal
     */

    /** print_wrong_predictions method
     *
     * Prints the IDs of tweets sentiment analyzer predicted wrong
     */
    void print_wrong_predictions();
};

#endif //SENTIMENT_ANALYZER_SENTIMENT_ANALYZER_H