#include <iostream>
#include <cstdlib>
using namespace std;

#include "PriorityQueue.h"

int main(){
	PriorityQueue<int,Compare<int> > queue;

	int init[10]={1,9,3,5,0,8,2,4,6,7};
	for(int i=0;i<10;i++){
		queue.Append(init[i]);
	}
	queue.Print();

	queue.Delete();

	queue.Print();

	system("pause");
	system("cls");
	
	PriorityQueue<SpecialData,SpecialCmp> spe_queue;
	int init2[5][2]={{34,2},{64,1},{18,3},{24,2},{55,4}};
	SpecialData data[5];
	for(int j=0;j<5;j++){
		data[j].m_npir=init2[j][1];
		data[j].m_ntenor=init2[j][0];
	}
	for(int k=0;k<5;k++){
		spe_queue.Append(data[k]);
	}
	spe_queue.Print();

    cout << spe_queue.GetFront() << endl << endl;


	spe_queue.Delete();
	spe_queue.Print();
	
	
	return 0;
}
