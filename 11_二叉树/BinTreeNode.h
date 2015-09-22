template<typename Type> class BinaryTree;

template<typename Type> class BinTreeNode{
public:
	friend class BinaryTree<Type>;
	BinTreeNode():m_pleft(NULL),m_pright(NULL){}
	BinTreeNode(Type item,BinTreeNode<Type> *left=NULL,BinTreeNode<Type> *right=NULL)
		:m_data(item),m_pleft(left),m_pright(right){}

	Type GetData() const;		//get thd data
	BinTreeNode<Type> *GetLeft() const;		//get the left node
	BinTreeNode<Type> *GetRight() const;	//get the right node

	void SetData(const Type data);			//change the data
	void SetLeft(const BinTreeNode<Type> *left);	//change thd left node
	void SetRight(const BinTreeNode<Type> *right);	//change the right node

	void InOrder();		//inorder the tree with the root of the node
	void PreOrder();	//perorder the tree with the root of the node
	void PostOrder();	//postoder the tree with the root of the node
	
	int Size();			//get size
	int Height();		//get height
	BinTreeNode<Type> *Copy(const BinTreeNode<Type> *copy);	//copy the node
	void Destroy(){		//destroy the tree with the root of the node
		if(this!=NULL){
			this->m_pleft->Destroy();
			this->m_pright->Destroy();
			delete this;
		}
	}

	friend bool equal(const BinTreeNode<Type> *s, const BinTreeNode<Type> *t);	//is equal?

private:
	BinTreeNode<Type> *m_pleft,*m_pright;
	Type m_data;
};

template<typename Type> Type BinTreeNode<Type>::GetData() const{
	return this!=NULL?m_data:-1;
}

template<typename Type> BinTreeNode<Type>* BinTreeNode<Type>::GetLeft() const{
	return this!=NULL?m_pleft:NULL;
}

template<typename Type> BinTreeNode<Type>* BinTreeNode<Type>::GetRight() const{
	return this!=NULL?m_pright:NULL;
}

template<typename Type> void BinTreeNode<Type>::SetData(const Type data){
	if(this!=NULL){
		m_data=data;
	}
}

template<typename Type> void BinTreeNode<Type>::SetLeft(const BinTreeNode<Type> *left){
	if(this!=NULL){
		m_pleft=left;
	}
}

template<typename Type> void BinTreeNode<Type>::SetRight(const BinTreeNode<Type> *right){
	if(this!=NULL){
		m_pright=right;
	}
}

template<typename Type> BinTreeNode<Type>* BinTreeNode<Type>::Copy(const BinTreeNode<Type> *copy){
	if(copy==NULL){
		return NULL;
	}

	BinTreeNode<Type> *temp=new BinTreeNode<Type>(copy->m_data);
	temp->m_pleft=Copy(copy->m_pleft);
	temp->m_pright=Copy(copy->m_pright);
	return temp;
}

template<typename Type> bool equal(const BinTreeNode<Type> *s,const BinTreeNode<Type> *t){
	if(s==NULL&&t==NULL){
		return 1;
	}
	if(s&&t&&s->m_data==t->m_data&&equal(s->m_pleft,t->m_pleft)&&equal(s->m_pright,t->m_pright)){
		return 1;
	}
	return 0;
}

//ÖÐÐò±éÀú
template<typename Type> void BinTreeNode<Type>::InOrder(){
	if(this!=NULL){
		this->m_pleft->InOrder();
		cout<<"--->"<<this->m_data;
		this->m_pright->InOrder();
	}
}

template<typename Type> void BinTreeNode<Type>::PreOrder(){
	if(this!=NULL){
		cout<<"--->"<<this->m_data;
		this->m_pleft->PreOrder();
		this->m_pright->PreOrder();
	}
}

template<typename Type> void BinTreeNode<Type>::PostOrder(){
	if(this!=NULL){
		this->m_pleft->PostOrder();
		this->m_pright->PostOrder();
		cout<<"--->"<<this->m_data;
	}
}

template<typename Type> int BinTreeNode<Type>::Size(){
	if(this==NULL){
		return 0;
	}
	return 1+this->m_pleft->Size()+this->m_pright->Size();
}

template<typename Type> int BinTreeNode<Type>::Height(){
	if(this==NULL){
		return -1;
	}
	int lheight,rheight;
	lheight=this->m_pleft->Height();
	rheight=this->m_pright->Height();
	return 1+(lheight>rheight?lheight:rheight);
}
