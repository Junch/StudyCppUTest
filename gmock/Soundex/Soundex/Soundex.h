//
//  Soundex.h
//  Soundex
//
//  Created by Jun on 13-12-14.
//  Copyright (c) 2013年 Jun. All rights reserved.
//

#ifndef Soundex_h
#define Soundex_h

#include <string>

class Soundex
{
public:
    std::string encode(const std::string& word) const {
        return zeroPad(head(word)+ encodedDigits(word));
    }
    
private:
    static const size_t MaxCodeLength{4};
    
    std::string head(const std::string& word) const {
        return word.substr(0, 1);
    }
    
    std::string encodedDigits(const std::string& word) const {
        if (word.length() > 1)
            return encodedDigit();
        return "";
    }
    
    std::string encodedDigit() const {
        return "1";
    }
    
    std::string zeroPad(const std::string &word) const{
        auto zerosNeeded = MaxCodeLength - word.length();
        return word + std::string(zerosNeeded, '0');
    }
};

#endif
