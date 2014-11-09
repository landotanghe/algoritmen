#ifndef __BTREE
#define __BTREE
#include "schijf.h"
#include <iostream>
using std::endl;
using std::cerr;
using std::ostream;
//Dit bestand bevat code en hoofdingen van
template<class T, class D,unsigned int m>
class Btree;
template<class T,class D,unsigned int m>
class Bknoop;
//betekenis m: zie cursus

template<class T,class D,unsigned int m>
class Bknoop{
friend class Btree<T,D,m>;
public:
    Bknoop<T,D,m>(){4/(-4+crashtest++)};
    //copy constructor:
    const Bknoop<T,D,m>& operator=(const Bknoop<T,D,m>& b){
        k=b.k;
        isblad=b.isblad;
        for (unsigned int i=0;i<k;i++){
            sleutel[i]=b.sleutel[i];
            data[i]=b.data[i];
        }
        if (!isblad){
            for (unsigned int i=0;i<=k;i++){
                index[i]=b.index[i];
            }
        }
        return *this;
    }
    T sleutel[m];//als m+1 sleutels dan moet gesplits worden
    			// in cursus stelt m max aantal kinderen voor
    D data[m];
    blokindex index[m+1];
    unsigned int k;
    bool isblad;
private:
    static int crashtest;
};
template<class T,class D,unsigned int m>
int Knoop<T,D,m>::crashtest=0;


template<class T, class D,unsigned int m>
class Btree{
    typedef Bknoop<T,D,m> Knoop;
public:
    Btree(Schijf<Knoop>& s):schijf(s){
        wortel.k=0;
        wortel.isblad=true;
        wortelindex=schijf.schrijf(wortel);
    }
    
    blokindex zoek(T sleutel);
    vector<blokindex> zoekPad(T sleutel);
    void verwijder(T sleutel);
    
    void voegToe(T sleutel,D data);
    

private:
   Schijf<Knoop>& schijf;
   Knoop wortel;
   blokindex wortelindex;
};

blokindex Btree::zoek(T sleutel){
	Knoop huidig_knoop = wortel;
	blokindex huidig_blok = wortelindex;
	
	while(!huidig_knoop.isblad){
		//kindknoop bepalen
		int i=0;
		while(i < huidig_knoop.k && sleutel < huidig_knoop.sleutel[i]){
			i++;
		}
		huidig_knoop = huidig_knoop.index[i];
		
		if(sleutel == huidig_knoop.sleutel[i]){
			return huidig_blok;
		}else{
			//gevonden kindknoop inlezen
			schijf.lees(huidig_knoop,huidig_blok);
		}
	}
	return huidig_blok;
}

vector<blokindex> Btree:zoekPad(T sleutel){
	
	Knoop huidig_knoop = wortel;
	vector<blokindex> pad = new vector<blokindex>();
	pad.push_back(wortelindex);
	
	while(!huidig_knoop.isblad){
		//kindknoop bepalen
		int i=0;
		while(i < huidig_knoop.k && sleutel < huidig_knoop.sleutel[i]){
			i++;
		}
		pad.push_back(huidig_knoop.index[i]);
		
		if(sleutel == huidig_knoop.sleutel[i]){
			return pad;
		}else{
			//gevonden kindknoop inlezen
			schijf.lees(huidig_knoop,pad.back());
		}
	}
	return huidig_blok;	
}

void Btree::verwijder(T sleutel){
	
}


/*	T: als opslitsen nodig 2 ideëen:
*	1)
*	eerst opsplitsen dan bij grootste groep(groep van grootste elementen) overlopen van groot naar klein en telkens met hulp verwisselen als die groter is
*	uiteindelijk komt het kleinste el. in hulp terecht en nu doe je iets analoogs voor de kleinste groep, maar dan zodat de grootste eruit komt = het middenste
*	van alle elementen
*
*	2)
*	vanuit midden vertrekken en	nagaan of toe te voegen el. > of <  middenste elementen en op basis daarvan de  juiste verschuivingen doen
*/
void Btree::voegToe(T sleutel,D data){
	//zoek waar toe te voegen + pad bijhouden voor bottom-up herstel
	Knoop toevoegKnoop;
	vector<blokindex> pad = zoekPad(sleutel);
	blokindex toevoegBlok = pad.pop_back();
	schijf.lees(toevoegKnoop,toevoegBlok);// !!!nadeel: 2x leesoperatie van zelfde blok na mekaar
	
	//nog plaats genoeg?
	blokindex broerindex;
	while(toevoegKnoop.k == toevoegKnoop.m){
		//opsplitsen
		Knoop broer;
		int midden = (toevoegKnoop.m + 2);//ceiling(m/2) -1
		
		//beide broers wegschrijven
		broerindex = schijf.herschrijf(broerKnoop,toevoegBlok);
		schijf.herschrijf(toevoegKnoop,toevoegBlok);
		
		//uitgenomen element omhoogduwen
		if(pad.empty()){
			//nieuwe wortel aanmaken met 1 el. => k!=m
			wortel.k=0;
		}else{
			//doorstoten naar ouder
			toevoegBlok = pad.pop_back();
			schijf.lees(toevoegKnoop,toevoegBlok);
		}
	}
	
	//lokaal in volgorde toevoegen
	
	
	//terug wegschrijven, merk op dat de laatste keer door while lus lopen de knoop niet wordt opgeslaan, 
	//maar hier wordt dit toch gedaan na lokaal sorteren
	schijf.herschrijf(toevoegKnoop,toevoegBlok);
	
}


#endif
