#if !defined(MEDIATOR_H)
#define MEDIATOR_H

class prime_factors_dialog
{
public:
  virtual ~prime_factors_dialog() { }
  virtual void enable_ok_button(bool enabled) = 0;
};

class prime_factors_mediator
{
public:
  prime_factors_mediator(prime_factors_dialog& dialog) { }
};

#endif
