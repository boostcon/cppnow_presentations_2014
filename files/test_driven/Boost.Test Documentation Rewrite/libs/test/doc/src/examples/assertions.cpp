//[example_test_module
#define BOOST_TEST_MAIN
#define BOOST_TEST_MODULE "Assertions"
#include <boost/test/unit_test.hpp>
//]

#include <cstring>
#include <list>
#include <ostream>
#include <stdexcept>
#include <string>
#include <vector>

//[example_bitwise_equal
enum bit_flags
{
    source_file = 1u,
    header_file = 2u,
    build_file = 4u
};

BOOST_AUTO_TEST_CASE(example_bitwise_equal)
{
    BOOST_REQUIRE_BITWISE_EQUAL(
        source_file | build_file,
        build_file | source_file);
}
//]

//[example_close
BOOST_AUTO_TEST_CASE(example_close)
{
    BOOST_REQUIRE_CLOSE(100.f, 100.9f, 1.f);
    BOOST_REQUIRE_CLOSE(100.f, 99.1f, 1.f);
}
//]

//[example_close_fraction
BOOST_AUTO_TEST_CASE(example_close_fraction)
{
    BOOST_REQUIRE_CLOSE_FRACTION(100.f, 100.9f, 1.f);
    BOOST_REQUIRE_CLOSE_FRACTION(100.f, 99.1f, 1.f);
}
//]

//[example_equal
BOOST_AUTO_TEST_CASE(example_equal)
{
    // integral types
    unsigned const u = 1u;
    int const i = -1;
    char const A = 'A';
    // standard library types providing operator== and operator<<
    std::string const s = "scooby";

    BOOST_REQUIRE_EQUAL(1u, u);
    BOOST_REQUIRE_EQUAL(-1, i);
    BOOST_REQUIRE_EQUAL('A', A);
    BOOST_REQUIRE_EQUAL("scooby", s);
}
//]

//[example_equal_custom_compare
// custom data structure
struct symbol
{
    char const* const name;
    int value;
};

// custom comparison operator
static bool operator==(symbol const& lhs, symbol const& rhs)
{
    return lhs.value == rhs.value
        && std::string(lhs.name) == std::string(rhs.name);
}

// custom stream insertion operator
static std::ostream& operator<<(std::ostream& stream, symbol const& value)
{
    return stream << value.name << ": " << value.value;
}

BOOST_AUTO_TEST_CASE(example_equal_custom_compare)
{
    symbol const s1 = { "var" , 1 };
    symbol const s2 = { "var", 1 };
    // If the compiler doesn't collapse multiple constants, then:
    // s1.name != s2.name;

    BOOST_REQUIRE_EQUAL(s1, s2);
}
//]

//[example_equal_collections
static std::list<int> generate_list()
{
    std::list<int> l;
    l.push_front(3);
    l.push_front(2);
    l.push_front(1);

    return l;
}

BOOST_AUTO_TEST_CASE(example_equal_collections)
{
    std::vector<int> expected;
    expected.push_back(1);
    expected.push_back(2);
    expected.push_back(3);

    std::list<int> actual = generate_list();

    BOOST_REQUIRE_EQUAL_COLLECTIONS(
        expected.begin(), expected.end(),
        actual.begin(), actual.end());
}

BOOST_AUTO_TEST_CASE(example_equal_collections_pod)
{
    int const expected[] = { 1, 2, 3 };

    std::list<int> actual = generate_list();

    BOOST_REQUIRE_EQUAL_COLLECTIONS(
        &expected[0], &expected[sizeof(expected)/sizeof(expected[0])],
        actual.begin(), actual.end());
}
//]

//[example_exception
class error_number_exception
{
public:
    error_number_exception(int num)
        : num_(num)
    { }

    int error_number() const { return num_; }

private:
    int num_;
};

static bool has_error_number_1(error_number_exception const& ex)
{
    return ex.error_number() == 1;
}

BOOST_AUTO_TEST_CASE(example_exception)
{
    BOOST_REQUIRE_EXCEPTION(throw error_number_exception(1),
        error_number_exception, has_error_number_1);
}
//]

//[example_ge
BOOST_AUTO_TEST_CASE(example_ge)
{
    // integral types
    unsigned const u = 1u;
    int const i = -10;
    char const A = 'A';
    // standard library types providing operator>= and operator<<
    std::string const s = "scooby";

    BOOST_REQUIRE_GE(2u, u);
    BOOST_REQUIRE_GE(1u, u);
    BOOST_REQUIRE_GE(-9, i);
    BOOST_REQUIRE_GE(-10, i);
    BOOST_REQUIRE_GE('B', A);
    BOOST_REQUIRE_GE('A', A);
    BOOST_REQUIRE_GE("scoobz", s);
    BOOST_REQUIRE_GE("scooby", s);
}
//]

//[example_gt
BOOST_AUTO_TEST_CASE(example_gt)
{
    // integral types
    unsigned const u = 1u;
    int const i = -10;
    char const A = 'A';
    // standard library types providing operator> and operator==
    std::string const s = "scooby";

    BOOST_REQUIRE_GT(2u, u);
    BOOST_REQUIRE_GT(-9, i);
    BOOST_REQUIRE_GT('B', A);
    BOOST_REQUIRE_GT("scoobz", s);
}
//]

//[example_le
BOOST_AUTO_TEST_CASE(example_le)
{
    // integral types
    unsigned const u = 10u;
    int const i = -10;
    char const M = 'M';
    // standard library types providing operator>= and operator<<
    std::string const s = "scooby";

    BOOST_REQUIRE_LE(9u, u);
    BOOST_REQUIRE_LE(10u, u);
    BOOST_REQUIRE_LE(-11, i);
    BOOST_REQUIRE_LE(-10, i);
    BOOST_REQUIRE_LE('L', M);
    BOOST_REQUIRE_LE('M', M);
    BOOST_REQUIRE_LE("scoobx", s);
    BOOST_REQUIRE_LE("scooby", s);
}
//]

//[example_lt
BOOST_AUTO_TEST_CASE(example_lt)
{
    // integral types
    unsigned const u = 10u;
    int const i = -10;
    char const M = 'M';
    // standard library types providing operator>= and operator<<
    std::string const s = "scooby";

    BOOST_REQUIRE_LT(9u, u);
    BOOST_REQUIRE_LT(-11, i);
    BOOST_REQUIRE_LT('L', M);
    BOOST_REQUIRE_LT("scoobx", s);
}
//]

//[example_message
static int g_i;

// simple predicate
static bool global_int_is_positive()
{
    return g_i > 0;
}

// predicate that builds up detail message
static boost::test_tools::predicate_result global_int_equal(int expected)
{
    if (g_i == expected)
    {
        return true;
    }

    boost::test_tools::predicate_result failed = false;
    failed.message() << "g_i != " << expected << "; actual: " << g_i;
    return failed;
}

BOOST_AUTO_TEST_CASE(example_message)
{
    g_i = 1;

    BOOST_REQUIRE_MESSAGE(global_int_is_positive(),
        "g_i is not positive; actual: " << g_i);
    BOOST_REQUIRE_MESSAGE(global_int_equal(1), "g_i equals 1");
}
//]

//[example_ne
BOOST_AUTO_TEST_CASE(example_ne)
{
    // integral types
    unsigned const u = 1u;
    int const i = -1;
    char const A = 'A';
    // standard library types providing operator!= and operator<<
    std::string const s = "scooby";

    BOOST_REQUIRE_NE(2u, u);
    BOOST_REQUIRE_NE(-2, i);
    BOOST_REQUIRE_NE('B', A);
    BOOST_REQUIRE_NE("scoobz", s);
}
//]

//[example_no_throw
BOOST_AUTO_TEST_CASE(example_no_throw)
{
    BOOST_REQUIRE_NO_THROW(1 + 1);
}
//]

//[example_predicate
static bool custom_string_compare(char const* const expected, char const* const actual)
{
    return std::strcmp(expected, actual) == 0;
}

BOOST_AUTO_TEST_CASE(example_predicate)
{
    char const* const s = "scooby";

    BOOST_REQUIRE_PREDICATE(custom_string_compare, ("scooby")(s));
}
//]

//[example_small
BOOST_AUTO_TEST_CASE(example_small)
{
    float const f = 0.1f;

    BOOST_REQUIRE_SMALL(f, 0.25f);
}
//]

//[example_throw
static void always_throws()
{
    throw std::runtime_error("whoops");
}

BOOST_AUTO_TEST_CASE(example_throw)
{
    BOOST_REQUIRE_THROW(always_throws(), std::runtime_error);
}
//]

//[example_test_dont_print_log_value
struct custom
{
    int value;
};

BOOST_TEST_DONT_PRINT_LOG_VALUE(custom);

static bool operator==(custom const& expected, custom const& actual)
{
    return expected.value == actual.value;
}

BOOST_AUTO_TEST_CASE(example_test_dont_print_log_value)
{
    custom const v1 = { 1 };
    custom const v2 = { 1 };
    BOOST_REQUIRE_EQUAL(v1, v2);
}
//]

//[example_checkpoint
BOOST_AUTO_TEST_CASE(example_checkpoint)
{
    int const i = 0;
    BOOST_TEST_CHECKPOINT("i = " << i);

    BOOST_REQUIRE(i == 0);
}
//]

//[example_test_message
BOOST_AUTO_TEST_CASE(example_test_message)
{
    int const i = 0;
    BOOST_TEST_MESSAGE("i = " << i);

    BOOST_REQUIRE(i == 0);
}
//]
