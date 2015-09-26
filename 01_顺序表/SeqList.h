#ifndef __SEQLIST_H
#define __SEQLIST_H

#define OUTPUT_DEBUG 1

// ˳������洢�ռ�
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

    // ��ȡ˳���ǰ����
    int Length() const
    {
        return m_ncurrentsize;
    }

    // ��ѯָ��Ԫ����˳����е�λ��
    int Find(Type x) const;

    // �ж�ָ��Ԫ���Ƿ���˳�����
    bool IsElement(Type x) const;

    // ��˳����ָ��λ�ò���Ԫ��
    bool Insert(Type x,int i);

    // ��˳����ͷ������Ԫ��
    bool InsertBefore(Type x);

    // ��˳����β������Ԫ��
    bool InsertAfter(Type x);
    
    // ɾ��˳�����ָ��λ�õ�Ԫ��
    bool RemoveById(int i, Type& x);

    // ��˳�����ɾ��ָ��Ԫ��
    bool Remove(Type x);

    // ��˳�����ɾ������ָ��Ԫ��(�ж����ɾ��)
    bool RemoveAll(Type x);

    // �ж�˳����Ƿ�Ϊ��
    int IsEmpty() 
    {
        return (m_ncurrentsize == 0);
    }

    // �ж�˳����Ƿ�����
    int IsFull() 
    {
        return (m_ncurrentsize == m_nmaxsize);
    }

    // ��ȡ˳���ָ��λ�õ�Ԫ��
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

    // �ڿ���̨���˳�������
    void Print(char* pInfo = "");

private:
    Type *m_elements;       // ˳���Ԫ�ػ�����ָ��
    const int m_nmaxsize;   // ˳�����󳤶�
    int m_ncurrentsize;     // ˳���ǰ����
};


//������������ѯָ��Ԫ����˳����е�λ��
//���������x    ָ��Ԫ��
//�����������
//�������أ�ʧ�ܷ���-1������ֵΪԪ������λ��
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

//�����������ж�x�Ƿ������˳�����
//���������x    ָ��Ԫ��
//�����������
//�������أ�true-���ڣ�false-������
template <typename Type> 
bool SeqList<Type>::IsElement(Type x) const 
{
    return (Find(x) != -1);
}

//������������ָ��λ�ò���Ԫ��
//���������x    ָ��Ԫ��
//          i    ָ��λ��
//�����������
//�������أ�true-�ɹ���false-ʧ��
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

//������������˳����ͷ������Ԫ��
//���������x    ָ��Ԫ��
//�����������
//�������أ�true-�ɹ���false-ʧ��
template <typename Type>
bool SeqList<Type>::InsertBefore(Type x) {
    if (IsFull())
    {
        cout << "[ERR][SeqList::InsertBefore] full" << endl;
        return false;
    }

    return Insert(x, 0);
}

//������������˳����β������Ԫ��
//���������x    ָ��Ԫ��
//�����������
//�������أ�true-�ɹ���false-ʧ��
template <typename Type>
bool SeqList<Type>::InsertAfter(Type x) {
    if (IsFull())
    {
        cout << "[ERR][SeqList::InsertBefore] full" << endl;
        return false;
    }

    return Insert(x, Length());
}

//������������˳�����ɾ��ָ��λ�õ�Ԫ��
//���������i    ָ��λ��
//���������x    ��ɾ����Ԫ��
//�������أ�true-�ɹ���false-ʧ��
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

//������������˳�����ɾ��ָ��Ԫ��
//���������x    ָ��Ԫ��
//�����������
//�������أ�true-�ɹ���false-ʧ��
template <typename Type> 
bool SeqList<Type>::Remove(Type x) 
{
    if (IsEmpty())
    {
        cout << "[ERR][SeqList::Remove] empty" << endl;
        return false;
    }

    bool bRet = true;
    int size = m_ncurrentsize;  // ��ʼɾ��ǰ�ȱ��浱ǰ����
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

//������������˳�����ɾ������ָ��Ԫ��
//���������x    ָ��Ԫ��
//�����������
//�������أ�true-�ɹ���false-ʧ��
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

            // ����ɹ�ɾ����λ��i��Ԫ�أ�����i����++
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
