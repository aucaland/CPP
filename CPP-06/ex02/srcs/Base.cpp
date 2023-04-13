//
// Created by aurel on 4/12/23.
//

#include "../incs/A.h"
#include "../incs/B.h"
#include "../incs/C.h"
#include <cstdlib>
#include <ctime>
#include <exception>
using std::cout;
using std::endl;


Base * generate(void)
{
	Base *ptr;
	srand(time(NULL));
	switch ( rand() % 3 + 1)
	{
		case 1:
			ptr = new A();
			break;
		case 2:
			ptr = new B();
			break;
		case 3:
			ptr = new C();
			break;
		default:
			return NULL;
	}
	return ptr;
}

void identify(Base *p)
{
	A *Aptr =  dynamic_cast<A*>(p);
	B *Bptr = dynamic_cast<B*>(p);
	C *Cptr = dynamic_cast<C*>(p);

	if (Aptr != NULL)
		cout << "Object type pointed to by p (Base *p) : A" << endl;
	else if (Bptr != NULL)
		cout << "Object type pointed to by p (Base *p) : B" << endl;
	else if (Cptr != NULL)
		cout << "Object type pointed to by p (Base *p) : C" << endl;
	else
		cout << "Unknown Type" << endl;
}

void identify(Base &p)
{
	try {
		A &Aptr =  dynamic_cast<A&>(p);
		cout << &Aptr << " : Object type pointed to by p (Base &p) : A" << endl;
	}
	catch (...){
	}
	try {
		B &Bptr =  dynamic_cast<B&>(p);
		cout << &Bptr << "Object type pointed to by p (Base &p) : B" << endl;
	}
	catch (...){
	}
	try {
		C &Cptr =  dynamic_cast<C&>(p);
		cout << &Cptr << "Object type pointed to by p (Base &p) : C" << endl;
	}
	catch (...){
	}
}