#pragma once
#include <string>
#include <cstring>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include "TreeMap.h"
#include "HashMap.h"

using namespace std;

class TopFive {
public:
    struct Song {
        string name;
        string artist;
        string lyrics;
        int streams; // from spotify if time allows
        HashMap wordMapHash;
        TreeMap wordMapTree;
    };

    vector<Song> allSongs;

    void CreateMapsForSongs(vector<Song> allSongs);
    vector<pair<Song, int>> FindTop5Hash(vector<Song>& allSongs, string word);
    vector<pair<Song, int>> FindTop5Tree(vector<Song>& allSongs, string word);
    void PrintTop5Hash(string searchedWord);
    void PrintTop5Tree(string searchedWord);

private:
    void insertWordsHash(Song& song);
    void insertWordsTree(Song& song);
};
