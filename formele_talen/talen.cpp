#include <iostream>
#include <string>
#include <vector>
#include "symbool.h"
#include "regexp.h"
using namespace std;

void breakDownRegexp(const Regexp* r,Symbool* s,Symbool me);
int main(){
	//watDoetSymbool();
	
	Regexp r( "(x)((a)|(c))(d)");
	Symbool s;
	breakDownRegexp(&r,&s,s);
	
	return 0;	
}

void breakDownRegexp(const Regexp* r,Symbool* s,Symbool me){
		
	
	if(r->geefOpcode() == Regexp::letter){
		cout << me << "::=" << r->geefLetter() << endl;
	}else if(r->geefOpcode() == Regexp::ster){
		Symbool starring = ++(*s);
		breakDownRegexp(r->geefEersteOperand(),s,starring);
		cout << me << "::=" << "<" << starring << ">" << endl;
	}else{
		Symbool s1= ++(*s);
		breakDownRegexp(r->geefEersteOperand(),s,s1);
		Symbool s2= ++(*s);
		breakDownRegexp(r->geefTweedeOperand(),s,s2);
		char oper;
		if(r->geefOpcode()==Regexp:: of){
			oper='|';
		}else{
			oper='.';	
		}
		cout << me << "::=" << "<" << s1 << ">" << oper << "<" << s2 << ">" << endl;
	}
	
}

void watDoetSymbool(){
	Symbool s;
	for(int i=0;i<30;i++){
		cout << s << endl;
		++s;
	}
}
