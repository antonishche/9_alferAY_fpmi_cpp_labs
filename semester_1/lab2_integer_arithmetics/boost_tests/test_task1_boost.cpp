#define BOOST_TEST_MODULE IntegerAlgorithmsTests
#include <boost/test/included/unit_test.hpp>

#include "../src/task1.h"

BOOST_AUTO_TEST_SUITE(RemoveMinDigitsSuite)

BOOST_AUTO_TEST_CASE(BasicTest) {
    BOOST_CHECK_EQUAL(remove_min_digits(12341), 234);
    BOOST_CHECK_EQUAL(remove_min_digits(555), 0);
    BOOST_CHECK_EQUAL(remove_min_digits(98765), 9876);
}

BOOST_AUTO_TEST_CASE(WithZero) {
    BOOST_CHECK_EQUAL(remove_min_digits(102030), 123);
    BOOST_CHECK_EQUAL(remove_min_digits(100200300), 123);
}

BOOST_AUTO_TEST_CASE(EdgeCases) {
    BOOST_CHECK_EQUAL(remove_min_digits(7), 0);
    BOOST_CHECK_EQUAL(remove_min_digits(111), 0);
    BOOST_CHECK_EQUAL(remove_min_digits(123456789), 23456789);
}

BOOST_AUTO_TEST_CASE(InvalidThrows) {
    BOOST_CHECK_THROW(remove_min_digits(0), std::invalid_argument);
    BOOST_CHECK_THROW(remove_min_digits(-1), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(FindMinDigitSuite)

BOOST_AUTO_TEST_CASE(Basic) {
    BOOST_CHECK_EQUAL(find_min_digit(12341), 1);
    BOOST_CHECK_EQUAL(find_min_digit(98765), 5);
    BOOST_CHECK_EQUAL(find_min_digit(111), 1);
}

BOOST_AUTO_TEST_CASE(WithZeroInNumber) {
    BOOST_CHECK_EQUAL(find_min_digit(102030), 0);
    BOOST_CHECK_EQUAL(find_min_digit(1000), 0);
}

BOOST_AUTO_TEST_CASE(SingleDigit) {
    BOOST_CHECK_EQUAL(find_min_digit(0), 0);
    BOOST_CHECK_EQUAL(find_min_digit(5), 5);
    BOOST_CHECK_EQUAL(find_min_digit(9), 9);
}

// BOOST_AUTO_TEST_CASE(InvalidThrows) {
//     BOOST_CHECK_THROW(find_min_digit(-1), std::invalid_argument);
//     BOOST_CHECK_THROW(find_min_digit(-100), std::invalid_argument);
// }

BOOST_AUTO_TEST_SUITE_END()