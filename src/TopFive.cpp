#include "TopFive.h"
#include <algorithm>

void TopFive::CreateMapsForSongs(vector<Song> allSongs)
{
    for (auto& song : allSongs)
    {
        insertWords(song); //  The insertWords(song) function calls the constructor for both tree and hash
    }
}

void TopFive::PrintTop5(string searchedWord) 
{
    vector<Song> topFive = FindTop5();
    if (topFive.empty()) 
    {
        return;
    }

    cout << "\"" << searchedWord << "\" appears in the following songs most frequently:\n";
    int rank = 1;
        for (auto& song : topFive) {
            cout << rank << ". \"" << song.name << "\" " << song.wordMapHash.getWordFrequency(searchedWord)
            << " " << song.streams << endl;
            ++rank;
    }
}

void TopFive::insertWords(Song& song)
{
    TreeMap(song.lyrics);
    HashMap(song.lyrics);
}
