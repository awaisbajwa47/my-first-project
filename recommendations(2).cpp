#include <iostream>
using namespace std;

// ANSI color codes
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define CYAN    "\033[36m"
#define MAGENTA "\033[35m"
#define BLUE    "\033[34m"

int main() {
    int interestChoice, difficultyChoice;

    cout << CYAN << "====== AI Recommendation Assistant ======" << RESET << endl;
    cout << GREEN << "Welcome! Let's find the best recommendation for you." << RESET << endl << endl;

    cout << YELLOW << "Please select your area of interest:" << RESET << endl;
    cout << "1. Gaming" << endl;
    cout << "2. Learning" << endl;
    cout << "3. Entertainment" << endl;
    cout << BLUE << "Enter your choice (1-3): " << RESET;
    cin >> interestChoice;

    if (interestChoice < 1 || interestChoice > 3) {
        cout << RED << "Oops! Invalid choice. Please restart the program and select a valid option." << RESET << endl;
        return 0;
    }

    cout << YELLOW << "\nSelect your preferred difficulty or experience level:" << RESET << endl;
    cout << "1. Beginner" << endl;
    cout << "2. Intermediate" << endl;
    cout << "3. Advanced" << endl;
    cout << BLUE << "Enter your choice (1-3): " << RESET;
    cin >> difficultyChoice;

    if (difficultyChoice < 1 || difficultyChoice > 3) {
        cout << RED << "Oops! Invalid choice. Please restart the program and select a valid option." << RESET << endl;
        return 0;
    }

    cout << MAGENTA << "\n----------------------------------------" << RESET << endl;
    cout << GREEN << "AI Recommendation:" << RESET << endl;

    if (interestChoice == 1) { // Gaming
        switch (difficultyChoice) {
            case 1:
                cout << "We suggest starting with casual or puzzle games. Recommended Genre: Platformer" << endl;
                break;
            case 2:
                cout << "Try strategy-based games with adaptive AI opponents. Recommended Genre: Tactical RPG" << endl;
                break;
            case 3:
                cout << "Challenge yourself with competitive multiplayer games. Recommended Genre: MOBA / FPS" << endl;
                break;
        }
    }
    else if (interestChoice == 2) { // Learning
        switch (difficultyChoice) {
            case 1:
                cout << "Start with basic tutorials or videos. Recommended Subject: Beginner Programming" << endl;
                break;
            case 2:
                cout << "Engage with interactive learning platforms. Recommended Subject: Intermediate Math / Science" << endl;
                break;
            case 3:
                cout << "Take on projects or advanced courses. Recommended Subject: AI / Data Science" << endl;
                break;
        }
    }
    else if (interestChoice == 3) { // Entertainment
        switch (difficultyChoice) {
            case 1:
                cout << "Enjoy light-hearted content. Recommended: Comedy movies or shows" << endl;
                break;
            case 2:
                cout << "Explore engaging series or documentaries. Recommended: Thriller / Sci-fi" << endl;
                break;
            case 3:
                cout << "Dive into complex narratives or classic films. Recommended: Art-house / Historical films" << endl;
                break;
        }
    }

    cout << MAGENTA << "----------------------------------------" << RESET << endl;
    cout << CYAN << "Thank you for using AI Recommendation Assistant! Enjoy your choice!" << RESET << endl;

    return 0;
}
