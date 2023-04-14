#include "../incs/easyfind.h"
#include <deque>

int main()
{
    char mot[] = {"abc"};
    int digits[] = {1 ,2 ,3};
    std::deque<char> stackChar(mot, mot + 3);
    std::deque<int> stackInt(digits, digits + 3);

    try
    {
        cout << "stackInt : " << *easyfind(stackInt, 2) << endl;
        cout << "stackChar : " << *easyfind(stackChar, 2) << endl;
    }
    catch (std::exception &e) {
        cout << e.what() << endl;
    }
}