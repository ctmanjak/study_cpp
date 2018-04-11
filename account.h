#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__
#include <iostream>
#include "jstring.h"

namespace CREDIT_RATING
{
	enum {RATING_A=7, RATING_B=4, RATING_C=2};
}

class Account
{
	int accountID, money;
	String customerName;
public:
	Account();
	Account(int accountID, String customerName, int money);
	Account(const Account& copy);
	virtual void Deposit(int money);
	void Withdraw(int money);
	virtual void ShowAccountInfo() const;
	int GetAccountID() const;
	Account& operator=(const Account& copy);
	virtual ~Account() {};
};

class NormalAccount : public Account
{
	int interest;
public:
	NormalAccount(int accountID, String customerName, int money, int interest);
	void Deposit(int money);
	void ShowAccountInfo() const;
};

class HighCreditAccount : public NormalAccount
{
	int rating;
public:
	HighCreditAccount(int accountID, String customerName, int money, int interest, int rating);
	void Deposit(int money);
	void ShowAccountInfo() const;
};
typedef Account * ACCOUNT_PTR;


#endif
