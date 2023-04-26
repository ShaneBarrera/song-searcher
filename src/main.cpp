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
#include "Bridges.h"
#include "Song.h"
using namespace std;

int main()
{
    //  Alex's verification, need your own if running most likely? but feel free to try
    bridges::Bridges bridges("exla", "1255981382944");
    bridges.setTitle("Song Data Stuff");
    bridges::DataSource ds(&bridges);

    //  IMPORTANT NOTE: there are two Song classes in use: bridges::dataset::Song and TopFive::Song
    //  get the whole dataset of songs and store in a Song vector
    std::vector<bridges::dataset::Song> songs = ds.getSongData();

    //  Construct an instance of our TopFive class
    TopFive top5 = TopFive();

    //  TESTING (uncomment if you want to see how it works)
    //  Try printing lyrics and constructing a TopFive::Song object for a single Song from dataset
    //cout<< songs[0].getLyrics() << endl;
    //TopFive::Song s(songs[0].getSongTitle(), songs[0].getArtist(), songs[0].getLyrics());

    //  For all songs in the dataset make TopFive::Song objects for them, also add them to the allSongs vector
    for (bridges::dataset::Song song : songs) {
        TopFive::Song s = TopFive::Song(song.getSongTitle(), song.getArtist(), song.getLyrics());
        top5.allSongs.push_back(s);
    }
    
    TopFive::Song x = TopFive::Song("Sample Song", "Sample artist", "yo yo yo my sample lyrics are super happy");
    top5.allSongs.push_back(x);

    string input;
    bool isWord = false;
    
    while (!isWord) {
        cout << "Enter a word to search song lyrics for: " << endl;
        getline(cin, input);
        if (!input.empty() && (input.begin(), input.end(), ::isalpha)) {
            isWord = true;
        }
        else {
            cout << "Invalid input. Please enter another word with no spaces!" << endl;
        }
    }
    
    //use tree to print the top 5 songs with word "happy"
    cout << "Using the red-black tree..." << endl;
    top5.PrintTop5Tree(input);

    cout << "Using the hash..." << endl;
    top5.PrintTop5Hash(input);
    top5.DestroyEverything();

    return 0;
}
