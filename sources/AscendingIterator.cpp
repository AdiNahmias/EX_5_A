#include "AscendingIterator.hpp"
#include <vector>
#include <algorithm> // for std::sort

AscendingIterator::AscendingIterator(MagicalContainer& container)
    : container(container)
{
    std::vector<int> sortedElements = container.getElements();
    std::sort(sortedElements.begin(), sortedElements.end());
    this->container.setElements(sortedElements);
    
}

AscendingIterator::AscendingIterator(const AscendingIterator& other)
    : container(other.container)
{} 

int AscendingIterator::operator*() const {
    // Access the current element in the MagicalContainer
    return container.getElements()[static_cast<std::vector<int>::size_type>(index)];
}

AscendingIterator& AscendingIterator::operator++() {
    // Increment the index
    ++index;
    return *this;
}


bool AscendingIterator::operator==(const AscendingIterator& other) const {
    return index == other.index;
}

bool AscendingIterator::operator!=(const AscendingIterator& other) const {
    return index != other.index;
}

bool AscendingIterator::operator>(const AscendingIterator& other) const {
    return index > other.index;
}

bool AscendingIterator::operator<(const AscendingIterator& other) const {
    return index < other.index;
}


AscendingIterator AscendingIterator::begin() const {
    return AscendingIterator(container); // Return a new iterator at the beginning
}

AscendingIterator AscendingIterator::end() const {
    // Return an iterator representing the end (one past the last element)
    AscendingIterator it(container);
    it.index = container.size();
    return it;
}