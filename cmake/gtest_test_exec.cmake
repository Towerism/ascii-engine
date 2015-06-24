include(gtest_add_tests)
macro(gtest_test_exec TARGET)
  gtest_add_tests(${TARGET} "" "AUTO")
endmacro()