#include <iostream>
#include "src/InputBuffer.h"

using namespace std;

void printPrompt() {
    cout << "db> ";
}
void readInput(InputBuffer &inputBuffer) {
    getline(cin, inputBuffer.buffer);
    if(inputBuffer.buffer.size() == 0) {
        printPrompt();
        readInput(inputBuffer);
    }
}

int main() {

}