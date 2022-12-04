#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int partOne() {
    ifstream in("../input");
    string aLine;
    char enemy;
    char me;
    int points = 0;

    while (getline(in, aLine)) {
        istringstream inn(aLine);
        inn >> enemy >> me;

        switch(enemy) {
            case 'A':
                switch(me) {
                    case 'X':
                        points += 4;
                        break;
                    case 'Y':
                        points += 8;
                        break;
                    case 'Z':
                        points += 3;
                        break;
                }
                break;
            case 'B':
                switch(me) {
                    case 'X':
                        points += 1;
                        break;
                    case 'Y':
                        points += 5;
                        break;
                    case 'Z':
                        points += 9;
                        break;
                }
                break;
            case 'C':
                switch(me) {
                    case 'X':
                        points += 7;
                        break;
                    case 'Y':
                        points += 2;
                        break;
                    case 'Z':
                        points += 6;
                        break;
                }
        }
    }
    in.close();
    return points;
}

int partTwo() {
    ifstream in("../input");
    string aLine;
    char enemy;
    char me;
    int points = 0;

    while (getline(in, aLine)) {
        istringstream inn(aLine);
        inn >> enemy >> me;

        switch(enemy) {
            case 'A':
                switch(me) {
                    case 'X':
                        points += 3;
                        break;
                    case 'Y':
                        points += 4;
                        break;
                    case 'Z':
                        points += 8;
                        break;
                }
                break;
            case 'B':
                switch(me) {
                    case 'X':
                        points += 1;
                        break;
                    case 'Y':
                        points += 5;
                        break;
                    case 'Z':
                        points += 9;
                        break;
                }
                break;
            case 'C':
                switch(me) {
                    case 'X':
                        points += 2;
                        break;
                    case 'Y':
                        points += 6;
                        break;
                    case 'Z':
                        points += 7;
                        break;
                }
        }
    }
    in.close();
    return points;
}

int main() {
    cout << "Part One: " << partOne() << endl;
    cout << "Part Two: " << partTwo() << endl;
    return 0;
}