#pragma once
#include "Strategy.hpp"
#include <iostream>

// a player that takes turns from console
class ManualStrategy : public Strategy {
public:
    ManualStrategy();

    move makeMove(const std::set<piece>& whitePieces, const std::set<piece>& blackPieces) const override;

private:
    bool isValidTurn(const std::set<piece>& whitePieces, const std::set<piece>& blackPieces, move) const;

    void printBoard(const std::set<piece>& whitePieces, const std::set<piece>& blackPieces) const;
};