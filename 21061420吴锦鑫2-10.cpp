/*��д���򣬽�һ�����Ƶ��Ͱ����еļ򵥼����࣬��Ӽ��Ͻ����ɾ��Ԫ�صȳ�
Ա�������ܣ�����д���Գ���*/
#include <iostream>
using namespace std;

class CSet
{
public:
    CSet();//���캯��
    bool Add(int x);//����Ԫ��
    void Display() const;//��ʾ����
    CSet Union(const CSet &rhs) const;//����
    CSet Intersect(const CSet &rhs) const;//����
    CSet Except(const CSet &rhs) const;//�
    bool In(int x) const;//�Ƿ����Ԫ��x
    void Delete(int x);//ɾ��Ԫ��
private:
    enum{MaxSIZE = 100};
    int m_iDatasA[MaxSIZE];//��СΪö�ٳ���MaxSIZE������
    int m_ICount;//��ʾ�����ڴ��Ԫ�صĸ���
};

CSet::CSet():m_ICount(0)//���캯��
{
}

bool CSet::Add(int x)//����Ԫ��
{
    if(In(x))//������Ԫ�ػ�����
        return false;
    if(m_ICount>=MaxSIZE)
        throw "OverFlow";//�����������׳��쳣����
    int i = m_ICount-1;
    while(i>=0&&x<m_iDatasA[i])//��ǰ����Ԫ�غ���
    {
        m_iDatasA[i+1]=m_iDatasA[i];
        i--;
    }
    m_iDatasA[i+1]=x;
    m_ICount++;
    return true;
}

void CSet::Display() const//��ʾ����
{
    cout<<"{";
    int i;
    for(i=0;i<m_ICount-1;i++)
        cout<<m_iDatasA[i]<<",";
    if(i<m_ICount)
        cout<<m_iDatasA[i];
    cout<<"}"<<endl;
}

CSet CSet::Union(const CSet &rhs) const//��������������ΪCSet
{
    CSet result;
    int i,j;
    i=j=0;
    while(i<m_ICount&&j<rhs.m_ICount)
    {
        if(result.m_ICount>=MaxSIZE)
            throw "OverFlow";//�����������׳��쳣����
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

CSet CSet::Intersect(const CSet &rhs) const//����
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

CSet CSet::Except(const CSet &rhs) const//�
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

bool CSet::In(int x) const//�Ƿ����Ԫ��x
{
    int i=0;
    while(i<m_ICount&&x>m_iDatasA[i])
        i++;
    if(i<m_ICount&&x==m_iDatasA[i])
        return true;
    return false;
}

void CSet::Delete(int x)//ɾ��Ԫ��
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

    cin>>m>>n>>k;//����A��
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




