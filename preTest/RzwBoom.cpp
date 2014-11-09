#include <iostream>
using namespace std;

#include "RzwBoom.h"

	template <class T,class D>
	int Rzwboom<T,D>::diepte(){		
		if(k==0){
			//einde recursie
			return 0;
		}else{
			int linkerDiepte = k->links.diepte() + 1;
			int rechterDiepte = k->rechts.diepte() + 1;
			//grootste van de 2
			if(linkerDiepte > rechterDiepte){
				return linkerDiepte;
			}else{
				return rechterDiepte;
			}
		}
	}
	
	template <class T,class D>
	int Rzwboom<T,D>::zwartediepte(){		
		if(k==0){
			//einde recursie
			return 0;//eigenlijk 1, maar dit komt op hetzelfde neer,want de wortel wordt meegeteld in plaats van de bladeren
		}else{
			int linker_diepte = k->links.zwartediepte();
			int rechter_diepte = k->rechts.zwartediepte();
			
			//count me too??
			if(k->rzw == rood){
				linker_diepte++;
				rechter_diepte++;
			}
			
			//grootste van de 2
			if(linker_diepte > rechter_diepte){
				return linker_diepte;
			}else{
				return rechter_diepte;
			}
		}
	}
	
	template <class T,class D>
	bool Rzwboom<T,D>::is_kleurbaar(){
		int min=INT_MAX;
		int max=0;
		
		return is_kleurbaar(min,max,0);	
	}
	
	template <class T,class D>
	bool Rzwboom<T,D>::is_kleurbaar(int &min_diepte,int &max_diepte,int huidige_diepte){
		if(k==0){
			//controleer dieptes als eindknoop
			if(min_diepte > huidige_diepte){
				cout << "min" << min_diepte << "->" << huidige_diepte << "\n";
				min_diepte=huidige_diepte;
			}
			if(max_diepte < huidige_diepte){
				cout << "max" <<max_diepte << "->" << huidige_diepte << "\n";
				max_diepte=huidige_diepte;
			}	
			
			//langste tak kan hoogstens ROOD-ZWART afwisselen, meer ROOD zou ongeldig zijn 
			return min_diepte*2 >= max_diepte;
		}else{
			//recursie verderzetten van links naar rechts
			return k->links.is_kleurbaar(min_diepte,max_diepte,huidige_diepte+1)
				 && k->rechts.is_kleurbaar(min_diepte,max_diepte,huidige_diepte+1);
		}			
	}
	
	
int main(){
	Rzwboom<int,int> boom;
	boom.voegtoe(3,3,false);
	boom.voegtoe(1,1,false);
	boom.voegtoe(2,2,false);
	boom.voegtoe(5,5,false);
	boom.voegtoe(4,4,false);
	boom.voegtoe(6,6,false);
	cout << boom << "\n";
	cout << "diepte: " << boom.diepte() << "\n";
	cout << "zwarte diepte: " << boom.zwartediepte() << "\n";
	if(boom.is_kleurbaar()){
		cout << "is kleurbaar" << "\n";
	}else{
		cout << "is NIET kleurbaar" << "\n";	
	}
	
	char ch;
	cin >> ch;
	return 0;	
}
