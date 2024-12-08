#include <cstddef>
#include <cstdint>
#include <ctime>
#include <format>
#include <iomanip>
#include <iostream>
#include <print>
#include <string>
#include <utility>

// Log level enum
enum class level : uint8_t
{
    debug,   // 调试级别
    info,    // 提示级别
    warning, // 警告级别
    error,   // 错误级别
    n_levels
};

inline level g_log_level = level::info;

inline void setLevel(level lvl)
{
    g_log_level = lvl;
}

/* 处理日志级别工具类 */
class LevelUtil
{
  public:
    static const std::string toString(level level)
    {
        using enum level;
        switch (level)
        {
#define XX(name)      \
    case name:        \
        return #name; \
        break;

            XX(debug);
            XX(info);
            XX(warning);
            XX(error);

#undef XX
        default:
            return "Unknonwn level";
        }
    }

    static const std::string getColor(level level)
    {
        return level_strings_.at((size_t)level);
    }

  private:
    // 日志等级打印字符串
    static constexpr std::array level_strings_{
        "\033[1;36m", /* 青色 */
        "\033[1;32m", /* 绿色 */
        "\033[1;33m", /* 黄色 */
        "\033[1;31m", /* 红色 */
    };
};

template <typename... Args>
void log(level lvl, std::format_string<Args...> fmt, Args &&...args)
{
    if (g_log_level > lvl)
        return;
    std::string str;
    time_t t = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    std::cout << '[' << std::put_time(std::localtime(&t), "%Y-%m-%d %H:%M:%S") << ']'
              << std::format(" [{}{}\033[0m] ", LevelUtil::getColor(lvl), LevelUtil::toString(lvl))
              << std::format(fmt, std::forward<Args>(args)...) << '\n';
}

template <typename... Args>
void debug(std::format_string<Args...> fmt, Args &&...args)
{
    log(level::debug, std::move(fmt), std::forward<Args>(args)...);
}

template <typename... Args>
void info(std::format_string<Args...> fmt, Args &&...args)
{
    log(level::info, std::move(fmt), std::forward<Args>(args)...);
}

template <typename... Args>
void warn(std::format_string<Args...> fmt, Args &&...args)
{
    log(level::warning, std::move(fmt), std::forward<Args>(args)...);
}

template <typename... Args>
void error(std::format_string<Args...> fmt, Args &&...args)
{
    log(level::error, std::move(fmt), std::forward<Args>(args)...);
}
