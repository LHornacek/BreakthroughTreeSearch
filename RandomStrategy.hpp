#pragma once
#include "Strategy.hpp"
#include <random>
#include <iostream>

class RandomStrategy : public Strategy {
public:
    RandomStrategy();

    move makeMove(const std::set<piece>& whitePieces, const std::set<piece>& blackPieces) const override;
};