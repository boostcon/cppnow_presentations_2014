#if !defined(SCANNER_HPP)
#define SCANNER_HPP

#include <string>
#include <vector>

//[text_files_decl
extern std::vector<std::string> text_files(std::string const& directory);
//]

//[text_files_dependency_decl
class directory_scanner;

extern std::vector<std::string> text_files(
    std::string const& directory,
    directory_scanner& scanner);
//]

#endif
