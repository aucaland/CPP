#include "../incs/Span.h"

//int main() //main exercice
//{
//    Span sp = Span(5);
//    sp.addNumber(6);
//    sp.addNumber(3);
//    sp.addNumber(17);
//    sp.addNumber(9);
//    sp.addNumber(11);
//    std::cout << sp.shortestSpan() << std::endl;
//    std::cout << sp.longestSpan() << std::endl;
//    return 0;
//}

int main()
{
    std::list<Span > vectList;

    Span emptyVect(0);
    Span longestVect(50);
    Span hugeVect(10000);
	Span veryVeryHuge(100000);
//	Span veryVeryVeryVeryVeryVeryHuge(10000000);

    vectList.push_back(emptyVect); // vecList[0]
    vectList.push_back(longestVect); // 1
    vectList.push_back(hugeVect); // 2
	vectList.push_back(veryVeryHuge); // 3
//	vectList.push_back(veryVeryVeryVeryVeryVeryHuge); // 4

    int index = 0;
    std::list<Span>::iterator it;
    for ( it = vectList.begin(); it != vectList.end() ; it++) {
		std::srand(static_cast<unsigned int>(std::time(NULL)));
        cout << RED << "vectList[" << index++ << "] :" << RESET << endl << endl;
		for ( unsigned int i = 0 ;  i < it->getCapacity(); i++) {
			try {
				it->addNumber( rand() % (it->getCapacity() * 10000 ) );
			}
			catch (std::exception &e){
				cout << e.what() << endl;
			}
		}
        try{
            cout << "shortSpan = " << it->shortestSpan() << endl;
            cout << "longestSpan = " << it->longestSpan() << endl << endl;
        }
        catch (std::exception &e){
            cout << e.what() << endl;
        }
    }
}