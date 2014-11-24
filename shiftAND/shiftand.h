#include "bitpatroon.h"
#include <queue>
typedef unsigned int uint;
typedef unsigned char uchar;
class Shiftand{
public:
//naaldlengte moet kleiner dan patroonlengte zijn,
//anders wordt een exceptie opgegooid.
    Shiftand(const uchar* naald,uint _naaldlengte);
    void zoek(std::queue<const uchar*>& plaats,
                     const uchar* hooiberg, uint hooiberglengte);
private:
    Bitpatroon naald[256];
    uint naaldlengte;
       
    
};

Shiftand::Shiftand(const uchar* _naald,uint _naaldlengte):
naaldlengte(_naaldlengte)
{
    if(naaldlengte>256){
        naaldlengte=256;
    }
    for(int i=0;i<naaldlengte;i++){
        naald[i]=_naald[i];
    }
}
