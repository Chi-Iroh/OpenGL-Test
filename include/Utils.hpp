#pragma once
#include <concepts>

template<class Container, typename T>
concept isContainer = requires(Container& container) {
    container.cbegin();
    container.begin();
    container.cend();
    container.end();
    container.size();
    { (*container.cbegin()) } -> std::convertible_to<T>;
};

template<class Container, typename T>
requires(isContainer<Container, T>)
constexpr bool containerHas(const Container& container, const T& value) {
    for (const T& elem : container) {
        if (elem == value) {
            return true;
        }
    }
    return false;
}