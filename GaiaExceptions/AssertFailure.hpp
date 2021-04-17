#pragma once

#include "ExceptionBase.hpp"

namespace Gaia::Exceptions
{
    class AssertFailure : public ExceptionBase
    {
    public:
        /**
		 * @brief Constructor which will automatically write down the condition information into the message.
		 * @param condition The assert condition which should be satisfied.
		 */
        explicit AssertFailure(const std::string& condition = "None") :
            ExceptionBase("AssertFailed", "Assert:" + condition + " Failed." + message)
        {}

        /**
         * @brief Throw an exception of AssertFailure if the given condition is not satisfied.
         * @param condition The condition that should be satisfied.
         * @param description The description of the condition.
         */
        static inline void ThrowIfNot(bool condition, const std::string& description)
        {
            if (!condition)
            {
                throw AssertFailure(description);
            }
        }
    };
}
