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

bool Tweet::operator==(const Tweet& t) const {
    return (this->ID == t.ID);
}

bool Tweet::operator==(const DSString& dstr) const {
    return (this->ID == dstr);
}

bool Tweet::operator<(const Tweet& t) const {
    return (this->ID < t.ID);
}

bool Tweet::operator<(const DSString& dstr) const {
    return (this->ID < dstr);
}

bool Tweet::operator>(const Tweet& t) const {
    return (this->ID > t.ID);
}

bool Tweet::operator>(const DSString& dstr) const {
    return (this->ID > dstr);
}

DSString& Tweet::get_sentiment() {
    return this->sentiment;
}

void Tweet::set_sentiment(const DSString& sentiment) {
    this->sentiment = sentiment;
}

DSString& Tweet::get_ID() {
    return this->ID;
}

void Tweet::set_ID(const DSString& ID) {
    this->ID = ID;
}

DSString& Tweet::get_date() {
    return this->date;
}

void Tweet::set_date(const DSString& date) {
    this->date = date;
}

DSString& Tweet::get_username() {
    return this->username;
}

void Tweet::set_username(const DSString& username) {
    this->username = username;
}

DSString& Tweet::get_tweet() {
    return this->tweet;
}

void Tweet::set_tweet(const DSString& tweet) {
    this->tweet = tweet;
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

