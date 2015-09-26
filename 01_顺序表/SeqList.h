#ifndef __SEQLIST_H
#define __SEQLIST_H

#define OUTPUT_DEBUG 1

// 顺序表最大存储空间
const int DefaultSize=100;

template <typename Type> 
class SeqList 
{
public:
    SeqList(int sz = DefaultSize) : m_nmaxsize(sz), m_ncurrentsize(0) 
    {
        if(sz > 0) 
        {
            m_elements = new Type[m_nmaxsize];
        }
    }

    ~SeqList() {
        delete[] m_elements;
    }

    // 获取顺序表当前长度
    int Length() const
    {
        return m_ncurrentsize;
    }

    // 查询指定元素在顺序表中的位置
    int Find(Type x) const;

    // 判断指定元素是否在顺序表中
    bool IsElement(Type x) const;

    // 在顺序表的指定位置插入元素
    bool Insert(Type x,int i);

    // 在顺序表的头部插入元素
    bool InsertBefore(Type x);

    // 在顺序表的尾部插入元素
    bool InsertAfter(Type x);
    
    // 删除顺序表中指定位置的元素
    bool RemoveById(int i, Type& x);

    // 在顺序表中删除指定元素
    bool Remove(Type x);

    // 在顺序表中删除所有指定元素(有多个则都删除)
    bool RemoveAll(Type x);

    // 判断顺序表是否为空
    int IsEmpty() 
    {
        return (m_ncurrentsize == 0);
    }

    // 判断顺序表是否已满
    int IsFull() 
    {
        return (m_ncurrentsize == m_nmaxsize);
    }

    // 获取顺序表指定位置的元素
    bool Get(int i, Type& x)
    {
        if ((i < 0) || (i >= m_ncurrentsize))
        {
            cout << "[ERR][SeqList::Get] can't find the element" << endl;
            return false;
        }

        x = m_elements[i];
        return true;
    }

    // 在控制台输出顺序表内容
    void Print(char* pInfo = "");

private:
    Type *m_elements;       // 顺序表元素缓冲区指针
    const int m_nmaxsize;   // 顺序表最大长度
    int m_ncurrentsize;     // 顺序表当前长度
};


//功能描述：查询指定元素在顺序表中的位置
//输入参数：x    指定元素
//输出参数：无
//函数返回：失败返回-1，其他值为元素所在位置
template <typename Type> 
int SeqList<Type>::Find(Type x) const 
{
    for(int i = 0; i < m_ncurrentsize; i++)
    {
        if(m_elements[i] == x)
        {
            return i;
        }
    }

    cout << "[ERR][SeqList::Find] can't find the element you want to find" << endl;
    return -1;
}

//功能描述：判断x是否存在于顺序表中
//输入参数：x    指定元素
//输出参数：无
//函数返回：true-存在，false-不存在
template <typename Type> 
bool SeqList<Type>::IsElement(Type x) const 
{
    return (Find(x) != -1);
}

//功能描述：在指定位置插入元素
//输入参数：x    指定元素
//          i    指定位置
//输出参数：无
//函数返回：true-成功，false-失败
template <typename Type>
bool SeqList<Type>::Insert(Type x, int i) {
    if( (i < 0) || (i > m_ncurrentsize) || IsFull() ){
        cout << "[ERR][SeqList::Insert] the operate is illegal m_ncurrentsize = " << m_ncurrentsize << ", i = " << i << endl;
        return false;
    }

    m_ncurrentsize++;
    for(int j = m_ncurrentsize -1; j > i; j--) {
        m_elements[j] = m_elements[j-1];
    }

    m_elements[i] = x;
    return true;
}

//功能描述：在顺序表的头部插入元素
//输入参数：x    指定元素
//输出参数：无
//函数返回：true-成功，false-失败
template <typename Type>
bool SeqList<Type>::InsertBefore(Type x) {
    if (IsFull())
    {
        cout << "[ERR][SeqList::InsertBefore] full" << endl;
        return false;
    }

    return Insert(x, 0);
}

//功能描述：在顺序表的尾部插入元素
//输入参数：x    指定元素
//输出参数：无
//函数返回：true-成功，false-失败
template <typename Type>
bool SeqList<Type>::InsertAfter(Type x) {
    if (IsFull())
    {
        cout << "[ERR][SeqList::InsertBefore] full" << endl;
        return false;
    }

    return Insert(x, Length());
}

//功能描述：在顺序表中删除指定位置的元素
//输入参数：i    指定位置
//输出参数：x    被删除的元素
//函数返回：true-成功，false-失败
template <typename Type> 
bool SeqList<Type>::RemoveById(int i, Type& x) 
{
    if ((i < 0) || (i >= m_ncurrentsize))
    {
        cout << "[ERR][SeqList::RemoveById] , m_ncurrentsize = " << m_ncurrentsize << ", i = " << i << endl;
        return false;
    }

    if (IsEmpty())
    {
        cout << "[ERR][SeqList::RemoveById] empty" << endl;
        return false;
    }
    
    x = m_elements[i];
    for (int j = i; j < m_ncurrentsize-1; j++)
    {
        m_elements[j] = m_elements[j+1];
    }

    m_ncurrentsize--;

    return true;
}

//功能描述：在顺序表中删除指定元素
//输入参数：x    指定元素
//输出参数：无
//函数返回：true-成功，false-失败
template <typename Type> 
bool SeqList<Type>::Remove(Type x) 
{
    if (IsEmpty())
    {
        cout << "[ERR][SeqList::Remove] empty" << endl;
        return false;
    }

    bool bRet = true;
    int size = m_ncurrentsize;  // 开始删除前先保存当前长度
    int i;
    for(i = 0 ; i < m_ncurrentsize; i++)
    {
        if(m_elements[i] == x)
        {
            Type t;
            bRet = RemoveById(i, t);
            break;
        }
    }

    if (size == m_ncurrentsize)
    {
        cout << "[ERR][SeqList::Remove] can't find the element you want to remove : " << x << endl;
        bRet = false;
    }

    return bRet;
}

//功能描述：在顺序表中删除所有指定元素
//输入参数：x    指定元素
//输出参数：无
//函数返回：true-成功，false-失败
template <typename Type> 
bool SeqList<Type>::RemoveAll(Type x) 
{
    if (IsEmpty())
    {
        cout << "[ERR][SeqList::RemoveAll] empty" << endl;
        return false;
    }

    bool bRet = true;
    int size = m_ncurrentsize;

    for(int i = 0 ; i < m_ncurrentsize;) 
    {
        if(m_elements[i] == x)
        {
            Type t;
            bRet = RemoveById(i, t);
            if (!bRet)
            {
                cout << "[ERR][SeqList::RemoveAll] failed to call RemoveById" << endl;
                break;
            }

            // 如果成功删除了位置i的元素，则本轮i不用++
            continue;   
        }

        i++;
    }

    return bRet;
}


template <typename Type> 
void SeqList<Type>::Print(char* pInfo) 
{
#if OUTPUT_DEBUG
    cout << "SeqList - " << pInfo << endl;
    for(int i=0; i<m_ncurrentsize; i++)
    {
        cout << i << ":\t" << m_elements[i] << endl;
    }

    cout << endl << endl;
#endif
}

#endif
