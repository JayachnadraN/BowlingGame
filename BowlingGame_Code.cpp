#include <iostream>
#include <vector>
using namespace std;

class BowlingGame {
public:
    vector<int> rolls;

    void roll(int pins) {
        rolls.push_back(pins);
    }

    int calculateScore() {
        int score = 0;
        int index = 0;

        for (int frame = 0; frame < 10; ++frame) {
            if (rolls[index] == 10) { // Strike
                score += 10 + get(index + 1) + get(index + 2);
                index += 1;
            } else if (get(index) + get(index + 1) == 10) { // Spare
                score += 10 + get(index + 2);
                index += 2;
            } else {
                score += get(index) + get(index + 1);
                index += 2;
            }
        }
        return score;
    }

private:
    int get(int idx) {
        if (idx < rolls.size()) return rolls[idx];
        return 0;
    }
};

int main() {
    BowlingGame game;
    int pins;

    cout << "Welcome to Bowling Score Calculator\n";

    for (int frame = 1; frame <= 10; ++frame) {
        cout << "\nFrame " << frame << endl;

        // First roll
        while (true) {
            cout << "  Roll 1: ";
            cin >> pins;
            if (pins >= 0 && pins <= 10) {
                game.roll(pins);
                break;
            } else {
                cout << "    enter a valid pin count (0-10)\n";
            }
        }

        // Strike handling for frames 1–9
        if (pins == 10 && frame < 10) continue;

        int first = pins;

        // Second roll
        while (true) {
            cout << "  Roll 2: ";
            cin >> pins;
            if (pins >= 0 && pins <= 10 && (frame == 10 || first + pins <= 10)) {
                game.roll(pins);
                break;
            } else {
                cout << "  invalid input. Total pins in a frame must be ≤ 10\n";
            }
        }

        // Frame 10 bonus roll
        if (frame == 10 && (first == 10 || first + pins == 10)) {
            while (true) {
                cout << "  Bonus Roll: ";
                cin >> pins;
                if (pins >= 0 && pins <= 10) {
                    game.roll(pins);
                    break;
                } else {
                    cout << " Enter a valid pin count (0-10)\n";
                }
            }
        }
    }

    cout << "\n final Score: " << game.calculateScore() << "\n";
    return 0;
}
