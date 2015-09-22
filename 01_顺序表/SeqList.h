#ifndef __SEQLIST_H
#define __SEQLIST_H

#define OUTPUT_DEBUG 0

// 顺序表最大存储空间
const int DefaultSize=100;

template <typename Type> 
class SeqList {
public:
	SeqList(int sz=DefaultSize) : m_nmaxsize(sz),m_ncurrentsize(0) {
		if(sz>0) {
			m_elements=new Type[m_nmaxsize];
		}
	}

	~SeqList() {
		delete[] m_elements;
	}

	int Length() const{					//get the length
		return m_ncurrentsize;
	}

	int Find(Type x) const;				//find the position of x
	int IsElement(Type x) const;		//is it in the list
	int Insert(Type x,int i);			//insert data
	int Remove(Type x);					//delete data
	
	int IsEmpty() {
		return (m_ncurrentsize == 0);
	}

	int IsFull() {
		return (m_ncurrentsize == m_nmaxsize);
	}

	Type Get(int i) {					//get the ith data
		return (i < 0 || i>= m_ncurrentsize) ? ( cout<<"can't find the element" << endl, 0) : m_elements[i];
	}

	void Print();
private:
	Type *m_elements;
	const int m_nmaxsize;
	int m_ncurrentsize;
};


/*
	返回x在顺序表中所在的位置
*/
template <typename Type> 
int SeqList<Type>::Find(Type x) const {
	for(int i=0; i<m_ncurrentsize; i++)
		if(m_elements[i] == x)
			return i;
	cout<<"can't find the element you want to find"<<endl;
	return -1;
}

/*
	判断x是否存在于顺序表中
*/
template <typename Type> 
int SeqList<Type>::IsElement(Type x) const {
	if(Find(x)==-1)
		return 0;
	return 1;
}

/*
	将x插入i指定的位置
*/
template <typename Type>
int SeqList<Type>::Insert(Type x, int i) {
	if( (i < 0) || (i > m_ncurrentsize) || IsFull() ){
		cout << "the operate is illegal" << endl;
		return 0;
	}

	m_ncurrentsize++;
	for(int j = m_ncurrentsize -1; j > i; j--) {
		m_elements[j]=m_elements[j-1];
	}

	m_elements[i]=x;
	return 1;
}


template <typename Type> 
int SeqList<Type>::Remove(Type x) {
	int size = m_ncurrentsize;
	for(int i = 0 ; i < m_ncurrentsize;) {
		if(m_elements[i]==x){
			for(int j=i; j < m_ncurrentsize; j++) {
				m_elements[j]=m_elements[j+1];
			}

			m_ncurrentsize--;
			continue;
		}
		i++;
	}

	if(size == m_ncurrentsize){
		cout << "can't find the element you want to remove" << endl;
		return 0;
	}

	return 1;
}

template <typename Type> 
void SeqList<Type>::Print() {
#if OUTPUT_DEBUG
	for(int i=0; i<m_ncurrentsize; i++)
	{
		cout << i+1 << ":\t" << m_elements[i] << endl;
	}

	cout << endl << endl;
#endif
}

#endif
