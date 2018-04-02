#include <iostream>
#include <cstring>
#include "bankcustomer.h"

int main(void)
{
	int a;
	AccountHandler * manager = new AccountHandler();

	while(true)
	{
		manager->ShowMenu();
		std::cout<<"¼±ÅÃ: ";
		std::cin>>a;

		switch (a)
		{
		case 1:
			manager->CreateAccount();
			break;
		case 2:
			manager->Deposit();
			break;
		case 3:
			manager->Withdraw();
			break;
		case 4:
			manager->ShowCustomerInfo();
			break;
		case 5:
			return 0;
		}
	}

	delete manager;
	return 0;
}
