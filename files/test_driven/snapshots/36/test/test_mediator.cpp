#define BOOST_TEST_NO_LIB
#include <boost/test/unit_test.hpp>
#include <turtle/mock.hpp>
#include "mediator.h"

MOCK_BASE_CLASS(mock_dialog, prime_factors_dialog)
{
  MOCK_METHOD(enable_ok_button, 1);
  MOCK_METHOD(value_text, 0);
};

BOOST_AUTO_TEST_CASE(ok_button_initially_disabled)
{
  mock_dialog dialog;
  MOCK_EXPECT(dialog.enable_ok_button).once().with(false);

  prime_factors_mediator mediator(dialog);
}

BOOST_AUTO_TEST_CASE(ok_button_enabled_with_valid_integer)
{
  mock_dialog dialog;
  MOCK_EXPECT(dialog.enable_ok_button).once().with(false);
  MOCK_EXPECT(dialog.enable_ok_button).once().with(true);
  MOCK_EXPECT(dialog.value_text).returns("123");

  prime_factors_mediator mediator(dialog);
  mediator.value_changed();
}

BOOST_AUTO_TEST_CASE(empty_text_disables_button)
{
  mock_dialog dialog;
  MOCK_EXPECT(dialog.enable_ok_button).at_least(1).with(false);
  MOCK_EXPECT(dialog.value_text).returns("");

  prime_factors_mediator mediator(dialog);
  mediator.value_changed();
}
