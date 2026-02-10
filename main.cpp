#include <iostream>
#include <cstdlib>
#include <array>
#include <ctime>
#include <limits>

const int max_length = 15;

int horseAdvance();
void printLane(const std::array<int, 4>& horses);

int main() {
    srand(static_cast<unsigned int>(time(0)));

    std::array<int, 4> horses = {0, 0, 0, 0};
    bool horseWinner = false;
    int winningHorseIndex = -1;

    while (!horseWinner) {
        std::cout << "Press Enter to update the race display";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout << "\n\n\n\n\n\n\n\n\n\n";

        for (int i = 0; i < horses.size(); ++i) {
            horses[i] += horseAdvance();
        }

        printLane(horses);


        for (int i = 0; i < horses.size(); ++i) {
             if (horses[i] >= max_length) {
                horseWinner = true;
                winningHorseIndex = i;
                break;
             }
        }
    }

    std::cout << "Horse " << winningHorseIndex + 1 << " has won the race!" << std::endl;

    return 0;
}

int horseAdvance() {
    /* Random 50/50 was initial implementation but to make it interesting there is a 1 in 100 chance 
    that if the value is 42 then the horse advances 3 spaces, to make things interesting. I'm not 
    entirely sure what this is supposed to emulate in the literal context of the situation, but
    horses are flipping coins these days so nothing is off limits.*/
    int randomNum = rand() % 100;
    if (randomNum == 42){
        return 3;
    }
    if (randomNum % 2 == 0) {
        return 1;
    }
    return 0;
}

void printLane(const std::array<int, 4>& horses) {
    std::cout << "--------------- Finish Line (Position " << max_length << ")\n";
    for (int i = 0; i < horses.size(); ++i) {
        for (int j = 0; j < horses[i]; ++j) {
            std::cout << " ";
        }
        std::cout << (i + 1) << std::endl;
    }
    std::cout << "---------------\n";
}
