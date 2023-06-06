#include "../incs/easyfind.h"
#include <deque>
#include <vector>

int main()
{
    char mot[] = {"abc"};
    int digits[] = {1 ,2 ,3};
    std::deque<char> stackChar(mot, mot + 3);
    std::deque<int> stackInt(digits, digits + 3);
	std::vector<int> vecInt( digits, digits + 2);

    try
    {
        cout << "stackInt : " << *easyfind(stackInt, 2) << endl;
		cout << "vecInt : " << *easyfind( vecInt, 2 ) << endl;
		cout << "stackChar : " << *easyfind(stackChar, 2) << endl;
    }
    catch (std::exception &e) {
        cout << e.what() << endl;
    }
}