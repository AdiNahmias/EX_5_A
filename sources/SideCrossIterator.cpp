#include "SideCrossIterator.hpp"
#include <algorithm> // for std::sort
#include <cstddef>


SideCrossIterator::SideCrossIterator(MagicalContainer& container)
    : container(container)
{
    std::vector<int> sortedElements = container.getElements();
    std::sort(sortedElements.begin(), sortedElements.end());
    size_t start = 0;
    size_t end = sortedElements.size() -1;
    std::vector<int> crossElements(sortedElements.size());
    for (size_t i = 0; i < crossElements.size() ; i+=2) {
        crossElements[i] = sortedElements[start];
        crossElements[i+1] = sortedElements[end];
        start++;
        end--;

    }
    this->container.setElements(crossElements);
}

SideCrossIterator::SideCrossIterator(const SideCrossIterator& other)
    : container(other.container)
{}

int SideCrossIterator::operator*() const {
    // Access the current element in the MagicalContainer
    return container.getElements()[static_cast<std::vector<int>::size_type>(index)];
}

SideCrossIterator& SideCrossIterator::operator++() {
    // Increment the index
    ++index;
    return *this;
}


bool SideCrossIterator::operator==(const SideCrossIterator& other) const {
    return index == other.index;
}

bool SideCrossIterator::operator!=(const SideCrossIterator& other) const {
    return index != other.index;
}

bool SideCrossIterator::operator>(const SideCrossIterator& other) const {
    return index > other.index;
}

bool SideCrossIterator::operator<(const SideCrossIterator& other) const {
    return index < other.index;
}


SideCrossIterator SideCrossIterator::begin() const {
    return SideCrossIterator(container); // Return a new iterator at the beginning
}

SideCrossIterator SideCrossIterator::end() const {
    // Return an iterator representing the end (one past the last element)
    SideCrossIterator it(container);
    it.index = container.size();
    return it;
}