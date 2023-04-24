#pragma once
#include <string>
#include <cstring>
#include <iostream>
using namespace std;

class Top5 {

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
};

