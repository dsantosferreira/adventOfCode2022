#include <iostream>
#include <fstream>
#include <sstream>
#include <stack>
#include <vector>

using namespace std;

vector<stack<char>> initializeVector() {
    vector<stack<char>> v;
    stack<char> s1;
    stack<char> s2;
    stack<char> s3;
    stack<char> s4;
    stack<char> s5;
    stack<char> s6;
    stack<char> s7;
    stack<char> s8;
    stack<char> s9;

    s1.push('R'); s1.push('S'); s1.push('L'); s1.push('F'); s1.push('Q');
    s2.push('N'); s2.push('Z'); s2.push('Q'); s2.push('G'); s2.push('P'); s2.push('T');
    s3.push('S'); s3.push('M'); s3.push('Q'); s3.push('B');
    s4.push('T'); s4.push('G'); s4.push('Z'); s4.push('J'); s4.push('H'); s4.push('C'); s4.push('B'); s4.push('Q');
    s5.push('P'); s5.push('H'); s5.push('M'); s5.push('B'); s5.push('N'); s5.push('F'); s5.push('S');
    s6.push('P'); s6.push('C'); s6.push('Q'); s6.push('N'); s6.push('S'); s6.push('L'); s6.push('V'); s6.push('G');
    s7.push('W'); s7.push('C'); s7.push('F');
    s8.push('Q'); s8.push('H'); s8.push('G'); s8.push('Z'); s8.push('W'); s8.push('V'); s8.push('P'); s8.push('M');
    s9.push('G'); s9.push('Z'); s9.push('D'); s9.push('L'); s9.push('C'); s9.push('N'); s9.push('R');

    v.push_back(s1);
    v.push_back(s2);
    v.push_back(s3);
    v.push_back(s4);
    v.push_back(s5);
    v.push_back(s6);
    v.push_back(s7);
    v.push_back(s8);
    v.push_back(s9);

    return v;
}

string partOne() {
    string answer;
    vector<stack<char>> v = initializeVector();
    ifstream in("../input");
    string aLine;
    int quantity, from, to, element;
    string dummyString;

    while (getline(in, aLine)) {
        istringstream inn(aLine);
        inn >> dummyString;
        inn >> quantity;
        inn >> dummyString;
        inn >> from;
        inn >> dummyString;
        inn >> to;

        for (int i = 0; i < quantity; i++) {
            v[to - 1].push(v[from - 1].top());
            v[from - 1].pop();
        }
    }

    for (stack<char> stack : v) {
        answer += stack.top();
    }

    return answer;
}

string partTwo() {
    string answer;
    vector<stack<char>> v = initializeVector();
    stack<char> auxStack;
    ifstream in("../input");
    string aLine;
    int quantity, from, to, element;
    string dummyString;

    while (getline(in, aLine)) {
        istringstream inn(aLine);
        inn >> dummyString;
        inn >> quantity;
        inn >> dummyString;
        inn >> from;
        inn >> dummyString;
        inn >> to;

        for (int i = 0; i < quantity; i++) {
            auxStack.push(v[from - 1].top());
            v[from - 1].pop();
        }

        while (!auxStack.empty()) {
            v[to - 1].push(auxStack.top());
            auxStack.pop();
        }
    }

    for (stack<char> stack : v) {
        answer += stack.top();
    }

    return answer;
}

int main() {
    cout << "Part one: " << partOne() << endl;
    cout << "Part two: " << partTwo() << endl;
    return 0;
}