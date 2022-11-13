#include "Strategy.hpp"

Strategy::Strategy() : isWhite() {}

void Strategy::setIsWhite(bool value) {
    this->isWhite = value;
}

std::vector<move> Strategy::generatePossibleMoves(const std::set<piece>& whitePieces, const std::set<piece>& blackPieces, bool isWhiteTurn) const {
    std::vector<move> moves = std::vector<move>();
    if (isWhiteTurn) {
        for (piece piece : whitePieces) {
            if (whitePieces.find({ piece.row - 1, piece.col }) == whitePieces.end() &&
                blackPieces.find({ piece.row - 1, piece.col }) == blackPieces.end()) {
                moves.push_back({ piece.row, piece.col, piece.row - 1, piece.col });
            }
            if (whitePieces.find({ piece.row - 1, piece.col - 1 }) == whitePieces.end() && piece.col - 1 <= 6) {
                moves.push_back({ piece.row, piece.col, piece.row - 1, piece.col - 1 });
            }
            if (whitePieces.find({ piece.row - 1, piece.col + 1 }) == whitePieces.end() && piece.col + 1 <= 7) {
                moves.push_back({ piece.row, piece.col, piece.row - 1, piece.col + 1 });
            }
        }
    }
    else {
        for (piece piece : blackPieces) {
            if (blackPieces.find({ piece.row + 1, piece.col }) == blackPieces.end() &&
                whitePieces.find({ piece.row + 1, piece.col }) == whitePieces.end()) {
                moves.push_back({ piece.row, piece.col, piece.row + 1, piece.col });
            }
            if (blackPieces.find({ piece.row + 1, piece.col - 1 }) == blackPieces.end() && piece.col - 1 <= 6) {
                moves.push_back({ piece.row, piece.col, piece.row + 1, piece.col - 1 });
            }
            if (blackPieces.find({ piece.row + 1, piece.col + 1 }) == blackPieces.end() && piece.col + 1 <= 7) {
                moves.push_back({ piece.row, piece.col, piece.row + 1, piece.col + 1 });
            }
        }
    }
    return moves;
}