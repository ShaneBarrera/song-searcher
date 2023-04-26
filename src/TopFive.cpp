#include "TopFive.h"

void TopFive::PrintTop5Hash(string searchedWord)
{
    vector<pair<int, Song>> topFive = FindTop5Hash(allSongs, searchedWord);
    if (topFive.empty())
    {
        return;
    }

    cout << "\"" << searchedWord << "\" appears in the following songs most frequently:\n";
    int rank = 1;
    for (auto& song : topFive) {
        cout << rank << ". \"" << song.second.name << "\" " << song.first << endl;
        /// next line would print streams
//             << " " << song.second.streams << endl;
        ++rank;
    }
}

void TopFive::PrintTop5Tree(string searchedWord)
{
    vector<pair<int, Song>> topFive = FindTop5Tree(allSongs, searchedWord);
    if (topFive.empty())
    {
        return;
    }

    cout << "\"" << searchedWord << "\" appears in the following songs most frequently:\n";
    int rank = 1;
    for (auto& song : topFive) {
        cout << rank << ". \"" << song.second.name << "\" " << song.first << endl;
        /// next line would print streams
//             << " " << song.second.streams << endl;
        ++rank;
    }
}

vector<pair<int, TopFive::Song>> TopFive::FindTop5Hash(vector<Song>& allSongs, string word) {
    priority_queue<pair<int, Song>> songsOrderedHash;

    for (unsigned int i = 0; i < allSongs.size(); i++) {
        songsOrderedHash.push(make_pair(allSongs[i].wordMapHash.getWordFrequency(word), allSongs[i]));
        allSongs[i].wordMapHash.clear();
    }

    vector<pair<int, Song>> topFiveSongs;
    for (int i = 0; i < 5 && !songsOrderedHash.empty(); i++) {
        topFiveSongs.push_back(songsOrderedHash.top());
        songsOrderedHash.pop();
    }
    return topFiveSongs;
}

vector<pair<int, TopFive::Song>> TopFive::FindTop5Tree(vector<Song>& allSongs, string word) {
    priority_queue<pair<int, Song>> songsOrderedTree;

    for (int i = 0; i < allSongs.size(); i++)
        songsOrderedTree.push(make_pair(allSongs[i].wordMapTree.GetNumUses(word), allSongs[i]));

    vector<pair<int, Song>> topFiveSongs;
    for (int i = 0; i < 5 && !songsOrderedTree.empty(); i++) {
        topFiveSongs.push_back(songsOrderedTree.top());
        songsOrderedTree.pop();
    }
    return topFiveSongs;
}

void TopFive::DestroyEverything() {
    for (auto song : allSongs) {
        song.wordMapTree.HelperDestruct(song.wordMapTree.GetRoot());
        //song.wordMapHash.DestroyNodes();
    }
}
