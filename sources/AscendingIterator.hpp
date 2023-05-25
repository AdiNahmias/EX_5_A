#ifndef ASCENDINGITERATOR_H
#define ASCENDINGITERATOR_H

#include "MagicalContainer.h"
class MagicalContainer;

class AscendingIterator {
    
    private:

        MagicalContainer& container;
        
        int index;

    public:

        AscendingIterator(MagicalContainer& container); // Default constructor
        AscendingIterator(const AscendingIterator& other); // Copy constructor
        ~AscendingIterator() = default; // Destructor

        int operator*() const;
        AscendingIterator& operator++();
        bool operator==(const AscendingIterator& other) const;
        bool operator!=(const AscendingIterator& other) const;
        bool operator>(const AscendingIterator& other) const;
        bool operator<(const AscendingIterator& other) const;
        AscendingIterator begin() const;
        AscendingIterator end() const;

};

#endif
