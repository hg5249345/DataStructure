template<typename Type> 
class QueueNode {
public:
	QueueNode(Type item)
	{
		m_data = item;
	}

public:
	Type m_data;
	QueueNode<Type> *m_pnext;
};