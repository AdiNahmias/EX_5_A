#include "doctest.h"
#include "MagicalContainer.hpp"
#include <iostream>
#include <vector>
#include <algorithm> 

using namespace ariel;


TEST_CASE("Cheking addElement function"){
    MagicalContainer container;
    CHECK_NOTHROW(container.addElement(17));
    CHECK_NOTHROW(container.addElement(2));
    CHECK_NOTHROW(container.addElement(25));
    CHECK_NOTHROW(container.addElement(9));
    CHECK_NOTHROW(container.addElement(3));
    CHECK_NOTHROW(container.addElement(0));
    CHECK_NOTHROW(container.addElement(2));
}


TEST_CASE("Checking getElements function") {
    MagicalContainer container;
    container.addElement(17);
    container.addElement(2);
    container.addElement(25);
    container.addElement(9);
    container.addElement(3);
    std::vector<int> elements = container.getElements();
    CHECK(elements.size() == 5);
    CHECK(elements[0] == 17);
    CHECK(elements[1] == 2);
    CHECK(elements[2] == 25);
    CHECK(elements[3] == 9);
    CHECK(elements[4] == 3);
}


TEST_CASE("Checking setElements function") {
    MagicalContainer container;
    std::vector<int> elements = {5, 10, 15, 20};
    container.setElements(elements);
    CHECK(container.size() == 4);
    CHECK(container.getElements() == elements);
}


TEST_CASE("Cheking removeElement function and size function"){
    MagicalContainer container;
    container.addElement(17);
    container.addElement(2);
    container.addElement(25);
    container.addElement(9);
    container.addElement(3);
    CHECK_NOTHROW(container.removeElement(17));
    CHECK_NOTHROW(container.removeElement(16));//remove nothing
    CHECK(container.size() == 4);
    CHECK_NOTHROW(container.removeElement(2));
    CHECK_NOTHROW(container.removeElement(25));
    CHECK_NOTHROW(container.removeElement(6));//remove nothing
    CHECK_NOTHROW(container.removeElement(9));
    CHECK(container.size() == 1);
    CHECK_NOTHROW(container.removeElement(3));
    CHECK(container.size() == 0);

}

//----------------AscendingIterator----------------------------


TEST_CASE("Checking operator== for AscendingIterator") {
    MagicalContainer container;
    container.addElement(10);
    container.addElement(20);
    container.addElement(30);
    MagicalContainer::AscendingIterator iter1(container);
    MagicalContainer::AscendingIterator iter2(container);
    MagicalContainer::AscendingIterator iter3(container);
    CHECK(iter1 == iter2);  // Same position, so iterators are equal
    ++iter2;
    CHECK(iter1 != iter2);  // Different positions, so iterators are not equal
    ++iter3;
    ++iter3;
    CHECK(iter1 != iter3);  // Different positions, so iterators are not equal
}

TEST_CASE("Checking operator!= for AscendingIterator") {
    MagicalContainer container;
    container.addElement(10);
    container.addElement(20);
    container.addElement(30);
    MagicalContainer::AscendingIterator iter1(container);
    MagicalContainer::AscendingIterator iter2(container);
    CHECK_FALSE(iter1 != iter2);  // Same position, so iterators are equal
    ++iter2;
    CHECK(iter1 != iter2);  // Different positions, so iterators are not equal
}

TEST_CASE("Cheking AscendingIterator"){
    MagicalContainer container;
    container.addElement(17);
    container.addElement(2);
    container.addElement(25);
    container.addElement(9);
    container.addElement(3);
    MagicalContainer::AscendingIterator ascIter(container);
    auto begin = ascIter.begin();
    CHECK(*begin == 2);
    ++begin;
    CHECK(*begin == 3);
    ++begin;
    CHECK(*begin == 9);
    ++begin;
    CHECK(*begin == 17);
    ++begin;
    CHECK(*begin == 25);
    
}

TEST_CASE("Checking AscendingIterator with an empty container") {
    MagicalContainer container;
    MagicalContainer::AscendingIterator ascIter(container);
    auto begin_it = ascIter.begin();
    auto end_it = ascIter.end();
    CHECK(begin_it == end_it);
}

TEST_CASE("Checking AscendingIterator with a single element") {
    MagicalContainer container;
    container.addElement(42);
    MagicalContainer::AscendingIterator ascIter(container);
    auto begin = ascIter.begin();
    CHECK(*begin == 42);  // The iterator points to the single element
    CHECK(++begin == ascIter.end());  // The iterator is now at the end
}




//-------------------SideCrossIterator------------------------


TEST_CASE("SideCrossIterator comparison operators") {
    MagicalContainer container;
    container.addElement(3);
    container.addElement(8);
    container.addElement(5);
    container.addElement(12);
    MagicalContainer::SideCrossIterator iter1(container);
    MagicalContainer::SideCrossIterator iter2(container);

    // Test equality operator
    CHECK(iter1 == iter1);
    CHECK(iter1 == iter2);

    ++iter2;
    CHECK_FALSE(iter1 == iter2);

    // Test inequality operator
    CHECK_FALSE(iter1 != iter1);
    CHECK_FALSE(iter1 != iter2);

    ++iter2;
    CHECK(iter1 != iter2);

    // Test greater than operator
    CHECK_FALSE(iter1 > iter1);
    CHECK_FALSE(iter1 > iter2);

    ++iter1;
    CHECK(iter1 > iter2);

    // Test less than operator
    CHECK_FALSE(iter1 < iter1);
    CHECK_FALSE(iter1 < iter2);

    ++iter2;
    CHECK(iter1 < iter2);
}



TEST_CASE("Cheking SideCrossIterator"){
    MagicalContainer container;
    container.addElement(17);
    container.addElement(2);
    container.addElement(25);
    container.addElement(9);
    container.addElement(3);
    MagicalContainer::SideCrossIterator crossIter(container);
    auto begin = crossIter.begin();
    CHECK(*begin == 2);
    ++begin;
    CHECK(*begin == 25);
    ++begin;
    CHECK(*begin == 3);
    ++begin;
    CHECK(*begin == 17);
    ++begin;
    CHECK(*begin == 9);
}




TEST_CASE("Checking SideCrossIterator with an empty container") {
    MagicalContainer container;
    MagicalContainer::SideCrossIterator crossIter(container);
    auto begin_it = crossIter.begin();
    auto end_it = crossIter.end();
    CHECK(begin_it == end_it);
}


TEST_CASE("SideCrossIterator reverse order") {
    MagicalContainer container;
    container.addElement(9);
    container.addElement(7);
    container.addElement(5);
    container.addElement(3);
    MagicalContainer::SideCrossIterator crossIter(container);
    auto temp = crossIter.begin();
    // Test the iterator with elements in reverse order
    CHECK(*temp == 3);  // The iterator points to the smallest element
    ++temp;
    CHECK(*temp == 9);
    ++temp;
    CHECK(*temp == 5);
    ++temp;
    CHECK(*temp == 7);  // The iterator points to the largest element
    ++temp;
    CHECK(temp == crossIter.end());  // The iterator is now at the end
}

TEST_CASE("SideCrossIterator odd number of elements") {
    MagicalContainer container;
    container.addElement(8);
    container.addElement(3);
    container.addElement(12);
    container.addElement(5);
    container.addElement(10);
    //3 5 8 10 12 -> 3 12 5 10 8
    MagicalContainer::SideCrossIterator crossIter(container);
    auto temp = crossIter.begin();
    // Test the iterator with an odd number of elements
    CHECK(*temp == 3);  // The iterator points to the smallest element
    ++temp;
    CHECK(*temp == 12);
    ++temp;
    CHECK(*temp == 5);
    ++temp;
    CHECK(*temp == 10);  // The iterator points to the largest element
    CHECK_FALSE(temp == crossIter.end());  // The iterator is now not at the end
}



//-------------------PrimeIterator------------------------


TEST_CASE("PrimeIterator comparison operators") {
    MagicalContainer container;
    container.addElement(3);
    container.addElement(8);
    container.addElement(5);
    container.addElement(12);
    MagicalContainer::PrimeIterator iter1(container);
    MagicalContainer::PrimeIterator iter2(container);

    // Test equality operator
    CHECK(iter1 == iter1);
    CHECK(iter1 == iter2);

    ++iter2;
    CHECK_FALSE(iter1 == iter2);

    // Test inequality operator
    CHECK_FALSE(iter1 != iter1);
    CHECK_FALSE(iter1 != iter2);

    ++iter2;
    CHECK(iter1 != iter2);

    // Test greater than operator
    CHECK_FALSE(iter1 > iter1);
    CHECK_FALSE(iter1 > iter2);

    ++iter1;
    CHECK(iter1 > iter2);

    // Test less than operator
    CHECK_FALSE(iter1 < iter1);
    CHECK_FALSE(iter1 < iter2);

    ++iter2;
    CHECK(iter1 < iter2);
}


TEST_CASE("PrimeIterator with prime elements") {
    MagicalContainer container;
    container.addElement(2);
    container.addElement(3);
    container.addElement(5);
    container.addElement(7);
    container.addElement(11);
    MagicalContainer::PrimeIterator primeIter(container);
    auto begin = primeIter.begin();
    CHECK(*begin == 2);  // The iterator points to the first prime element
    ++begin;
    CHECK(*begin == 3);
    ++begin;
    CHECK(*begin == 5);
    ++begin;
    CHECK(*begin == 7);
    ++begin;
    CHECK(*begin == 11);  // The iterator points to the last prime element
    ++begin;
    CHECK(begin == primeIter.end());  // The iterator is now at the end
}

TEST_CASE("PrimeIterator without prime elements") {
    MagicalContainer container;
    container.addElement(4);
    container.addElement(6);
    container.addElement(8);
    container.addElement(9);
    container.addElement(10);
    MagicalContainer::PrimeIterator primeIter(container);
    auto begin = primeIter.begin();
    auto end = primeIter.end();
    CHECK(begin == end);  // The iterator is already at the end since there are no prime elements
}

TEST_CASE("PrimeIterator with mixed elements") {
    MagicalContainer container;
    container.addElement(2);
    container.addElement(4);
    container.addElement(7);
    container.addElement(8);
    container.addElement(11);
    MagicalContainer::PrimeIterator primeIter(container);
    auto begin = primeIter.begin();
    CHECK(*begin == 2);  // The iterator points to the first prime element
    ++begin;
    CHECK(*begin == 7);
    ++begin;
    CHECK(*begin == 11);  // The iterator points to the last prime element
    ++begin;
    CHECK(begin == primeIter.end());  // The iterator is now at the end
}


TEST_CASE("PrimeIterator with large prime numbers") {
    MagicalContainer container;
    container.addElement(3491);
    container.addElement(5867);
    container.addElement(7649);
    container.addElement(7829);
    container.addElement(7901);
    MagicalContainer::PrimeIterator primeIter(container);
    auto begin = primeIter.begin();
    CHECK(*begin == 3491);  // The iterator points to the first prime element (9999991)
    ++begin;
    CHECK(*begin == 5867); 
    ++begin;
    CHECK(*begin == 7649);
    ++begin;
    CHECK(*begin == 7829);
    ++begin;
    CHECK(*begin == 7901); 
   
}

TEST_CASE("PrimeIterator empty container") {
    MagicalContainer container;
    MagicalContainer::PrimeIterator primeIter(container);
    auto begin_it = primeIter.begin();
    auto end_it = primeIter.end();
    CHECK(begin_it == end_it);  // The iterator is already at the end since the container is empty
}