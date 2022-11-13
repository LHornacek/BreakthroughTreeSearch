#include "Game.hpp"
#include "ManualStrategy.hpp"
#include "RandomStrategy.hpp"
#include "MinimaxStrategy.hpp"

// returns how many times player1 won
unsigned int playGames(unsigned int gameCount, Game& game) {
    unsigned int winCount = 0;
    for (unsigned int i = 0; i < gameCount; i++) {
        if (game.playGame()) {
            winCount++;
        }
        game.switchPlayers();
    }
    return winCount;
}

std::shared_ptr<Strategy> chooseAlgorithm() {
    std::cout << std::endl << "Available options: Manual - 0, Random - 1, Minimax - 2" << std::endl;
    std::cout << "Enter algorithm (as number from available options): ";
    int x;
    std::cin >> x;
    switch (x)
    {
        case 0:
            return std::shared_ptr<Strategy>(new ManualStrategy());
        case 1:
            return std::shared_ptr<Strategy>(new RandomStrategy());
        case 2:
            std::cout << "Enter search depth (1-4 recommended): ";
            int depth;
            std::cin >> depth;
            return std::shared_ptr<Strategy>(new MinimaxStrategy(depth));
        default:
            return nullptr;
    }
}

int main() {
    unsigned int numberOfGames;
    std::shared_ptr<Strategy> player1;
    std::shared_ptr<Strategy> player2;

    player1 = chooseAlgorithm();
    if (player1 == nullptr) {
        return 0;
    }
    player2 = chooseAlgorithm();
    if (player2 == nullptr) {
        return 0;
    }
    Game game = Game(player1, player2);

    std::cout << "\nChoose number of games to simulate: ";
    std::cin >> numberOfGames;
    std::cout << "Simulating..." << std::endl;

    unsigned int x = playGames(numberOfGames, game);
    std::cout << "Player one won " << x << " times, player two won " << numberOfGames - x << " times." << std::endl;
}