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
        return zeroPad(word);
    }
    
private:
    std::string zeroPad(const std::string &word) const{
        return word + "000";
    }
};

#endif
