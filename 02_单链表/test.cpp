#include <iostream>
using namespace std;

#include "SingleList.h"


int main()
{
	SingleList<int> list;
	for(int i=0; i<20; i++){
		list.Insert(i*3, i);
	}

	for(int j=0; j<5; j++){
		list.Insert(3, j*3);
	}

	cout<<"the Length of the list is "<<list.Length()<<endl;
	list.Print();

	list.Remove(5);
	cout<<"the Length of the list is "<<list.Length()<<endl;
	list.Print();

	cout << *list.Find(3,6) << endl;

	list.RemoveAll(3);
	cout << "the Length of the list is " << list.Length() << endl;
	list.Print();

	cout << "The third element is " << list.Get(3) << endl;

	ListNode<int> *pData = list.Find(18,2);
	if (pData != NULL)
	{
		cout << *pData << endl;
	} 
	else
	{
		cout << "NULL" << endl;
	}
	

	list.Find(100);

	list.MakeEmpty();
	cout<<"the Length of the list is "<<list.Length()<<endl;
	list.Print();

	return 0;
}
