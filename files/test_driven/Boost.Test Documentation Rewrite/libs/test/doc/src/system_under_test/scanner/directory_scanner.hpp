#if !defined(DIRECTORY_SCANNER_H)
#define DIRECTORY_SCANNER_H

#include <string>

//[directory_scanner
class directory_scanner
{
public:
    virtual ~directory_scanner() {}

    virtual void begin(std::string const &directory) = 0;

    virtual bool has_next() const = 0;

    virtual std::string next() const = 0;
};
//]

#endif
