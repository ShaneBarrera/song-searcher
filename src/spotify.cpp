// #include <iostream>
// #include <curl/curl.h>

// size_t write_callback(char *ptr, size_t size, size_t nmemb, std::string *data)
// {
//     data->append(ptr, size * nmemb);
//     return size * nmemb;
// }

// void get_spotify_song_data(const std::string& song_name)
// {
//     CURL *curl;
//     CURLcode res;
//     curl = curl_easy_init();
//     if(curl) {
//         std::string url = "https://api.spotify.com/v1/search?type=track&q=" + song_name;
//         curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        
//         struct curl_slist *headers = NULL;
//         headers = curl_slist_append(headers, "Content-Type: application/json");
//         headers = curl_slist_append(headers, "Authorization: Bearer <YOUR_ACCESS_TOKEN>");
//         curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        
//         curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "GET");
        
//         std::string response;
//         curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
//         curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

//         res = curl_easy_perform(curl);
//         if(res != CURLE_OK) {
//             std::cerr << "Error: " << curl_easy_strerror(res) << std::endl;
//         }
//         else {
//             std::cout << response << std::endl;
//         }

//         curl_easy_cleanup(curl);
//     }
// }
