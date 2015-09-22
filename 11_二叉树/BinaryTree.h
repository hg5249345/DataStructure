#include "BinTreeNode.h"

template<typename Type> class BinaryTree{
public:
	BinaryTree():m_proot(NULL){}
	BinaryTree(const Type stop):m_stop(stop),m_proot(NULL){}
	BinaryTree(BinaryTree<Type>& copy);
	virtual ~BinaryTree(){
		m_proot->Destroy();
	}
	virtual bool IsEmpty(){		//is empty?
		return m_proot==NULL;
	}
	
	virtual BinTreeNode<Type> *GetLeft(BinTreeNode<Type> *current);	//get the left node
	virtual BinTreeNode<Type> *GetRight(BinTreeNode<Type> *current);//get the right node
	virtual BinTreeNode<Type> *GetParent(BinTreeNode<Type> *current);//ghe thd parent
	const BinTreeNode<Type> *GetRoot() const;	//get root
	
	virtual bool Insert(const Type item);		//insert a new node
	virtual BinTreeNode<Type> *Find(const Type item) const;	//find thd node with the data

	void InOrder();	
	void PreOrder();
	void PostOrder();

	int Size();		//get size
	int Height();	//get height

	BinaryTree<Type>& operator=(const BinaryTree<Type> copy);	//evaluate node

	friend bool operator==(const BinaryTree<Type> s,const BinaryTree<Type> t);//is equal?
	friend ostream& operator<<(ostream& ,BinaryTree<Type>&);	//output the data
	friend istream& operator>>(istream& ,BinaryTree<Type>&);	//input the data
		
private:
	Type m_stop;		//just using for input the data;
	BinTreeNode<Type> *m_proot;

	//find the parent of current in the tree with the root of start
	BinTreeNode<Type> *GetParent(BinTreeNode<Type> *start,BinTreeNode<Type> *current);
	void Print(BinTreeNode<Type> *start,int n=0);	//print the tree with the root of start
};

template<typename Type> BinaryTree<Type>::BinaryTree(BinaryTree<Type>& copy){
	if(copy.m_proot){
		this->m_stop=copy.m_stop;
	}
	m_proot=m_proot->Copy(copy.m_proot);
}
template<typename Type> BinTreeNode<Type>* BinaryTree<Type>::GetLeft(BinTreeNode<Type> *current){
	return m_proot&&current?current->m_pleft:NULL;
}

template<typename Type> BinTreeNode<Type>* BinaryTree<Type>::GetRight(BinTreeNode<Type> *current){
	return m_proot&&current?current->m_pright:NULL;
}

template<typename Type> const BinTreeNode<Type>* BinaryTree<Type>::GetRoot() const{
	return m_proot;
}

template<typename Type> BinTreeNode<Type>* BinaryTree<Type>::GetParent(BinTreeNode<Type> *start, BinTreeNode<Type> *current){
	if(start==NULL||current==NULL){
		return NULL;
	}
	if(start->m_pleft==current||start->m_pright==current){
		return start;
	}
	BinTreeNode<Type> *pmove;
	if((pmove=GetParent(start->m_pleft,current))!=NULL){//find the parent in the left subtree
		return pmove;
	}
	else{
		return GetParent(start->m_pright,current);	//find the parent in the right subtree
	}
}

template<typename Type> BinTreeNode<Type>* BinaryTree<Type>::GetParent(BinTreeNode<Type> *current){
	return m_proot==NULL||current==m_proot?NULL:GetParent(m_proot,current);	
}


template<typename Type> bool BinaryTree<Type>::Insert(const Type item){
	BinTreeNode<Type> *pstart=m_proot,*newnode=new BinTreeNode<Type>(item);
	if(m_proot==NULL){
		m_proot=newnode;
		return 1;
	}
	while(1){
		if(item==pstart->m_data){
			cout<<"The item "<<item<<" is exist!"<<endl;
			return 0;
		}
		if(item<pstart->m_data){
			if(pstart->m_pleft==NULL){
				pstart->m_pleft=newnode;
				return 1;
			}
			pstart=pstart->m_pleft;	//if less than the node then insert to the left subtree
		}
		else{
			if(pstart->m_pright==NULL){
				pstart->m_pright=newnode;
				return 1;
			}
			pstart=pstart->m_pright;//if more than the node then insert to the right subtree
		}
	}
}

template<typename Type> BinTreeNode<Type>* BinaryTree<Type>::Find(const Type item) const{
	BinTreeNode<Type> *pstart=m_proot;
	while(pstart){
		if(item==pstart->m_data){
			return pstart;
		}
		if(item<pstart->m_data){
			pstart=pstart->m_pleft;	//if less than the node then find in the left subtree
		}
		else{
			pstart=pstart->m_pright;//if more than the node then find in the right subtree
		}
	}
	return NULL;
}

template<typename Type> void BinaryTree<Type>::Print(BinTreeNode<Type> *start, int n){
	if(start==NULL){
		for(int i=0;i<n;i++){
			cout<<"     ";
		}
		cout<<"NULL"<<endl;
		return;
	}
	Print(start->m_pright,n+1);	//print the right subtree
	for(int i=0;i<n;i++){	//print blanks with the height of the node
		cout<<"     ";
	}
	if(n>=0){
		cout<<start->m_data<<"--->"<<endl;//print the node
	}
	Print(start->m_pleft,n+1);	//print the left subtree
}

template<typename Type> BinaryTree<Type>& BinaryTree<Type>::operator=(const BinaryTree<Type> copy){
	if(copy.m_proot){
		this->m_stop=copy.m_stop;
	}
	m_proot=m_proot->Copy(copy.m_proot);
    return *this;
}

template<typename Type> 
ostream& operator<<(ostream& os,BinaryTree<Type>& out)
{
	out.Print(out.m_proot);
	return os;
}

template<typename Type> 
istream& operator>>(istream& is,BinaryTree<Type>& in)
{
	Type item;
	cout<<"initialize the tree:"<<endl<<"Input data(end with "<<in.m_stop<<"!):";
	is>>item;
	while(item!=in.m_stop){	//m_stop is the end of input
		in.Insert(item);
		is>>item;
	}
	return is;
}

template<typename Type> bool operator==(const BinaryTree<Type> s,const BinaryTree<Type> t){
	return equal(s.m_proot,t.m_proot);
}

template<typename Type> void BinaryTree<Type>::InOrder(){
	this->m_proot->InOrder();
}

template<typename Type> void BinaryTree<Type>::PreOrder(){
	this->m_proot->PreOrder();
}

template<typename Type> void BinaryTree<Type>::PostOrder(){
	this->m_proot->PostOrder();
}

template<typename Type> int BinaryTree<Type>::Size(){
	return this->m_proot->Size();

}

template<typename Type> int BinaryTree<Type>::Height(){
	return this->m_proot->Height();
}
