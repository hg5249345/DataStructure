#include <iostream>
#include <gtest/gtest.h>
#include <ctime>
#include "SeqList.h"

using namespace std;

#pragma comment(lib,"../gtestd.lib")

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

TEST(SeqList, Int)
{
	/////////////////////////////////////////////////////////////////////
    // ϵͳ��������
    /////////////////////////////////////////////////////////////////////

	SeqList<int> intSeqList(15);
	ASSERT_TRUE(intSeqList.Length() == 0);

    // ˳����ʱɾ��ʧ��
    int tmp = 0;
    EXPECT_FALSE(intSeqList.RemoveById(3, tmp));
    EXPECT_FALSE(intSeqList.Remove(tmp));
    EXPECT_FALSE(intSeqList.RemoveAll(tmp));

    // ��ʼ��˳�������֤����
	srand(time(0));
	for(int i=0; i < 14; i++){
		EXPECT_TRUE(i == intSeqList.Length());
		EXPECT_TRUE(intSeqList.Insert(rand() % 100, intSeqList.Length()));
	}
	intSeqList.Print("insert 14 elements");

    // �������һ��Ԫ��
	tmp = rand() % 100;
	EXPECT_TRUE(intSeqList.Insert(tmp, intSeqList.Length()));
    intSeqList.Print("insert 14th element");

    // ���Ҳ����Ԫ��(��������ͬ��Ԫ��)
	//EXPECT_TRUE(14 == intSeqList.Find(tmp));
	EXPECT_TRUE(intSeqList.IsElement(tmp));

    // ˳����������޷���������
	EXPECT_FALSE(intSeqList.Insert(rand() % 100, intSeqList.Length()));
    intSeqList.Print("full, can't insert");

    // ��ȡ��5��Ԫ��
    int iGetData = 0;
    EXPECT_TRUE(intSeqList.Get(5, iGetData));

    // ɾ����5��Ԫ��
	EXPECT_TRUE(intSeqList.Remove(iGetData));
    intSeqList.Print("after remove");

    // ��ʱ˳�����һ��λ�ã�������Ԫ��
	EXPECT_TRUE(intSeqList.Insert(rand() % 100, intSeqList.Length()));
    intSeqList.Print("insert after remove");

    // ɾ������Ԫ��
    EXPECT_TRUE(intSeqList.RemoveById(6, tmp));
    EXPECT_TRUE(intSeqList.RemoveById(3, tmp));
    EXPECT_TRUE(intSeqList.RemoveById(10, tmp));

    // ��ͷ������һ��Ԫ��
    tmp = rand() % 100;
    EXPECT_TRUE(intSeqList.InsertBefore(tmp));
    iGetData = 0;
    EXPECT_TRUE(intSeqList.Get(0, iGetData));
    EXPECT_TRUE(tmp == iGetData);
    intSeqList.Print("insert a element before list");

    // ��β������һ��Ԫ��
    tmp = rand() % 100;
    EXPECT_TRUE(intSeqList.InsertAfter(tmp));
    iGetData = 0;
    EXPECT_TRUE(intSeqList.Get(intSeqList.Length()-1, iGetData));
    EXPECT_TRUE(tmp == iGetData);
    intSeqList.Print("insert a element after list");
}


TEST(SeqList, ElementType)
{
    /////////////////////////////////////////////////////////////////////
    // �Զ�����������
    /////////////////////////////////////////////////////////////////////

	SeqList<ElementType> elementSeqList(3);
    elementSeqList.Print();
    EXPECT_TRUE(0 == elementSeqList.Length());
	
    // ��������3��Ԫ��
	ElementType tmp1(1,2);
	EXPECT_TRUE(elementSeqList.Insert(tmp1,0));

	ElementType tmp2(3,4);
	EXPECT_TRUE(elementSeqList.Insert(tmp2,1));

	ElementType tmp3(5,6);
	EXPECT_TRUE(elementSeqList.Insert(tmp3,2));
    EXPECT_TRUE(3 == elementSeqList.Length());

    elementSeqList.Print("insert 3 elements");

    // ˳����������޷�����
	ElementType tmp4(7,8);
	EXPECT_FALSE(elementSeqList.Insert(tmp4,2));

    EXPECT_TRUE(elementSeqList.IsElement(tmp2));
	EXPECT_TRUE(elementSeqList.Remove(tmp2));
    EXPECT_FALSE(elementSeqList.IsElement(tmp2));
    EXPECT_TRUE(2 == elementSeqList.Length());
    elementSeqList.Print("remove an element");

    ElementType eRemoveData;
    EXPECT_TRUE(elementSeqList.RemoveById(1,eRemoveData));
    EXPECT_TRUE(1 == elementSeqList.Length());
    elementSeqList.Print("remove an element by id");

    // ˳���δ�������Բ���
	EXPECT_TRUE(elementSeqList.Insert(tmp4,1));
    EXPECT_TRUE(2 == elementSeqList.Length());
    elementSeqList.Print("insert an element");
}

int main(int argc, char** argv)
{
	testing::InitGoogleTest(&argc,argv);
	int r = RUN_ALL_TESTS();

	return 0;
}
