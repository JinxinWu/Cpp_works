/*���һ��Բ�࣬ʹ����м������ð뾶����ȡ�뾶����������������ܳ��Ĺ��ܣ�
ʵ����Щ��Ա��������дԲ����Գ���*/
#include <iostream>

using namespace std;
#define PI 3.141592653589793

class CCircle
{
public:
    CCircle(double x);
    ~CCircle();
    void Calculation_S(double x);
    void Calculation_C(double x);
    void Show() const;
private:
    double S;
    double C;
};

CCircle::CCircle(double x)
{
    cout<<"circle construct<"<<x<<">"<<endl;
}
CCircle::~CCircle()
{
    cout<<"destruct circle"<<endl;
}
void CCircle::Calculation_S(double x)
{
    S=PI*PI*x;
}
void CCircle::Calculation_C(double x)
{
    C=2*PI*x;
}
void CCircle::Show() const
{
    cout<<"�����"<<S<<endl;
    cout<<"�ܳ���"<<C<<endl;
}
int main(){
    double a;
    cin>>a;
	CCircle Circle1(a);
	Circle1.Calculation_S(a);
	Circle1.Calculation_C(a);
	Circle1.Show();
	cin>>a;
	CCircle Circle2(a);
	Circle2.Calculation_S(a);
	Circle2.Calculation_C(a);
	Circle2.Show();
	return 0;
}










