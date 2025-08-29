#include <iostream>
#include <random>

char computerChoice() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0,2);
    int num = dist(gen);
    if(num == 0){
        return 'r';
    } else if(num == 1){
        return 's';
    } else {
        return 'p';
    }
}

std::string winner(char computer, char player) {
    if (computer == player)
    {
        return "Draw!";
    }
    if ((computer == 'r' && player == 's') || (computer == 's' && player == 'p') || (computer == 'p' && player == 'r')) {
        return "Lost!";
    }
    return "Win!";
}

int main() {
    std::cout << "Let's play rock papers scissors!" << std::endl << "Choose your pick!" << std::endl;
    char computer = computerChoice();
    char player;
    do {
        std::cin >> player;
        if ((player != 'r') && (player != 's') && (player != 'p')) {
            std::cout << "Type r, p, or s!";
        };
    } while ((player != 'r') && (player != 's') && (player != 'p'));
    std::string result = winner(computer, player);

    std::cout << result << std::endl << "Computer chose " << computer;
    return 0;
}

