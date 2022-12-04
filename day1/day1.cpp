#include <iostream>
#include <fstream>
#include <climits>

using namespace std;

int partOne() {
    int maxElf = INT32_MIN;
    ifstream in("../input");
    string aLine;
    int aSum = 0;
    while (getline(in, aLine)) {
        if (aLine == "") {
            if (aSum > maxElf) {
                maxElf = aSum;
            }
            aSum = 0;
        }
        else {
            aSum += stoi(aLine);
        }
    }
    if (aSum > maxElf) {
        maxElf = aSum;
    }
    return maxElf;
}

int partTwo() {
    int maxElf = INT32_MIN;
    int secondMaxElf = INT32_MIN;
    int thirdMaxElf = INT32_MIN;

    ifstream in("../input");
    string aLine;
    int aSum = 0;
    while (getline(in, aLine)) {
        if (aLine == "") {
            if (aSum > maxElf) {
                thirdMaxElf = secondMaxElf;
                secondMaxElf = maxElf;
                maxElf = aSum;
            }
            else if (aSum > secondMaxElf) {
                thirdMaxElf = secondMaxElf;
                secondMaxElf = aSum;
            }
            else if (aSum > thirdMaxElf)
                thirdMaxElf = aSum;
            aSum = 0;
        }
        else {
            aSum += stoi(aLine);
        }
    }
    if (aSum > maxElf) {
        thirdMaxElf = secondMaxElf;
        secondMaxElf = maxElf;
        maxElf = aSum;
    }
    else if (aSum > secondMaxElf) {
        thirdMaxElf = secondMaxElf;
        secondMaxElf = aSum;
    }
    else if (aSum > thirdMaxElf)
        thirdMaxElf = aSum;
    return maxElf + secondMaxElf + thirdMaxElf;
}

int main() {
    cout << "Part one: " << partOne() << endl;
    cout << "Part two: " << partTwo() << endl;
}