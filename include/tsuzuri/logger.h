#pragma once

#include <mutex>
#include <fstream>
#include <source_location>
#include <string_view>
#include <filesystem>

namespace tsuzuri
{
    enum class Error
    {
        build_cannot_open_file_path
    };

    constexpr inline std::string_view DEFAULT_LOG_PATH = "logs/app.log";

    /*
     * invariance: one logger corresponds to one file opented
     */
    class Logger
    {
    public:
        explicit Logger();
        explicit Logger(std::filesystem::path logPath);

        Logger(const Logger& other) = delete;
        Logger& operator=(const Logger& other) = delete;

        Logger(Logger&& other) = delete;
        Logger& operator=(Logger&& other) = delete;

        void log(std::string_view text, const std::source_location location = std::source_location::current());

    private:

        std::ofstream file_;
        std::mutex mut_;
    };
}
