#include <iostream>
#include <string>

using namespace std;

class Shape
{
public:
	Shape() :_area(0) {}
	virtual double GetArea() = 0;
	virtual void Input() = 0;
	virtual void Show() = 0;
protected:
	double _area;
};

class Ractangle :public Shape
{
public:
	Ractangle(double length, double width) :_length(length), _width(width), Shape() {}
	double GetArea();
	void Input();
	void Show();
protected:
	double _length;
	double _width;
};
double Ractangle::GetArea()
{
	_area = _length * _width;
	return _area;
}
void Ractangle::Input()
{
	cin >> _length >> _width;
}
void Ractangle::Show()
{
	cout << "Ractangle" << endl << "length:" << _length << " width:" << _width << endl;
}

class Cube :public Ractangle
{
public:
	Cube(double length, double width, double height) :Ractangle(length, width), _height(height) {}
	double GetArea();
	void Input();
	void Show();
private:
	double _height;
};
double Cube::GetArea()
{
	_area = 2 * (_length * _width + _length * _height + _width * _height);
	return _area;
}
void Cube::Input()
{
	cin >> _length >> _width >> _height;
}
void Cube::Show()
{
	cout << "Cube" << endl << "length:" << _length << " width:" << _width << " height:" << _height << endl;
}

int main()
{
	Shape* p[3];
	string temp;
	string p1 = "Ractangle";
	string p2 = "Cube";
	for (int i = 0; i < 3; ++i)
	{
		cin >> temp;
		if (temp == p1)
		{
			p[i] = new Ractangle(0.00, 0.00);//此时要先new一个派生类对象
			p[i]->Input();
		}
		else if (temp == p2)
		{
			p[i] = new Cube(0.00, 0.00, 0.00);
			p[i]->Input();
		}
		else
		{
			cout << "输入错误";
			break;
		}
	}
	//输出
	double sum = 0.0;
	for (int i = 0; i < 3; ++i)
	{
		p[i]->Show();
		sum += p[i]->GetArea();
	}
	cout << "sum_area:" << sum;

	return 0;
}
