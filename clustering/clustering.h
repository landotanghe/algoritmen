#include <map>
#include <priority_queue>
#include <vector>
#include "graaf.h"
#include "union_find.h"
using namespace std;

class ClusterFinder{
    private:
        string vers1;
        string vers2;
        
        double afstand(string a,string b);//hoe gelijk zijn 2 verzen
        int countCommonWords(string a,string b);
    public:
        vector<vector<int>> findClusters(const vector<string> &verzen);//gegeven een tabel van verzen, verzamelt de indices uit de gegeven tabel in clusters
                                                                       //de clusters overlopen = de buitenste vector overlopen
                                                                       //alle indices van de verzen kunnen uit de cluster gehaald worden
};

double ClusterFinder::afstand(string a,string b){
    int n_a = a.size();
    int n_b = b.size();
    int n_ab = countCommonWords(a,b);
    return Math.log( (n_a+n_b) / (2*n_ab) );
}

int ClusterFinder::countCommonWords<string a,string b){
//aantal keer dat een woord voorkomt in a, later terug verminderen als voorkomt in b
    map<string,int> occurances; 
    int count;
    //...
    //for/while(){
        string word="";
        if(occurances[word] > 0){
            occurances[word]--;
            count++;
        }
    //}
    return count;
}
