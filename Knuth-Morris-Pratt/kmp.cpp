#include "knuthmorrispratt.h"
#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

typedef unsigned int uint;
typedef unsigned char uchar;

int main(){
	uchar needle[] = {'t','h','i','s'};
	uint needleSize = 4;
	uchar haystack[100000] =  {'t','h','i','s','i','t','h','i','s','a'}; 
	uint haystackSize = 10;
	cout << "inited" << endl;
	/*
	ifstream hayFile;
	hayFile.open("bijbel.txt");
	
	hayFile.close();
	*/
	KnuthMorrisPratt kmp(needle,needleSize);
	queue<uint> locations;
	
	cout << "constructed" << endl;
	kmp.search(locations,haystack,haystackSize);
	
	cout << "searched" << endl;
	
	while(!locations.empty()){
		int begin = locations.front();
		cout << begin << endl;
		locations.pop();
	}
	
	return 0;
}
