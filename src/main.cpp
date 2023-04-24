#include <sstream>
#include <fstream> 
#include <iostream>
#include <iomanip>
#include <unordered_map>
#include <vector>
#include <string>

int main()
{
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
