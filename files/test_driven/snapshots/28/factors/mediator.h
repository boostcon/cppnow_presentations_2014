#if !defined(MEDIATOR_H)
#define MEDIATOR_H

class prime_factors_dialog
{
public:
  virtual ~prime_factors_dialog() { }
};

class prime_factors_mediator
{
public:
  prime_factors_mediator(prime_factors_dialog& dialog) { }
};

#endif
