#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iomanip>

using namespace std;

char x;
int nob = 0, _prev = 0;

class library
{
	private:
		int stock, nissue;
		float price;
		char *btitle, *author, *publisher;
		
	public:
		library()
		{
			btitle = new char[20];
			author = new char[20];
			publisher = new char[30];
			strcpy (btitle, "NULL");
			strcpy (author, "NULL");
			strcpy (publisher, "NULL");
			price = 0;
			stock = 0;
			nissue = 0;
		}
		
		void initialise();
		void issue(int);
		void retrn(int);
		void display();
		string BTitle()
		{
		    return btitle;
		}
		
		string BAuthor()
		{
			return author;
		}
		~library()
		{
			delete[] btitle;
			delete[] author;
			delete[] publisher;		
		}
		
		
}B[10];

void Disp (int num, library B[]);

int main()
{
	int x, num = 1, i, flag = 0, n, add = 0;
	char ch, btit[20], baut[20];
	
	while (1)
	{
		cout << "\t*********\n";
		cout << "\tMAIN MENU\n";
		cout << "   1. Enter data\n";
		cout << "   2. Display data\n";
		cout << "   3. Issue a book\n";
		cout << "   4. Return a book\n";
		cout << "   5. Exit\n";
		cout << "\t*********\n\n";
		cout << "Enter your choice: ";
		cin >> x;
		cout << "\n";
		switch(x)
		{
			case 1:	cout << "Enter the number of records you would like to enter (<10): ";
					cin >> num;
					add = nob + num;
					cout << endl;
					for(i = _prev; i < add; ++i)
					{
						cout << "\nFor Book No. "<< i + 1 << "\n";
						B[i].initialise();
						nob++;
					}
					_prev = nob;
					break;
				
			case 2:	Disp (num,B);
					break;
				
			case 3:	{
						flag = 0;
						while ((x = getchar()) != '\n' && x != EOF);
						cout << "Enter the Book Title: ";
						fgets (btit, 20, stdin);
						btit[strcspn(btit, "\n")] = 0;
						
						cout << "Enter the author's name: ";
						fgets (baut, 20, stdin);
						baut[strcspn(baut, "\n")] = 0;
						
						cout << endl;
						
						for(i = 0; i < nob; ++i)
						{
						 	if ((B[i].BTitle().compare (btit) == 0) && (B[i].BAuthor().compare (baut) == 0))
							{
								cout.setf(ios::left);
								cout << setw(22) << "Title";
								cout << setw(22) << "Author";
								cout << setw(22) << "Publisher";
								cout << setw(15) << "Price";
								cout << "No. of copies in stock\n";
								cout << "________________________________________________________________________________________________________________________\n";
								B[i].display();
								cout << "\nEnter the number of copies to issue: ";
								cin >> n;
							 	B[i].issue(n);
							 	flag = 1;
							 	break;
							}
						}
						
						if (flag == 0)
						{
							cout << "\nBOOK UNAVAILABLE!";
						}					
						
						break;	
					}	
					
				
			case 4:	{
						flag = 0;
						while ((x = getchar()) != '\n' && x != EOF);
						cout << "Enter the Book Title: ";
						fgets (btit, 20, stdin);
						btit[strcspn(btit, "\n")] = 0;
						
						
						for(i = 0; i < nob; ++i)
						{
						 	if ((B[i].BTitle().compare (btit) == 0))
							{
								cout << "Enter the no. of copies to return: ";
								cin >> n;
								B[i].retrn(n);
								flag = 1;
								break;
							}
						}
						
						if (flag == 0)
						{
							cout << "\nBOOK UNAVAILABLE!";
						}
						break;	
					}
					
				
			case 5:	exit(0);
					break;
				
			default: 
					cout<<"INVALID INPUT!";
					break;
		}
		cout << "\n\n";
	}
}

void library::initialise()
{
	
		while ((x = getchar()) != '\n' && x != EOF);
		cout << "\tBook Title: ";
		fgets (btitle, 20, stdin);
		btitle[strcspn(btitle, "\n")] = 0;

		cout << "\tAuthor: ";
		fgets (author, 20, stdin);
		author[strcspn(author, "\n")] = 0;

		cout << "\tPublisher: ";
		fgets (publisher, 30, stdin);
		publisher[strcspn(publisher, "\n")] = 0;

		cout << "\tBook Price: ";
		cin >> price;
		cout << "\tNumber of copies in stock: ";
		cin >> stock;
}

void library::issue (int n)
{
	if (stock < n)
	{
		cout << "\nRequired copies not in stock\n";
		return;
	}

	cout << endl << n << " copies of '" << btitle << "' SUCCESSFULLY ISSUED!\n";
	nissue += n;
	stock -= n;;		
}

void library::retrn(int n)
{
	if (nissue == 0)
	{
		cout << "\nBook Not Issued!\n";
		return;
	}
	
	if (nissue < n)
	{
		cout << "INSUFFIENT COPIES";
		return;
	}

	cout << "BOOK RETURNED SUCCESSFULLY!!!\n";
	stock += n;
	nissue -= n;	
}

void library::display()
{
	cout << setw(22) << btitle;
	cout << setw(22) << author;
	cout << setw(22) << publisher;
	cout << setw(15) << price;
	cout << stock;
	cout << endl;
}

void Disp (int num, library B[])
{
	cout.setf (ios::left);
	cout << setw(15) << "Serial No.";
	cout << setw(22) << "Title";
	cout << setw(22) << "Author";
	cout << setw(22) << "Publisher";
	cout << setw(15) << "Price";
	cout << "No. of copies in stock\n";
	cout << "________________________________________________________________________________________________________________________\n";
	
	for (int i = 0; i < nob; ++i)
	{
		cout.setf (ios::left);
		cout << setw(15) << i + 1;	
		B[i].display();		
	}
	cout<<endl;
}
