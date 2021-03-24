#pragma once

#include "ExceptionBase.hpp"

#include <type_traits>

namespace Gaia::Exceptions
{
	/**
	 * @brief This class is designed for wrapping exceptions which doesn't inherit ExceptionBase and make them
	 *        have the functions that ExceptionBase provides.
	 * @tparam ExceptionType The type of the exception to wrap.
	 */
	template<typename ExceptionType>
	class ExceptionWrapper : public ExceptionBase
	{
	public:
		/// The exception which is constructed along with the wrapper.
		ExceptionType WrappedException;

		/**
		 * @brief Constructor which will automatically write down the type information into the message.
		 * @tparam ConstructorArgumentTypes The types of the parameters for the constructor of ExceptionType.
		 */
		template<typename... ConstructorArgumentTypes>
		explicit ExceptionWrapper(ConstructorArgumentTypes... constructor_arguments) :
			ExceptionBase("WrappedException"), WrappedException(ExceptionType(constructor_arguments...))
		{
			static_assert(std::is_base_of_v<std::exception, ExceptionType>,
			        "Exception class is not derived from std::exception.");
			SetMessage(WrappedException.what());
		}
	};
}