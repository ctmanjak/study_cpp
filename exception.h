#ifndef __EXCEPTION_H__
#define __EXCEPTION_H__

class AccountException
{
protected:
	int money;
public:
	AccountException(int money);
	virtual void ShowException() = 0;
};

class WithdrawException : public AccountException
{
	int reqMoney;
public:
	WithdrawException(int money, int reqMoney);
	void ShowException();
};

class WrongRequestException : public AccountException
{
public:
	WrongRequestException(int money);
	void ShowException();
};
#endif
