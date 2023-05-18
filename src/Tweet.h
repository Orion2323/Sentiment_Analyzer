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

    /** Overloaded equality operator
     *
     * first:
     * @param t Tweet obj to compare
     * @return bool determining if both Tweet objs are the same
     *
     * second:
     * @param dstr DSString obj to compare
     * @return bool determining if Tweet and DSString objs are the same
     */
    bool operator==(const Tweet& t) const;
    bool operator==(const DSString& dstr) const;

    /** Overloaded less than operator
     *
     * first:
     * @param t Tweet obj to compare
     * @return bool determining if first Tweet obj is less than second Tweet obj
     *
     * second:
     * @param dstr DSString obj to compare
     * @return bool determining if Tweet obj is less than DSString obj
     */
    bool operator<(const Tweet& t) const;
    bool operator<(const DSString& dstr) const;

    /** Overloaded greater than operator
     *
     * first:
     * @param t Tweet obj to compare
     * @return bool determining if first Tweet obj is greater than second Tweet obj
     *
     * second:
     * @param dstr DSString obj to compare
     * @return bool determining if Tweet obj is greater than DSString obj
     */
    bool operator>(const Tweet& t) const;
    bool operator>(const DSString& dstr) const;

    /** sentiment getter and setter methods
     *
     * getter:
     * @returns reference to DSString holding sentiment value
     *
     * setter:
     * @param sentiment DSString holding a sentiment value
     */
    DSString& get_sentiment();
    void set_sentiment(const DSString& sentiment);

    /** ID getter and setter methods
     *
     * getter:
     * @returns reference to DSString holding ID
     *
     * setter:
     * @param sentiment DSString holding ID
     */
    DSString& get_ID();
    void set_ID(const DSString& ID);

    /** date getter and setter methods
     *
     * getter:
     * @returns reference to DSString holding date
     *
     * setter:
     * @param sentiment DSString holding date
     */
    DSString& get_date();
    void set_date(const DSString& date);

    /** username getter and setter methods
     *
     * getter:
     * @returns reference to DSString holding username
     *
     * setter:
     * @param sentiment DSString holding username
     */
    DSString& get_username();
    void set_username(const DSString& username);

    /** tweet getter and setter methods
     *
     * getter:
     * @returns reference to DSString holding tweet
     *
     * setter:
     * @param sentiment DSString holding tweet
     */
    DSString& get_tweet();
    void set_tweet(const DSString& tweet);

    friend std::ostream& operator<<(std::ostream& inOF, const Tweet& twt);
};


#endif //SENTIMENT_ANALYZER_TWEET_H
