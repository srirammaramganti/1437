#include <iostream>
#include <string>
#include <vector>
using namespace std;

void backtrackDistinct(const string &word, string &current, vector<bool> &used) {
    if (current.size() == word.size()) {
        cout << current << endl;
        return;
    }

    for (size_t i = 0; i < word.size(); ++i) {
        if (!used[i]) {
            used[i] = true;
            current.push_back(word[i]);

            backtrackDistinct(word, current, used);

            current.pop_back();
            used[i] = false;
        }
    }
}

void generatePermutations() {
    string word = "Mississippi";
    string current;
    vector<bool> used(word.size(), false);

    backtrackDistinct(word, current, used);
}

int main() {
    generatePermutations();
    return 0;
}