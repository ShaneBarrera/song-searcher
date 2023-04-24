#include "TopFive.h"
#include <algorithm>

void TopFive::insertWords(Song& song)
{
    TreeMap(song.lyrics);
    HashMap(song.lyrics);
    // string word;
    // istringstream stream(song.lyrics);
    // while (stream >> word)
    // {
    //     transform(word.begin(), word.end(), word.begin(), ::tolower);
    //     if (song.wordMapHash.find(word) == song.wordMapHash.end()) {
    //         song.wordMapHash[word] = 1;
    //     } 
    //     else {
    //         //  We will increment for the key to store the next word
    //         song.wordMapHash[word]++;
    //     }

    //     // For the RB tree, insert the current word
    //     song.wordMapTree.Insert(song.lyrics);
    // }
}
