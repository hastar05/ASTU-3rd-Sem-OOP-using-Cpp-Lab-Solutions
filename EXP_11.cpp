#include <iostream>
#include <stdio.h>

using namespace std;

//declaration of class IntArr
class IntArr
{
	//declaration of private data members
	private:
		int *arr;
		int cap;
		int noOfele;

	public:
		//constructor to initialize array to zero
		IntArr(int ca)
		{
			cap = ca;
			noOfele = 0;
			arr = new int[cap];
			cout << "Capacity of array = " << cap;
		}
	
		//destructor to delete array
		~IntArr()
		{
			delete[] arr;
		}
		
		//add function to assign values to the array
		void add (int el)
		{
			cout << "\n\nEnter " << el <<" elements:\n";
			for (int i = noOfele; i < el + noOfele; i++)
			{
				cout << "\tElement " << i + 1 << ": ";
				cin >> arr[i];
			}
			cout << "\nEntered elements are: ";
			for (int i = 0; i < el + noOfele; i++)
				cout<<arr[i]<<", ";
			
			noOfele = el;

		}
		
		//expand function to increase capacity of the array
		void expand(int ca)
		{
			cap = ca;
			int *temp = new int[cap];
			for (int i = 0; i < noOfele; i++)
			{
				temp[i] = arr[i];
			}
			delete[] arr;
			arr = temp;
		}
};

//main function to test IntArr class
int main()
{
	IntArr arr(10);
	arr.add(5);
	arr.expand(15);
	arr.add(10);
	return 0;
}
