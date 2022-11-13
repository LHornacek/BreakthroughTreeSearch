#pragma once
#include "StructDefinitions.hpp"
#include <set>
#include <vector>

//TODO <limits> instead
#include <climits>

class Strategy {
public:
    Strategy();

    virtual move makeMove(const std::set<piece>& whitePieces, const std::set<piece>& blackPieces) const = 0;

    void setIsWhite(bool value);

protected:
    bool isWhite;

    std::vector<move> generatePossibleMoves(const std::set<piece>& whitePieces, const std::set<piece>& blackPieces, bool isWhiteTurn) const;
};