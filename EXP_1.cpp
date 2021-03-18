#include <iostream>
#include <iomanip>
#include <string.h>
#include <stdlib.h>

const int noc = 10;

using namespace std;

class Banking
{
	char name[40];
	long int ac;
	char type[22];
	double balance;
	double deposit;
	double withdraw;
	
	public:
		Banking()
        {
            strcpy (name, "NULL");
            ac = 0;
            strcpy (type, "NULL");   
            balance = 0;
        }
        void ReadData();
		void Deposit();
		void Withdraw();
		void Display();
		int Ac()
		{
			return ac;
		}
};


void Disp (Banking B[]);

int main()
{
	Banking B[10];
	int choice;
	char ch;
	int acno;
	
	while (1)
	{
		cout << "\t  *MAIN MENU*" << endl;
		cout << "\t1. Enter Data." << endl;
		cout << "\t2. Display Data." << endl;
		cout << "\t3. Withdraw cash." << endl;
		cout << "\t4. Deposit cash." << endl;
		cout << "\t5. Exit." << "\n\n";
		cout << "Enter your choice (1-5): ";
		cin >> choice;
		cout << endl;
		
		switch(choice)
		{
			case 1: 
                    {
                        cout << "\nEnter data for " << noc << " customers:\n\n";
        				for (int i = 0; i < noc; ++i)
        				{
        				    cout << "For Customer No." << i + 1 << ":\n";
        					B[i].ReadData();
        				}
        				break;    
                    }
    				
			case 2: Disp (B);
				    break;
				    
			case 3:	cout << "Enter the Account No. of the customer who wants to withdraw cash: ";
    				cin >> acno;
    				
    				for (int i = 0; i < noc; ++i)
    				{
    				    if (acno == B[i].Ac())
    					{
    					    B[i].Withdraw();
    						break;
    					}
    					
    					if (i == noc - 1)
    					{
    						 cout << "INVALID ACCOUNT NUMBER!" << "\n";
    						 break;
    				    }
    				}
    				break;
    				
			case 4: cout<<"Enter the Account No. of the customer who wants to deposit cash: ";
    				cin>>acno;
    				
    				for (int i = 0; i < noc; ++i)
    				{
    				    if (acno == B[i].Ac())
    					{
    					    B[i].Deposit();
    					    cout << "Deposit successful!\n";
    					    break;
    					}
    					
                        if(i == noc - 1)
    					{
    					    cout<<"INVALID ACCOUNT NUMBER!"<<"\n";
    					    break;	
    					}
					}
					break;
					
			case 5: exit(0);
					break;
					
			default: 
                    cout<<"\nINVALID CHOICE!";
					break;
		}
		cout << endl;
    }
	return 0;
}


void Banking::Deposit()
{
	cout << "Enter the amount to deposit: ";
	cin >> deposit;
	cout << endl;
	balance += deposit; 
}

void Banking::Withdraw()
{
	cout << "Enter the amount to withdraw: ";
	cin >> withdraw;
	if (withdraw > balance)
	{
	    cout  << "\nINSUFFICIENT BALANCE!\n";
	    return;
    }
	cout << "\n";
	balance -= withdraw;
	cout << "Withdraw successful!\n";
}

void Banking::ReadData()
{
    int num, flag = 1;
	cin.ignore();
	cout << "\tCustomer Name: ";
	fgets(name, 40, stdin);
	name[strcspn(name, "\n")] = 0;
	cout << "\tAccount Number: ";
	cin >> ac;
	
	cin.ignore();
	cout << "\tType of account:\n\t\t1. Savings\n\t\t2. Current\n\t\t3. Fixed Deposit";
	while (flag == 1)
	{
	    cout << "\n\tYour answer (1-3): ";
    	cin >> num;
    	if (num == 1)
    	{
    	   strcpy (type, "Savings Account");
           flag = 0;     
        }
        if (num == 2)
        {
            strcpy (type, "Current account");    
            flag = 0;
        }
        if (num == 3)
        {
            strcpy (type, "Fixed Deposit account");
            flag = 0;   
        }
        if (num < 1 || num > 3) 
        {
            cout << "\tINVALID TYPE! Enter a valid type.";
            flag = 1;    
        }
    }

	cout << "\tOpening Balance: ";
	cin >> balance;
	cout << "\n\n";
}

void Banking::Display()
{
	cout << setw(30) << name;
	cout << setw(15) << fixed << setprecision(2) << balance;
	cout << endl; 
}

void Disp (Banking B[])
{
	cout.setf (ios::left);
	cout << setw(15) << "SERIAL NO.";
	cout << setw(30) << "NAME";
	cout << setw(15) << "BALANCE";
	cout << endl;
	
    for (int i = 0; i < noc; ++i)
	{
	    cout.setf (ios::left);
	    cout << setw(15) << i + 1;
		B[i].Display();
	}
	cout<<endl;
}
