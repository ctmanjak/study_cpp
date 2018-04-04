#include <iostream>
#include <cstring>
#include "bankcustomer.h"

Account::Account()
	: accountID(0), money(0), customerName(NULL) {}

Account::Account(int accountID, String customerName, int money)
	: accountID(accountID), money(money)
{
	this->customerName = customerName;
}
Account::Account(const Account& copy)
	: accountID(copy.accountID), money(copy.money)
{
	customerName = copy.customerName;
}
void Account::Deposit(int money)
{
	this->money += money;
}
void Account::Withdraw(int money)
{
	this->money -= money;
}
void Account::ShowAccountInfo() const
{
	std::cout<<"����ID: "<<accountID<<std::endl;
	std::cout<<"�� ��: "<<customerName<<std::endl;
	std::cout<<"�� ��: "<<money<<std::endl;
}
int Account::GetAccountID() const
{
	return accountID;
}
Account& Account::operator=(const Account& copy)
{
	this->accountID = copy.accountID;
	customerName = copy.customerName;
	return *this;
}

AccountHandler::AccountHandler()
	: customers(10), customerNum(0) {}

void AccountHandler::CreateAccount()
{
	int accountID, money, interest, choice;
	char customerName[20];

	std::cout<<"[������������]"<<std::endl;
	std::cout<<"1.���뿹�ݰ��� 2.�ſ�ŷڰ���"<<std::endl;
	std::cout<<"����: ";
	std::cin>>choice;
	if (choice != 1 && choice != 2) return;
	if (choice == 1) std::cout<<"[���뿹�ݰ��� ����]"<<std::endl;
	else if (choice == 2) std::cout<<"[�ſ�ŷڰ��� ����]"<<std::endl;
	std::cout<<"����ID: ";
	std::cin>>accountID;
	std::cout<<"�� ��: ";
	std::cin>>customerName;
	std::cout<<"�� ��: ";
	std::cin>>money;
	std::cout<<"������: ";
	std::cin>>interest;
	if (choice == 1)
		customers[customerNum++] = new NormalAccount(accountID, customerName, money, interest);
	else if (choice == 2)
	{
		int rating;
		std::cout<<"�ſ���(1toA, 2toB, 3toC): ";
		std::cin>>rating;
		switch (rating)
		{
		case 1:
			customers[customerNum++] = new HighCreditAccount(accountID, customerName, money, interest, CREDIT_RATING::RATING_A);
			break;
		case 2:
			customers[customerNum++] = new HighCreditAccount(accountID, customerName, money, interest, CREDIT_RATING::RATING_B);
			break;
		case 3:
			customers[customerNum++] = new HighCreditAccount(accountID, customerName, money, interest, CREDIT_RATING::RATING_C);
			break;

		}
	}
}

NormalAccount::NormalAccount(int accountID, String customerName, int money, int interest)
	: Account(accountID, customerName, money), interest(interest) {}
void NormalAccount::Deposit(int money)
{
	Account::Deposit(money + money * (interest/100.0));
}
void NormalAccount::ShowAccountInfo() const
{
	Account::ShowAccountInfo();
	std::cout<<"������: "<<interest<<std::endl;
}

HighCreditAccount::HighCreditAccount(int accountID, String customerName, int money, int interest, int rating)
	: NormalAccount(accountID, customerName, money, interest), rating(rating) {}
void HighCreditAccount::Deposit(int money)
{
	NormalAccount::Deposit(money);
	Account::Deposit(money*(rating/100.0));
}
void HighCreditAccount::ShowAccountInfo() const
{
	NormalAccount::ShowAccountInfo();
	switch(rating)
	{
	case 2:
		std::cout<<"�ſ���: C"<<std::endl;
	case 4:
		std::cout<<"�ſ���: B"<<std::endl;
	case 7:
		std::cout<<"�ſ���: A"<<std::endl;
	}
}

void AccountHandler::Deposit()
{
	int accountID, money;

	std::cout<<"����ID: ";
	std::cin>>accountID;
	std::cout<<"�Աݾ�: ";
	std::cin>>money;
	GetCustomerAccountByID(accountID)->Deposit(money);
}

void AccountHandler::Withdraw()
{
	int accountID, money;

	std::cout<<"����ID: ";
	std::cin>>accountID;
	std::cout<<"��ݾ�: ";
	std::cin>>money;
	GetCustomerAccountByID(accountID)->Withdraw(money);
}

void AccountHandler::ShowMenu() const
{
	std::cout<<"-----Menu-----"<<std::endl;
	std::cout<<"1. ���°���"<<std::endl;
	std::cout<<"2. �� ��"<<std::endl;
	std::cout<<"3. �� ��"<<std::endl;
	std::cout<<"4. �������� ��ü ���"<<std::endl;
	std::cout<<"5. ���α׷� ����"<<std::endl;
}
void AccountHandler::ShowCustomerInfo() const
{
	for(int i = 0; i < customerNum; i++)
	{
		customers[i]->ShowAccountInfo();
	}
}

int AccountHandler::GetCustomerNumber() const
{
	return customerNum;
}

ACCOUNT_PTR AccountHandler::GetCustomerAccountByID(int accountID) const
{
	for(int i = 0; i < customerNum; i++)
	{
		if(customers[i]->GetAccountID() == accountID)
		{
			return customers[i];
		}
	}
	return 0;
}

AccountHandler::~AccountHandler()
{
	for(int i = 0; i < customerNum; i++)
	{
		delete customers[i];
	}
}
