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

TEST_CASE("AscendingIterator single element") {
    MagicalContainer container;
    container.addElement(5);
    MagicalContainer::AscendingIterator ascIter(container);
    auto temp = ascIter.begin();
    // Test the iterator with a single element in the container
    CHECK(*temp == 5);  // The iterator points to the only element
    CHECK(container.size() == 1);
    ++temp;
    CHECK(temp == ascIter.end());  // The iterator is now at the end
}


TEST_CASE("AscendingIterator duplicate elements") {
    MagicalContainer container;
    container.addElement(3);
    container.addElement(7);
    container.addElement(5);
    container.addElement(3);
    container.addElement(7);
    MagicalContainer::AscendingIterator ascIter(container);
    auto temp = ascIter.begin();
    // Test the iterator with duplicate elements
    CHECK(*temp == 3);  // The iterator points to the smallest element
    ++temp;
    CHECK(*temp == 3);  // The iterator points to the next smallest element
    ++temp;
    CHECK(*temp == 5);
    ++temp;
    CHECK(*temp == 7);
    ++temp;
    CHECK(*temp == 7);  // The iterator points to the largest element (duplicate)
    ++temp;
    CHECK(temp == ascIter.end());  // The iterator is now at the end
}


//-------------------SideCrossIterator------------------------


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


TEST_CASE("SideCrossIterator single element") {
    MagicalContainer container;
    container.addElement(3);
    MagicalContainer::SideCrossIterator crossIter(container);
    auto temp = crossIter.begin();
    // Test the iterator with a single element in the container
    CHECK(*temp == 3);  // The iterator points to the only element
    CHECK(container.size() == 1);
    ++temp;
    CHECK(temp == crossIter.end());  // The iterator is now at the end
}



TEST_CASE("SideCrossIterator duplicate elements") {
    MagicalContainer container;
    container.addElement(3);
    container.addElement(7);
    container.addElement(5);
    container.addElement(3);
    container.addElement(7);
    //33577 -> 37375
    MagicalContainer::SideCrossIterator crossIter(container);
    auto temp = crossIter.begin();
    // Test the iterator with duplicate elements
    CHECK(*temp == 3);  
    ++temp;
    CHECK(*temp == 7);  
    ++temp;
    CHECK(*temp == 3);
    ++temp;
    CHECK(*temp == 7);
    ++temp;
    CHECK(*temp == 5); 
    ++temp;
    CHECK(temp == crossIter.end());  
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

TEST_CASE("PrimeIterator single element") {
    MagicalContainer container;
    container.addElement(5);
    MagicalContainer::PrimeIterator primeIter(container);
    auto temp = primeIter.begin();
    // Test the iterator with a single prime element in the container
    CHECK(*temp == 5);  // The iterator points to the only prime element
    CHECK(container.size() == 1);
    ++temp;
    CHECK(temp == primeIter.end());  // The iterator is now at the end
}

// TEST_CASE("PrimeIterator with large prime numbers") {
//     MagicalContainer container;
//     container.addElement(3491);
//     container.addElement(5867);
//     container.addElement(7649);
//     container.addElement(7829);
//     container.addElement(7901);
//     MagicalContainer::PrimeIterator primeIter(container);
//     auto begin = primeIter.begin();
//     CHECK(*begin == 3491);  // The iterator points to the first prime element (9999991)
//     ++begin;
//     CHECK(*begin == 5867); 
//     ++begin;
//     CHECK(*begin == 7649);
//     ++begin;
//     CHECK(*begin == 7829);
//     ++begin;
//     CHECK(*begin == 7901); 
   
// }

TEST_CASE("PrimeIterator empty container") {
    MagicalContainer container;
    MagicalContainer::PrimeIterator primeIter(container);
    auto begin_it = primeIter.begin();
    auto end_it = primeIter.end();
    CHECK(begin_it == end_it);  // The iterator is already at the end since the container is empty
}