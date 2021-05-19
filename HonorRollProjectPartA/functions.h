#pragma once
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <iomanip>
#include <vector>
using std::cout;
using std::cin;
using std::endl;
using std::string;

	std::string getName(); //Defining all the functions used
	bool disciplineIssue();
	std::vector<string> classNames(int);
	std::vector<int> classScores(std::vector<string>, int, const int);
	int calculateAverage(int, std::vector<int>);
	void printOut(std::string, int, std::vector<int>, int, bool);

