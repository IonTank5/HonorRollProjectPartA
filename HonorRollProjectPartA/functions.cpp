#include "functions.h"

std::string getName() { //Input of name with error checking
    std::string name;
    do {
        cout << "Enter name: ";
        std::getline(cin, name); //getline to allow spaces
    } while (name.length() <= 0); //Makes sure name isn't blank
    return name;
}

bool disciplineIssue() { //5% chance of discipline issue
    int seed, number, temp;
    srand(time(NULL)); //using multiple seeds from random and using the time to get as random of a number as possible
    for (int i = 0; i < rand() % 17 + 1; i++) {
        temp = rand();
    }
    seed = rand();
    srand(seed);
    number = rand() % 100;
    if (number <= 4) { //5% chance
        return true;
    }
    else {
        return false;
    }
}

std::vector<string> classNames(int classes){ //returns a vector string with the names of the classes, takes in amount of classes
    string temp;
    std::vector<string> courses;
    for (int i = 1; i <= classes; i++) {
        while (true) {
            cout << "Enter course " << i << " name (will be truncated to 20 characters): ";
            std::getline(cin, temp);
            if (temp.length() <= 20 && temp.length() > 0) {
                courses.push_back(temp);
                break;
            }
            else if (temp.length() > 20) {
                courses.push_back(temp.substr(0, 20)); //truncates to 20 if over 20 charactesrs long
                break;
            }
            else;
        }
    }
    return courses;
}

std::vector<int> classScores(std::vector<string> courses, int classes, const int MAX_GRADE) {
    string scoreNum;
    std::vector<int> scores;
    int tempScore;
    bool flag = false;
    cout << "Minimum Grade: 0\nMaximum Grade: 120\n"; //Displays min/max grades
    for (int i = 0; i < classes; i++) {
        while (true) {
            cout << "Enter score for " << courses[i] << ": ";
            std::getline(cin, scoreNum);
            flag = false; //bool reset
            for (int i = 0; i < scoreNum.length(); i++) {
                if (!isdigit(scoreNum[i])) {
                    flag = true; //flags if a character is not a digit
                    break;
                }
            }
                if(!flag){ //checks if all characters are digits
                    tempScore = std::stoi(scoreNum);
                    if (tempScore >= 0 && tempScore <= MAX_GRADE) {
                        scores.push_back(tempScore);
                        break;
                    }
                }
            }
        }
    return scores;
}

int calculateAverage(int classes, std::vector<int> scores) { //calculates average, pretty self explanatory
    int average = 0;
    for (int i = 0; i < classes; i++) {
        average += scores[i];
    }
    average /= classes;
    return average;
}

void printOut(std::string name, int classes, std::vector<int> scores, int average, bool discipline) { //prints out all the necessary data in a neat table
    cout << "Name: " << name << endl << endl;
    cout << std::left << "Class  " << std::setw(10) << std::right << "Grade" << endl;
    for (int i = 0; i < classes; i++) {
        cout << "Class " << i + 1 << std::right << std::setw(10) << scores[i] << endl;
    }
    cout << "\nAmount of Courses: " << classes << "\nAverage: " << average << "\nDisclipinary Infraction: ";
    if (discipline)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    if (classes >= 5 && average >= 90 && !discipline) {
        cout << "Congratulations " << name << "! You have made the honor roll" << endl;
    }
    else {
        cout << "I'm sorry " << name << " but you didn't qualify for the honor roll." << endl;
    }
}