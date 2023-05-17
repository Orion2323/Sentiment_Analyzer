#ifndef SENTIMENT_ANALYZER_TWEET_H
#define SENTIMENT_ANALYZER_TWEET_H

#include "DSString.h"

class Tweet {
private:
    DSString sentiment;
    DSString ID;
    DSString date;
    DSString username;
    DSString tweet;
public:
    /** Constructor
     *
     * first: default
     *
     * second:
     * @param sentiment DSString that holds sentiment value of tweet
     * @param ID DSString that holds ID of tweet
     * @param date DSString that holds date that tweet was written
     * @param username DSString that holds author of tweet
     * @param tweet DSString that holds tweet
     */
    explicit Tweet();
    explicit Tweet(const DSString& sentiment, const DSString& ID, const DSString& date, const DSString& username, const DSString& tweet);

    DSString& get_sentiment();
    DSString& get_ID();
    DSString& get_date();
    DSString& get_username();
    DSString& get_tweet();

    std::vector<DSString> get_tweet_words();

    friend std::ostream& operator<<(std::ostream& inOF, const Tweet& twt);
};


#endif //SENTIMENT_ANALYZER_TWEET_H
