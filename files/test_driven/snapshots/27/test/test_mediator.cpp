#define BOOST_TEST_NO_LIB
#include <boost/test/unit_test.hpp>
#include "mediator.h"

BOOST_AUTO_TEST_CASE(ok_button_initially_disabled)
{
  // ?what_type? dialog;

  prime_factors_mediator mediator(dialog);

  // ?how? verify that ok button is initially disabled
}
