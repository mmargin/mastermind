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
void sameColor(const vector<char> & colors) {
    // byrg
    map<char,int> codeColors;
    for (int i = 0; i < colors.size(); ++i) {
        string code(4, colors[i]);
        // rrrr
        // yyyy
        cout << code << endl;
        int r = 0;
        int w = 0;
        takeInput(r, w);
        // 1,0
        // r = 1 w = 0
        assert(w == 0);
        if (r == 4) {
            break;
        }
        else if (r > 0) {
            codeColors[colors[i]] = r;
        }
    }
    // what do we know? we know how many of each color in the code
    // map has counts of distinct colors
    
}
bool checkValid(int red, int white) {
    return (red >= 0 && white >= 0 && red + white <= 4);
}

void playGame(vector<Guess> & tries, int & total_red) {
    while (total_red != 4) {
        Guess g;
        int r = 0;
        int w = 0;
        cout << g.code; // code part under construction
        takeInput(r, w);
        if (checkValid(r, w)) {
            g.red = r;
            total_red = r;
            g.white = w;
            tries.push_back(g);
        }
    }
    cout << "Yay I guessed in " << tries.size() << " tries!" << endl;
}

int main() {
    int red = 0;
    vector<Guess> attempts;
    playGame(attempts, red);
    return 0;
}