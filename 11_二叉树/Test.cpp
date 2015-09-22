#include <iostream>

//using namespace std;
using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::ostream;

#include "BinaryTree.h"

int main(){
	BinaryTree<int> tree(-1);
//	int init[10]={3,6,0,2,8,4,9,1,5,7};
	int init[30]={17,6,22,29,14,0,21,13,27,18,2,28,8
		,26,3,12,20,4,9,23,15,1,11,5,19,24,16,7,10,25};
	for(int i=0;i<30;i++){
		tree.Insert(init[i]);
	}
	//cin>>tree;
	cout<<tree<<endl;

	cout<<tree.GetParent(tree.Find(20))->GetData()<<endl;
	cout<<tree.Find(15)->GetRight()->GetData()<<endl;

	cout<<"size="<<tree.Size()<<endl;
	cout<<"height="<<tree.Height()<<endl;

	tree.InOrder();
	cout<<endl<<endl;
	tree.PreOrder();
	cout<<endl<<endl;
	tree.PostOrder();
	cout<<endl<<endl;
	

	BinaryTree<int> tree2=tree;
	cout<<tree2<<endl;

	cout<<tree2.GetParent(tree2.Find(20))->GetData()<<endl;
	cout<<tree2.Find(15)->GetRight()->GetData()<<endl;

	cout<<(tree==tree2)<<endl;
	return 0;
}
