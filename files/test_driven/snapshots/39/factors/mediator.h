#if !defined(MEDIATOR_H)
#define MEDIATOR_H

#include <string>
#include <sstream>

class prime_factors_dialog
{
public:
  virtual ~prime_factors_dialog() { }
  virtual void enable_ok_button(bool enabled) = 0;
  virtual std::string value_text() const = 0;
};

class prime_factors_mediator
{
public:
  prime_factors_mediator(prime_factors_dialog& dialog)
      : dialog_(dialog) {
    dialog.enable_ok_button(false);
  }
  void value_changed() {
    std::istringstream stream(dialog_.value_text());
    int n;
    stream >> n;
    dialog_.enable_ok_button(!stream.fail() &&
      dialog_.value_text().length() > 0);
  }

private:
  prime_factors_dialog& dialog_;
};

#endif
