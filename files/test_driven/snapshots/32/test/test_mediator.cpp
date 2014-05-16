#define BOOST_TEST_NO_LIB
#include <boost/test/unit_test.hpp>
#include <turtle/mock.hpp>
#include "mediator.h"

MOCK_BASE_CLASS(mock_dialog, prime_factors_dialog)
{
  MOCK_METHOD(enable_ok_button, 1);
};

BOOST_AUTO_TEST_CASE(ok_button_initially_disabled)
{
  mock_dialog dialog;
  MOCK_EXPECT(dialog.enable_ok_button).once().with(false);

  prime_factors_mediator mediator(dialog);
}
