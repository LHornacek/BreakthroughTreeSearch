#include "ManualStrategy.hpp"

ManualStrategy::ManualStrategy() : Strategy() {}

move ManualStrategy::makeMove(const std::set<piece>& whitePieces, const std::set<piece>& blackPieces) const {
    printBoard(whitePieces, blackPieces);
    move move;
    while (true) {
        std::cin.clear();
        std::cout << "enter old position: ";
        std::cin >> move.oldRow >> move.oldCol;
        std::cout << "enter new position: ";
        std::cin >> move.newRow >> move.newCol;
        if (isValidTurn(whitePieces, blackPieces, move)) {
            return move;
        }
        else {
            std::cout << "invalid turn. try again" << std::endl;
        }
    }
}

bool ManualStrategy::isValidTurn(const std::set<piece>& whitePieces, const std::set<piece>& blackPieces, move move) const {
    if (isWhite) {
        return whitePieces.find({ move.oldRow, move.oldCol }) != whitePieces.end() && move.newCol <= 7 &&
               whitePieces.find({ move.newRow, move.newCol }) == whitePieces.end() && move.newRow == move.oldRow - 1 &&
               (move.newCol == move.oldCol - 1 || move.newCol == move.oldCol + 1 ||
                (move.newCol == move.oldCol && blackPieces.find({ move.newRow, move.newCol }) == blackPieces.end()));
    }
    else {
        return blackPieces.find({ move.oldRow, move.oldCol }) != blackPieces.end() && move.newCol <= 7 &&
               blackPieces.find({ move.newRow, move.newCol }) == blackPieces.end() && move.newRow == move.oldRow + 1 &&
               (move.newCol == move.oldCol - 1 || move.newCol == move.oldCol + 1 ||
                (move.newCol == move.oldCol && whitePieces.find({ move.newRow, move.newCol }) == whitePieces.end()));
    }
}

void ManualStrategy::printBoard(const std::set<piece>& whitePieces, const std::set<piece>& blackPieces) const {
    std::cout << std::endl;
    for (unsigned int row = 0; row < 8; row++) {
        for (unsigned int col = 0; col < 8; col++) {
            if (whitePieces.find({ row, col }) != whitePieces.end()) {
                std::cout << "1 ";
            }
            else if (blackPieces.find({ row, col }) != blackPieces.end()) {
                std::cout << "2 ";
            }
            else {
                std::cout << "0 ";
            }
        }
        std::cout << std::endl;
    }
}