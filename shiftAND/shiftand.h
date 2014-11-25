#include "bitpatroon.h"
#include <iostream>
#include <queue>
#include <vector>
#include <string>
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
    cout << "letterpatroon" << endl;
    for(int i=0;i<naaldlengte;i++){
        int letterwaarde=(int)naald[i];
        cout << "letterwaarde[" << naald[i] << "]" << ":";
        letterpatroon[letterwaarde].setBit(i);
        cout << letterpatroon[letterwaarde] << endl;  
    }
}

void Shiftand::zoek(queue<const uchar*>& plaats,const uchar* hooiberg, uint hooiberglengte){
    Bitpatroon *suffix_lengte_voldoet = new Bitpatroon[hooiberglengte+1]; //i(bit) duidt aan of de prefix met lengte i-1 uit naald in de tekst matcht met de string die op j(index) eindigt.
    Bitpatroon result_finder;
    result_finder.setBit(naaldlengte-1);//bv  000001000
                            //als dan R[j]= 110101000
                            //dan zal en()= 000001000 => true (dus enkel als de p-de bit aanstaat)
    
    // suffix_lengte_voldoet[0] stelt R0 voor= een fictieve voorloper om R1 makkelijk te kunnen berekenen, dus alle lengtes(alle i's)=false
    for(int j=0;j<hooiberglengte;j++){
        //R [j+1] = shift( R[j]) && S[t[J+1]]
        suffix_lengte_voldoet[j+1]= suffix_lengte_voldoet[j].shiftrechts(1);
        suffix_lengte_voldoet[j+1].setBit(0);
        suffix_lengte_voldoet[j+1]&= letterpatroon[hooiberg[j]];
        cout << "R[" << j+1 <<"]=   \t" << suffix_lengte_voldoet[j+1] << endl;
        if(result_finder.en( suffix_lengte_voldoet[j+1])){
            plaats.push(& hooiberg[j-naaldlengte+1]);
        }
    }
    
    delete[] suffix_lengte_voldoet;
}
