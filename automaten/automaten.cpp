#include "thompsonna.h"
#include "regexp.h"
#include <string>
#include <iostream>
using namespace std;

int main(){
	Regexp r("a|b");
	ThompsonNA na(r);
	na.schrijf(cout);
	
	string tekst[6]={"abba is in de ab geweest", "niets te zien", "bevat a en b", "geen","a","b"};
	for(int i=0;i<6;i++){
        cout << endl << endl;
        cout << tekst[i] << endl;
        if(na.bevat(tekst[i])){
            cout << "found"  << endl;
        }
    }		
	cin.get();
	return 0;
}
