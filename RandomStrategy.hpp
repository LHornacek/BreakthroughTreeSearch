#pragma once
#include "Strategy.hpp"
#include <random>
#include <iostream>

// a player that always chooses his move at random out of all possible valid moves
class RandomStrategy : public Strategy {
public:
    RandomStrategy();

    move makeMove(const std::set<piece>& whitePieces, const std::set<piece>& blackPieces) const override;
};