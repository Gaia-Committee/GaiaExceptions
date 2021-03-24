#pragma once

#include <exception>
#include <string>
#include <boost/stacktrace.hpp>

namespace Gaia::Exceptions
{
	/**
	 * @brief Base class for all exceptions.
	 * @details
	 *  This class provides basic exception message and call stack tracing storage and acquire.
	 */
	class ExceptionBase : public std::exception
	{
	private:
		/// Text used to identify type of the exception instance.
		const std::string Title;
		/// Text used to describe detailed information.
		std::string Message;
		/// Object used to get call stack, constructed along with the exception.
		boost::stacktrace::stacktrace CallStack;
		/**
		 * @brief Text contains both the title and detailed information of the exception instance.
		 * @details Generated along with the construction of the exception instance.
		 */
		std::string FormattedContent;

		/// Regenerate the content of FormattedContent according to the content of Message.
		void RegenerateFormattedContent();

	protected:
		/**
		 * @brief Reset the content of message and regenerate the FormattedContent.
		 * @param message Message Text.
		 */
		void SetMessage(std::string message);

	public:
		/**
		 * @brief Default constructor.
		 * @param title To describe the name of the type of this exception, e.g "NullPointer"
		 * @param message To describe the detailed information of this exception,
		 * 				  usually the reason why this exception occurs.
		 */
		explicit ExceptionBase(std::string title, std::string message = "");

		/**
		 * @brief Get the title of this exception.
		 * @return Const reference of the std::string title.
		 * @details Usually exception instances of the same class have the same title.
		 */
		[[nodiscard]] const inline std::string& GetTitle() const
		{
			return Title;
		}

		/**
		 * @brief Get the message of this exception.
		 * @return Const reference of the std::string message.
		 * @details Usually message describe the detailed reason why this exception occurs.
		 */
		[[nodiscard]] const inline std::string& GetMessage() const
		{
			return Message;
		}

		/**
		 * @brief Get the name of the function where this exception first occurs.
		 * @return An item of the call stack at a certain index.
		 */
		[[nodiscard]] std::string GetLocation() const;

		/**
		 * @brief Get the call stack of the constructor of this exception instance.
		 * @return Const reference of the call stack.
		 */
		[[nodiscard]] const inline boost::stacktrace::stacktrace& GetCallStack() const
		{
			return CallStack;
		}

		/// Standard function interface for exception message.
		[[nodiscard]] const char *what() const noexcept override
		{
			return FormattedContent.c_str();
		}
	};
}