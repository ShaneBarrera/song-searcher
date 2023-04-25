#include "TopFive.h"
#include <algorithm>

void TopFive::CreateMapsForSongs(vector<Song> allSongs)
{
    for (auto& song : allSongs)
    {
        insertWordsHash(song); //  The insertWords(song) function calls the constructor for both tree and hash
        insertWordsTree(song);
    }
}

void TopFive::PrintTop5Hash(string searchedWord)
{
    vector<pair<Song, int>> topFive = FindTop5Hash(allSongs, searchedWord);
    if (topFive.empty())
    {
        return;
    }

    cout << "\"" << searchedWord << "\" appears in the following songs most frequently:\n";
    int rank = 1;
    for (auto& song : topFive) {
        cout << rank << ". \"" << song.first.name << "\" " << song.second
            << " " << song.first.streams << endl;
        ++rank;
    }
}

void TopFive::PrintTop5Tree(string searchedWord)
{
    vector<pair<Song, int>> topFive = FindTop5Tree(allSongs, searchedWord);
    if (topFive.empty())
    {
        return;
    }

    cout << "\"" << searchedWord << "\" appears in the following songs most frequently:\n";
    int rank = 1;
    for (auto& song : topFive) {
        cout << rank << ". \"" << song.first.name << "\" " << song.second
            << " " << song.first.streams << endl;
        ++rank;
    }
}

void TopFive::insertWordsHash(Song& song)
{
    HashMap(song.lyrics);
}

void TopFive::insertWordsTree(Song& song)
{
    TreeMap(song.lyrics);
}

vector<pair<TopFive::Song, int>> TopFive::FindTop5Hash(vector<Song>& allSongs, string word) {
    priority_queue<pair<Song, int>> songsOrderedHash;

    for (int i = 0; i < allSongs.size(); i++)
        songsOrderedHash.push(make_pair(allSongs[i], allSongs[i].wordMapHash.getWordFrequency(word)));    

    vector<pair<Song, int>> topFiveSongs;
    for (int i = 0; i < 5 && !songsOrderedHash.empty(); i++) {
        topFiveSongs.push_back(songsOrderedHash.top());
        songsOrderedHash.pop();
    }
    return topFiveSongs;
}

vector<pair<TopFive::Song, int>> TopFive::FindTop5Tree(vector<Song>& allSongs, string word) {
    priority_queue<pair<Song, int>> songsOrderedTree;

    for (int i = 0; i < allSongs.size(); i++)
        songsOrderedTree.push(make_pair(allSongs[i], allSongs[i].wordMapTree.GetNumUses(word)));

    vector<pair<Song, int>> topFiveSongs;
    for (int i = 0; i < 5 && !songsOrderedTree.empty(); i++) {
        topFiveSongs.push_back(songsOrderedTree.top());
        songsOrderedTree.pop();
    }
    return topFiveSongs;
}

