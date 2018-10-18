#include "solutions.h"

using namespace std;

int main() {
    vector<string> strings = generateParenthesis(13);
    for(auto i=strings.begin(); i<strings.end(); i++){
        cout << *i << ' ';
    }
}