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

    //  For all songs in the dataset make TopFive::Song objects for them, also add them to the allSongs vector
    for (bridges::dataset::Song song : songs) {
        TopFive::Song s = TopFive::Song(song.getSongTitle(), song.getArtist(), song.getLyrics());
        top5.allSongs.push_back(s);
    }

    string input;
    bool isWord = false;
    
    while (true) {
        // Prompt user for word input
        while (!isWord) {
            cout << "Enter a word to search song lyrics for (or enter \"exit\" to quit): " << endl;
            getline(cin, input);
            if (input == "exit") {
                top5.DestroyEverything();
                return 0; // Exit program
            }
            if (!input.empty() && all_of(input.begin(), input.end(), ::isalpha)) {
                isWord = true;
            }
            else {
                cout << "Invalid input. Please enter another word with no spaces!" << endl;
            }
        }
        
        cout << "Using the red-black tree..." << endl;
        top5.PrintTop5Tree(input);

        cout << endl;

        cout << "Using the hash..." << endl;
        top5.PrintTop5Hash(input);

        cout << endl;

        // Reset for next iteration
        isWord = false;
    }
    return 0;
}
