#pragma once
#include <optional>
#include <string>
#include <vector>

class CommandLineArguments {
    std::vector<std::string> argv{};
public:
    explicit CommandLineArguments(int argc, char* argv[]);
    explicit CommandLineArguments() noexcept = default;

    bool has_option(const std::string& option) const;

    std::optional<std::string> get_option_value(const std::string& option) const;
};