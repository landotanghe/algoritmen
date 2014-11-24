#include "bitpatroon.h"
#include <queue>
#include <vector>
using namespace std;


typedef unsigned int uint;
typedef unsigned char uchar;
const int max_patroonlengte=sizeof(uint)*8;
class Shiftand{
public:
//naaldlengte moet kleiner dan patroonlengte zijn,
//anders wordt een exceptie opgegooid.
    Shiftand(const uchar* naald,uint _naaldlengte);
    void zoek(queue<const uchar*>& plaats,
                     const uchar* hooiberg, uint hooiberglengte);
private:
    Bitpatroon letterpatroon[256];
    uint naaldlengte;
       
    
};

Shiftand::Shiftand(const uchar* naald,uint _naaldlengte):
naaldlengte(_naaldlengte)
{
    //beveilig tegen te groot patroon:
    if(naaldlengte>max_patroonlengte){
        naaldlengte = max_patroonlengte;   
    }
    //tabel S uit cursus= letterpatroon[]
    for(int i=0;i<naaldlengte;i++){
        int letterwaarde=(int)_naald[i];
        letterpatroon[letterwaarde].eenbit(i);
    }
}

Shiftand::zoek(queue<const uchar*>& plaats,const uchar* hooiberg, uint hooiberglengte){
    Bitpatroon suffix_lengte* = new Bitpatroon[hooiberg]; //duidt voor index i aan of de prefix met lengte i-1 uit naald in de tekst matcht met de string die op j eindigt.
    suffix_geldig
    
    delete[] suffix_geldig;
}
