#include "accounthandler.h"

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
