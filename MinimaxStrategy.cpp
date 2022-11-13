#include "MinimaxStrategy.hpp"

MinimaxStrategy::MinimaxStrategy(unsigned int depth) : Strategy(), depth(depth) {}

move MinimaxStrategy::makeMove(const std::set<piece>& whitePieces, const std::set<piece>& blackPieces) const {
    std::vector<move> possibleMoves = generatePossibleMoves(whitePieces, blackPieces, isWhite);
    move bestMove = possibleMoves[0];
    int bestValue = std::numeric_limits<int>::min();
    for (move move : possibleMoves) {
        std::set<piece> whiteTemp = whitePieces;
        std::set<piece> blackTemp = blackPieces;
        if (isWhite) {
            whiteTemp.erase({ move.oldRow, move.oldCol });
            whiteTemp.insert({ move.newRow, move.newCol });
            blackTemp.erase({ move.newRow, move.newCol });
            if (move.newRow == 0 || blackTemp.empty()) {
                return move;
            }
        }
        else {
            blackTemp.erase({ move.oldRow, move.oldCol });
            blackTemp.insert({ move.newRow, move.newCol });
            whiteTemp.erase({ move.newRow, move.newCol });
            if (move.newRow == 7 || whiteTemp.empty()) {
                return move;
            }
        }
        int value = mini(whiteTemp, blackTemp, depth - 1);
        if (value == bestValue) {
            if (isWhite && move < bestMove) {
                bestMove = move;
            }
            if (!isWhite && move > bestMove) {
                bestMove = move;
            }
        }
        if (value > bestValue) {
            bestValue = value;
            bestMove = move;
        }
    }
    return bestMove;
}

int MinimaxStrategy::maxi(const std::set<piece>& whitePieces, const std::set<piece>& blackPieces, unsigned int depth) const {
    if (depth == 0) {
        return eval(whitePieces, blackPieces);
    }
    std::vector<move> moves = generatePossibleMoves(whitePieces, blackPieces, isWhite);
    int max = std::numeric_limits<int>::min();
    for (move move : moves) {
        std::set<piece> whiteTemp = whitePieces;
        std::set<piece> blackTemp = blackPieces;
        if (isWhite) {
            whiteTemp.erase({ move.oldRow, move.oldCol });
            whiteTemp.insert({ move.newRow, move.newCol });
            blackTemp.erase({ move.newRow, move.newCol });
            if (move.newRow == 0 || blackTemp.empty()) {
                return std::numeric_limits<int>::max();
            }
        }
        else {
            blackTemp.erase({ move.oldRow, move.oldCol });
            blackTemp.insert({ move.newRow, move.newCol });
            whiteTemp.erase({ move.newRow, move.newCol });
            if (move.newRow == 7 || whiteTemp.empty()) {
                return std::numeric_limits<int>::max();
            }
        }
        int value = mini(whiteTemp, blackTemp, depth - 1);
        if (value > max) {
            max = value;
        }
    }
    return max;
}

int MinimaxStrategy::mini(const std::set<piece>& whitePieces, const std::set<piece>& blackPieces, unsigned int depth) const {
    if (depth == 0) {
        return eval(whitePieces, blackPieces);
    }
    std::vector<move> moves = generatePossibleMoves(whitePieces, blackPieces, !isWhite);
    int min = std::numeric_limits<int>::max();
    for (move move : moves) {
        std::set<piece> whiteTemp = whitePieces;
        std::set<piece> blackTemp = blackPieces;
        if (isWhite) {
            blackTemp.erase({ move.oldRow, move.oldCol });
            blackTemp.insert({ move.newRow, move.newCol });
            whiteTemp.erase({ move.newRow, move.newCol });
            if (move.newRow == 7 || whiteTemp.empty()) {
                return std::numeric_limits<int>::min();
            }
        }
        else {
            whiteTemp.erase({ move.oldRow, move.oldCol });
            whiteTemp.insert({ move.newRow, move.newCol });
            blackTemp.erase({ move.newRow, move.newCol });
            if (move.newRow == 0 || blackTemp.empty()) {
                return std::numeric_limits<int>::min();
            }
        }
        int value = maxi(whiteTemp, blackTemp, depth - 1);
        if (value < min) {
            min = value;
        }
    }
    return min;
}

int MinimaxStrategy::eval(const std::set<piece>& whitePieces, const std::set<piece>& blackPieces) const {
    if (isWhite) {
        return whitePieces.size() - blackPieces.size();
    }
    else {
        return blackPieces.size() - whitePieces.size();
    }
}