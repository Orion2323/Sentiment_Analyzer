#include "DSString.h"

// default constructor
DSString::DSString() {
    this->str = nullptr;
}

DSString::DSString(const char* str) {
    if (str != nullptr) {
        this->str = new char[strlen(str) + 1];
        strcpy(this->str, str);
    } else {
        this->str = nullptr;
    }
}

DSString::DSString(const std::string& str) {
    if (str.c_str() != nullptr) {
        this->str = new char [str.size() + 1];
        strcpy(this->str, str.c_str());
    } else {
        this->str = nullptr;
    }
} 

// destructor
DSString::~DSString() {
    if (this->str != nullptr) {
        delete[] this->str;
    }
}

// copy constuctor
DSString::DSString(const DSString& dstr) {
    if (dstr.str != nullptr) {
        this->str = new char[strlen(dstr.str) + 1];
        strcpy(this->str, dstr.str);
    } else {
        this->str = nullptr;
    }
}

// assignment operator
DSString& DSString::operator=(const DSString& dstr) {
    if (this->str != nullptr) {
        delete[] this->str;
    }

    if (dstr.str != nullptr) {
        this->str = new char[strlen(dstr.str) + 1];
        strcpy(this->str, dstr.str);
    } else {
        this->str = nullptr;
    }

    return *this;
}

bool DSString::operator==(const char* str) const {
    if (str == nullptr && this->str == nullptr) {
        return true;
    } else if (str == nullptr || this->str == nullptr) {
        return false;
    } else {
        return (strcmp(this->str, str) == 0);
    }
}

bool DSString::operator==(const std::string& str) const {
    if (str.c_str() == nullptr && this->str == nullptr) {
        return true;
    } else if (str.c_str() == nullptr || this->str == nullptr) {
        return false;
    } else {
        return (strcmp(this->str, str.c_str()) == 0);
    }
}

bool DSString::operator==(const DSString& dstr) const {
    if (dstr.str == nullptr && this->str == nullptr) {
        return true;
    } else if (dstr.str == nullptr || this->str == nullptr) {
        return false;
    } else {
        return (strcmp(this->str, dstr.str) == 0);
    }
}

bool DSString::operator!=(const char* str) const {
    if (str == nullptr && this->str == nullptr) {
        return false;
    } else if (str == nullptr || this->str == nullptr) {
        return true;
    } else {
        return (strcmp(this->str, str) != 0);
    }
}

bool DSString::operator!=(const std::string& str) const {
    if (str.c_str() == nullptr && this->str == nullptr) {
        return false;
    } else if (str.c_str() == nullptr || this->str == nullptr) {
        return true;
    } else {
        return (strcmp(this->str, str.c_str()) != 0);
    }
}

bool DSString::operator!=(const DSString& dstr) const {
    if (dstr.str == nullptr && this->str == nullptr) {
        return false;
    } else if (dstr.str == nullptr || this->str == nullptr) {
        return true;
    } else {
        return (strcmp(this->str, dstr.str) != 0);
    }
}

bool DSString::operator<(const char* str) const {
    if (this->str == nullptr && str == nullptr) {
        return false;
    } else if (this->str != nullptr && str == nullptr) {
        return true;
    } else if (this->str == nullptr && str != nullptr) {
        return false;
    } else {
        return (strcmp(this->str, str) < 0);
    }
}

bool DSString::operator<(const std::string& str) const {
    if (this->str == nullptr && str.c_str() == nullptr) {
        return false;
    } else if (this->str != nullptr && str.c_str() == nullptr) {
        return true;
    } else if (this->str == nullptr && str.c_str() != nullptr) {
        return false;
    } else {
        return (strcmp(this->str, str.c_str()) < 0);
    }
}

bool DSString::operator<(const DSString& dstr) const {
    if (this->str == nullptr && dstr.str != nullptr) {
        return true;
    } else if (this->str != nullptr && dstr.str == nullptr) {
        return false;
    } else if (this->str == nullptr && dstr.str == nullptr) {
        return false;
    } else {
        return (strcmp(this->str, dstr.str) < 0);
    }
}

bool DSString::operator>(const char* str) const {
    if (this->str == nullptr && str == nullptr) {
        return false;
    } else if (this->str != nullptr && str == nullptr) {
        return true;
    } else if (this->str == nullptr && str != nullptr) {
        return false;
    } else {
        return (strcmp(this->str, str) > 0);
    }
}

bool DSString::operator>(const std::string& str) const {
    if (this->str == nullptr && str.c_str() != nullptr) {
        return false;
    } else if (this->str != nullptr && str.c_str() == nullptr) {
        return true;
    } else if (this->str == nullptr && str.c_str() == nullptr) {
        return false;
    } else {
        return (strcmp(this->str,str.c_str()) > 0);
    }
}

bool DSString::operator>(const DSString& dstr) const {
    if (this->str == nullptr && dstr.str != nullptr) {
        return false;
    } else if (this->str != nullptr && dstr.str == nullptr) {
        return true;
    } else if (this->str == nullptr && dstr.str == nullptr) {
        return false;
    } else {
        return (strcmp(this->str, dstr.str) > 0);
    }
}

// overloaded subscript operator
char& DSString::operator[](const int& index) const {
    if (index > -1 && index <= (strlen(this->str)-1)) {
        return this->str[index];
    } else {
        std::cout << "Invalid index!" << std::endl;
    }
}

// overloaded addition operator
DSString DSString::operator+(const DSString& dstr) {
    DSString word;
    char* add = nullptr;

    if (this->str != nullptr && dstr.str == nullptr) {
        add = new char[strlen(this->str) + 1];
        strcpy(add, this->str);
    } else if (this->str == nullptr && dstr.str != nullptr) {
        add = new char[strlen(dstr.str) + 1];
        strcpy(add, dstr.str);
    } else if (this->str != nullptr && dstr.str != nullptr){
        add = new char[this->get_size() + dstr.get_size() + 1];
        strcpy(add, this->str);
        strcat(add, dstr.str);
    }

    word = DSString(add);
    delete[] add;
    return word;
}

// method to make a substring from a DSString
DSString DSString::substr(const int& start, const int& numChars) {
    if (start < 0 || start > this->get_size()) {
        std::cout << "Start index out of bounds" << std::endl;
    } else if ((start + numChars) > this->get_size()) {
        std::cout << "Range out of bounds" << std::endl;
    } else {
        DSString word;
        char* substr = new char[numChars + 1];

        for (int i = 0; i < numChars; i++) {
            substr[i] = this->str[i + start];
        }

        // check if last char is a null temrinated character
        if (substr[numChars] != '\0') {
            substr[numChars] = '\0';
        }

        word = DSString(substr);
        delete[] substr;
        return word;
    }
}

// method for returning size of DSString
int DSString::get_size() const {
    if (this->str == nullptr) {
        return 0;
    } else {
        return strlen(this->str);
    }
}

// method for returning c_str of DSString
char* DSString::c_str() const {
    if (this->str == nullptr) {
        std::cout << "DSString is empty!" << std::endl;
    } else {
        return this->str;
    }
}

std::vector<DSString> DSString::tokenize() {
    std::vector<DSString> tokenizedTweet;
    // if statement checks if tweet is a string
    if (this->str != nullptr) {
        char* token = strtok(this->str, " ");   // tokenize first word

        while (token != nullptr) {
            DSString tokenWord = DSString(token);

            tokenizedTweet.push_back(tokenWord);    // add word to vector
            token = strtok(nullptr, " ");   // tokenize next word
        }
    }
    return tokenizedTweet;
}

void DSString::lowercase() {
    if (this->str != nullptr) {
        for (int i = 0; i < strlen(this->str); i++) {
            this->str[i] = tolower(this->str[i]);
        }
    }
}

void DSString::string_cleaning() {
    if (this->str != nullptr) {
        int counter = 0;
        char* newStr = new char[strlen(this->str) + 1];
        char c = '!';

        for (int i = 0; i < strlen(this->str); i++) {
            if (isalpha(this->str[i]) && this->str[i] != c) {
                c = this->str[i];
                newStr[counter] = this->str[i];
                counter++;
            }
        }

        if (strlen(newStr) > 0) {
            newStr[counter] = '\0';

            delete[] this->str;
            this->str = new char[strlen(newStr) + 1];
            strcpy(this->str, newStr);
        } else {
            delete[] this->str;
            this->str = new char[1];
            this->str[0] = '\0';
        }

        delete[] newStr;
    }
}

bool DSString::wchar_check() const {
    // check if DSString is empty
    if (this->str != nullptr) {
        // iterate through each char in DSString
        for (int i = 0; i < strlen(this->str); i++) {
            // check if char is in ASCII table range
            if (int(this->str[i]) < 0 || int(this->str[i]) > 127) {
                return true;
            }
        }
    }

    return false;
}

bool DSString::is_num() const {
    if (this->str == nullptr) {
        return false;
    } else {
        for (int i = 0; i < strlen(this->str); i++) {
            if (!isdigit(this->str[i])) {
                return false;
            }
        }

        return true;
    }
}

std::ostream& operator<<(std::ostream& inOF, const DSString& dstr) {
    inOF << dstr.str;
    return inOF;
}