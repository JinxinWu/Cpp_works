/*编写程序，进一步完善典型案例中的简单集合类，添加集合交、差、删除元素等成
员函数功能，并编写测试程序。*/
#include <iostream>
using namespace std;

class CSet
{
public:
    CSet();//构造函数
    bool Add(int x);//增加元素
    void Display() const;//显示集合
    CSet Union(const CSet &rhs) const;//并集
    CSet Intersect(const CSet &rhs) const;//交集
    CSet Except(const CSet &rhs) const;//差集
    bool In(int x) const;//是否包含元素x
    void Delete(int x);//删除元素
private:
    enum{MaxSIZE = 100};
    int m_iDatasA[MaxSIZE];//大小为枚举常量MaxSIZE的数组
    int m_ICount;//表示数组内存放元素的个数
};

CSet::CSet():m_ICount(0)//构造函数
{
}

bool CSet::Add(int x)//增加元素
{
    if(In(x))//集合中元素互异性
        return false;
    if(m_ICount>=MaxSIZE)
        throw "OverFlow";//集合已满，抛出异常处理
    int i = m_ICount-1;
    while(i>=0&&x<m_iDatasA[i])//从前往后，元素后移
    {
        m_iDatasA[i+1]=m_iDatasA[i];
        i--;
    }
    m_iDatasA[i+1]=x;
    m_ICount++;
    return true;
}

void CSet::Display() const//显示集合
{
    cout<<"{";
    int i;
    for(i=0;i<m_ICount-1;i++)
        cout<<m_iDatasA[i]<<",";
    if(i<m_ICount)
        cout<<m_iDatasA[i];
    cout<<"}"<<endl;
}

CSet CSet::Union(const CSet &rhs) const//并集，返回类型为CSet
{
    CSet result;
    int i,j;
    i=j=0;
    while(i<m_ICount&&j<rhs.m_ICount)
    {
        if(result.m_ICount>=MaxSIZE)
            throw "OverFlow";//集合已满，抛出异常处理
        if(m_iDatasA[i]<rhs.m_iDatasA[j])
        {
            result.m_iDatasA[result.m_ICount++]=m_iDatasA[i];
            i++;
        }
        else if(m_iDatasA[i]==rhs.m_iDatasA[j])
        {
            result.m_iDatasA[result.m_ICount++]=m_iDatasA[i];
            i++;
            j++;
        }
        else
        {
            result.m_iDatasA[result.m_ICount++]=rhs.m_iDatasA[j];
            j++;
        }
    }
    while(i<m_ICount)
    {
        if(result.m_ICount>=MaxSIZE)
            throw "OverFlow";
        result.m_iDatasA[result.m_ICount++]=m_iDatasA[i];
        i++;
    }
    while(j<rhs.m_ICount)
    {
        if(result.m_ICount>=MaxSIZE)
            throw "OverFlow";
        result.m_iDatasA[result.m_ICount++]=rhs.m_iDatasA[j];
        j++;
    }
    return result;
}

CSet CSet::Intersect(const CSet &rhs) const//交集
{
    CSet result;
    int i,j;
    i=j=0;
    for(i=0;i<m_ICount;i++)
    {
        for(j=0;j<rhs.m_ICount;j++)
        {
            if(m_iDatasA[i]==rhs.m_iDatasA[j])
            {
                result.m_iDatasA[result.m_ICount++]=m_iDatasA[i];
                //cout<<"<"<<m_iDatasA[i]<<">";
            }
        }
    }
    return result;
}

CSet CSet::Except(const CSet &rhs) const//差集
{
    CSet result;
    int i,j,flag=1;
    for(i=0;i<m_ICount;i++)
    {
        for(j=0;j<rhs.m_ICount;j++)
        {
            if(m_iDatasA[i]==rhs.m_iDatasA[j])
                flag=0;
        }
        if(flag==1)
        {
            result.m_iDatasA[result.m_ICount++]=m_iDatasA[i];
            //cout<<"2 ";
        }
    }
    return result;
}

bool CSet::In(int x) const//是否包含元素x
{
    int i=0;
    while(i<m_ICount&&x>m_iDatasA[i])
        i++;
    if(i<m_ICount&&x==m_iDatasA[i])
        return true;
    return false;
}

void CSet::Delete(int x)//删除元素
{
    int i;
    for(i=0;i<m_ICount;i++)
    {
        if(x==m_iDatasA[i])
        {
            int m=i;
            while(m<m_ICount)
            {
                m_iDatasA[m]=m_iDatasA[m+1];
                m++;
            }
            m_ICount--;
        }
    }
}

int main()
{
    CSet A,B,S,R,T;
    int i,m,n,k,x;

    cin>>m>>n>>k;//建立A集
    for(i=0;i<m;i++)
    {
        cin>>x;
        A.Add(x);
    }
    for(i=0;i<n;i++)
    {
        cin>>x;
        B.Add(x);
    }

    A.Display();
    B.Display();

    S=A.Union(B);
    S.Display();

    R=A.Intersect(B);
    R.Display();

    T=A.Except(B);
    T.Display();

    S.Delete(k);
    S.Display();
}




