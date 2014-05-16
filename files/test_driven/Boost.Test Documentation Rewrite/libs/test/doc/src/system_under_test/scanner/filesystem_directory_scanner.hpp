#if !defined(FILESYSTEM_DIRECTORY_SCANNER_H)
#define FILESYSTEM_DIRECTORY_SCANNER_H

#include "directory_scanner.hpp"
#include <boost/filesystem.hpp>

//[filesystem_directory_scanner
class filesystem_directory_scanner : public directory_scanner
{
public:
    filesystem_directory_scanner() {}
    virtual ~filesystem_directory_scanner() {}

    virtual void begin(std::string const &directory)
    {
        current = boost::filesystem::directory_iterator(directory);
    }

    virtual bool has_next() const
    {
        return current != end;
    }

    virtual std::string next() const
    {
        if (has_next())
        {
            std::string const result = (*current).path().filename().string();
            do
            {
                ++current;
            }
            while (has_next() && !boost::filesystem::is_regular_file((*current).path()));
            return result;
        }
        throw std::runtime_error("no next path");
    }

private:
    mutable boost::filesystem::directory_iterator current;
    boost::filesystem::directory_iterator end;
};
//]

#endif
