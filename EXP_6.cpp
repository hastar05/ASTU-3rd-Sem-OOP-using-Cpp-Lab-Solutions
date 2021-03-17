#include <iostream>
using namespace std;

class shape
{
	protected:
		double para1, para2;
	public:
		void get_data(float a, float b)
		{
			para1 = a;
			para2 = b;
		} 
		virtual void display_area() = 0;
};

class triangle: public shape
{
	public:
		void display_area()
		{
			cout << "Area of triangle with base = " << para1 << " and height = " << para2 << " is: " << 0.5*para1*para2;
		}
};

class rectangle: public shape
{
	public:
		void display_area()
		{
			cout << "Area of rectangle with length = " << para1 << " and breadth = " << para2 << " is: " << para1*para2;
		}
};

int main()
{
	int c;
	shape *s;
	cout << "1. Triangle\n2. Rectangle\n";
	cout << "\nEnter your choice (1-2): ";
	cin >> c;
	cout << endl;
	if (c == 1)
	{
		s = new triangle;
		s -> get_data(10.13, 20.66);
	}
	else if (c == 2)
	{
		s = new rectangle;
		s -> get_data(10.48, 30.18);
	}
	
	s -> display_area();
	cout << endl;
	return 0;
}
