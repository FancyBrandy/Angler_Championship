//Author:   Gregorics Tibor
//Date:     2018.09.23.
//Title:    Anglers

#include <iostream>
#include "champ.h"

using namespace std;

//Activity:  Looking for a skillful angler who has caught at least two catfishes
string most(const string &name)
{
    ChampEnor t(name);
    t.first();
    int max_champ=t.current().fish_total;
    string max_name=t.current().champ;
    for(;!t.end(); t.next()){
            if(t.current().fish_total>max_champ)
            {
                max_champ=t.current().fish_total;
                max_name=t.current().champ;
            }
    }
    return max_name;
}

//#define NORMAL_MODE
#ifdef NORMAL_MODE

//Activity:  Looking for a skillful angler who has caught at least two catfishes
int main()
{
    cout<<most("input.txt")<<endl;
    return 0;
}

#else
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

TEST_CASE("no catch", "t1.txt") {
    ChampEnor t("t1.txt");
    t.first();
    CHECK(t.current().fish_total==0);
}
TEST_CASE("1 contest", "t2.txt") {
    ChampEnor t("t2.txt");
    t.first();
    CHECK((most("t2.txt"))==(t.current().champ));
}

TEST_CASE("more contests", "t3.txt") {

    CHECK(most("t3.txt")=="Szeged0820");
}

TEST_CASE("kiliti512 3 fishes, szeged0820 3 fishes, gesztes0906 3 fishes", "t4.txt")
 {
    ChampEnor t("t4.txt");
    t.first();
    CHECK(t.current().fish_total==3);
    t.next();
    CHECK(t.current().fish_total==4);
    t.next();
    CHECK(t.current().fish_total==2);
}
#endif
