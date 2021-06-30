#include "ExceptionBase.hpp"

namespace Gaia::Exceptions
{
    /**
     * @brief This exception represents a operation failure on a hardware.
     */
    class HardwareFailure : public ExceptionBase
    {
    public:
        /// Constructor
        HardwareFailure(const std::string& hardware, const std::string& operation) :
                ExceptionBase("HardwareFailure",
                              "Operation " + operation + " on " + hardware + " failed."),
                HardwareName(hardware), OperationName(operation)
        {}

        /// The name of the hardware.
        const std::string HardwareName;
        /// The name of the operation.
        const std::string OperationName;
    };
}