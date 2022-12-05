#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int partOne() {
    int answer = 0;
    ifstream in("../input");
    string aLine, range1, range2, rangeStart1, rangeEnd1, rangeStart2, rangeEnd2;

    while (getline(in, aLine)) {
        istringstream inn(aLine);
        getline(inn, range1, ',');
        getline(inn, range2);

        istringstream r1Stream(range1);
        istringstream r2Stream(range2);

        getline(r1Stream, rangeStart1, '-');
        getline(r1Stream, rangeEnd1);
        getline(r2Stream, rangeStart2, '-');
        getline(r2Stream, rangeEnd2);

        if ((stoi(rangeStart1) <= stoi(rangeStart2) && stoi(rangeEnd1) >= stoi(rangeEnd2)) || (stoi(rangeStart2) <= stoi(rangeStart1) && stoi(rangeEnd2) >= stoi(rangeEnd1)))
            answer++;
    }
    return answer;
}

int partTwo() {
    int answer = 0;
    ifstream in("../input");
    string aLine, range1, range2, rangeStart1, rangeEnd1, rangeStart2, rangeEnd2;

    while (getline(in, aLine)) {
        istringstream inn(aLine);
        getline(inn, range1, ',');
        getline(inn, range2);

        istringstream r1Stream(range1);
        istringstream r2Stream(range2);

        getline(r1Stream, rangeStart1, '-');
        getline(r1Stream, rangeEnd1);
        getline(r2Stream, rangeStart2, '-');
        getline(r2Stream, rangeEnd2);

        if ((stoi(rangeStart1) <= stoi(rangeStart2) && stoi(rangeStart2) <= stoi(rangeEnd1)) || (stoi(rangeStart2) <= stoi(rangeStart1) && stoi(rangeStart1) <= stoi(rangeEnd2)))
            answer++;
    }
    return answer;
}

int main() {
    cout << "Part one " << partOne() << endl;
    cout << "Part two " << partTwo() << endl;
    return 0;
}