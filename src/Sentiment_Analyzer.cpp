#include "Sentiment_Analyzer.h"

// default constructor
Sentiment_Analyzer::Sentiment_Analyzer() {
    this->trainFile = nullptr;
    this->testFile = nullptr;
    this->ansKey = nullptr;
    this->outFile = nullptr;
}

Sentiment_Analyzer::Sentiment_Analyzer(char* trainFile, char* testFile, char* ansKey, char* outFile) {
    this->trainFile = trainFile;
    this->testFile = testFile;
    this->ansKey = ansKey;
    this->outFile = outFile;
}

void Sentiment_Analyzer::read_training_file() {
    if (this->trainFile == nullptr) {
        std::cout << "No training file was passed!" << std::endl;
        return;
    }

    // open training file
    std::ifstream inFS(this->trainFile);
    if (inFS.is_open()) {
        char* headers = new char[256];
        char* sentiment = new char[4];
        char* ID = new char[12];
        char* date = new char[30];
        char* dummy = new char[10];
        char* username = new char[20];
        char* tweet = new char[500];

        inFS.getline(headers, 256, '\n');
        while(!inFS.eof()) {
            inFS.getline(sentiment, 4, ',');
            DSString senVal(sentiment);

            inFS.getline(ID, 12, ',');
            DSString idString(ID);

            inFS.getline(date, 30, ',');
            DSString dateString(date);

            inFS.getline(dummy, 10, ',');
            inFS.getline(username, 20, ',');
            DSString nameString(username);

            inFS.getline(tweet, 500, '\n');
            DSString tweetString(tweet);

            Tweet newTweet(senVal, idString, dateString, nameString, tweetString);
            std::cout << newTweet << std::endl;
        }

        delete[] headers;
        delete[] sentiment;
        delete[] ID;
        delete[] date;
        delete[] dummy;
        delete[] username;
        delete[] tweet;
    } else {
        std::cout << "No training file found!" << std::endl;
    }
}