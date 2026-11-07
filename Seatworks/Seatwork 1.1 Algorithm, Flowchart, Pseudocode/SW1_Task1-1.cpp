#include <iostream>
using namespace std;

int main() 
{

    int total_Qz;
    float overall_score, student_score;
    float HighestPossib = 0, total_score = 0;

    cout << "How many quizzes to be encoded: ";
    cin >> total_Qz;

    for (int i = 1; i <= total_Qz; i++) {

        cout << "Quiz Number: " << i << endl;

        cout << "Total Score: ";
        cin >> overall_score;

        cout << "Student's Score: ";
        cin >> student_score;

        HighestPossib += overall_score;
    total_score += student_score;
    }

    float average = total_score / total_Qz;
    
    cout << "Final Quiz Computation Average: ";
    cout << "Number of Quizzes: " << total_Qz << endl;
    cout << "Total Possible Score: " << HighestPossib << endl;
    cout << "Student Total Score: " << total_score << endl;
    cout << "Average Score: " << average << endl;

    return 0;
}