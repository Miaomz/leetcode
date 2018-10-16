#include "solutions.h"

using namespace std;

int main() {
    vector<string> strings = letterCombinations("23");
    for(auto i=strings.begin(); i<strings.end(); i++){
        cout << *i << ' ';
    }
}