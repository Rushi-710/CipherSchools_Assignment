#include<iostream>
#include<fstream>
#include<ctype.h>
#include<iomanip>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

class account {
	int acno;
	char name[50];
	string ID;
	string pwd;
	int deposit;
	char type;
	public:
	void create_account();
	void show_account();
	void modify(); 
	void dep(int);
	void withdraw(int);
	void report();
	int retacno();
	int retdeposit();
	int rettype();
};
void account :: create_account() {
	cout << "\nEnter the Account Number : ";
	cin >> acno;
	cout << "\nEnter the Name of the Account Holder : ";
	cin >> name;
	cout << "\nEnter the ID Number : ";
	cin >> ID;
	cout << "\nEnter a New Password : ";
	cin >> pwd;
	cout << "\nEnter the Type of Account (C/S) : ";
	cin >> type;
	type = toupper(type);
	cout << "\nEnter the Initial Amount : ";
	cin >> deposit;
	cout << "\n\nAccount Created!";
}
void account :: show_account() {
	cout << "\nAccount Number : " << acno;
	cout << "\nAccount Holder Name : " << name;
	cout << "\nID Number : " << ID;
	cout << "\nType of Account : " << type;
	cout << "\nBalance Amount : " << deposit;
}
void account :: modify() {
	cout << "\nThe Account Number : "<<acno;
	cout << "\n\nEnter The Name of the Account Holder : ";
	gets(name);
	cout << "\nEnter the ID Number : ";
	cin >> ID;
	cout << "Change Password : ";
	cin >> pwd;
	cout << "\nEnter the Type of Account (C/S) : ";
	cin >> type;
	cout << "\nEnter The Balance Amount : ";
	cin >> deposit;
	}
	
void account :: dep(int x) {
	deposit+=x;
}
void account :: withdraw(int x) {
	deposit-=x;
}

void account :: report() {
	cout << acno << setw(10) <<" "<< name << setw(10);
	cout << " " << type << setw(6) << deposit << endl;
}

int account :: retacno() {
	return acno;
}
int account :: retdeposit() {
	return deposit;
}
int account :: rettype() {
	return type;
}


bool login();
void write_account();
void display_sp(int);
void modify_account(int);
void display_all();
void deposit_withdraw(int, int);
int intro();

int main() {
	char ch;
	int num;
	system ("cls");
	intro();
	do {
		system ("cls");
		cout<<"\n\n\n\tMAIN MENU";
		cout<<"\n\n\t01. DEPOSIT AMOUNT";
		cout<<"\n\n\t02. WITHDRAW AMOUNT";
		cout<<"\n\n\t03. BALANCE ENQUIRY";
		cout<<"\n\n\t04. TRANSFER AMOUNT";
		cout<<"\n\n\t05. MODIFY AN ACCOUNT";
		cout<<"\n\n\t06. EXIT";
		cout<<"\n\n\tSelect Your Option (1-6) ";
		cin>>ch;
		system ("cls");
		switch(ch)
		{
		case '1':
		cout<<"\n\n\tEnter The Account Number : "; cin>>num;
		deposit_withdraw(num, 1);
		break;
		case '2':
		cout<<"\n\n\tEnter The Account Number : "; cin>>num;
		deposit_withdraw(num, 2);
		break;
		case '3':
		cout<<"\n\n\tEnter The Account Number : "; cin>>num;
		display_sp(num);
		break;
		case '4':
		cout<<"\n\n\tEnter The Amount to be transfered : ";
		
	
		break;
		case '5':
		cout<<"\n\n\tEnter The Account Number : "; cin>>num;
		modify_account(num);
		break;
		case '6':
		cout<<"\n\n\tThanks for Using the Bank Management System!";
		break;
		default :cout<<"Wrong Option!\n Press enter for main menu" ;
		}
		getchar();
		}while(ch!='6');
		return 0;
}
void write_account()
{
	account ac;
	ofstream outFile;
	outFile.open("account.dat",ios::binary|ios::app);
	ac.create_account();
	outFile.write((char *) &ac, sizeof(account));
	outFile.close();
}

bool login(const string &user_id, const string &password) {
    ifstream outFile("account.dat");
    string ID, pwd;

    while (outFile) {
        getline(outFile, ID, '-'); 
        getline(outFile, pwd);
        if (ID == user_id && pwd == password)
            return true;
    }

    return false;
}

void display_sp(int n) {
	account ac;
	int flag=0;
	ifstream inFile;
	inFile.open("account.dat",ios::binary);
	if(!inFile)
	{
	cout<<"File could not be open !! Press any Key...";
	return;
	}
	cout<<"\nBALANCE DETAILS\n";
	while(inFile.read((char *) &ac, sizeof(account)))
	{
	if(ac.retacno()==n)
	{
	ac.show_account();
	flag=1;
	} }
	inFile.close();
	if(flag==0)
	cout<<"\n\nAccount number does not exist";
}

void modify_account(int n)
{
	int found=0;
	account ac;
	fstream File;
	File.open("account.dat",ios::binary|ios::in|ios::out);
	if(!File)
	{
	cout<<"File could not be open !! Press any Key...";
	return;
	}
	while(File.read((char *) &ac, sizeof(account)) && found==0)
	{
	if(ac.retacno()==n)
	{
	ac.show_account();
	cout<<"\n\nEnter The New Details of account"<<endl;
	ac.modify();
	int pos=(-1)*sizeof(account);
	File.seekp(pos,ios::cur);
	File.write((char *) &ac, sizeof(account));
	cout<<"\n\n\t Record Updated";
	found=1;
	} }
	File.close();
	if(found==0)
cout<<"\n\n Record Not Found ";
}

void display_all()
{
	account ac;
	ifstream inFile;
	inFile.open("account.dat",ios::binary);
	if(!inFile)
	{
	cout<<"File could not be open !! Press any Key...";
	return;
	}
	cout<<"====================================================\n";
	cout<<"A/c no. NAME Type Balance\n";
	cout<<"====================================================\n";
	while(inFile.read((char *) &ac, sizeof(account)))
	{
	ac.report();
	}
	inFile.close();
}

void deposit_withdraw(int n, int option)
{
	int amt;
	int found=0;
	account ac;
	fstream File;
	File.open("account.dat", ios::binary|ios::in|ios::out);
	if(!File)
	{
	cout<<"File could not be open !! Press any Key...";
	return;
	}
	while(File.read((char *) &ac, sizeof(account)) && found==0)
	{
	if(ac.retacno()==n)
	{
	ac.show_account();
	if(option==1)
	{
	cout<<"\n\n\tTO DEPOSIT AMOUNT ";
	cout<<"\n\nEnter The amount to be deposited";
	cin>>amt;
	ac.dep(amt);
	}
	if(option==2)
	{
	cout<<"\n\n\tTO WITHDRAW AMOUNT ";
	cout<<"\n\nEnter The amount to be withdraw";
	cin>>amt;
	int bal=ac.retdeposit()-amt;
	if((bal<500 && ac.rettype()=='S') || (bal<1000 && ac.rettype()=='C'))
	cout<<"Insufficience balance";
	else
	ac.withdraw(amt);
	}
	int pos=(-1)* sizeof(ac);
	File.seekp(pos,ios::cur);
	File.write((char *) &ac, sizeof(account));
	cout<<"\n\n\t Record Updated";
	found=1;
	}
	}
	File.close();
	if(found==0)
	cout<<"\n\n Record Not Found ";
}

int intro()
{
	char op;
	do {
	cout << "\n\n\t\t WELCOME TO BANK MANAGEMENT SYSTEM";
	cout << "\n\n\n\t01. New Account";
	cout << "\n\n\t02. Existing Account";
	cout << "\n\n\t03. Exit";
	cout << "\n\n\tSelect Your Option (1-3) : ";
	cin >> op;
	getchar();
	switch(op) {
		case '1' : {
		write_account();
		getchar();
		break;
	}
		case '2' : {
		system("cls");
		string user_id, password;
		cout << "Enter User ID : ";
	    cin >> user_id;
		cout << "Enter Password : ";
		cin >> password;
	    return (int)login(user_id, password);
		break;
	}
		case '3' : {
		cout << "\n\n\tThanks for Using Bank Management System!";
		break;
	}
		default : { 
		cout << "Wrong Option!!";
	}
	}
	getchar();
	}
	while(op != '3');
	return 0;
	}

