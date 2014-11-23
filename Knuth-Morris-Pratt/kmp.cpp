#include "knuthmorrispratt.h"
#include <iostream>
#include <fstream>
#include <queue>
#include <string>

using namespace std;

typedef unsigned int uint;
typedef unsigned char uchar;

int main(){
	
	// voorbeeld 1
	/*uchar needle[] = {'t','h','i','s',' ','i','s',' ','t','h','i','s'}; 
	uint needleSize = 12;							     //match here																    //and here
	uchar haystack[] =  {'h','i','t','h','t','h','i',    't','h','i','s',' ','i','s',' ','t','h','i','s','s','i','t','h','i','s','a',   't','h','i','s',' ','i','s',' ','t','h','i','s',   't','a','i','s','i','x',' ','i','s','i','s'}; 
						//1  2    3   4   5   6   7                                                  19   0   1   2   3   4   5     26                                              38                                       
	uint haystackSize = 49;
	*/
	
	//voorbeeld 2
	
	uchar needle[] = {'j','e','z','u'};
	uint needleSize = 4;
	ifstream in("bijbel.txt");
	string contents((istreambuf_iterator<char>(in)), istreambuf_iterator<char>());
	//cout << contents;
	const uchar *haystack =(uchar*) contents.c_str();
	uint haystackSize = contents.size()-1;
	in.close();
	
	KnuthMorrisPratt kmp(needle,needleSize);
	queue<uint> locations;
	
	kmp.search(locations,haystack,haystackSize);
	
	cout << "searched" << endl;
	
	while(!locations.empty()){
		int begin = locations.front();
		cout << begin << endl;
		locations.pop();
	}
	
	return 0;
}
