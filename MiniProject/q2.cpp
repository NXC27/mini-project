#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

class BankAccount
{
    private:
    int acc_no;
    string name;
    string acc_type;
    int balance;
    int password;
    public:
    //constructor
    BankAccount(int n=0, string un="", string at="", int pw=0, int b=0)
        :acc_no(n),name(un),acc_type(at),balance(b),password(pw){}
    int check_password(int pass)
    {
        if (pass == password)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    int check_account_number(int num)
    {
        if (num == acc_no)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    void deposit(int value)
    {
        if (value>0)
        {
            cout<<"### Deposit Successfully ###\n"<<endl;
            balance+=value;
            transaction_record("deposit", value);
        }
        else
        {
            cout<<"!!! Error: Enter a valid number\n"<<endl;
        }
    }
    void withdraw(int value)
    {
        if (value>0 && value<=balance)
        {
            cout<<"### Withdraw Successfully ###\n"<<endl;
            balance-=value;
            transaction_record("withdraw", value);
        }
        else if (value<0)
        {
            cout<<"!!! Error: Enter a valid number\n"<<endl;
        }
        else if (value>balance)
        {
            cout<<"!!! Error: Not enough to withdraw\n"<<endl;
        }
    }
    void transaction_record(string transac_type, int value)
    {
        //current time
        time_t now = time(0);
        //open file
        fstream logfile;
        logfile.open("./log.txt", ios::out|ios::app);
        if (logfile.is_open())
        {
            logfile<<to_string(now)+" "+transac_type+" "+to_string(value)+"\n";
            logfile.close();
        }
    }
    void transac_history()
    {
        fstream logfile;
        logfile.open("./log.txt", ios::in);
        if (logfile.is_open())
        {
            string line;
            cout<<"=== Diplay Log File ==="<<endl;
        	while(!logfile.eof())
        	{
        		getline(logfile,line);
        		//display in terminal
        		cout<<line<<endl;
        	}
        	logfile.close();
        }
        else
        {
            cout<<"!!! Error: Cannot open log file"<<endl;
        }
    }
    void display()
    {
        {
            cout<<"=== Bank Account Detail ==="<<endl;
            cout<<"Account Number: "<<acc_no<<endl;
            cout<<"Name: "<<name<<endl;
            cout<<"Account Type: "<<acc_type<<endl;
            cout<<"Balance: "<<balance<<endl;
            cout<<endl;
        }
    }
};

int main()
{
    BankAccount ba(1234, "nguyen", "saving", 1234);
    int num;
    int pass;
    int choice;
    int amount;
    //login
    do
    {
        cout<<"Enter your account number: ";
        cin>>num;
        cout<<"Enter your password: ";
        cin>>pass;
    } while (!ba.check_password(pass) || !ba.check_account_number(num));
    
    //menu
    while(1)
    {
        cout<<"*** *** MENU *** ***"<<endl;
        cout<<"1.Display Account Detail"<<endl;
        cout<<"2.Deposit"<<endl;
        cout<<"3.Withdraw"<<endl;
        cout<<"4.Display Transaction History"<<endl;
        cout<<"5.Exit"<<endl;
        cout<<"Choice: ";
        cin>>choice;
        switch(choice)
        {
            case 1:
                ba.display();
                break;
            case 2:
                cout<<"Enter an amount: ";
                cin>>amount;
                ba.deposit(amount);
                break;
            case 3:
                cout<<"Enter an amount: ";
                cin>>amount;
                ba.withdraw(amount);
                break;
            case 4:
                ba.transac_history();
                break;
            case 5:
                return 0;
                break;
            default:
                cout<<"Pleas enter a valid value"<<endl;
                break;
        }
    }
}