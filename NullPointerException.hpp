#pragma once

#include "ExceptionBase.hpp"

namespace Gaia::Exceptions
{
	/// The title of NullPointerException, its value is "NullPointer"
	extern const char NullPointerExceptionName[];

	/**
	 * @brief This exception occurs when a null pointer is used or given.
	 * @details
	 *  This exception will only be thrown by code from Gaia or where it is manually thrown, which means that external
	 *  libraries such as standard CPP libraries will not use this exception.
	 */
	class NullPointerException : public ExceptionBase
	{
	public:
		/**
		 * @brief Constructor which will automatically write down the type information into the message.
		 * @param pointer The pointer which is null.
		 * @param message Usually the description of this pointer.
		 */
		template<typename PointerType>
		explicit NullPointerException(PointerType* pointer, const std::string& message = "None") :
			ExceptionBase("NullPointer",
				 "A null pointer is given where non-null pointer is required. Pointer type: " +
				 std::string(typeid(PointerType).name()) +
				 ". Message:" + message)
		{}

		/**
		 * @brief Check the pointer and throw a NullPointerException when it's null.
		 * @tparam PointerType The class of the given pointer, and it will be automatically determined by the compiler.
		 * @param pointer The pointer to check.
		 * @param message Optional, and it's usually used to describe the pointer.
		 */
		template<typename PointerType>
		static inline void ThrowIfNull(PointerType* pointer, const std::string& message = "None")
		{
			if (pointer)
			{
				throw NullPointerException(pointer, message);
			}
		}
	};
}
