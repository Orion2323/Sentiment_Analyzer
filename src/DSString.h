#ifndef SENTIMENT_ANALYZER_DSSTRING_H
#define SENTIMENT_ANALYZER_DSSTRING_H

#include <iostream>
#include <cstring>
#include <fstream>

class DSString {
private:
    char* str;
public:
    /**  Constructors
    *
    *   first: default
    *
    *   second:
    *   @params: str: char pointer
    *
    *   Third:
    *   @param: str: string variable
    */
    explicit DSString();
    explicit DSString(const char* str);
    explicit DSString(const std::string& str);

    // rule of 3
    /** Destructor
     * Ensures dynamic allocated memory is deallocated properly
     */
    ~DSString();

    /** Copy constructor
     * Creates a constructor from another DSString obj
     *
     * @param dstr source DSString
     */
    DSString(const DSString& dstr);

    /** Assignment operator
     * Sets a DSString equal to another DSString
     *
     * @param dstr source DSString
     * @return reference to new DSString obj
     */
    DSString& operator=(const DSString& dstr);

    /**  Overloaded equality methods
    *   Returns a boolean if current DSString exactly like parameter variable
    *
    *   first:
    *   @param: str char pointer to compare
    *
    *   second:
    *   @param: str string varible to compare
    *
    *   Third:
    *   @param: dstr DSString variable to compare
    */
    bool operator==(const char* str) const;
    bool operator==(const std::string& str) const;
    bool operator==(const DSString& dstr) const;

    /**  Overloaded non equality methods
    *   Returns a boolean if current DSString is not exactly like parameter variable
    *
    *   first:
    *   @param: str char pointer to compare
    *
    *   second:
    *   @param: str string varible to compare
    *
    *   Third:
    *   @param: dstr DSString variable to compare
    */
    bool operator!=(const char* str) const;
    bool operator!=(const std::string& str) const;
    bool operator!=(const DSString& dstr) const;

    /**  Overloaded less than methods
    *   Returns a boolean if current DSString is less than parameter variable
    *
    *   first:
    *   @param: str char pointer to compare
    *
    *   second:
    *   @param: str string varible to compare
    *
    *   Third:
    *   @param: dstr DSString variable to compare
    */
    bool operator<(const char* str) const;
    bool operator<(const std::string& str) const;
    bool operator<(const DSString& dstr) const;

    /**  Overloaded greater than methods
    *   Returns a boolean if current DSString is greater than parameter variable
    *
    *   first:
    *   @param: str char pointer to compare
    *
    *   second:
    *   @param: str string varible to compare
    *
    *   Third:
    *   @param: dstr DSString variable to compare
    */
    bool operator>(const char* str) const;
    bool operator>(const std::string& str) const;
    bool operator>(const DSString& dstr) const;

    /** Overloaded subscript operator
     * Returns a char from the DSString
     *
     * @param index integer for element user wants to access from DSString
     * @return reference to char
     */
    char& operator[](const int& index) const;

    /** Overloaded plus operator
     * Returns a new DSString that has been merged with another
     *
     * @param dstr secondary DSString
     * @return DSString that holds merged char*
     */
    DSString operator+(const DSString& dstr);

    /** Substring method
     * Creates a sub-DSString from DSString obj
     *
     * @param start starting index of sub-DSString
     * @param numChars length of sub-DSString
     * @return sub-DSString obj
     */
    DSString substr(const int& start, const int& numChars);

    /** Get Size method
     * Returns size of DSString
     *
     * @return int holding size of DSString
     */
    int getSize() const;

    /** C-string method
     * Gets char* from DSString
     *
     *
     * @return char* holding contents of DSString
     */
    char* c_str() const;

    friend std::ostream& operator<<(std::ostream& inOF, const DSString& dstr);
};

#endif //SENTIMENT_ANALYZER_DSSTRING_H