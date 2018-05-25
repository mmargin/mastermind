#include <string>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int randHelper(int min, int max) {
   return rand() % max + min;
}

string random_code_gen() {
    vector<char> colors;
    colors.push_back('r');
    colors.push_back('y');
    colors.push_back('b');
    colors.push_back('g');
    colors.push_back('o');
    colors.push_back('p');
    string code = "xxxx";
    for (int i = 0; i < 4; ++i) {
        code[i] = colors[randHelper(0, 6)];     
    }
    cout << code << endl;
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
    return guess;
}
bool check_validity(const string & str) {
    // checks to see if all the colors are valid
    int guess_size = str.size();
    if (str.size() == 4) {
        for (int i = 0; i < guess_size; ++i) {
            if (str[i] != 'r' && str[i] != 'y' && str[i] != 'b' && str[i] != 'g'
                && str[i] != 'o' && str[i] != 'p') {
                cout << "That's not a valid move! Use the reserved characters ";
                cout << "Don't worry, this guess won't count as a point. Try again!" 
                     << endl;
                return false;
            }
        }
        return true;
    }
    cout << "That's not a valid move! Please use 4 characters in your guess. ";
    cout << "Don't worry, this guess won't count as a point. Try again!" 
         << endl;
    return false;
}

vector<int> check_guess(string user, string comp) {
    // returns the red and white hints
    int red = 0;
    int white = 0;
    vector<int> result;
    result.push_back(0);
    result.push_back(0);
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
                user[i] = 'x';
                comp[i] = 'x';
            }
        }
    }
    cout << "Your guess earned " << red << " red and " << white << " white" << endl;
    result[0] = red;
    result[1] = white;
    return result;
}

void win_game(int red, int & total, bool & game_won, string & user_guess) {
    if (red == 4) {
        cout << "Congrats you have guessed correctly! You win!" << endl;
        ++total;
        cout << "You guessed in " << total << " tries!" << endl;
        game_won = true;
    }
    else {
        cout << "You're getting closer, try again!" << endl;
        user_guess = user_input();
        ++total;
    }
}
int main() {
    int tries = 0;
    srand(time(0));
    bool game_won = false;
    start();
    string computer_guess = random_code_gen();
    string user_guess = user_input();
    while (!game_won) {
        if (!check_validity(user_guess)) {
            user_guess = user_input();
        }
        else {
            vector<int> tot = check_guess(user_guess, computer_guess);
            win_game(tot[0], tries, game_won, user_guess);
        }
    }
    return 0;
}

//yypbyypb