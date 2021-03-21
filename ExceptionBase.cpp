#include "ExceptionBase.hpp"

#include <sstream>

namespace Gaia::Exceptions
{
	/// Constructor.
	ExceptionBase::ExceptionBase(std::string title, std::string message) :
			Title(std::move(title)), Message(std::move(message))
	{
		CallStack = boost::stacktrace::stacktrace();
		std::stringstream message_builder;
		message_builder << "[" << Title << "] " << Message << " :" << std::endl;
		message_builder << CallStack << std::endl;
		FormattedContent = message_builder.str();
	}

	/// Extract the location from the call stack.
	std::string ExceptionBase::GetLocation() const
	{
		auto& callstack = CallStack.as_vector();
		if (callstack.size() >= 2)
		{
			return CallStack.as_vector()[1].name();
		}
		return CallStack.as_vector()[0].name();
	}
}