#include <iostream>
#include <ctime>


using namespace std;
/*using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::ostream;*/


#include "Sort.h"

void generateData(int *data, int len);

int main(){
	int initData[15] = {0};
	DataList<int> *data = NULL;

	Sort<int> sort;

	cout << "InsertSort" << endl;
	generateData(initData, sizeof(initData)/sizeof(int));
    data = new DataList<int>(initData, sizeof(initData)/sizeof(int));
	data->Print();
    sort.InsertSort(*data); 
	data->Print();

	cout << "BinaryInsertSort" << endl;
	generateData(initData, sizeof(initData)/sizeof(int));
    data = new DataList<int>(initData, sizeof(initData)/sizeof(int));
	data->Print();
    sort.BinaryInsertSort(*data); 
	data->Print();

	cout << "ShellSort" << endl;
	generateData(initData, sizeof(initData)/sizeof(int));
    data = new DataList<int>(initData, sizeof(initData)/sizeof(int));
	data->Print();
    sort.ShellSort(*data); 
	data->Print();

	cout << "BubbleSort" << endl;
	generateData(initData, sizeof(initData)/sizeof(int));
    data = new DataList<int>(initData, sizeof(initData)/sizeof(int));
	data->Print();
    sort.BubbleSort(*data); 
	data->Print();

	cout << "QuickSort" << endl;
	generateData(initData, sizeof(initData)/sizeof(int));
    data = new DataList<int>(initData, sizeof(initData)/sizeof(int));
	data->Print();
    sort.QuickSort(*data); 
	data->Print();

	cout << "SelectSort" << endl;
	generateData(initData, sizeof(initData)/sizeof(int));
    data = new DataList<int>(initData, sizeof(initData)/sizeof(int));
	data->Print();
    sort.SelectSort(*data); 
	data->Print();

	cout << "HeapSort" << endl;
	generateData(initData, sizeof(initData)/sizeof(int));
    data = new DataList<int>(initData, sizeof(initData)/sizeof(int));
	data->Print();
    sort.HeapSort(*data); 
	data->Print();

	cout << "MergeSort" << endl;
	generateData(initData, sizeof(initData)/sizeof(int));
    data = new DataList<int>(initData, sizeof(initData)/sizeof(int));
	data->Print();
    sort.MergeSort(*data); 
	data->Print();

	cout << "RadixSort" << endl;
	generateData(initData, sizeof(initData)/sizeof(int));
    data = new DataList<int>(initData, sizeof(initData)/sizeof(int));
	data->Print();
    sort.RadixSort(*data,2,10); 
	data->Print();

    return 0;
}

void generateData(int *data, int len)
{
	static int offset = 0;
	int start = 0;
	int end = 100;
	
	srand(unsigned(time(0) + offset));
    for(int icnt = 0; icnt < len; ++icnt)
        data[icnt] = start+(end-start)*rand()/RAND_MAX;

	offset += data[0];
}