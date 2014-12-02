#include <iostream>
#include <vector>
using namespace std;

class UnionFind{
private:
	vector<int> parents;//slaat index op van de ouderknoop, voor wortels staat hier -1 => vertegenwoordigers
	map<int,int> depths; //slaat voor de ouderknoopindex(key) de diepte (value) op van de bijhorende boom
	
	int zoekVerwertegenwoordiger(int knoop){
		
		int k =knoop;
		int p = parents[k];
		
		while(p!=-1){
			k = p;
			p = parents[k];
			
		}
		//k is nu vertegenwoordiger
		//knoop is nog steeds originele
		p= parents[knoop];
		int i=knoop;
		while(p!=-1){
			i = p;
			p = parents[i];
		}	
			
		return k;
		
	}
	
public:
	UnionFind(int aantalKnopen);
	bool isGelijk(int knoop1,int knoop2);
	void union(int knoop1,int knoop2);
	geefClusters();
};

UnionFind::UnionFind(int aantalKnopen){
	parents.resize(aantalKnopen); //reserve:enkel plaats in geheugen reserveren <-> resize: ook de lengte al instellen
	for(int i=0;i<aantalKnopen;i++){
		parents[i]=-1;//alle knopen zijn aparte bomen
		depths[i]=0;
	}
}

bool UnionFind::isGelijk(int knoop1,int knoop2){
	int vert1=zoekVertegenwooriger(knoop1);
	int vert2=zoekVertegenwooriger(knoop2);
	
	return vert1==vert2;
}

void UnionFind::union(int knoop1,int knoop2){
	
	
}
