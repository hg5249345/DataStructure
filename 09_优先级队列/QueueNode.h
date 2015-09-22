template<typename Type,typename Cmp> class PriorityQueue;

template<typename Type,typename Cmp> 
class QueueNode
{
private:
	friend class PriorityQueue<Type,Cmp>;
	QueueNode(const Type item,QueueNode<Type,Cmp> *next=NULL)
		:m_data(item),m_pnext(next){}

	friend ostream& operator<<(ostream& ,QueueNode<Type, Cmp>&);
private:
	Type m_data;
	QueueNode<Type,Cmp> *m_pnext;
};

template<typename Type,typename Cmp>
ostream& operator<<(ostream& os,QueueNode<Type, Cmp>& out){
	os << out.m_data;
	return os;
}
