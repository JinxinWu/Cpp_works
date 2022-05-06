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
        cout << "名字：" << _name << "性别：" << _sex << "年龄" << _age << endl;
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
        cout << "是一位目前在学课程" << _classNum << "门的学生" << endl;
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
        cout << "是一位目前每周授课" << _classNum << "学时的老师" << endl;
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
    HDUPerson* p1 = new Student("Tom", "男", 18, 6);
    HDUPerson* p2 = new Teacher("Marry", "女", 31, 8);
    p1->IntroduceSelf();
    p2->IntroduceSelf();
    return 0;
}