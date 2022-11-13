#include "RandomStrategy.hpp"

RandomStrategy::RandomStrategy() : Strategy() {}

move RandomStrategy::makeMove(const std::set<piece>& whitePieces, const std::set<piece>& blackPieces) const {
    std::vector<move> moves = generatePossibleMoves(whitePieces, blackPieces, isWhite);
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<> distribution(0, moves.size() - 1);
    return moves[distribution(mt)];
}