#pragma once

#include "ExceptionBase.hpp"

namespace Gaia::Exceptions
{
    /**
     * @brief This exception represents a failure related to the network.
     */
    class NetworkFailure : public ExceptionBase
    {
    public:
        /// Constructor
        NetworkFailure(const std::string& address, const std::string& operation) :
            ExceptionBase("NetworkFailure",
                          "Network operation " + operation + " to " + address + " failed"),
            AddressName(address), OperationName(operation)
        {}

        /// Text of the ip and port address.
        const std::string AddressName;
        /// Name of the operation.
        const std::string OperationName;
    };
}