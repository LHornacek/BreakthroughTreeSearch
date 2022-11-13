#include "Game.hpp"

Game::Game(const std::shared_ptr<Strategy>& player1, const std::shared_ptr<Strategy>& player2) : player1(player1), player2(player2), oneIsWhite(true) {
    player1->setIsWhite(true);
    player2->setIsWhite(false);
}

bool Game::playGame() {
    resetBoard();
    return playGame(whitePieces, blackPieces, oneIsWhite);
}

void Game::switchPlayers() {
    oneIsWhite = !oneIsWhite;
    player1->setIsWhite(oneIsWhite);
    player2->setIsWhite(!oneIsWhite);
}

void Game::resetBoard() {
    whitePieces = std::set<piece>();
    blackPieces = std::set<piece>();
    for (unsigned int col = 0; col < 8; col++) {
        for (unsigned int row = 0; row < 2; row++) {
            blackPieces.insert({ row, col });
        }
        for (unsigned int row = 6; row < 8; row++) {
            whitePieces.insert({ row, col });
        }
    }
}

bool Game::playGame(std::set<piece>& whitePieces, std::set<piece>& blackPieces, bool isPlayerOneTurn) {
    bool isWon;
    move move;
    while (true) {
        if (isPlayerOneTurn) {
            move = player1->makeMove(whitePieces, blackPieces);
            if (oneIsWhite) {
                whitePieces.erase({move.oldRow, move.oldCol });
                whitePieces.insert({move.newRow, move.newCol });
                blackPieces.erase({move.newRow, move.newCol });
                isWon = move.newRow == 0 || blackPieces.empty();
            }
            else {
                blackPieces.erase({move.oldRow, move.oldCol });
                blackPieces.insert({move.newRow, move.newCol });
                whitePieces.erase({move.newRow, move.newCol });
                isWon = move.newRow == 7 || whitePieces.empty();
            }
        }
        else {
            move = player2->makeMove(whitePieces, blackPieces);
            if (!oneIsWhite) {
                whitePieces.erase({move.oldRow, move.oldCol });
                whitePieces.insert({move.newRow, move.newCol });
                blackPieces.erase({move.newRow, move.newCol });
                isWon = move.newRow == 0 || blackPieces.empty();
            }
            else {
                blackPieces.erase({move.oldRow, move.oldCol });
                blackPieces.insert({move.newRow, move.newCol });
                whitePieces.erase({move.newRow, move.newCol });
                isWon = move.newRow == 7 || whitePieces.empty();
            }
        }

        if (isWon) {
            return isPlayerOneTurn;
        }

        isPlayerOneTurn = !isPlayerOneTurn;
    }
}

void Game::printBoard(const std::set<piece>& whitePieces, const std::set<piece>& blackPieces) const {
    std::cout << std::endl;
    for (unsigned int row = 0; row < 8; row++) {
        for (unsigned int col = 0; col < 8; col++) {
            if (whitePieces.find({row, col }) != whitePieces.end()) {
                std::cout << "1 ";
            }
            else if (blackPieces.find({row, col }) != blackPieces.end()) {
                std::cout << "2 ";
            }
            else {
                std::cout << "0 ";
            }
        }
        std::cout << std::endl;
    }
}