#include "graaf.h"
using namespace std;

template<RichtType RT>
class SamenhangGraaf: public Graaf<RT>{
typedef std::map<int, int>  Knoop;      // beeldt knoopnummer (van buur) af op verbindingsnummer
	private:
		vector<int> componentNummers;
		
	private:
		void bepaalGerichtComponenten();
		void rec_postorderNummeren(int i, vector<int> &postorders, int &counter);
		void rec_bepaalGerichtComponenten();
		
  	  	void bepaalOngerichtComponenten();	
  	  	void rec_bepaalOngerichtComponenten(int i, vector<bool> &ontdekt,int component);	
    public:
		void bepaalComponenten();
};

template<RichtType RT>
void SamenhangGraaf<RT>::bepaalComponenten(){
	if(this->isGericht()){
		bepaalGerichtComponenten();
	}else{
		bepaalOngerichtComponenten();
	}
}


//componenten van gerichte graaf
template<RichtType RT>
void SamenhangGraaf<RT>::bepaalGerichtComponenten(){
	/*	1)graaf omkeren
		2)postorder nummers bepalen en daarna	
	  	3)componenten bepalen met diepte eerst volgens hoogste postorder
		
		Hetzelfde effect wordt bekomen door de elementen postorder
		in een queue te steken, door de recursie zullen er elementen
		in de queue blijven die al ontdekt zijn, deze moeten dan 
		hier genegeerd worden
	*/
	
	//1)
    vector<Knoop>  knopenOmgekeerd;
    for(int i=0;i<this->aantalKnopen();i++){
		for(Knoop::const_iterator it=this->knopen[i].begin(); it!=this->knopen[i].end(); i++){
			int it->first = buur
			knopenOmgekeerd[buur] = i;// i->buur ==> buur->i  
		}	
	}
    //2)
    vector<int> postorders;
    vector<bool> ontdekt;
    postorders.resize(this->aantalKnopen());
    for(int i=0; i<this->aantalKnopen(); i++){
		ontdekt[i]=false;
	}
    ...
    
    //3)
}

template<RichtType RT>
void SamenhangGraaf<RT>::rec_bepaalGerichtComponenten(){
	
}

//componenten van ONgerichte graaf: bomen bepalen
template<RichtType RT>
void SamenhangGraaf<RT>::bepaalOngerichtComponenten(){
	vector<bool> ontdekt;
	for(int i=0;i<this->aantalKnopen();i++){
		ontdekt.push_back(false);
	}
	int component = 0;
	for(int i=0; i<this->aantalKnopen(); i++){
		if(!ontdekt[i]){
			rec_bepaalOngerichtComponenten(i,ontdekt,component);
			component++;//volgende boom
		}
	}
}

template<RichtType RT>
void SamenhangGraaf<RT>::rec_bepaalOngerichtComponenten(int i, vector<bool> &ontdekt,int component){
	ontdekt[i]=true;
	componentNummers[i]=component;
	for(Knoop::const_iterator it = this->knopen[i].begin(); it!=this->knopen[i].end(); it++){
		if(!ontdekt[i]){
			rec_bepaalOngerichtComponenten(i,ontdekt,component);
		}
	}
}

