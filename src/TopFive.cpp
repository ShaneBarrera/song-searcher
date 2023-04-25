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
    vector<Song> topFive = FindTop5Hash(allSongs, searchedWord); //  Haven't created the FindTop5() function yet
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

void TopFive::PrintTop5Tree(string searchedWord) 
{
    vector<Song> topFive = FindTop5Tree(allSongs, searchedWord); //  Haven't created the FindTop5() function yet
    if (topFive.empty()) 
    {
        return;
    }

    cout << "\"" << searchedWord << "\" appears in the following songs most frequently:\n";
    int rank = 1;
        for (auto& song : topFive) {
            cout << rank << ". \"" << song.name << "\" " << song.wordMapTree.GetNumUses(searchedWord)
            << " " << song.streams << endl;
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

vector<TopFive::Song> TopFive::FindTop5Hash(vector<Song>& allSongs, string word) {
    priority_queue<pair<Song, int>> songsOrderedHash;

    for (int i = 0; i < allSongs.size(); i++)
        songsOrderedHash.push(make_pair(allSongs[i], allSongs[i].wordMapHash.getWordFrequency(word)));    

    vector<pair<Song, int>> topFiveSongs;
    for (int i = 0; i < 5; i++)
        topFiveSongs.push_back(songsOrderedHash.top());

}

vector<TopFive::Song> TopFive::FindTop5Tree(vector<Song>& allSongs, string word) {
    priority_queue<pair<Song, int>> songsOrderedTree;

    for (int i = 0; i < allSongs.size(); i++)
        songsOrderedTree.push(make_pair(allSongs[i], allSongs[i].wordMapHash.getWordFrequency(word)));

    vector<pair<Song, int>> topFiveSongs;
    for (int i = 0; i < 5; i++)
        topFiveSongs.push_back(songsOrderedTree.top());

}

//vect or sorted map
//add them to a vector
//sort
//return top 5
//keep track of the name of the word is for the number
//Maybe an ordered map? or a max
