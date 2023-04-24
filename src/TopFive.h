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

    struct Song {
        string name;
        string artist;
        string lyrics;
        int streams; // from spotify if time allows
        HashMap wordMapHash;
        TreeMap wordMapTree;
    };

    vector<Song> allSongs;

public:
    void CreateMapsForSongs(vector<Song> allSongs);
    vector<Song> FindTop5Hash(vector<Song>& allSongs, string word);
    vector<Song> FindTop5Tree(vector<Song>& allSongs, string word);
    void PrintTop5(string searchedWord);
    void insertWords(Song& song);
};
