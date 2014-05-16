#define BOOST_TEST_NO_LIB
#include <boost/test/unit_test.hpp>
#include "mediator.h"

BOOST_AUTO_TEST_CASE(ok_button_initially_disabled)
{
  prime_factors_dialog dialog;

  prime_factors_mediator mediator(dialog);

  BOOST_REQUIRE(!"verify that ok button is initially disabled");
}
