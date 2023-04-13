//
// Created by aurel on 4/13/23.
//

#include "../incs/Base.h"

int main()
{
	try
	{
		Base * instance = generate();
		identify(instance);
		identify(*instance);

		delete instance;
	}
	catch (std::bad_alloc & e)
	{
		cout << e.what() << endl;
	}
}