#pragma once
#include <string>
#include <cstring>
#include <iostream>
#include <unordered_map>
#include "TreeMap.h"
#include "HashMap.h"

using namespace std;

class TopFive {

    struct Song {
        string name;
        string artist;
        string lyrics;
        Int streams; // from spotify if time allows
        HashMap wordMapHash;
        TreeMap wordMapTree;
    };

    vector<Song> allSongs;

Public:
    void CreateMapsForSongs();
    vector<Song> FindTop5();
    void PrintTop5();
    void insertWords(Song &song);
};

