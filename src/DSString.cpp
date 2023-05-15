#include "DSString.h"

/*  Constructors
*   
*   first: default
*   
*   second: 
*   @params: str: char pointer
*
*   Third:
*   @param: str: string variable 
*/
DSString::DSString() {
    this->str = new char[1];
    this->str[0] = '\0';
}

DSString::DSString(const char* str) {
    if (str != nullptr) {
        this->str = new char[strlen(str) + 1];
        strcpy(this->str, str);
    } else {
        this->str = new char[1];
        this->str[0] = '\0';
    }
}

DSString::DSString(const std::string& str) {
    this->str = new char [str.size() + 1];
    strcpy(this->str, str.c_str());
} 

// destructor
DSString::~DSString() {
    if (this->str != nullptr) {
        delete this->str;
    }
}

// copy constuctor
DSString::DSString(const DSString& dstr) {
    this->str = new char[strlen(dstr.str) + 1];
    strcpy(this->str, dstr.str);
}

// assignment operator
DSString& DSString::operator=(const DSString& dstr) {
    if (this->str != nullptr) {
        delete this->str;
    }

    this->str = new char[strlen(dstr.str) + 1];
    strcpy(this->str, dstr.str);

    return *this;
}

/*  Overloaded equality methods
*   Returns a boolean if current DSString exactly like parameter variable
* 
*   first:
*   @params: str char pointer to compare 
*  
*   second: 
*   @params: str string varible to compare
*
*   Third:
*   @param: dstr DSString variable to compare
*/
bool DSString::operator==(const char* str) const {
    return (strcmp(this->str, str) == 0);
}

bool DSString::operator==(const std::string& str) const {
    return (strcmp(this->str, str.c_str()) == 0);
}

bool DSString::operator==(const DSString& dstr) const {
    return (strcmp(this->str, dstr.str) == 0);
}

/*  Overloaded non equality methods
*   Returns a boolean if current DSString is not exactly like parameter variable
*
*   first:
*   @params: str char pointer to compare
*
*   second:
*   @params: str string varible to compare
*
*   Third:
*   @param: dstr DSString variable to compare
*/
bool DSString::operator!=(const char* str) const {
    return (strcmp(this->str, str) != 0);
}

bool DSString::operator!=(const std::string& str) const {
    return (strcmp(this->str, str.c_str()) != 0);
}

bool DSString::operator!=(const DSString& dstr) const {
    return (strcmp(this->str, dstr.str) != 0);
}

/*  Overloaded less than methods
*   Returns a boolean if current DSString is less than parameter variable
* 
*   first:
*   @params: str char pointer to compare 
*  
*   second: 
*   @params: str string varible to compare
*
*   Third:
*   @param: dstr DSString variable to compare
*/
bool DSString::operator<(const char* str) const {
    return (strcmp(this->str, str) < 0);
}

bool DSString::operator<(const std::string& str) const {
    return (strcmp(this->str, str.c_str()) < 0);
}

bool DSString::operator<(const DSString& dstr) const {
    return (strcmp(this->str, dstr.str) < 0);
}

/*  Overloaded greater than methods
*   Returns a boolean if current DSString is greater than parameter variable
* 
*   first:
*   @params: str char pointer to compare 
*  
*   second: 
*   @params: str string varible to compare
*
*   Third:
*   @param: dstr DSString variable to compare
*/
bool DSString::operator>(const char* str) const {
    return (strcmp(this->str, str) > 0);
}

bool DSString::operator>(const std::string& str) const {
    return (strcmp(this->str, str.c_str()) > 0);
}

bool DSString::operator>(const DSString& dstr) const {
    return (strcmp(this->str, dstr.str) > 0);
}

// overloaded subscript operator
char& DSString::operator[](const int& index) const {
    if (index > -1 && index < (strlen(this->str)-1)) {
        return this->str[index];
    } else {
        std::cout << "Invalid index!" << std::endl;
    }
}

// overloaded addition operator
DSString DSString::operator+(const DSString& dstr) {
    DSString word;
    char* add = nullptr;

    if (dstr.str != nullptr) {
        add = new char[this->getSize() + dstr.getSize() + 1];
        strcpy(add, this->str);
        strcat(add, dstr.str);
    } else {
        add = new char[this->getSize() + 1];
        strcpy(add, this->str);
    }
    word = DSString(add);
    delete[] add;
    return word;
}

// method to make a substring from a DSString
DSString DSString::substr(const int& start, const int& numChars) {
    if (start < 0 || start > this->getSize()) {
        std::cout << "Start index out of bounds" << std::endl;
    } else if ((start + numChars) > this->getSize()) {
        std::cout << "Range out of bounds" << std::endl;
    } else {
        DSString word;
        char* substr = new char[numChars + 1];

        for (int i = 0; i < numChars; i++) {
            substr[i] = this->str[i + start];
        }

        word = DSString(substr);
        delete[] substr;
        return word;
    }
}

// method for returning size of DSString
int DSString::getSize() const {
    return strlen(this->str);
}

// method for returning c_str of DSString
char* DSString::c_str() const {
    return this->str;
}