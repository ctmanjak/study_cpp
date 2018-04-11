#include <iostream>
#include "exception.h"

AccountException::AccountException(int money) : money(money) {}

WithdrawException::WithdrawException(int money, int reqMoney) : AccountException(money), reqMoney(reqMoney) {}

void WithdrawException::ShowException()
{
	std::cout<<"�ܾ� ����!"<<std::endl;
	std::cout<<"��� ��û �ݾ�: "<<reqMoney<<std::endl;
	std::cout<<"�ܾ�: "<<money<<std::endl;
}

WrongRequestException::WrongRequestException(int money) : AccountException(money) {}

void WrongRequestException::ShowException()
{
	std::cout<<"�߸��� �Է��Դϴ�!"<<std::endl;
	std::cout<<"�Է°�: "<<money<<std::endl;
}
