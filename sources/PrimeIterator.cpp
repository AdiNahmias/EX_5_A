#include "PrimeIterator.hpp"
#include <vector>
#include <cstddef>




bool PrimeIterator::isPrime(int number) {
    if (number <= 1) {
        return false;
    }
    for (int i = 2; i * i <= number; ++i) {
        if (number % i == 0) {
            return false;  // Number is divisible, hence not prime
        }
    }

    return true;  // Number is prime
}

PrimeIterator::PrimeIterator(MagicalContainer& container)
    : container(container)
{
    std::vector<int> primeElements;
    for (size_t i = 0; i < container.getElements().size(); i++)
    {
        if (isPrime(container.getElements()[i])) {
            primeElements.push_back(container.getElements()[i]);
        }
    }
    container.setElements(primeElements);
}


PrimeIterator::PrimeIterator(const PrimeIterator& other)
    : container(other.container)
{}
int PrimeIterator::operator*() const {
    // Access the current element in the MagicalContainer
    return container.getElements()[static_cast<std::vector<int>::size_type>(index)];
}

PrimeIterator& PrimeIterator::operator++() {
    // Increment the index
    ++index;
    return *this;
}

bool PrimeIterator::operator==(const PrimeIterator& other) const {
    return index == other.index;
}

bool PrimeIterator::operator!=(const PrimeIterator& other) const {
    return index != other.index;
}

bool PrimeIterator::operator>(const PrimeIterator& other) const {
    return index > other.index;
}

bool PrimeIterator::operator<(const PrimeIterator& other) const {
    return index < other.index;
}


PrimeIterator PrimeIterator::begin() const {
    return PrimeIterator(container); // Return a new iterator at the beginning
}

PrimeIterator PrimeIterator::end() const {
    // Return an iterator representing the end (one past the last element)
    PrimeIterator it(container);
    it.index = container.size();
    return it;
}