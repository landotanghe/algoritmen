#include <queue>
#include <vector>
typedef unsigned int uint;
typedef unsigned char uchar;
class KnuthMorrisPratt{
	public:
	    KnuthMorrisPratt(const uchar* _needle,uint _needleSize)p(_needleSize){
			for(int i=0;i<_needleSize;i++){
				P.push(needle[i]);	
			}
		}
	    void search(std::queue<const uchar*>& location,
	                     const uchar* haystack, uint haystackSize);

	private:
		vector<uchar> P;
		uint p;  //needleSize
		
		vector<uint> prefixValues;
		vector<uint> hops;
		      
		void calculatePrefixes();
};

void KnuthMorrisPratt::search(std::queue<const uchar*>& location,
	                     const uchar* haystack, uint haystackSize){
	
}


void KnuthMorrisPratt::calculatePrefixes(){
	hops.push(-1);//niet gedefinieerd:prefixfunctie(0)
	hops.push(0);//prefixfunctie(-1) altijd 0
	
	for(int i=1;i<p;i++){//prefixfunctie van 2 t.e.m. p berekenen (dus aan de hand van die voor 1 t.e.m. p-1)
		uint currentPrefix = prefixValues[i];
		while(currentPrefix>-1 && P[i]!=P[currenPrefix]){
			currentPrefix=prefixValue[currentPrefix];//prefixwaarde daalt, we zoeken links verder
		}
		prefixValues.push(currentPrefix+1);//prefixwaarde van i+1, max. waarde q(i+1) is i+1 en wordt bereikt als while niet doorlopen is
	}
}

    
