#pragma once
#include "Strategy.hpp"
#include <iostream>
#include <set>
#include <memory>

// holds all game pieces and player strategies
class Game {
public:
    Game(const std::shared_ptr<Strategy>& player1, const std::shared_ptr<Strategy>& player2);

    // returns true if player1 won
    bool playGame();

    // switches which player is white and which is black
    void switchPlayers();

    // plays game with specified starting board
    bool debugFunction(std::set<piece> whitePieces, std::set<piece> blackPieces);

    void printBoard(const std::set<piece>& whitePieces, const std::set<piece>& blackPieces) const;

private:
    void resetBoard();

    const std::shared_ptr<Strategy> player1;
    const std::shared_ptr<Strategy> player2;
    std::set<piece> whitePieces;
    std::set<piece> blackPieces;
    bool oneIsWhite;
};