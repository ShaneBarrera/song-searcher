#pragma once
#include <string>
#include <cstring>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <vector>
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
        vector<Song> allSongs;
    }

    

public:

    vector<Song> FindTop5();
    void PrintTop5(string searchedWord);
    void insertWords(Song &song);
    void CreateMapsForSongs(vector<Song> allSongs);
};

