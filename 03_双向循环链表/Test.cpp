#include <iostream>
#include <gtest/gtest.h>
#include "DoubleList.h"

using namespace std;

#pragma comment(lib,"../gtestd.lib")

int main()
{
	DoubleList<int> list;
	for(int i=0;i<20;i++){
		list.Insert(i*3,i);
	}
	cout<<"the Length of the list is "<<list.Length()<<endl;
	list.Print();
	for(int j=0;j<5;j++){
		list.Insert(3,j*3);
	}
	cout<<"the Length of the list is "<<list.Length()<<endl;
	list.Print();

	list.Remove(5);
	cout<<"the Length of the list is "<<list.Length()<<endl;
	list.Print();

	cout<<list.FindData(54)->GetData()<<endl;

	cout<<"The third element is "<<list.Get(3)<<endl;

	list.MakeEmpty();
	cout<<"the Length of the list is "<<list.Length()<<endl;
	list.Print();

	return 0;
}
