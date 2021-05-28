//Author:   Gregorics Tibor
//Date:     2018.09.23.
//Title:    Anglers

#pragma once

#include "contest.h"
#include <string>

//Datatype of anglers
struct Champ {
    std::string champ;
    int fish_total;
};

//Datatype of enumerator of anglers
class ChampEnor{
    private:
        ContestEnor _tt;
        Champ _cur;
        bool _end;
    public:
        ChampEnor(const std::string &str): _tt(str) { };
        void first() {_tt.first(); next();}
        void next();
        Champ current() const { return _cur;}
        bool end() const { return _end;}
};

