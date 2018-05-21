#include <string>
#include <vector>
#include <iostream>
using namespace std;

string random_code_gen() {
    
}

void start() {
    cout << "Welcome to Maria's Mastermind Game" << endl;
    cout << "Please guess the code chosen by the computer" << endl;
    cout << 
        "Your options are (r)ed, (y)ellow, (b)lue, (g)reen, (o)range or (p)ink" 
        << endl;
    cout << "You are guessing 4 spots";
}

string user_input() {
    string guess;
    cout << "What is your guess?" << endl;
    cin >> guess;
}
bool check_validity(string){
    // checks to see if all the colors are valid
}

vector<int> check_guess(string) {
    // returns the red and white hints
}

void win_game(int red) {
    if (red == 4) {
        cout << "Congrats you have guessed correctly! You win!" << endl;
    }
    else {
        cout << "You're gettung closer, try again!";
    }
}

int main() {
    
    while(check_validity(user_input())) {
        check_guess(user_input());
    }
    return 0;
}