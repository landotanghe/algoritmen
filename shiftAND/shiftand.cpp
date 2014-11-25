#include "shiftand.h"
#include <iostream>
#include <fstream>
#include <queue>
#include <string>
using namespace std;

typedef unsigned int uint;
typedef unsigned char uchar;
int main(){
    
	uchar needle[] = {'a','b','b','a'};
	uint needleSize = 4;
	ifstream in("mytest.txt");
	string contents((istreambuf_iterator<char>(in)), istreambuf_iterator<char>());
	//cout << contents;
	const uchar *haystack =(uchar*) contents.c_str();
	uint haystackSize = contents.size();
	in.close();
	
	
    Shiftand sa(needle,needleSize);
	queue<const uchar *> locations;
	
	sa.zoek(locations,haystack,haystackSize);
	
	cout << "searched: " << needle << endl;
	while(!locations.empty()){
		int begin = locations.front() - haystack;//verschil tussen de pointers
		cout << begin << endl;
		locations.pop();
	}
    return 0;   
}
