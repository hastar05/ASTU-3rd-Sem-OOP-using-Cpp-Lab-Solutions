#include<iostream>
#include<stdio.h>

using namespace std;

class FLOAT
{
	private:
		float x;
	
	public:
		void setData(int a)
		{
			x = a;
		}
		
		void getData()
		{
			cout << x << endl;
		}
		
		//Defining an operator function + to overload
		FLOAT operator +(FLOAT f)
		{
			FLOAT temp;
			temp.x = x + f.x;
			return temp;
		}
		
		//Defining an operator function - to overload
		FLOAT operator -(FLOAT f)
		{
			FLOAT temp;
			temp.x = x - f.x;
			return temp;
		}
		//Defining an operator function * to overload
		FLOAT operator *(FLOAT f)
		{
			FLOAT temp;
			temp.x = x * f.x;
			return temp;
		}
		
		//Defining an operator function / to overload
		FLOAT operator /(FLOAT f)
		{
			FLOAT temp;
			temp.x = x / f.x;
			return temp;
		}
};

int main()
{
	FLOAT f1, f2, f3, f4, f5, f6;
	
	f1.setData (20);
	f2.setData (10);
	
	//Overloading operator +
	f3 = f1 + f2;
	cout << "20 + 10 = ";
	f3.getData();
	
	//Overloading operator -
	f4 = f1 - f2;
	cout << "20 - 10 = ";
	f4.getData();
	
	//Overloading operator *
	f5 = f1 * f2;
	cout << "20 * 10 = ";
	f5.getData();

	//Overloading operator /
	f6 = f2 / f1;
	cout << "10 / 20 = ";
	f6.getData();
	return 0;
}
