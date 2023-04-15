//
// pch.cpp
//

#include "pch.h"

// swear filter func for test
bool swears(string inputLine) {

    return false;
}

// extra char func for test
bool extraChar(string inputLine) {

    return false;
}

int main() {
    ifstream inputFile("inputFile.txt");
    string inputLine;

    if (inputFile) {
        getline(inputFile, inputLine);

        extraChar(inputLine);
        swears(inputLine);

    }
    else {
        cout << "Could not open the provided file\n";
    }

}