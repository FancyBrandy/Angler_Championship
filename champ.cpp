//Author:   Gregorics Tibor
//Date:     2018.09.23.
//Title:    Anglers

#include "champ.h"

using namespace std;

//Task: 	Reading the next angler with his ability
//Input:    ContestEnor tt  - the enumerator of contests
//Output:   Angler _cur     - the next angler
//          bool _end       - the end of the enumeration
//Activity:
void ChampEnor::next()
{
    if( !(_end = _tt.end()) ){
        _cur.champ = _tt.current().contest;
        _cur.fish_total=0;
        for( ; !_tt.end() && _tt.current().contest == _cur.champ; _tt.next() ){// the enumeration lasts as long as the same championship is read
            _cur.fish_total += (_tt.current().counter );
        }
    }
}
