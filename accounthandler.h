#ifndef __ACCOUNTHANDLER_H__
#define __ACCOUNTHANDLER_H__
#include "array.h"
#include "account.h"

class AccountHandler
{
	BoundCheckArray<ACCOUNT_PTR> customers;
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
