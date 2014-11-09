#include <iostream>
#include<fstream>
#include "punt2.h"
using namespace std;

class Boom2D{
	private:
		Knoop2D* knoop;
		
	public:
		void voegToe(x,y);
		bool bevat(x,y);
		punt2 dichtsteBuur(x,y);
};

class Knoop2D{
	public:
		static const bool VERDEEL_OP_X=true,VERDEEL_OP_Y=false;
		
		Boom2D links,rechts;
		punt2 punt;
};



int main(){
	Boom2D boom;
	
 	ifstream verz;
	verz.open("puntenverzameling.txt");
	int x,y;
	while(verz >> x){
		if(verz >> y){
			boom.voegToe(x,y);
		}
	}
	return 0;	
}
