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
#include <unordered_map>

class Soundex
{
public:
    std::string encode(const std::string& word) const {
        return zeroPad(head(word)+ encodedDigits(tail(word)));
    }
    
private:
    static const size_t MaxCodeLength{4};
    
    std::string head(const std::string& word) const {
        return word.substr(0, 1);
    }
    
    std::string tail(const std::string& word) const {
        return word.substr(1);
    }
    
    std::string encodedDigits(const std::string& word) const {
        std::string encoding;
        for (auto letter: word) {
            if (isComplete(encoding))
                break;
            if (encodedDigit(letter) != lastDigit(encoding))
                encoding += encodedDigit(letter);
        }
        return encoding;
    }
    
    std::string lastDigit(const std::string& encoding) const{
        if (encoding.empty())   return "";
        return std::string(1, encoding.back());
    }
    
    bool isComplete(const std::string& encoding) const{
        return encoding.length() == MaxCodeLength - 1;
    }
    
    std::string encodedDigit(char letter) const {
        std::unordered_map<char, std::string> encodings{
            {'b', "1"}, {'f', "1"}, {'p', "1"}, {'v', "1"},
            {'c', "2"}, {'g', "2"}, {'j', "2"}, {'k', "2"}, {'q', "2"}, {'s', "2"}, {'x', "2"}, {'z', "2"},
            {'d', "3"}, {'t', "3"},
            {'l', "4"},
            {'m', "5"}, {'n', "5"},
            {'r', "6"}
        };
    
        auto it = encodings.find(letter);
        return it == encodings.end() ? "": it->second;
    }
    
    std::string zeroPad(const std::string &word) const{
        auto zerosNeeded = MaxCodeLength - word.length();
        return word + std::string(zerosNeeded, '0');
    }
};

#endif
