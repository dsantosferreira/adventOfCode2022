#include <iostream>
#include <fstream>
#include <sstream>
#include <set>

using namespace std;

int partOne() {
    int answer = 0;
    ifstream in("../input");
    string aLine;
    char aChar;
    set<char> typesSeen;

    while (getline(in, aLine)) {
        istringstream inn(aLine);
        typesSeen.clear();

        for (int i = 0; i < aLine.size() / 2; i++) {
            inn >> aChar;
            typesSeen.insert(aChar);
        }

        while (inn >> aChar) {
            if (typesSeen.find(aChar) != typesSeen.end())
                break;
        }

        if (islower(aChar)) {
            answer += aChar - 'a' + 1;
        }
        else {
            answer += aChar - 'A' + 27;
        }
    }
    return answer;
}

int partTwo() {
    int answer = 0;
    ifstream in("../input");
    string aLine1, aLine2, aLine3;
    char aChar;
    set<char> typesSeen1;
    set<char> typesSeen2;

    while (getline(in, aLine1)) {
        getline(in, aLine2);
        getline(in, aLine3);

        istringstream inn1(aLine1);
        istringstream inn2(aLine2);
        istringstream inn3(aLine3);

        typesSeen1.clear();
        typesSeen2.clear();

        for (int i = 0; i < aLine1.size(); i++) {
            inn1 >> aChar;
            typesSeen1.insert(aChar);
        }

        for (int j = 0; j < aLine2.size(); j++) {
            inn2 >> aChar;
            if (typesSeen1.find(aChar) != typesSeen1.end())
                typesSeen2.insert(aChar);
        }

        while (inn3 >> aChar) {
            if (typesSeen2.find(aChar) != typesSeen2.end())
                break;
        }

        if (islower(aChar)) {
            answer += aChar - 'a' + 1;
        }
        else {
            answer += aChar - 'A' + 27;
        }
    }
    return answer;
}

int main() {
    cout << "Part One: " << partOne() << endl;
    cout << "Part Two: " << partTwo() << endl;
    return 0;
}