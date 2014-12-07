#include "thompsonna.h"
#include "regexp.h"
#include <iostream>
using namespace std;

int main(){
	Regexp r("a|b");
	ThompsonNA na(r);
	na.schrijf(cout);
	
	return 0;
}
