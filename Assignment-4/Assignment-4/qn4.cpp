#include <iostream>
#include <queue>
using namespace std;

void firstNonRepeating(string str) {
    int count[26] = {0};
    queue<char> q;
    for (char ch : str) {
        q.push(ch);
        count[ch - 'a']++;

        while (!q.empty() && count[q.front() - 'a'] > 1) {
            q.pop();  
        }
        
        if (q.empty()) {
            cout << "-1 ";
        } else {
            cout << q.front() << " ";
        }
    }
    cout << endl;
}

int main() {
    string input = "aabc";
    cout << "Input: " << input << endl;
    cout << "Output: ";
    firstNonRepeating(input);
    return 0;
}
