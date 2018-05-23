#include <string>
#include <vector>
#include <iostream>
#include  <cstdlib>
using namespace std;

string random_code_gen() {
    vector<string> colors = {"r", "y", "b", "g", "o", "p"};
    string code = "";
    for (int i = 0; i < 4; ++i) {
        code += colors[rand() * 6];
    }
    cout << code;
    return code;

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

vector<int> check_guess(string user, string comp) {
    // returns the red and white hints
    int red = 0;
    int white = 0;
    vector<int> result = {0,0};
    for (int i = 0; i < 4; ++i) {
        if (user[i] == comp[i]) {
            ++red;
            user[i] = 'x';
            comp[i] = 'x';
        }
    }
    // now you should take anything that isn't 'x' in comp and see if you find in user
    for (int i = 0; i < 4; ++i) {
        if (comp[i] != 'x') {
            if (user.find(comp[i])) {
                ++white;
            }
        }
    }
    result.push_back(red);
    result.push_back(white);
    return result;
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
    int tries = 0;
    bool game_won = false;
    start();
    string computer_guess = random_code_gen();
    // while loop so that it repeats until valid but also to keep adding up
    while (!game_won) {
        string user_guess = user_input();
        while (check_validity(user_guess)) {
            vector<int> tot = check_guess(user_guess, computer_guess);
            win_game(tot[0], tries);
        }
    }
    return 0;
}