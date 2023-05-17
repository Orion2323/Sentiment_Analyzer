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
    // check if char* is nullptr
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
        // iterate through file lines
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

            // create tweet object
            Tweet newTweet(senVal, idString, dateString, nameString, tweetString);
            this->tweetList.push_back(newTweet);
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

void Sentiment_Analyzer::make_classifier() {
    // iterate through tweet objects
    std::vector<int> errCnt(6, 0);

    for (Tweet& t : this->tweetList) {
        std::vector<DSString> tweetWords = t.get_tweet_words();

        // iterate through each word in tweet
        for (DSString& str : tweetWords) {
            // check if DSString size is less than 3
            if (str.get_size() < 4) {
                continue;
            }

            // check if DSString is a mention
            if (str[0] == '@') {
                continue;
            }

            // check if DSString is a website
            if (str[0] == 'h' && str[1] == 't' && str[3] == 'p') {
                continue;
            } else if (str[str.get_size()  - 3] == 'c' && str[str.get_size() - 2] == 'o' && str[str.get_size() - 1] == 'm') {
                continue;
            } else if (str[0] == 'w' && str[1] == 'w' && str[2] == 'w') {
                continue;
            }

            // check for wchars
            if (str.wchar_check()) {
                continue;
            }

            // check if DSString is a number
            if (str.is_num()) {
                continue;
            }

           // clean up DSString
            str.lowercase();
            str.string_cleaning();

            // check size of DSString
            if (str.get_size() < 4) {
                continue;
            }

            // check if DSString is a website
            if (str[0] == 'h' && str[1] == 't' && str[3] == 'p') {
                continue;
            } else if (str[str.get_size()  - 3] == 'c' && str[str.get_size() - 2] == 'o' && str[str.get_size() - 1] == 'm') {
                continue;
            } else if (str[0] == 'w' && str[1] == 'w' && str[2] == 'w') {
                continue;
            }

            // check if DSString is a number
            if (str.is_num()) {
                continue;
            }

            // check sentiment value of tweet
            int senVal = -1;
            if (t.get_sentiment() == "4") {
                senVal = 1;
            }

            // check if DSString already in classifier
            if (!this->classifier.count(str)) {
                this->classifier.insert({str, 0});
            }

            this->classifier[str] += senVal;
        }
    }

    // binerize words by value
    std::vector<DSString> delWords;
    std::map<DSString, int>::iterator it;
    for (it = this->classifier.begin(); it != this->classifier.end(); it++) {
        if (it->second > 0) {
            it->second = 1;
        } else if (it->second < 0) {
            it->second = -1;
        } else {
            delWords.push_back(it->first);
        }
    }

    // delete neutral words
    for (const DSString& str : delWords) {
        this->classifier.erase(str);
    }

    // print classifier
    for (std::pair<DSString,int> p : this->classifier) {
        if (p.first[0] == 'b') {
            std::cout << p.first << " " << p.second << std::endl;
        }
    }

    std::cout << this->classifier.size() << std::endl;
}