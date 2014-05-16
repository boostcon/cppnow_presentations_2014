#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>
#include "directory_scanner.hpp"
#include "scanner.hpp"

//[fake_directory_scanner
class fake_directory_scanner : public directory_scanner
{
public:
    fake_directory_scanner()
        : begin_called(false),
        has_next_called(false),
        next_called(false),
        next_call_count(0U)
    {}

    virtual ~fake_directory_scanner() {}

    virtual void begin(std::string const &directory)
    {
        begin_called = true;
        begin_last_directory = directory;
    }
    bool begin_called;
    std::string begin_last_directory;

    virtual bool has_next() const
    {
        has_next_called = true;
        return next_call_count <= next_fake_results.size();
    }
    mutable bool has_next_called;
    bool has_next_fake_result;

    virtual std::string next() const
    {
        next_called = true;
        ++next_call_count;
        return has_next() ? next_fake_results[next_call_count - 1U] : "";
    }
    mutable bool next_called;
    mutable std::size_t next_call_count;
    std::vector<std::string> next_fake_results;
};
//]

//[test_scanner
static std::string const ARBITRARY_DIRECTORY_NAME("foo");
static std::string const ARBITRARY_NON_TEXT_FILE_NAME("foo.foo");
static std::string const ARBITRARY_TEXT_FILE_NAME("foo.txt");
static std::string const ARBITRARY_OTHER_TEXT_FILE_NAME("bar.txt");

struct text_files_fixture
{
    void expect_enumerate_non_text_file()
    {
        scanner.next_fake_results.push_back(ARBITRARY_NON_TEXT_FILE_NAME);
    }

    void expect_enumerate_text_file(std::string const& file_name = ARBITRARY_TEXT_FILE_NAME)
    {
        scanner.next_fake_results.push_back(file_name);
        expected.push_back(file_name);
    }

    fake_directory_scanner scanner;
    std::vector<std::string> empty;
    std::vector<std::string> expected;
};

BOOST_FIXTURE_TEST_SUITE(test_text_files, text_files_fixture);

BOOST_AUTO_TEST_CASE(returns_empty_for_empty_directory)
{
    std::vector<std::string> files = text_files(ARBITRARY_DIRECTORY_NAME, scanner);

    BOOST_REQUIRE_EQUAL_COLLECTIONS(empty.begin(), empty.end(), files.begin(), files.end());
}

BOOST_AUTO_TEST_CASE(returns_empty_for_no_text_files)
{
    expect_enumerate_non_text_file();

    std::vector<std::string> files = text_files(ARBITRARY_DIRECTORY_NAME, scanner);

    BOOST_REQUIRE_EQUAL_COLLECTIONS(empty.begin(), empty.end(), files.begin(), files.end());
}

BOOST_AUTO_TEST_CASE(returns_file_for_text_file)
{
    expect_enumerate_text_file();

    std::vector<std::string> files = text_files(ARBITRARY_DIRECTORY_NAME, scanner);

    BOOST_REQUIRE_EQUAL_COLLECTIONS(expected.begin(), expected.end(), files.begin(), files.end());
}

BOOST_AUTO_TEST_CASE(returns_only_text_file_for_mixed_files)
{
    expect_enumerate_text_file();
    expect_enumerate_non_text_file();

    std::vector<std::string> files = text_files(ARBITRARY_DIRECTORY_NAME, scanner);

    BOOST_REQUIRE_EQUAL_COLLECTIONS(expected.begin(), expected.end(), files.begin(), files.end());
}

BOOST_AUTO_TEST_CASE(returns_all_text_files)
{
    expect_enumerate_text_file();
    expect_enumerate_non_text_file();
    expect_enumerate_text_file(ARBITRARY_OTHER_TEXT_FILE_NAME);

    std::vector<std::string> files = text_files(ARBITRARY_DIRECTORY_NAME, scanner);

    BOOST_REQUIRE_EQUAL_COLLECTIONS(expected.begin(), expected.end(), files.begin(), files.end());
}

BOOST_AUTO_TEST_SUITE_END();
//]
