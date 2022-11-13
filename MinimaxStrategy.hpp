#pragma once
#include "Strategy.hpp"

class MinimaxStrategy : public Strategy {
public:
    MinimaxStrategy(unsigned int depth);

    move makeMove(const std::set<piece>& whitePieces, const std::set<piece>& blackPieces) const override;

private:
    int maxi(const std::set<piece>& whitePieces, const std::set<piece>& blackPieces, unsigned int depth) const;

    int mini(const std::set<piece>& whitePieces, const std::set<piece>& blackPieces, unsigned int depth) const;

    int eval(const std::set<piece>& whitePieces, const std::set<piece>& blackPieces) const;

    const unsigned int depth;
};