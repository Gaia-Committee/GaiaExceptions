#include <gtest/gtest.h>
#include <GaiaExceptions/GaiaExceptions.hpp>
#include <iostream>

using namespace Gaia;

TEST(ExceptionWrapper, BasicThrow)
{
	Exceptions::ExceptionWrapper<std::runtime_error> test_exception("std::runtime_error");
	std::cout << test_exception.GetMessage() << std::endl;
	std::cout << test_exception.what() << std::endl;
}