#ifndef __bankcustomer_h__
#define __bankcustomer_h__
#include <iostream>

namespace CREDIT_RATING
{
	enum {RATING_A=7, RATING_B=4, RATING_C=2};
}

class Account
{
	int accountID, money;
	char * customerName;
public:
	Account();
	Account(int accountID, char * customerName, int money);
	Account(const Account& copy);
	virtual void Deposit(int money);
	void Withdraw(int money);
	virtual void ShowAccountInfo() const;
	int GetAccountID() const;
	void operator=(const Account& copy);
	virtual ~Account();
};

class NormalAccount : public Account
{
	int interest;
public:
	NormalAccount(int accountID, char * customerName, int money, int interest);
	void Deposit(int money);
	void ShowAccountInfo() const;
};

class HighCreditAccount : public NormalAccount
{
	int rating;
public:
	HighCreditAccount(int accountID, char * customerName, int money, int interest, int rating);
	void Deposit(int money);
	void ShowAccountInfo() const;
};
typedef Account * ACCOUNT_PTR;
class AccountArray
{
	ACCOUNT_PTR * arr;
	int arrlen;
public:
	AccountArray(int arrlen) : arrlen(arrlen)
	{
		arr = new ACCOUNT_PTR[arrlen];
	}
	ACCOUNT_PTR& operator[](int idx)
	{
		//if(idx < 0 || idx >= arrlen)
		return arr[idx];
	}
	ACCOUNT_PTR& operator[](int idx) const
	{
		//if(idx < 0 || idx >= arrlen)
		return arr[idx];
	}
	int GetArrLen() const
	{
		return arrlen;
	}
};
class AccountHandler
{
	AccountArray customers;
	int customerNum;
public:
	AccountHandler();
	void CreateAccount();
	void Deposit();
	void Withdraw();
	void ShowMenu() const;
	void ShowCustomerInfo() const;
	int GetCustomerNumber() const;
	ACCOUNT_PTR GetCustomerAccountByID(int accountID) const;
	~AccountHandler();
};

#endif
