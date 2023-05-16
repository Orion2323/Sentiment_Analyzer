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

DSString& Tweet::getSentiment() {
    return this->sentiment;
}

DSString& Tweet::getID() {
    return this->ID;
}

DSString& Tweet::getDate() {
    return this->date;
}

DSString& Tweet::getUsername() {
    return this->username;
}

DSString& Tweet::getTweet() {
    return this->tweet;
}

std::ostream& operator<<(std::ostream& inOF, const Tweet& twt) {
    inOF << twt.sentiment << std::endl;
    inOF << twt.ID << std::endl;
    inOF << twt.date << std::endl;
    inOF << twt.username << std::endl;
    inOF << twt.tweet << std::endl;

    return inOF;
}

