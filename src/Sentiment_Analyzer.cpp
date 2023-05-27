#include <iomanip>
#include "Sentiment_Analyzer.h"

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

    // check if file is open
    if (inFS.is_open()) {
        std::cout << "Reading training file..." << std::endl;
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

    inFS.close();
}

void Sentiment_Analyzer::make_classifier() {
    std::cout << "Making classifier..." << std::endl;
    // iterate through tweet objects
    for (Tweet& t : this->tweetList) {
        std::vector<DSString> tweetWords = t.get_tweet().tokenize();

        // iterate through each word in tweet
        for (DSString& str : tweetWords) {
            if (this->classifier_check(str)) {
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
    }

    // standardize sentiment of words
    std::vector<DSString> delWords;
    std::map<DSString, double>::iterator it;
    for (it = this->classifier.begin(); it != this->classifier.end(); it++) {
        if (it->second == 1) {
            it->second = 1;
        } else if (it->second > 1) {
            it->second = log2(it->second);
        } else if (it->second == -1) {
            it->second = -1;
        } else if (it->second < -1) {
            it->second = log2(-1 * it->second) * -1;
        } else {
            delWords.push_back(it->first);
        }
    }

    // delete neutral words
    for (const DSString& str : delWords) {
        this->classifier.erase(str);
    }

    // clear tweetList
    this->tweetList.clear();
}

bool Sentiment_Analyzer::classifier_check(DSString& dstr) {
    // check if DSString size is less than 3
    if (dstr.get_size() < 3) {
        return false;
    }

    // check if DSString is a mention
    if (dstr[0] == '@') {
        return false;
    }

    // check if DSString is a website
    if (dstr.get_size() > 3) {
        if (dstr[0] == 'h' && dstr[1] == 't' && dstr[3] == 'p') {
            return false;
        } else if (dstr[dstr.get_size()  - 3] == 'c' && dstr[dstr.get_size() - 2] == 'o' && dstr[dstr.get_size() - 1] == 'm') {
            return false;
        } else if (dstr[dstr.get_size()  - 4] == 'c' && dstr[dstr.get_size() - 3] == 'o' && dstr[dstr.get_size() - 2] == 'm' && dstr[dstr.get_size() - 1] == '.') {
            return false;
        } else if (dstr[0] == 'w' && dstr[1] == 'w' && dstr[2] == 'w') {
            return false;
        }
    }

    // check for wchars
    if (dstr.wchar_check()) {
        return false;
    }

    // check if DSString is a number
    if (dstr.is_num()) {
        return false;
    }

    // clean up DSString
    dstr.lowercase();
    dstr.string_cleaning();

    // check size of DSString
    if (dstr.get_size() < 3) {
        return false;
    }

    // check if DSString is a website
    if (dstr.get_size() > 3) {
        if (dstr[0] == 'h' && dstr[1] == 't' && dstr[3] == 'p') {
            return false;
        } else if (dstr[dstr.get_size()  - 3] == 'c' && dstr[dstr.get_size() - 2] == 'o' && dstr[dstr.get_size() - 1] == 'm') {
            return false;
        } else if (dstr[dstr.get_size()  - 4] == 'c' && dstr[dstr.get_size() - 3] == 'o' && dstr[dstr.get_size() - 2] == 'm' && dstr[dstr.get_size() - 1] == '.') {
            return false;
        } else if (dstr[0] == 'w' && dstr[1] == 'w' && dstr[2] == 'w') {
            return false;
        }
    }

    // check if DSString is a number
    if (dstr.is_num()) {
        return false;
    }

    return true;
}

void Sentiment_Analyzer::read_testing_file() {
    // check if testing file char* is null
    if (this->testFile == nullptr) {
        std::cout << "No testing file was passed!" << std::endl;
        return;
    }

    // check if testing file is open
    std::ifstream inFS(this->testFile);
    if (inFS.is_open()) {
        std::cout << "Reading testing file..." << std::endl;
        char* header = new char[256];
        char* ID = new char[12];
        char* date = new char[30];
        char* dummy = new char[10];
        char* username = new char[20];
        char* tweet = new char[500];

        // get headers and iterate through file lines
        inFS.getline(header, 256, '\n');
        while (!inFS.eof()) {
            inFS.getline(ID, 12, ',');
            DSString idString(ID);

            inFS.getline(date, 30, ',');
            DSString dateString(date);

            inFS.getline(dummy, 10, ',');

            inFS.getline(username, 20, ',');
            DSString userString(username);

            inFS.getline(tweet, 500, '\n');
            DSString tweetString(tweet);

            DSString dummy2("NULL");
            Tweet newTweet(dummy2, idString, dateString, userString, tweetString);

            // add Tweet obj to prediction map
            this->prediction_map.insert({newTweet, DSString("-1")});
        }

        delete[] header;
        delete[] ID;
        delete[] date;
        delete[] dummy;
        delete[] username;
        delete[] tweet;
    } else {
        std::cout << "No testing file found!" << std::endl;
    }

    inFS.close();
}

void Sentiment_Analyzer::make_predictions() {
    std::cout << "Making predictions..." << std::endl;

    // iterate through each tweet
    for (std::pair<Tweet,DSString> p : this->prediction_map) {
        std::vector<DSString> tweetWords = p.first.get_tweet().tokenize();

        // iterate through each word in tweet
        int sum = 0;
        for (DSString& dstr : tweetWords) {
            // clean up string and check if it exists in classifier
            if (this->classifier_check(dstr) && this->classifier.count(dstr)) {
                sum += this->classifier[dstr];
            }
        }

        // check if sum is positive or negative
        if (this->prediction_map.count(p.first)) {
            if (sum > 0) {
                this->prediction_map[p.first] = DSString("4");
            } else {
                this->prediction_map[p.first] = DSString("0");
            }
        }
    }
}

void Sentiment_Analyzer::read_answer_key_file() {
    // check if testing file char* is null
    if (this->ansKey == nullptr) {
        std::cout << "No answer key file was passed!" << std::endl;
        return;
    }

    // check if file is open
    std::ifstream inFS(this->ansKey);
    if (inFS.is_open()) {
        std::cout << "Reading answer key file..." << std::endl;

        char* headers = new char[256];
        char* sentiment = new char[4];
        char* ID = new char[12];

        inFS.getline(headers, 256, '\n');
        while (!inFS.eof()) {
            inFS.getline(sentiment, 4, ',');
            DSString sentimentString(sentiment);

            inFS.getline(ID, 12, '\n');
            DSString idString(ID);

            std::pair<DSString, DSString> newPair(idString, sentimentString);
            this->answers.push_back(newPair);
        }
    } else {
        std::cout << "No answer key file found!" << std::endl;
    }

    inFS.close();
}

void Sentiment_Analyzer::accuracy_check() {
    std::cout << "Calculating accuracy..." << std::endl;
    double correct = 0;

    for (const std::pair<DSString, DSString>& p : this->answers) {
        DSString dummy("NULL");
        Tweet twt(p.second, p.first, dummy, dummy, dummy);

        if (this->prediction_map.count(twt)) {
            if (this->prediction_map[twt] == p.second) {
                correct++;
            } else {
                this->wrongTweets.push_back(p.first);
            }
        }
    }

    float accuracy = correct/10000;
    this->print_wrong_predictions(accuracy);
}

void Sentiment_Analyzer::print_wrong_predictions(const float& accuracy) {
    // check if output file was passed in
    if (this->outFile == nullptr) {
        std::cout << "Output file path was not passed in!" << std::endl;
        return;
    }

    // check if file path is open
    std::ofstream inOF(this->outFile);
    if (inOF.is_open()) {
        // print accuracy
        //std::cout << "\n" << std::setw(3) << accuracy << std::endl;
        inOF << std::setw(3) << accuracy << std::endl;

        // print ids of wrongly predicted tweets
        for (const DSString& id: this->wrongTweets) {
            //std::cout << id << std::endl;
            inOF << id << std::endl;
        }
    } else {
        std::cout << "Output file not found!" << std::endl;
    }
}