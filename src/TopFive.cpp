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
    vector<Song> topFive = FindTop5(); //  Haven't created the FindTop5() function yet
    if (topFive.empty())
    {
        return;
    }

    cout << "\"" << searchedWord << "\" appears in the following songs most frequently:\n";
    int rank = 1;
    for (auto& song : topFive) {
        cout << rank << ". \"" << song.name << "\" " << song.wordMapHash.getWordFequency(searchedWord)
            << " " << song.streams << endl;
        ++rank;
    }

    cout << "\"" << searchedWord << "\" appears in the following songs most frequently:\n";
    int rank = 1;
    for (auto& song : topFive) {
        cout << rank << ". \"" << song.name << "\" " << song.wordMapTree.GetNumUses(searchedWord)
            << " " << song.streams << endl;
        ++rank;
    }
}

queue<TopFive::Song> TopFive::FindTop5(vector<Song>& allSongs) {

}


void TopFive::insertWords(Song& song)
{
    TreeMap(song.lyrics);
    HashMap(song.lyrics);
}
