#include "pch.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;


// Test to make sure everything is working correctly


// Test to check for all upper case words in text file
TEST(TestCaseName, TestName) {

	string line, word;
	ifstream file("inputFile.txt");

	if (!file.is_open()) {
		cout << "Error Opening File,\n";
		FAIL();
	}

	while (getline(file, line)) {
		istringstream ss(line);
		while (ss >> word) {
			for (int i = 0; i < word.length(); i++) {
				EXPECT_TRUE(isupper(word[i]));
			}
		}
	}

	file.close();

}

// Test for a provided word to be replaced with a random word from a separate text file
TEST(TestCaseName, TestName) {

	string word = "WORD";
	string line, line2, word, word2;
	bool check = false;
	int wordCount = 0;
	ifstream file("inputFile.txt");
	ifstream file2("randomWords.txt");

	while (file2 >> word) {
		wordCount++;
	}

	srand(time(NULL));
	int randomNumber = rand() % wordCount + 1;

	if (!file.is_open()) {
		cout << "Error Opening File\n";
		FAIL();
	}

	if (!file2.is_open()) {
		cout << "Error Opening File2\n";
		FAIL();
	}

	while (getline(file, line)) {
		istringstream ss(line);
		while (ss >> word) {
			if (word == "WORD") {
				while (getline(file2, line2)) {
					istringstream ss2(line2);
					while (ss2 >> word2) {
						if (wordCount == randomNumber) {
							word = word2;
							SUCCEED();
						}
					}
				}
			}
		}
	}

	FAIL();

	file.close();





}


/*
TEST(TestCaseName, TestName) {
	EXPECT_EQ(1, 1);
	EXPECT_TRUE(true);
}
*/

