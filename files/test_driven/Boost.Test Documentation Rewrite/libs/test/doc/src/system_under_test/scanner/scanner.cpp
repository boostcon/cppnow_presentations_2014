#include "scanner.hpp"
#include "filesystem_directory_scanner.hpp"

//[text_files_dependency_impl
extern std::vector<std::string>
text_files(std::string const &directory,
    directory_scanner &scanner)
{
    std::vector<std::string> files;
    scanner.begin(directory);
    while (scanner.has_next())
    {
        std::string file(scanner.next());
        if (file.length() >= 4 &&
            file.substr(file.length() - 4) == ".txt")
        {
            files.push_back(file);
        }
    }
    return files;
}
//]

//[text_files_impl
extern std::vector<std::string>
text_files(std::string const& directory)
{
    filesystem_directory_scanner scanner;
    return text_files(directory, scanner);
}
//]
