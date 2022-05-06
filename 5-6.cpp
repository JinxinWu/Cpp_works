#include <iostream>

using namespace std;

class Person
{
public:
    Person(int num, string name) :_num(num), _name(name), _wage(0) {}
    void Set(int num, string name)
    {
        _num = num;
        _name = name;
    }
    virtual void IntroduceSelf()
    {
        cout << "编号:" << _num << " 姓名:" << _name << " 月工资:" << _wage << endl;
    }
    virtual void GetWage() = 0;
protected:
    double _wage;
private:
    int _num;
    string _name;
};

class Manager :public Person
{
public:
    Manager(int num, string name) :Person(num, name){}
    void GetWage()
    {
        _wage = 8000;
    }
    void IntroduceSelf()
    {
        cout << "这是一位经理" << endl;
        Person::IntroduceSelf();
    }
};

class Technician :public Person
{
public:
    Technician(int num, string name, double hour) :Person(num, name), _hour(hour) {}
    void GetWage()
    {
        _wage = _hour * 100;
    }
    void IntroduceSelf()
    {
        cout << "这是一位兼职技术人员" << endl;
        Person::IntroduceSelf();
    }
private:
    double _hour;
};

class Salesman : public Person
{
public:
    Salesman(int num, string name, double sales) :Person(num, name), _sales(sales) {}
    void GetWage()
    {
        _wage = _sales * 0.04 + _sales;
    }
    void IntroduceSelf()
    {
        cout << "这是一位销售员" << endl;
        Person::IntroduceSelf();
    }
private:
    double _sales;
};

class Salesmanager : public Person
{
public:
    Salesmanager(int num, string name, double sumSales) :Person(num, name), _sumSales(sumSales) {}
    void GetWage()
    {
        _wage = _sumSales * 0.005 + 5000;
    }
    void IntroduceSelf()
    {
        cout << "这是一位销售经理" << endl;
        Person::IntroduceSelf();
    }
private:
    double _sumSales;
};

int main()
{
    Person* p1 = new Manager(20, "wang");
    Person* p2 = new Technician(6, "he", 300);
    Person* p3 = new Salesman(99, "an", 2000);
    Person* p4 = new Salesmanager(12, "wu", 2000000);

    p1->GetWage();
    p1->IntroduceSelf();
    p2->GetWage();
    p2->IntroduceSelf();
    p3->GetWage();
    p3->IntroduceSelf();
    p4->GetWage();
    p4->IntroduceSelf();

    return 0;
}