#include <string>
#include <vector>
#include <iostream>
#include <cassert>
#include <map>
using namespace std;

struct Guess {
    string code;
    int red = 0;
    int white = 0;
};
vector<char> createColorVector() {
    vector<char> colors;
    colors.push_back('r');
    colors.push_back('y');
    colors.push_back('b');
    colors.push_back('g');
    colors.push_back('o');
    colors.push_back('p');
    return colors;
}
void takeInput(int & red, int & white) {
    char misc;
    cout << "Enter the red value followed by a comma and then the white value!" 
         << endl;
    cin >> red;
    assert(red >= 0 && red <= 4);
    cin >> misc;
    cin >> white;
    assert(white >= 0 && white <= 4);
}
bool checkValid(int red, int white) {
    return (red >= 0 && white >= 0 && red + white <= 4);
}
map<char,int> sameColor(const vector<char> & colors) {
    map<char,int> codeColors;
    int totRed = 0;
    for (int i = 0; i < colors.size(); ++i) {
        string code(4, colors[i]);
        cout << code << endl;
        int r = 0;
        int w = 0;
        takeInput(r, w);
        assert(w == 0);
        if (r == 4) {
            break;
        }
        else if (r > 0) {
            totRed += r;
            codeColors[colors[i]] = r;
        }
        if (totRed == 4) {
            break;
        }
    }
    // what do we know? we know how many of each color in the code
    // map has counts of distinct colors
    return codeColors;
}
void playGame(vector<Guess> & tries, int & current_red, map<char,int> & codeColors) {
    while (current_red != 4) {
        if (tries.size() > 1) {

        }
        Guess g;
        for (auto & x : codeColors) { // create a code that has all the right colors
            for (int i = 0; i < x.second; ++i) {
                g.code += x.first;
            }
        }
        int r = 0;
        int w = 0;
        cout << g.code << endl;
        takeInput(r, w);
        if (checkValid(r, w)) {
            g.red = r;
            current_red = r;
            g.white = w;
            tries.push_back(g);
        }
    }
    cout << "Yay I guessed in " << tries.size() << " tries!" << endl;
}

int main() {
    int red = 0;
    vector<Guess> attempts; // + the same color ones you automatically did
    vector<char> colorPossibilities = createColorVector();
    map<char,int> codeColorsUsed = sameColor(colorPossibilities);
    playGame(attempts, red, codeColorsUsed);
    return 0;
}