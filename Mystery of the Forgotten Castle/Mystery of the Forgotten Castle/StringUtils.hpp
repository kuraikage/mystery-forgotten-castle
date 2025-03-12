#pragma once
#include <string_view>
#include <string>
#include <algorithm>
#include <cctype>

/**
 * @brief Converts a string to lowercase.
 * 
 * This function takes a string view as input and returns a new string
 * with all characters converted to lowercase.
 * 
 * @param input The input string view to be converted to lowercase.
 * @return A new string with all characters in lowercase.
 */
[[nodiscard]] inline std::string ToLower(std::string_view input)
{
    std::string lowerInput(input); // Convert to std::string (mutable)
    std::transform(lowerInput.begin(), lowerInput.end(), lowerInput.begin(),
        [](unsigned char c) { return static_cast<unsigned char>(std::tolower(c)); }); // casting to unsigned char to avoid undefined behavior with signed characters.
    return lowerInput;
}

/**
 * @brief Trims leading and trailing whitespace from a string view.
 * 
 * This function removes leading and trailing whitespace characters
 * (including spaces, tabs, newlines, etc.) from the input string view
 * and returns a new string view with the trimmed content.
 * 
 * @param input The input string view to be trimmed.
 * @return A new string view with leading and trailing whitespace removed.
 */
constexpr std::string_view Trim(std::string_view input)
{
    const auto stringBegin = input.find_first_not_of(" \t\n\r\f\v");
    if (stringBegin == std::string_view::npos)
        return {};

    const auto stringEnd = input.find_last_not_of(" \t\n\r\f\v");
    return input.substr(stringBegin, stringEnd - stringBegin + 1);
}