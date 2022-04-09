/*设计一个圆类，使其具有计算设置半径、获取半径、计算面积、计算周长的功能，
实现这些成员函数，编写圆类测试程序*/
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
    cout<<"面积："<<S<<endl;
    cout<<"周长："<<C<<endl;
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










