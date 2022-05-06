#include <iostream>

using namespace std;

class HDUPerson
{
public:
    HDUPerson(string name, string sex, int age):_name(name),_sex(sex),_age(age){}
    void Set(string name, string sex, int age)
    {
        _name = name;
        _sex = sex;
        _age = age;
    }
    void Get()
    {
        cout << "���֣�" << _name << "�Ա�" << _sex << "����" << _age << endl;
    }
    virtual void IntroduceSelf()
    {
        cout << _name << " " << _sex << " " << _age << endl;
    }
    virtual void GetCurrentNum() = 0;
private:
    string _name;
    string _sex;
    int _age;
};

class Student :public HDUPerson
{
public:
    Student(string name, string sex, int age,int classNum):HDUPerson(name,sex,age),_classNum(classNum){}
    void IntroduceSelf();
    void GetCurrentNum()
    {
        cout << "��һλĿǰ��ѧ�γ�" << _classNum << "�ŵ�ѧ��" << endl;
    }
private:
    int _classNum;
};
void Student::IntroduceSelf()
{
    HDUPerson::IntroduceSelf();
    GetCurrentNum();
}

class Teacher :public HDUPerson
{
public:
    Teacher(string name, string sex, int age, int classNum) :HDUPerson(name, sex, age), _classNum(classNum) {}
    void IntroduceSelf();
    void GetCurrentNum()
    {
        cout << "��һλĿǰÿ���ڿ�" << _classNum << "ѧʱ����ʦ" << endl;
    }
private:
    int _classNum;
};
void Teacher::IntroduceSelf()
{
    HDUPerson::IntroduceSelf();
    GetCurrentNum();
}

int main()
{
    HDUPerson* p1 = new Student("Tom", "��", 18, 6);
    HDUPerson* p2 = new Teacher("Marry", "Ů", 31, 8);
    p1->IntroduceSelf();
    p2->IntroduceSelf();
    return 0;
}