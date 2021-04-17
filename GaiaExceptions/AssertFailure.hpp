#pragma once

#include "ExceptionBase.hpp"

namespace Gaia::Exceptions
{
    /**
     * @brief This exception usually occurs when a manually appointed condition is unsatisfied.
     * @details
     *  This exception can be used to describe a disorder of the program.
     *  For example, it can be thrown when some functions are not invoked according to the right sequence designed by
     *  the developer, or some files should exist but actually not.
     */
    class AssertFailure : public ExceptionBase
    {
    public:
        /**
		 * @brief Constructor which will automatically write down the condition information into the message.
		 * @param condition The assert condition which should be satisfied.
		 */
        explicit AssertFailure(const std::string& condition = "Hidden Expression") :
            ExceptionBase("AssertFailed", "Assert:" + condition + " Failed.")
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
