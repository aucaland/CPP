#include "../incs/MutantStack.h"

int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	cout << "Elem of mystack (MutantStack)" << endl;
	while ( it != ite )
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	cout << "size of stack mystack (MutantStack):" << s.size() << endl;
	cout << "size of stack s (std::stack(mystack)):" << s.size() << endl;
	cout << "Elem of CopyC(mystack), which use the copy constructor of MutantStack : " << endl;

	MutantStack<int> copyC(mstack);
	MutantStack<int>::iterator itt = copyC.begin();
	MutantStack<int>::iterator itte = copyC.end();
	++itt;
	--itt;
	while ( itt != itte )
	{
		std::cout << *itt << std::endl;
		++itt;
	}

	MutantStack<int> assignementStack = mstack;

	cout << "Elem of assignementStack = (mystack), which use the copy assignement op of MutantStack : " << endl;
	MutantStack<int>::iterator ittt = copyC.begin();
	MutantStack<int>::iterator ittte = copyC.end();
	++ittt;
	--ittt;
	while ( ittt != ittte )
	{
		std::cout << *ittt << std::endl;
		++ittt;
	}
	return 0;
}
