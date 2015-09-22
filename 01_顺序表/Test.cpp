#include <iostream>
#include "SeqList.h"

#include <ctime>
#include <gtest/gtest.h>
#pragma comment(lib,"../gtestd.lib")

using namespace std;

class ElementType;
ostream& operator<<(ostream& os, ElementType& data);

class ElementType
{
public:
	ElementType()
	{
	}

	ElementType(int fd, int sd)
	{
		firstData = fd;
		secondData = sd;
	}

public:
	int firstData;
	int secondData;

	bool operator==(const ElementType data) const;
	bool operator<(const ElementType data) const;
	bool operator>(const ElementType data) const;

	friend ostream& operator<<(ostream& os, ElementType& data);
};

bool ElementType::operator==(const ElementType data) const
{
	if (this->firstData == data.firstData && this->secondData == data.secondData)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

bool ElementType::operator<(const ElementType data) const
{
	if (this->firstData < data.firstData)
	{
		return 1;
	}
	else if (this->firstData == data.firstData)
	{
		if (this->secondData < data.secondData)
		{
			return 1;
		}
	}

	return 0;
}

bool ElementType::operator>(const ElementType data) const
{
	if (this->firstData > data.firstData)
	{
		return 1;
	}
	else if (this->firstData == data.firstData)
	{
		if (this->secondData > data.secondData)
		{
			return 1;
		}
	}

	return 0;
}

ostream& operator<<(ostream& os, ElementType& data)
{
	os << "(" << data.firstData << ", " << data.secondData << ")" << endl;
	return os;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////
//  Gtest
///////////////////////////////////////////////////////////////////////////////////////////////////////

TEST(SeqList, main)
{
	/////////////////////////////////////////////////////////////////////
	// 系统数据类型
	/////////////////////////////////////////////////////////////////////
	SeqList<int> intSeqList(15);
	ASSERT_TRUE(intSeqList.Length() == 0);

	srand(time(0));
	for(int i=0; i < 14; i++){
		EXPECT_TRUE(i == intSeqList.Length());
		EXPECT_TRUE(1 == intSeqList.Insert(rand() % 100, intSeqList.Length()));
	}
	intSeqList.Print();

	EXPECT_TRUE(1 == intSeqList.Insert(rand() % 100, intSeqList.Length()));
	EXPECT_TRUE(0 == intSeqList.Insert(rand() % 100, intSeqList.Length()));




	/*
	test.Insert(1,0);
	test.Print();

	cout << (test.Find(0)?"can't be found ":"Be found ") << 0 << endl <<endl;
	test.Remove(7);
	test.Print();
	test.Remove(9);
	test.Print();
	test.Remove(0);
	test.Print();
	*/
	/////////////////////////////////////////////////////////////////////
	// 自定义数据类型
	/////////////////////////////////////////////////////////////////////

}

int main(int argc, char** argv)
{
	/*
	SeqList<int> test(15);
	int array[]={2,5,8,1,9,9,7,6,4,3,2,9,7,7};
	for(int i=0; i < sizeof(array) / sizeof(int); i++){
		test.Insert(array[i], test.Length());
	}
	test.Print();

	test.Insert(1,0);
	test.Print();

	cout << (test.Find(0)?"can't be found ":"Be found ") << 0 << endl <<endl;
	test.Remove(7);
	test.Print();
	test.Remove(9);
	test.Print();
	test.Remove(0);
	test.Print();
	*/

	testing::InitGoogleTest(&argc,argv);
	int r = RUN_ALL_TESTS();

/*
	//自定义数据类型

	SeqList<ElementType> test(3);
	ElementType tmp1(2,1);
	test.Insert(tmp1,0);

	ElementType tmp2(1,2);
	test.Insert(tmp2,1);

	ElementType tmp3(2,2);
	test.Insert(tmp3,2);

	test.Print();

	ElementType tmp4(2,1);
	test.Remove(tmp4);
	test.Print();
*/

	return 0;
}
