#include <iostream>
#include "exception.h"

AccountException::AccountException(int money) : money(money) {}

WithdrawException::WithdrawException(int money, int reqMoney) : AccountException(money), reqMoney(reqMoney) {}

void WithdrawException::ShowException()
{
	std::cout<<"잔액 부족!"<<std::endl;
	std::cout<<"출금 요청 금액: "<<reqMoney<<std::endl;
	std::cout<<"잔액: "<<money<<std::endl;
}

WrongRequestException::WrongRequestException(int money) : AccountException(money) {}

void WrongRequestException::ShowException()
{
	std::cout<<"잘못된 입력입니다!"<<std::endl;
	std::cout<<"입력값: "<<money<<std::endl;
}
