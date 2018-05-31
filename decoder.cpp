#include <string>
#include <vector>
#include  <iostream>
using namespace std;

struct Guess { //
    string code;
    int red = 0;
    int white = 0;
};
bool checkValid(int red, int white) {
    return (red >= 0 && white >= 0 && red + white <= 4);
}
void takeInput(int & red, int & white) {
    char misc;
    cout << "Enter the red value followed by a comma and then the white value" 
         << endl;
    cin >> red;
    cin >> misc;
    cin >> white;
}
void playGame(vector<Guess> & tries) {
    Guess g;
    int r = 0;
    int w = 0;
    cout << g.code; // code part under construction
    takeInput(r, w);

    if (checkValid(r, w)) {
        g.red = r;
        g.white = w;
        tries.push_back(g);
    }

}

int main() {
    vector<Guess> attempts;
    return 0;
}