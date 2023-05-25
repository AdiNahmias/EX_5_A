#ifndef MAGICALCONTAINER
#define MAGICALCONTAINER
#include <vector>
#include "AscendingIterator.hpp"
#include "SideCrossIterator.hpp"
#include "PrimeIterator.hpp"


class MagicalContainer {


private:

    std::vector<int> elements;

public:

    MagicalContainer() = default; //Default constructor
    MagicalContainer(const MagicalContainer& other)=default; //Copy constructor
    ~MagicalContainer() = default; //Destructor

    std::vector<int> getElements();
    void setElements(std::vector<int> elements);
    void addElement(int element);
    void removeElement(int element);
    int size() const;

};


#endif