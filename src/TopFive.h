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
    queue<Song> FindTop5(vector<Song>& allSongs);
    void PrintTop5(string searchedWord);
    void insertWords(Song& song);
};
