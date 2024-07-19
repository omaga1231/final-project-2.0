//csc114
//final project
//omar abukar
//7/19/2024
//thanks teacher for helping us this semester :}

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

const int STUDENTNUM = 10;
const int COURSENUM = 5;

//the grade function
//hope i got an A :)
char calculateGrade(double averageScore) {
    if (averageScore >= 90.0) {
        return 'A';
    }
    else if (averageScore >= 80.0) {
        return 'B';
    }
    else if (averageScore >= 70.0) {
        return 'C';
    }
    else if (averageScore >= 60.0) {
        return 'D';
    }
    else {
        return 'F';
    }
}

int main() {
    //it reads the name to an arrays
    string studentNames[STUDENTNUM];
    ifstream namesFile("studentNames.txt");

    if (namesFile.is_open()) {
        for (int i = 0; i < STUDENTNUM; i++) {
            getline(namesFile, studentNames[i]);
        }
        namesFile.close();
    }
    else {
        cout << "Could not open studentNames.txt\n";
        return 0;
    }

    // score to 2d array
    int scores[STUDENTNUM][COURSENUM];
    string fileName = "scores.txt";
    ifstream scoresFile(fileName);

    if (scoresFile.is_open()) {
        string line, word;
        int row = 0;

        while (getline(scoresFile, line)) {
            stringstream str(line);
            int column = 0;
            while (getline(str, word, ',')) {
                scores[row][column++] = stoi(word);
            }
            row++;
        }
        scoresFile.close();
    }
    else {
        cout << "Could not open " << fileName << "\n";
        return 0;
    }

    // the average grade
    double averages[STUDENTNUM];
    char grades[STUDENTNUM];

    cout << "Student Grades:\n";
    for (int i = 0; i < STUDENTNUM; i++) {
        int sum = 0;
        for (int j = 0; j < COURSENUM; j++) {
            sum += scores[i][j];
        }
        averages[i] = static_cast<double>(sum) / COURSENUM;
        grades[i] = calculateGrade(averages[i]);

        cout << studentNames[i] << ": Average Score = " << averages[i] << ", Final Grade = " << grades[i] << "\n";
    }

    // Save student names and final grade to (grades.txt)
    ofstream outputFile("grades.txt");
    if (outputFile.is_open()) {
        for (int i = 0; i < STUDENTNUM; i++) {
            outputFile << studentNames[i] << ": Average Score = " << averages[i] << ", Final Grade = " << grades[i] << "\n";
        }
        cout << "Grades saved to grades.txt\n";
        outputFile.close();
    }
    else {
        cout << "i cant open grades.txt for writing\n";
        return 0;
    }

    return 0;
}
