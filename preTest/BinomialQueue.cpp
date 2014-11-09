#include <iostream>
#include <vector>
using namespace std;

template <class P,class D>
class BinomialNode;
template <class P,class D>
class BinomialTree;
template <class P,class D>
class BinomialQueue;
/*
template <class P,class D>
typedef BinomialTree<P,D> BT;
template <class P,class D>
typedef BinomialQueue<P,D> BQ;
*/
template <class P,class D>
class BinomialQueue{
	public:
		void voegToe(P priority, D data);
		void merge(BinomialQueue<P,D> &other);
	private:
		vector<BinomialTree<P,D> > *trees; 	
	
};

template <class P,class D>
class BinomialTree{
	public:
		BinomialTree<P,D>(){
			height=0;
			root=new BinomialNode<P,D>
		}
		BinomialNode<P,D> *root;
		int height;
		void add(BinomialTree<P,D> &other);
};


template <class P,class D>
class BinomialNode{
	public:
		P priority;
		D data;
		BinomialNode<P,D> *kind;//linkse kind
		BinomialNode<P,D> *broer;//rechtse broer
};

template <class P,class D>
void BinomialQueue<P,D>::voegToe(P priority, D data){
	
}

template <class P,class D>
void BinomialQueue<P,D>::merge(BinomialQueue<P,D> &other){
	BinomialTree<P,D> * extra;
	
}

template <class P,class D>
void BinomialTree<P,D>::add(BinomialTree<P,D> &other){
	height++;
		
}



int main(){
	BinomialQueue<int,int> queue;	
	
	return 0;
}
