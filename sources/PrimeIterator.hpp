#ifndef PRIMEITERATOR
#define PRIMEITERATOR
#include "MagicalContainer.h"
class MagicalContainer;

class PrimeIterator  {

    private:
    
        MagicalContainer& container;
        int index;

    public:
        PrimeIterator(MagicalContainer& container);//Default constructor
        PrimeIterator(const PrimeIterator& other);//Copy constructor
        ~PrimeIterator() = default; //Destructor

        //help function
        bool isPrime(int number);

        int operator*() const;
        PrimeIterator& operator++();
        PrimeIterator begin() const;
        PrimeIterator end() const;
        bool operator==(const PrimeIterator& other) const;
        bool operator!=(const PrimeIterator& other) const;
        bool operator>(const PrimeIterator& other) const;
        bool operator<(const PrimeIterator& other) const;
        



};

#endif 