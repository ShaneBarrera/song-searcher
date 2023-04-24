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

vector<TopFive::Song> TopFive::FindTop5Hash(vector<Song>& allSongs, string word) {
    priority_queue<pair<Song, int>> songsOrderedHash;

    for (int i = 0; i < allSongs.size(); i++)
        songsOrderedHash.push(make_pair(allSongs[i], allSongs[i].wordMapHash.getWordFequency(word)));    

    vector<pair<Song, int>> topFiveSongs;
    for (int i = 0; i < 5; i++)
        topFiveSongs.push_back(songsOrderedHash.top());

}

vector<TopFive::Song> TopFive::FindTop5Tree(vector<Song>& allSongs, string word) {
    priority_queue<pair<Song, int>> songsOrderedTree;

    for (int i = 0; i < allSongs.size(); i++)
        songsOrderedTree.push(make_pair(allSongs[i], allSongs[i].wordMapHash.getWordFequency(word)));

    vector<pair<Song, int>> topFiveSongs;
    for (int i = 0; i < 5; i++)
        topFiveSongs.push_back(songsOrderedTree.top());

}


void TopFive::insertWords(Song& song)
{
    TreeMap(song.lyrics);
    HashMap(song.lyrics);
}
