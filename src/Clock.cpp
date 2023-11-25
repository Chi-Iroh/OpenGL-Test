#include "../include/Clock.hpp"

Clock::Clock() :
    start{ getActualTime() }
{}

Time Clock::getElapsedTime() const {
    return getActualTime() - start;
}