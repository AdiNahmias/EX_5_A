#ifndef SIDECROSSITERATOR
#define SIDECROSSITERATOR
#include "MagicalContainer.h"

class MagicalContainer;
class SideCrossIterator {

    private:
        MagicalContainer& container;
        int index;

    public:
        SideCrossIterator(MagicalContainer& container);//Default constructor
        SideCrossIterator(const SideCrossIterator& other);//Copy constructor
        ~SideCrossIterator() = default; //Destructor

        int operator*() const;
        SideCrossIterator& operator++();
        SideCrossIterator begin() const;
        SideCrossIterator end() const;
        bool operator==(const SideCrossIterator& other) const;
        bool operator!=(const SideCrossIterator& other) const;
        bool operator>(const SideCrossIterator& other) const;
        bool operator<(const SideCrossIterator& other) const;


};


#endif