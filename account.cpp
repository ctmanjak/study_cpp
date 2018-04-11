#include <iostream>
#include <cstring>
#include "account.h"
#include "exception.h"

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
	if(money < 0)
		throw WrongRequestException(money);
		
	this->money += money;
}
void Account::Withdraw(int money)
{
	if(money < 0)
		throw WrongRequestException(money);

	if(money > this->money)
		throw WithdrawException(this->money, money);

	this->money -= money;
}
void Account::ShowAccountInfo() const
{
	std::cout<<"계좌ID: "<<accountID<<std::endl;
	std::cout<<"이 름: "<<customerName<<std::endl;
	std::cout<<"잔 액: "<<money<<std::endl;
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

NormalAccount::NormalAccount(int accountID, String customerName, int money, int interest)
	: Account(accountID, customerName, money), interest(interest) {}
void NormalAccount::Deposit(int money)
{
	Account::Deposit(money + money * (interest/100.0));
}
void NormalAccount::ShowAccountInfo() const
{
	Account::ShowAccountInfo();
	std::cout<<"이자율: "<<interest<<std::endl;
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
		std::cout<<"신용등급: C"<<std::endl;
	case 4:
		std::cout<<"신용등급: B"<<std::endl;
	case 7:
		std::cout<<"신용등급: A"<<std::endl;
	}
}
