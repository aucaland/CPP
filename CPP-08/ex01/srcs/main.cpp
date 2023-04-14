#include "../incs/Span.h"

int main()
{
    srand(time(NULL));
    std::list<Span > vectList;

    Span emptyVect(0);
    Span longestVect(50);
    Span hugeVect(10000);
    Span veryVeryHuge(100000);

    vectList.push_back(emptyVect);
    vectList.push_back(longestVect);
    vectList.push_back(hugeVect);
    vectList.push_back(veryVeryHuge);

    int index = 0;
    std::list<Span>::iterator it;
    for ( it = vectList.begin(); it != vectList.end() ; it++) {
        cout << "vectList[" << index++ << "] :" << endl << endl;
        for ( unsigned int i = 0 ;  i < it->getCapacity(); i++) {
            {try {
                    it->addNumber(rand() % 100000);
                }
                catch (std::exception &e){
                    cout << e.what() << endl;
                }
            }
        }
        try{
            cout << "shortSpan = " << it->shortestSpan() << endl;
            cout << "longestSpan = " << it->longestSpan() << endl;
        }
        catch (std::exception &e){
            cout << e.what() << endl;
        }
    }
}