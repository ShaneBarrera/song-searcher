#pragma once
#include <string>
#include <iostream>
using namespace std;

#ifndef SONG_H
#define SONG_H

namespace bridges {
    namespace dataset {
        class Song {
        private:
            string artist, // song author
                song,   // song title
                album,  // album title
                lyrics, // full lyrics
                release_date;

        public:
            Song()
                : artist(""), song(""), album(""), lyrics(""),
                release_date("") {
            }

            Song(const string& artist, const string& song, const
                string& album, const string& lyrics,
                const string& release_date)
                : artist(artist), song(song), album(album), lyrics(lyrics),
                release_date(release_date) {
            }
            string getArtist() const {
                return artist;
            }
            void setArtist(const string& artist) {
                this->artist = artist;
            }

            string getSongTitle() const {
                return song;
            }

            void setSongTitle(const string& song) {
                this->song = song;
            }

            string getAlbumTitle() const {
                return album;
            }
            void setAlbumTitle(const string& album) {
                this->album = album;
            }

            string getLyrics() const {
                return lyrics;
            }

            void setLyrics(const string& lyrics) {
                this->lyrics = lyrics;
            }

            string getReleaseDate() const {
                return release_date;
            }

            void setReleaseDate(const string& release_date) {
                this->release_date = release_date;
            }
        };
    }
} // namespace bridges

#endif