#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int noc;

using namespace std;

class account
{
	protected:
		char name[40];
		long int ac;
		char type[22];
		double deposit;
		double withdraw;
	
	public:
		double balance;
		account()
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
		
		string actype ()
		{
			return type;
		}
};

class sav_acct : public account
{
	public:
		double compund_interest(int t)
		{
			balance *= pow (1.03, t);
			return balance;
		}
};

class curr_acct : public account
{
	public:
		void penalty()
		{
			balance -= 20;	
		}
};

void Disp (account A[]);

int main()
{
	account A[10];
	sav_acct sa[10];
	curr_acct ca[10];
	int choice, flag = 0;;
	char ch;
	long int acno;
	
	while (1)
	{
		cout << "________________________________________________________________\n";
		cout << "\t  *MAIN MENU*\n" << endl;
		cout << "\t1. Enter Data." << endl;
		cout << "\t2. Display Data." << endl;
		cout << "\t3. Withdraw cash." << endl;
		cout << "\t4. Deposit cash." << endl;
		cout << "\t5. Write a cheque." << endl;
		cout << "\t6. Deposit interest." << endl;
		cout << "\t7. Exit." << "\n";
		cout << "__________________________________________________________________\n\n";
		cout << "Enter your choice (1-7): ";
		cin >> choice;
		cout << endl;
		
		switch(choice)
		{
			case 1: 
                    {
                    	cout << "Enter the number of customers: ";
                    	cin >> noc;
                        cout << "\nEnter data for " << noc << " customers:\n\n";
        				for (int i = 0; i < noc; ++i)
        				{
        				    cout << "For Customer No." << i + 1 << ":\n";
        					A[i].ReadData();
        				}
        				break;    
                    }
    				
			case 2: Disp (A);
				    break;
				    
			case 3:	flag = 0;
					cout << "Enter the Account No. of the customer who wants to withdraw cash: ";
    				cin >> acno;
    				
    				for (int i = 0; i < noc; ++i)
    				{
    				    if (acno == A[i].Ac())
    					{
    					    A[i].Withdraw();
    					    flag = 1;
    						break;
    					}
    				}
    				
    				if (flag == 0)
    				{
    						 cout << "INVALID ACCOUNT NUMBER!" << "\n";
    						 break;
    				}
    				
    				break;
    				
			case 4: int i;
					flag = 0;
					cout << "Enter the Account No. of the customer who wants to deposit cash: ";
    				cin >> acno;
    				
    				for (i = 0; i < noc; ++i)
    				{
    				    if (acno == A[i].Ac())
    					{
    					    A[i].Deposit();
    					    cout << "Deposit successful!\n";
    					    flag = 1;
    					    break;
    					}
					}
					
					if (flag == 0)
    				{
    					cout<<"INVALID ACCOUNT NUMBER!"<<"\n";
    					break;	
    				}
					break;
					
			case 5:	{
						int i;
						flag = 0; 
						long acno;
						double amount, bal;
						
						fflush (stdin);
						
						cout << "Enter the account number of the customer: ";
						cin >> acno;
						
						for (i = 0; i < noc; ++i)
						{
							if (acno == A[i].Ac())
							{
								flag = 1;
								
								if ((A[i].actype().compare ("Current Account") == 0))
								{
									cout << "\nEnter the amount: ";
									cin >> amount;
						
									A[i].balance -= amount;
									
									cout << "\nRupees " << amount << " successfully debited!\n";
									break;	
								}
								else 
								{
									cout << "\nCheque book facility not available for Savings Account!\n";
									break;	
								}	
							}
						}
						
	    				if (flag == 0)
	    				{
	    					cout << "INVALID ACCOUNT NUMBER!" << "\n";
	    					break;
	    				}
						
						break;
					}
					
			case 6: {
						int i;
						flag = 0;
						long acno;
						float t;
						double bal, ci;
						
						fflush (stdin);
						
						cout << "Enter the account number of the customer: ";
						cin >> acno;
						
						for (i = 0; i < noc; ++ i)
						{
							if (acno == A[i].Ac())
							{
								flag = 1;
								
								if ((A[i].actype().compare ("Savings Account") == 0))
								{
									sa[i].balance = A[i].balance;
									bal = sa[i].balance;
									cout << "\nEnter the time (in years): ";
									cin >> t;
							
									A[i].balance = sa[i].compund_interest(t);
									ci = A[i].balance - bal;
									
									cout << "Compund interest of rupees " << fixed << setprecision(2) << ci << " at a rate of 3% p.a. for " << t << " years successfully added to the account.\n";						
									break;
								}
								
								else 
								{
									cout << "\nCompund interest not available for Current Account!\n";
									break;	
								}	
							}
						}
						
						
    				if (flag == 0)
    				{
    					cout << "INVALID ACCOUNT NUMBER!" << "\n";
    					break;
    				}
						break;
					}
					
			case 7: exit(0);
					break;
					
			default: 
                    cout<<"\nINVALID CHOICE!";
					break;
		}
		cout << endl;
    }
	return 0;
}


void account::Deposit()
{
	cout << "Enter the amount to deposit: ";
	cin >> deposit;
	cout << endl;
	balance += deposit; 
}

void account::Withdraw()
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
	if (balance < 200 && (actype().compare ("Current Account") == 0))
	{
			balance -= 20;
			cout << "Notice: Penalty of rupees 20 imposed.\n";
	}
}

void account::ReadData()
{
    int num, flag = 1;
	cin.ignore();
	cout << "\tCustomer Name: ";
	fgets(name, 40, stdin);
	name[strcspn(name, "\n")] = 0;

	cout << "\tAccount Number: ";
	cin >> ac;
	
	cin.ignore();
	cout << "\tType of account:\n\t\t1. Savings\n\t\t2. Current";
	while (flag == 1)
	{
	    cout << "\n\tYour answer (1-2): ";
    	cin >> num;
    	if (num == 1)
    	{
    	   strcpy (type, "Savings Account");
           flag = 0;     
        }
        if (num == 2)
        {
            strcpy (type, "Current Account");    
            flag = 0;
        }
    
        if (num < 1 || num > 2) 
        {
            cout << "\tINVALID TYPE! Enter a valid type.";
            flag = 1;    
        }
    }
    flag = 1;
    while (flag == 1)
	{
	    cout << "\tOpening Balance: ";
		cin >> balance;
		if (balance < 200 && num == 2)
		{
			cout << "\tMINIMUM BALANCE MUST BE RUPEES 200! Please deposit atleast 200 rupees.\n";
			flag = 1; 
		}
		else 
			flag = 0;
    }
	cout << "\n\n";
}

void account::Display()
{
	cout << setw(20) << ac;
	cout << setw(30) << name;
	cout << setw(15) << fixed << setprecision(2) << balance;
	cout << endl;
}

void Disp (account A[])
{
	cout.setf (ios::left);
	cout << setw(15) << "SERIAL NO.";
	cout << setw(20) << "ACCOUNT NO.";
	cout << setw(30) << "NAME";
	cout << setw(15) << "BALANCE";
	cout << endl;
	
    for (int i = 0; i < noc; ++i)
	{
	    cout.setf (ios::left);
	    cout << setw(15) << i + 1;
		A[i].Display();
	}
	cout<<endl;
}
