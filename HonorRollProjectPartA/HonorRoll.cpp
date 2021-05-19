/*
Jacob Choi
1/22/21
Honor Roll 1
Changes: Added Comments, fixed output
*/

#include <iostream>
#include "functions.h"
using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
	const int MAX_GRADE = 120; //Setting max grade constant int for use in functions
	string classNum;
	int classes=0;
	string name = getName(); //Gets the input for the name with error trapping
	while (classes < 1 || classes > 8) { //Error trap for amount of classes
		cout << "How many classes are you taking (Must be between 1 and 8): ";
		std::getline(cin, classNum); //getline so if a special charcter/whitespace is entered it takes the entire line and moves to the next iteration
			if (isdigit(classNum[0])) { //Checks to make sure every character is a digit
				classes = std::stoi(classNum); //Changes to an int if its confirmed to be an integer
		}
	}
	std::vector<string> courses = classNames(classes); //vector string created from input
	std::vector<int> scores = classScores(courses, classes, MAX_GRADE); //vector fo ints for scores from input
	int average = calculateAverage(classes, scores); //Calculating the average from the grades
	bool discipline = disciplineIssue(); //5% chance of discipline issue
	printOut(name, classes, scores, average, discipline); //printouts out all the data
	return 0;
}
