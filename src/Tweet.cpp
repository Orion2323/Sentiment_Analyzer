#include "Tweet.h"

// default constructor
Tweet::Tweet() = default;

Tweet::Tweet(const DSString& sentiment, const DSString& ID, const DSString& date, const DSString& username, const DSString& tweet) {
    this->sentiment = sentiment;
    this->ID = ID;
    this->date = date;
    this->username = username;
    this->tweet = tweet;
}

DSString& Tweet::get_sentiment() {
    return this->sentiment;
}

DSString& Tweet::get_ID() {
    return this->ID;
}

DSString& Tweet::get_date() {
    return this->date;
}

DSString& Tweet::get_username() {
    return this->username;
}

DSString& Tweet::get_tweet() {
    return this->tweet;
}

std::vector<DSString> Tweet::get_tweet_words() {
    return this->tweet.tokenize();
}

std::ostream& operator<<(std::ostream& inOF, const Tweet& twt) {
    inOF << twt.sentiment << std::endl;
    inOF << twt.ID << std::endl;
    inOF << twt.date << std::endl;
    inOF << twt.username << std::endl;
    inOF << twt.tweet << std::endl;

    return inOF;
}

