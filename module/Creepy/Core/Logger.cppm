module;

#include <print>

export module creepy.core.logger;

// TODO: We need to include <print> everywhere use this Logger
// Need import std; to fix this problem

export namespace Creepy::Log {

    enum class LogLevel : uint32_t {
        Info = 0, Warning, Error
    };

    template <LogLevel logLevel, typename... Args>
    struct Logger{
        constexpr Logger(std::format_string<Args...> str, Args&&... args){

            const char* logLevelChar = []() static {
                if constexpr(logLevel == LogLevel::Info){
                    return "Info";
                }
                else if constexpr(logLevel == LogLevel::Warning){
                    return "Warning";
                }
                else{
                    return "Error";
                }
            }();

            std::println("[{}] - {}", logLevelChar, std::format(str, std::forward<Args>(args)...));
        }
    };

    template <LogLevel logLevel = LogLevel::Info, typename... Args>
    Logger(std::format_string<Args...>, Args&&...) -> Logger<logLevel, Args...>;

    template <typename... Args>
    using Info = Logger<LogLevel::Info, Args...>;

    template <typename... Args>
    using Warning = Logger<LogLevel::Warning, Args...>;

    template <typename... Args>
    using Error = Logger<LogLevel::Error, Args...>;
}