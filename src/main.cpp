#include <sstream>
#include <fstream> 
#include <iostream>
#include <iomanip>
#include <unordered_map>
#include <vector>
#include <string>
#include <DataSource.h>
#include "TreeMap.h"
#include "TopFive.h"

//#include <curl/curl.h>
#include "Bridges.h"
#include "Song.h"
using namespace std;

int main()
{
    /// Alex's verification, need your own if running most likely? but feel free to try
    bridges::Bridges bridges("exla", "1255981382944");
    bridges.setTitle("Song Data Stuff");
    bridges::DataSource ds(&bridges);

    ///IMPORTANT NOTE: there are two Song classes in use: bridges::dataset::Song and TopFive::Song
    //get the whole dataset of songs and store in a Song vector
    std::vector<bridges::dataset::Song> songs = ds.getSongData();

    //construct an instance of our TopFive class
    TopFive top5 = TopFive();

    ///for testing (uncomment if you want to see how it works)
//    //try printing lyrics and constructing a TopFive::Song object for a single Song from dataset
//    cout<< songs[0].getLyrics() << endl;
//    TopFive::Song s(songs[0].getSongTitle(), songs[0].getArtist(), songs[0].getLyrics());

    /// for all songs in the dataset make TopFive::Song objects for them, also add them to the allSongs vector
    for (bridges::dataset::Song song : songs) {
        TopFive::Song s(song.getSongTitle(), song.getArtist(), song.getLyrics());
        top5.allSongs.push_back(s);
    }

    ///use tree to print the top 5 songs with word "happy"
    cout << "Using the red-black tree..." << endl;
    top5.PrintTop5Tree("happy");


///old stuff, probably needs to be cleaned up or deleted?
    // TreeMap songTree(132);
    // unordered_map<string, int> frequency;

    // for (int i = 0; i < songTree.size(); i++) 
    // {
    //     TreeMap* song = songTree.getSong(i);
        
    //     for (string word : song->getWords()) 
    //     {
    //         frequency[word]++;
    //     }
    // }

    // while (true) 
    // {
    //     cout << "Enter a word to search song lyrics for: ";
    //     string word;
    //     getline(cin, word);

    //     int num = frequency.find(word);
    //     if (num == frequency.end())
    //     {
    //         cout << "That word doesn't exist. Please try again." << endl;
    //         continue;
    //     }

    //     vector<TreeMap*> songList;
    //     for (int i = 0; i < songTree.size(); i++) 
    //     {
    //         TreeMap* song = songTree.getSong(i);
            
    //         if (song->contains(word)) 
    //         {
    //             songList.push_back(song);
    //         }
    //     }

    //     sort(songs.begin(), songs.end(), [](Song* a, Song* b) {
    //         if (a->getWordFrequency(word) != b->getWordFrequency(word)) {
    //             return a->getWordFrequency(word) > b->getWordFrequency(word);
    //         } else {
    //             return a->getStreams() > b->getStreams();
    //         }
    //     });

    //     // print list of songs
    //     cout << "\"" << word << "\" appears in the following songs most frequently:" << endl;
    //     int rank = 1;
    //     for (Song* song : songs) {
    //         cout << rank << ". \"" << song->getTitle() << "\" " << song->getWordFrequency(word) << " " << song->getStreams() << endl;
    //         rank++;
    //     }
    // }

    return 0;
}
