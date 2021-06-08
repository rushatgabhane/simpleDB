#include "Util.h"

string getFirstWord(string &buffer) {
    string firstWord;
    for(int i=0; i<buffer.size() && buffer[i] != ' '; i++) {
        firstWord += buffer[i];
    }
    return firstWord;
}