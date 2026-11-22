#include "include/tsuzuri/logger.h"
#include <stdexcept>
#include <filesystem>
#include <format>
#include <iostream>
#include <source_location>

namespace tsuzuri
{
    Logger::Logger()
        : Logger(std::filesystem::path{DEFAULT_LOG_PATH})
    {}

    Logger::Logger(std::filesystem::path logPath)
    {
        const std::filesystem::path parentPath = logPath.parent_path();
        if (!parentPath.empty()) {
            std::filesystem::create_directories(parentPath);
        }

        file_.open(logPath, std::ios::app);
        if (!file_) {
            throw std::runtime_error(std::format("cannot open the file path {}", logPath.string()));
        }
    }

    void Logger::log(std::string_view text, 
            const std::source_location location)
    {
        std::lock_guard<std::mutex> lock(mut_);
        std::string prefixText = std::format(
                "[tsuzuri] {} at line {}, {}: ",
                location.file_name(),
                location.line(),
                location.function_name()
                );
        file_ << prefixText
            << text
            << '\n';

        std::cout << prefixText
            << text
            << '\n';
    }
}
