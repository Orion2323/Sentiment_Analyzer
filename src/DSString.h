#include <iostream>
#include <cstring>

class DSString {
private:
    char* str;
public:
    explicit DSString();
    explicit DSString(const char* str);
    explicit DSString(const std::string& str);

    // rule of 3
    ~DSString();
    DSString(const DSString& dstr);
    DSString& operator=(const DSString& dstr);

    //overloaded operators
    bool operator==(const char* str) const;
    bool operator==(const std::string& str) const;
    bool operator==(const DSString& dstr) const;

    bool operator!=(const char* str) const;
    bool operator!=(const std::string& str) const;
    bool operator!=(const DSString& dstr) const;

    bool operator<(const char* str) const;
    bool operator<(const std::string& str) const;
    bool operator<(const DSString& dstr) const;

    bool operator>(const char* str) const;
    bool operator>(const std::string& str) const;
    bool operator>(const DSString& dstr) const;

    char& operator[](const int& index) const;
    DSString operator+(const DSString& dstr);

    DSString substr(const int& start, const int& numChars);
    int getSize() const;
    char* c_str() const;
};