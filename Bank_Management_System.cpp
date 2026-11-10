#include<iostream>
using namespace std;

class BankAccount
{
    int accountNumber;
    string holderName;
    float balance;
    static int totalAccounts;

    public:
        BankAccount()
        {
            cout<<"Enter details for Account "<<totalAccounts+1<<":"<<endl;
            cout<<"Enter Account Number:";
            cin>>accountNumber;
            cout<<"Holder Name:";
            cin>>holderName;
            cout<<"Account Balance:";
            cin>>balance;
            cout<<endl;
            totalAccounts+=1;
        }
        void deposit(float amount);
        void withdraw(float amount);
        void displayDetails();
        static void displayTotalAccounts();
};

int BankAccount :: totalAccounts;

void BankAccount :: deposit(float amount)
{
    balance+=amount;
    cout<<"Rs."<<amount<<" deposited successfully.New Balance:"<<balance<<endl<<endl;
}

void BankAccount :: withdraw(float amount)
{
    if(amount<=balance)
    {
        cout<<"Rs."<<amount<<" withdrawn successfully."<<endl<<endl;
        balance-=amount;
    }
    else
    {
        cout<<"Your Balance is Not Sufficient"<<endl<<endl;
    }
}

void BankAccount :: displayDetails()
{
    cout<<"Account Number:"<<accountNumber<<" | "<<"Name:"<<holderName<<" | "<<"Balance:"<<balance<<endl;
}

void BankAccount :: displayTotalAccounts()
{
    cout<<"Total Bank Accounts Created:"<<totalAccounts<<endl;
}
int main()
{
    int n;
    cout<<"Enter number of accounts:";
    cin>>n;
    cout<<endl<<endl;

    BankAccount* arr=new BankAccount[n];
    cout<<"Account Details:"<<endl;
    for(int i=0;i<n;i++)
    {
        arr[i].displayDetails();
    }
    cout<<endl<<endl;

    for(int i=0;i<n;i++)
    {
        float a;
        cout<<"Enter Deposit Amount for Account "<<i+1<<":";
        cin>>a;
        arr[i].deposit(a);

        float c;
        cout<<"Enter Withdrawn Amount:";
        cin>>c;
        arr[i].withdraw(c);
    }
    
    cout<<"Updated Account Details:"<<endl;
    for(int i=0;i<n;i++)
    {
        arr[i].displayDetails();
    }

    cout<<endl;

    BankAccount::displayTotalAccounts();

    delete[] arr;

    return 0;
}