// test.h, Tobias Kreilos, Hochschule Offenburg
// A very simple test framework.
// Version 1.1
// Version history at the end
// The file defines a single function check(a,b) that can be called with parameters
// of different types (but equal for a and b). The function asserts that the two
// paramters are equal (within a certain, predefined range for floating point numbers)
// and prints the result of the comparison on the command line.
// Additionally a summary of all tests is printed at the end of the program.

#ifndef TEST_H
#define TEST_H

#include <iostream>
#include <sstream>
#include <cmath>

/** Simple macro to execute the code that follows the macro (without call from main)
 * 
 * Define a class, that is directly instantiated
 * and contains the test code in the constructor.
 * 
 * Usage:
 * TEST(MyTest)
 * {
 *    // test code
 * }
 */
#define TEST(name)                \
    struct _TestClass##name       \
    {                             \
        _TestClass##name();       \
    } _TestClass##name##Instance; \
    _TestClass##name::_TestClass##name()

// Use a namespace to hide implementation details
namespace SimpleTest
{
    /**
     * Make it possible to print the underlying value of class enums with ostream
     */
    template <typename T>
    std::ostream &operator<<(typename std::enable_if<std::is_enum<T>::value, std::ostream>::type &stream, const T &e)
    {
        return stream << static_cast<typename std::underlying_type<T>::type>(e);
    }

    /**
     * Convert anything to a string.
     */
    template <typename T>
    std::string toString(const T &t)
    {
        std::ostringstream ss;
        ss << t;
        return "\"" + ss.str() + "\"";
    }

    /**
     * Convert bools to string "true" or "false" instead of 0 and 1
     */
    template <>
    inline std::string toString<bool>(const bool &b)
    {
        return b ? "\"true\"" : "\"false\"";
    }

    /**
     * Comparison function for different types
     */
    template <typename T>
    bool isEqual(const T &t1, const T &t2)
    {
        return t1 == t2;
    }

    /**
     * Double values are equal if they differ no more than 1e-12
     */
    template <>
    inline bool isEqual<double>(const double &expectedValue, const double &actualValue)
    {
        const double epsilon = 1e-12;
        const double distance = fabs(actualValue - expectedValue);
        return (distance < epsilon);
    }

   /**
     * Float values are equal if they differ no more than 1e-6
     */
    template <>
    inline bool isEqual<float>(const float &expectedValue, const float &actualValue)
    {
        const double epsilon = 1e-6;
        const double distance = fabs(actualValue - expectedValue);
        return (distance < epsilon);
    }

    /**
     * Test summary is printed in the destructor.
     * Apart from that, the class implements counting of total and failed tests, comparison of floating
     * point numbers within sensible boundaries and prints the result of each test on the command line.
     */
    class Test
    {
    public:
        /**
         * Test class is a Singleton
        */
        static Test &instance()
        {
            static Test test;
            return test;
        }

        /**
         * the main entry point for tests. Test two values for equality and output the result.
         */
        template <typename T>
        bool check(const T &expectedValue, const T &actualValue)
        {
            bool testResult = isEqual(expectedValue, actualValue);
            if (testResult == true)
            {
                registerPassingTest();
                std::cout << "Test successful! Expected value == actual value (=" << toString(expectedValue) << ")" << std::endl;
            }
            else
            {
                registerFailingTest();
                std::cout << "Error in test: expected value " << toString(expectedValue) << ", but actual value was " << toString(actualValue) << std::endl;
            }

            return testResult;
        }

    private:
        /**
         * On destruction, print a summary of all tests.
         */
        ~Test()
        {
            std::cout << "\n--------------------------------------" << std::endl;
            std::cout << "Test summary:" << std::endl;
            std::cout << "Executed tests: " << numTests_ << std::endl;
            std::cout << "Failed tests: " << numFailedTests_ << std::endl;
        }

        void registerPassingTest()
        {
            numTests_++;
        }

        void registerFailingTest()
        {
            numTests_++;
            numFailedTests_++;
        }

        /**
         * For statistics
         */
        int numTests_ = 0;

        /**
         * For statistics
         */
        int numFailedTests_ = 0;
    };

} // SimpleTest namespace

/**
 * Check if the expected value is equal to the actual value.
 * Result is printed on the command line and at the end of the program, a
 * summary of all tests is printed.
 */
template <typename T1, typename T2>
void check(const T1 &actualValue, const T2 &expectedValue)
{
    const T1 expectedValueAsT1 = static_cast<T1>(expectedValue);
    SimpleTest::Test::instance().check(expectedValueAsT1, actualValue);
}

/**
 * Check if the entered value is true.
 * Result is printed on the command line and at the end of the program, a
 * summary of all tests is printed.
 */
inline void check(bool a)
{
    SimpleTest::Test::instance().check(true, a);
}

#endif // TEST_H

/**
 * V1.0: Creation of franework
 * V1.1: make check(bool) inline, automatically convert expected value type to actual value type
*/