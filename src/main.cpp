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
    string sample = "This is an example with example is a multiple copies of this word";
    cout << sample << endl;
    TreeMap map = TreeMap(sample);
    map.PrintInorder(map.GetRoot());
    cout << map.GetNumUses("this") << endl;

    bridges::Bridges bridges("exla", "1255981382944");

    bridges.setTitle("Song Data Stuff");
    bridges::DataSource ds(&bridges);

//    bridges::dataset::Song s = ds.getSong("Harder Faster Better Stronger", "Daft Punk");
//
////     print song attributes
//    cout << endl << "Title: " << s.getSongTitle() << endl
//         << "Artist: " << s.getArtist() << endl
//         << "Album: " << s.getAlbumTitle() << endl
//         << "Release Date: " << s.getReleaseDate() << endl;
//
//    // print lyrics
//    std::cout << s.getLyrics() << std::endl;

    std::vector<bridges::dataset::Song> songs = ds.getSongData();

    TopFive top5 = TopFive();

    // loop through the songs and print their titles
    for (bridges::dataset::Song song : songs) {
        cout<< song.getLyrics() << endl;
//        TopFive::Song s(song.getSongTitle(), song.getArtist(), song.getLyrics());
//        top5.allSongs.push_back(s);
    }

//    for (auto song : top5.allSongs) {
//        cout << song.name << endl;
//    }


//    bridges::Song song("Hello", "Adele", "25");



//    CURL* curl = curl_easy_init();
//    curl_easy_setopt(curl, CURLOPT_URL, "http://bridges-music.herokuapp.com/bridges_music_server");

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
