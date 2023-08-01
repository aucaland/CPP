#include "../incs/RPN.h"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		cout << "Only one argument is Accepted" << endl;
		return 0;
	}
	try
	{
		RPN rpn(av[1]);
		cout << rpn.getResult() << endl;
	}
	catch (std::exception &e)
	{
		cout << e.what() << endl;
	}
}