#ifndef SENTIMENT_ANALYZER_DSSTRING_H
#define SENTIMENT_ANALYZER_DSSTRING_H

#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>

class DSString {
private:
    char* str;
public:
    /** Constructors
    *
    * first: default
    *
    * second:
    * @params: str: char pointer
    *
    * Third:
    * @param: str: string variable
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
    * Checks if DSString obj and other obj are the same
    *
    * first:
    * @param: str char pointer to compare
    * @return bool determining if DSString obj and char* are the same
    *
    * second:
    * @param: str string variable to compare
    * @return bool determining if DSString obj and string are the same
    *
    * Third:
    * @param: dstr DSString variable to compare
    * @return bool determining if both DSString objs are the same
    */
    bool operator==(const char* str) const;
    bool operator==(const std::string& str) const;
    bool operator==(const DSString& dstr) const;

    /**  Overloaded non equality methods
    * Checks if DSString obj and obj are NOT the same
    *
    * first:
    * @param: str char pointer to compare
    * @return bool determining if DSString obj and char* are NOT the same
    *
    * second:
    * @param: str string variable to compare
    * @return bool determining if DSString obj and string are NOT the same
    *
    * Third:
    * @param: dstr DSString variable to
    * @return bool determining if both DSString objs are NOT the same
    */
    bool operator!=(const char* str) const;
    bool operator!=(const std::string& str) const;
    bool operator!=(const DSString& dstr) const;

    /**  Overloaded less than methods
    * Checks if DSString obj is less than obj
    *
    * first:
    * @param: str char pointer to compare
    * @return bool determining if DSString obj is less than char*
    *
    * second:
    * @param: str string variable to compare
    * @return bool determining if DSString obj is less than string
    *
    * Third:
    * @param: dstr DSString variable to
    * @return bool determining if first DSString obj is less than second DSString obj
    */
    bool operator<(const char* str) const;
    bool operator<(const std::string& str) const;
    bool operator<(const DSString& dstr) const;

    /**  Overloaded greater than methods
    * Checks if DSString obj is greater than obj
    *
    * first:
    * @param: str char pointer to compare
    * @return bool determining if DSString obj is greater than char*
    *
    * second:
    * @param: str string variable to compare
    * @return bool determining if DSString obj is greater than string
    *
    * Third:
    * @param: dstr DSString variable to
    * @return bool determining if first DSString obj is greater than second DSString obj
    */
    bool operator>(const char* str) const;
    bool operator>(const std::string& str) const;
    bool operator>(const DSString& dstr) const;

    /** Overloaded subscript operator
     * Gets a char from DSString
     *
     * @param index integer for element user wants to access from DSString
     * @return reference to char
     */
    char& operator[](const int& index) const;

    /** Overloaded plus operator
     * Adds two DSString objs together
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
     * Gets size of DSString
     *
     * @return int holding size of DSString
     */
    int get_size() const;

    /** C-string method
     * Gets char* from DSString
     *
     *
     * @return char* holding contents of DSString
     */
    char* c_str() const;

    /** tokenize method
     * Tokenizes a DSString and return a vector of DSStrings
     *
     * @return vector of DSString consisting of subwords within DSString obj
     */
    std::vector<DSString> tokenize();

    /** lowercase method
     * Turns all chars in DSString into lowercase chars
     */
    void lowercase();

    /** string_cleaning method
     * Takes out all non-letter chars from DSString
     */
    void string_cleaning();

    bool wchar_check() const;

    /** Check if DSString is a number
     *
     * @return bool determining if DSString is a number
     */
    bool is_num() const;

    friend std::ostream& operator<<(std::ostream& inOF, const DSString& dstr);
};

#endif //SENTIMENT_ANALYZER_DSSTRING_H