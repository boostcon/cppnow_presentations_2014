#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>
#include "scanner.hpp"

//[mock_directory_scanner
#include "directory_scanner.hpp"
#include <turtle/mock.hpp>

MOCK_BASE_CLASS(mock_directory_scanner, directory_scanner)
{
    MOCK_METHOD(begin, 1);
    MOCK_METHOD(has_next, 0);
    MOCK_METHOD(next, 0);
};
//]

//[test_scanner_with_mocks
static std::string const ARBITRARY_DIRECTORY_NAME("foo");
static std::string const ARBITRARY_NON_TEXT_FILE_NAME("foo.foo");
static std::string const ARBITRARY_TEXT_FILE_NAME("foo.txt");
static std::string const ARBITRARY_OTHER_TEXT_FILE_NAME("bar.txt");

struct text_files_fixture
{
    text_files_fixture()
    {
        MOCK_EXPECT(scanner.begin).once().with(ARBITRARY_DIRECTORY_NAME);
    }

    void expect_enumerate_non_text_file()
    {
        MOCK_EXPECT(scanner.has_next).once().returns(true);
        MOCK_EXPECT(scanner.next).once().returns(ARBITRARY_NON_TEXT_FILE_NAME);
    }

    void expect_enumerate_text_file(std::string const& file_name = ARBITRARY_TEXT_FILE_NAME)
    {
        MOCK_EXPECT(scanner.has_next).once().returns(true);
        MOCK_EXPECT(scanner.next).once().returns(file_name);
        expected.push_back(file_name);
    }

    void expect_enumerate_end()
    {
        MOCK_EXPECT(scanner.has_next).once().returns(false);
    }

    mock_directory_scanner scanner;
    std::vector<std::string> empty;
    std::vector<std::string> expected;
};

BOOST_FIXTURE_TEST_SUITE(test_text_files, text_files_fixture);

BOOST_AUTO_TEST_CASE(returns_empty_for_empty_directory)
{
    expect_enumerate_end();

    std::vector<std::string> files = text_files(ARBITRARY_DIRECTORY_NAME, scanner);

    BOOST_REQUIRE_EQUAL_COLLECTIONS(empty.begin(), empty.end(), files.begin(), files.end());
}

BOOST_AUTO_TEST_CASE(returns_empty_for_no_text_files)
{
    expect_enumerate_non_text_file();
    expect_enumerate_end();

    std::vector<std::string> files = text_files(ARBITRARY_DIRECTORY_NAME, scanner);

    BOOST_REQUIRE_EQUAL_COLLECTIONS(empty.begin(), empty.end(), files.begin(), files.end());
}

BOOST_AUTO_TEST_CASE(returns_file_for_text_file)
{
    expect_enumerate_text_file();
    expect_enumerate_end();

    std::vector<std::string> files = text_files(ARBITRARY_DIRECTORY_NAME, scanner);

    BOOST_REQUIRE_EQUAL_COLLECTIONS(expected.begin(), expected.end(), files.begin(), files.end());
}

BOOST_AUTO_TEST_CASE(returns_only_text_file_for_mixed_files)
{
    expect_enumerate_text_file();
    expect_enumerate_non_text_file();
    expect_enumerate_end();

    std::vector<std::string> files = text_files(ARBITRARY_DIRECTORY_NAME, scanner);

    BOOST_REQUIRE_EQUAL_COLLECTIONS(expected.begin(), expected.end(), files.begin(), files.end());
}

BOOST_AUTO_TEST_CASE(returns_all_text_files)
{
    expect_enumerate_text_file();
    expect_enumerate_non_text_file();
    expect_enumerate_text_file(ARBITRARY_OTHER_TEXT_FILE_NAME);
    expect_enumerate_end();

    std::vector<std::string> files = text_files(ARBITRARY_DIRECTORY_NAME, scanner);

    BOOST_REQUIRE_EQUAL_COLLECTIONS(expected.begin(), expected.end(), files.begin(), files.end());
}

BOOST_AUTO_TEST_SUITE_END();
//]
