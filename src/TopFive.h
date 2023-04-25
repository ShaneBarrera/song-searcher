#pragma once
#include <string>
#include <cstring>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>
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
        bool operator<(const Song& other) const {
            return this->streams < other.streams;
        };
        Song(string name, string artist, string lyrics) {
            this->name = name;
            this->artist = artist;
            this->lyrics = lyrics;
            wordMapHash = HashMap(lyrics);
            wordMapTree = TreeMap(lyrics);
        }
    };

    vector<Song> allSongs;

//    void CreateMapsForSongs(vector<Song> allSongs);
    vector<pair<int, Song>> FindTop5Hash(vector<Song>& allSongs, string word);
    vector<pair<int, Song>> FindTop5Tree(vector<Song>& allSongs, string word);
    void PrintTop5Hash(string searchedWord);
    void PrintTop5Tree(string searchedWord);

private:
//    void insertWordsHash(Song& song);
//    void insertWordsTree(Song& song);
};
