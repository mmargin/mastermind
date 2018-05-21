#include <string>
#include <vector>
#include <iostream>
using namespace std;

string random_code_gen() {
    return "rybg";
}

void start() {
    cout << "Welcome to Maria's Mastermind Game!" << endl;
    cout << "Please guess the code chosen by the computer" << endl;
    cout << "Put the 1st letter of the color and enter without any spaces"
         << endl;
    cout << "You are guessing 4 colors, please only have 4 characters in your guess"
         << endl;
}

string user_input() {
    string guess;
    cout << 
        "Your options are (r)ed, (y)ellow, (b)lue, (g)reen, (o)range or (p)ink" 
        << endl;
    cout << "What is your guess?" << endl;
    cin >> guess;
}
bool check_validity(const string & str) {
    // checks to see if all the colors are valid
    int guess_size = str.size();
    if (str.size() == 4) {
        for (int i = 0; i < guess_size; ++i) {
            if (str[i] != 'r' && str[i] != 'y' && str[i] != 'b' && str[i] != 'g'
                && str[i] != 'o' && str[i] != 'p') {
                return false;
            }
        }
        return true;
    }
    return false;
}

vector<int> check_guess(string) {
    // returns the red and white hints
}

void win_game(int red, int total) {
    if (red == 4) {
        cout << "Congrats you have guessed correctly! You win!" << endl;
        cout << "You guessed in " << total << " tries!" << endl;
    }
    else {
        cout << "You're getting closer, try again!";
        ++total;
    }
}

int main() {
    start();
    while (check_validity(user_input())) {
        check_guess(user_input());
    }
    return 0;
}