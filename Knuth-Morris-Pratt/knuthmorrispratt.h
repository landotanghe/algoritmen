#include <queue>
#include <vector>
#include <iostream>

using namespace std;

typedef unsigned int uint;
typedef unsigned char uchar;
class KnuthMorrisPratt{
	public:
	    KnuthMorrisPratt(const uchar* _needle,uint _needleSize);
	    void search(std::queue<uint>& location,
	                     const uchar* haystack, uint haystackSize);

	private:
		vector<uchar> P;
		uint p;  //needleSize
		
		vector<int> prefixValues;
		vector<uint> indices;
		      
		void calculatePrefixes();
		void calculateIndices();
};

KnuthMorrisPratt::KnuthMorrisPratt(const uchar* needle,uint _needleSize){
	for(int i=0;i<_needleSize;i++){
		P.push_back(needle[i]);	
	}
	calculatePrefixes();
	calculateIndices();
}

void KnuthMorrisPratt::search(std::queue<uint>& locations,
	                     const uchar* T, uint haystackSize){
	int i=0;//huidige positie in P (pattern,needle)
	for(int j=0;j<haystackSize;j++){//huidige positie in T (text,haystack), !! j is niet beginpositie van P zoals in sommige teksten
		if(P[i]==T[j]){
			i++;
			if(i==p){
				locations.push(j-p);
				i=indices[i];
			}
		}else{
			i=indices[i];
		}
	}
}


void KnuthMorrisPratt::calculatePrefixes(){
	prefixValues.push_back(-1);//niet gedefinieerd:prefixfunctie(0)
	prefixValues.push_back(0);//prefixfunctie(-1) altijd 0
	
	for(int i=1;i<p;i++){//prefixfunctie van 2 t.e.m. p berekenen (dus aan de hand van die voor 1 t.e.m. p-1)
		uint currentPrefix = prefixValues[i];
		while(currentPrefix>-1 && P[i]!=P[currentPrefix]){
			currentPrefix=prefixValues[currentPrefix];//prefixwaarde daalt, we zoeken links verder
		}
		prefixValues.push_back(currentPrefix+1);//prefixwaarde van i+1, max. waarde q(i+1) is i+1 en wordt bereikt als while niet doorlopen is
	}
	cout << "prefixes" << endl;
	for(int i=0;i<p;i++){
		cout << P[i] << "\t" << endl;
	}
	for(int i=0;i<p+1;i++){
		cout << prefixes[i] << "\t" << endl;
	}
}

void KnuthMorrisPratt::calculateIndices(){
	//zie wiki: opm wiki praat over m:beginpos van p, wij houden hier j bij,
	//			de huidig te vergelijken positie, wat terugspringen in haystack
	//			overbodig maakt, bij een een overeenkomst moet j - p teruggeg. worden als beginpositie vd match
	//			
	//			Ook houdt wiki geen rekening met P[q(i)] = P[i], cursus wel d.m.v. q'
		
	//hayStack: ABC ABCDAB ABCDABCDABDE
	//needle:       ABCDABD (i=7)
	//spring naar:      ABCDABD(i=i-q'(i)=3)
	//conflict bij 'D'!=' '
	//prefix 'AB' moet echter niet herckeckt worden
	//we kunnen verder springen zodat volgdende vergelijking 'C' met ' ' vergelijkt
	
	indices.push_back(0);//zodat als foutpositie i=0, opnieuw begint bij i=0
	for(int i=0;i<p;i++){
		int q = prefixValues[i];
		while(q>-1 && P[q]==P[i]){//als P[i] fout geeft dan zal P[q(i)] ook fout geven als ze gelijk zijn
			q = prefixValues[q];
		}
		if(q<0){
			indices.push_back(0);//toch volledig herbeginnen, bv P='AAAA' 
							//						en T = '...AAAB...' 	
							//						Pshifted      'AAAA'
		}else{
			indices.push_back(q);
		}		
	}
	cout << "indices" << endl;
	for(int i=0;i<p;i++){
		cout << P[i] << "\t" << endl;
	}
	for(int i=0;i<p+1;i++){
		cout << indices[i] << "\t" << endl;
	}
};

    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
