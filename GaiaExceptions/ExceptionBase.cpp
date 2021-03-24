#include "ExceptionBase.hpp"

#include <sstream>

namespace Gaia::Exceptions
{
	/// Constructor.
	ExceptionBase::ExceptionBase(std::string title, std::string message) :
			Title(std::move(title)), Message(std::move(message))
	{
		CallStack = boost::stacktrace::stacktrace();
		RegenerateFormattedContent();
	}

	/// Regenerate the content of FormattedContent according to the content of Message.
	void ExceptionBase::RegenerateFormattedContent()
	{
		std::stringstream message_builder;
		message_builder << "[" << Title << "] " << Message << " :" << std::endl;

		// Print the call stack, and will print the source file and line number in debug mode.
		unsigned int frame_index = 0;
		for (const auto& frame : CallStack)
		{
			message_builder << "#" << frame_index << " " << frame.name() << std::endl;
			#ifdef DEBUG
			if (!frame.source_file().empty())
			{
				message_builder << "    in " << frame.source_file() << " : " << frame.source_line() << std::endl;
			}
			#endif
			++frame_index;
		}

		FormattedContent = message_builder.str();
	}

	/// Reset the content of message and regenerate the FormattedContent.
	void ExceptionBase::SetMessage(std::string message)
	{
		Message = std::move(message);
		RegenerateFormattedContent();
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