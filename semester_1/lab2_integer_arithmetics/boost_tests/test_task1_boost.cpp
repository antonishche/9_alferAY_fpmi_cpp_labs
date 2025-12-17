#define BOOST_TEST_MODULE IntegerAlgorithmsTests
#include <boost/test/included/unit_test.hpp>
#include "../src/task1.h"

BOOST_AUTO_TEST_SUITE(RemoveMinDigitsSuite)

BOOST_AUTO_TEST_CASE(BasicTest)
{
    BOOST_CHECK_EQUAL(remove_min_digits(12341), 234);
    BOOST_CHECK_EQUAL(remove_min_digits(555), 0);
    BOOST_CHECK_EQUAL(remove_min_digits(98765), 9876);
    BOOST_CHECK_EQUAL(remove_min_digits(112233), 2233);
}

BOOST_AUTO_TEST_CASE(WithZero)
{
    BOOST_CHECK_EQUAL(remove_min_digits(102030), 123);
    BOOST_CHECK_EQUAL(remove_min_digits(100200300), 123);
    BOOST_CHECK_EQUAL(remove_min_digits(101010), 111);
}

BOOST_AUTO_TEST_CASE(SingleAndEdge)
{
    BOOST_CHECK_EQUAL(remove_min_digits(7), 0);
    BOOST_CHECK_EQUAL(remove_min_digits(0), 0);
    BOOST_CHECK_EQUAL(remove_min_digits(111), 0);
    BOOST_CHECK_EQUAL(remove_min_digits(123456789), 23456789);
}

BOOST_AUTO_TEST_CASE(NegativeInput)
{
    BOOST_CHECK_EQUAL(remove_min_digits(-123), 0);
    BOOST_CHECK_EQUAL(remove_min_digits(-1), 0);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(FindMinDigitSuite)

BOOST_AUTO_TEST_CASE(Basic)
{
    BOOST_CHECK_EQUAL(find_min_digit(12341), 1);
    BOOST_CHECK_EQUAL(find_min_digit(98765), 5);
    BOOST_CHECK_EQUAL(find_min_digit(111), 1);
}

BOOST_AUTO_TEST_CASE(WithZero)
{
    BOOST_CHECK_EQUAL(find_min_digit(102030), 0);
    BOOST_CHECK_EQUAL(find_min_digit(1000), 0);
    BOOST_CHECK_EQUAL(find_min_digit(500), 0);
}

BOOST_AUTO_TEST_CASE(SingleDigit)
{
    BOOST_CHECK_EQUAL(find_min_digit(0), 0);
    BOOST_CHECK_EQUAL(find_min_digit(5), 5);
    BOOST_CHECK_EQUAL(find_min_digit(9), 9);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(ExceptionSuite)

BOOST_AUTO_TEST_CASE(NoExceptionForValidInput)
{
    BOOST_CHECK_NO_THROW(remove_min_digits(123));
    BOOST_CHECK_NO_THROW(find_min_digit(456));
}

BOOST_AUTO_TEST_CASE(ThrowForInvalidInput)
{
    struct TestStruct {
        static void call_remove() { remove_min_digits(-10); }
        static void call_find() { find_min_digit(-5); }
    };
    
    BOOST_CHECK_THROW(TestStruct::call_remove(), std::invalid_argument);
    BOOST_CHECK_THROW(TestStruct::call_find(), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()