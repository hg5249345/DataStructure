# DataStructure
20150922 gtestd.lib is the output of gmock

#01_顺序表:
// 获取顺序表当前长度
int Length() const

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
int IsEmpty();
}

// 判断顺序表是否已满
int IsFull();

// 获取顺序表指定位置的元素
bool Get(int i, Type& x);

// 在控制台输出顺序表内容
void Print(char* pInfo = "");


