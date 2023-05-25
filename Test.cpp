#include "doctest.h"
#include "MagicalContainer.h"
#include <iostream>
#include <vector>


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

TEST_CASE("Cheking removeElement function"){
    MagicalContainer container;
    container.addElement(17);
    container.addElement(2);
    container.addElement(25);
    container.addElement(9);
    container.addElement(3);
    CHECK_THROWS_AS(container.removeElement(80), std::runtime_error);
    CHECK_THROWS_AS(container.removeElement(16), std::runtime_error);
    CHECK_THROWS_AS(container.removeElement(8), std::runtime_error);
    CHECK_THROWS_AS(container.removeElement(6), std::runtime_error);
    CHECK_NOTHROW(container.removeElement(17));
    CHECK(container.size() == 4);
    CHECK_NOTHROW(container.removeElement(2));
    CHECK_NOTHROW(container.removeElement(25));
    CHECK_NOTHROW(container.removeElement(9));
    CHECK(container.size() == 1);
    CHECK_NOTHROW(container.removeElement(3));
    CHECK(container.size() == 0);

}

TEST_CASE("Cheking AscendingIterator"){
    MagicalContainer container;
    container.addElement(17);
    container.addElement(2);
    container.addElement(25);
    container.addElement(9);
    container.addElement(3);
    AscendingIterator ascIter(container);
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