#include <iostream>
#include <vector>
using namespace std;

class Bowling_Game {
private:
    vector<int> bowling_rolls;

public:
    void bowling_roll(int pins) {
        bowling_rolls.push_back(pins);
    }
    int score() {
        int totalScore = 0;
        int rollIndex = 0;

        for (int frame = 0; frame < 10; ++frame) {
            if (isStrike(rollIndex)) {
                totalScore += 10 + getSafe(rollIndex + 1) + getSafe(rollIndex + 2);
                rollIndex += 1;
            } else if (isSpare(rollIndex)) {
                totalScore += 10 + getSafe(rollIndex + 2);
                rollIndex += 2;
            } else {
                totalScore += getSafe(rollIndex) + getSafe(rollIndex + 1);
                rollIndex += 2;
            }
        }
        return totalScore;
    }
private:
    bool isStrike(int index) {
        return getSafe(index) == 10;
    }
    bool isSpare(int index) {
        return getSafe(index) + getSafe(index + 1) == 10;
    }
    int getSafe(int index) {
        return index < bowling_rolls.size() ? bowling_rolls[index] : 0;
    }
};

int main() {
    Bowling_Game game;

    vector<int> BowlingRolls = {
        1, 4,    
        4, 5,    
        6, 4,    
        5, 0,    
        10,      
        0, 1,    
        7, 3,    
        6, 0,    
        10,      
        2, 8, 6 
    };

    for (int pins : BowlingRolls) {
        game.bowling_roll(pins);
    }

    cout << "Final Score: " << game.score() << endl;  

    return 0;
}
