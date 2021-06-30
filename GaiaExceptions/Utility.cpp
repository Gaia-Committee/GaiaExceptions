#include "Utility.hpp"
#include "ExceptionBase.hpp"

#include <sstream>
#include <fstream>
#include <chrono>

namespace Gaia::Exceptions
{
    /// Save the exception to a file.
    void Dump(std::exception& error, const std::string& file_name)
    {
        std::ofstream file;

        if (!file_name.empty())
        {
            file.open(file_name);
        }
        else
        {
            auto current_time_point = std::chrono::system_clock::now();
            auto global_time = std::chrono::system_clock::to_time_t(current_time_point);
            auto local_time = std::localtime(&global_time);

            std::stringstream file_name_builder;

            file_name_builder << "Exception ";
            file_name_builder << local_time->tm_mon + 1 << "-" << local_time->tm_mday << "_";
            file_name_builder << local_time->tm_hour << "-" << local_time->tm_min << "-" << local_time->tm_sec;
            file_name_builder << ".log";

            file.open(file_name_builder.str());
        }

        if (!file.is_open())
        {
            throw Exceptions::ExceptionBase("Failure",
                                           "Failed to open file to write down the exception information.");
        }

        file << error.what();
        file.close();
    }
}