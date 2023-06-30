#include <algorithm>
#include <format>
#include <stdexcept>
#include "CommandLineArguments.hpp"

CommandLineArguments::CommandLineArguments(int argc, char* argv[]) {
    if (argc <= 0) {
        throw std::invalid_argument(std::format("argc must be greater or equal to 1, but {} was given !", argc));
    }
    if (argv[argc] != nullptr) {
        throw std::invalid_argument(std::format("NULL string not found at index {} (argc) !", argc));
    }
    this->argv.reserve(argc);
    try {
        std::copy(&argv[0], &argv[argc], std::back_inserter(this->argv));
    } catch (std::logic_error& exception) {
        const auto nullStringPos{ std::find(&argv[0], &argv[argc], nullptr) };
        throw std::invalid_argument(std::format("NULL string found at index {} but given argc is {} !", nullStringPos - &argv[0], argc));
    }
}

bool CommandLineArguments::has_option(const std::string& option) const {
    for (const std::string& arg : argv) {
        if (arg.starts_with(option) && (arg.size() == option.size() || !isalnum(arg[option.size()]))) {
            return true;
        }
    }
    return false;
}

std::optional<std::string> CommandLineArguments::get_option_value(const std::string& option) const {
    for (unsigned i{}; const std::string& arg : argv) {
        if (arg.starts_with(option) && (arg.size() == option.size() || !isalnum(arg[option.size()]))) {
            return i == argv.size() ? std::nullopt : std::optional{ argv[i + 1] };
        }
    }
    return std::nullopt;
}