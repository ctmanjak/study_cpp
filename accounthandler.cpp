#include "accounthandler.h"

AccountHandler::AccountHandler()
	: customers(10), customerNum(0) {}

void AccountHandler::CreateAccount()
{
	int accountID, money, interest, choice;
	char customerName[20];

	std::cout<<"[계좌종류선택]"<<std::endl;
	std::cout<<"1.보통예금계좌 2.신용신뢰계좌"<<std::endl;
	std::cout<<"선택: ";
	std::cin>>choice;
	if (choice != 1 && choice != 2) return;
	if (choice == 1) std::cout<<"[보통예금계좌 개설]"<<std::endl;
	else if (choice == 2) std::cout<<"[신용신뢰계좌 개설]"<<std::endl;
	std::cout<<"계좌ID: ";
	std::cin>>accountID;
	std::cout<<"이 름: ";
	std::cin>>customerName;
	std::cout<<"잔 액: ";
	std::cin>>money;
	std::cout<<"이자율: ";
	std::cin>>interest;
	if (choice == 1)
		customers[customerNum++] = new NormalAccount(accountID, customerName, money, interest);
	else if (choice == 2)
	{
		int rating;
		std::cout<<"신용등급(1toA, 2toB, 3toC): ";
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

	std::cout<<"계좌ID: ";
	std::cin>>accountID;
	std::cout<<"입금액: ";
	std::cin>>money;
	GetCustomerAccountByID(accountID)->Deposit(money);
}

void AccountHandler::Withdraw()
{
	int accountID, money;

	std::cout<<"계좌ID: ";
	std::cin>>accountID;
	std::cout<<"출금액: ";
	std::cin>>money;
	GetCustomerAccountByID(accountID)->Withdraw(money);
}

void AccountHandler::ShowMenu() const
{
	std::cout<<"-----Menu-----"<<std::endl;
	std::cout<<"1. 계좌개설"<<std::endl;
	std::cout<<"2. 입 금"<<std::endl;
	std::cout<<"3. 출 금"<<std::endl;
	std::cout<<"4. 계좌정보 전체 출력"<<std::endl;
	std::cout<<"5. 프로그램 종료"<<std::endl;
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
