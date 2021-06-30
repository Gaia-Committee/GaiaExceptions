#pragma once

#include <string>
#include <exception>
#include "ExceptionBase.hpp"

namespace Gaia::Exceptions
{
    /**
     * @brief Save the information of an exception to a file.
     * @param error The exception to save.
     * @param file_name The name of the file to store the information;
     *                  It will be automatically generated if it's empty.
     */
    void Dump(std::exception& error, const std::string& file_name = std::string());
}
