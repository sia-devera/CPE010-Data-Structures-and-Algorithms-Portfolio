#include <iostream>
#include <string>
#include "DOUBLY_LL_SUPPLEMENTARY.h"

int main(){

    // My Playlist but still empty:
    DoublyList<std::string>* playlist = nullptr;

    std::cout << "Current Playlist:" << std::endl;
    if (playlist == nullptr){
        std::cout << "Playlist is empty." << std::endl;
        std::cout << std::endl;
    }
    else{
        ListTraversal(playlist);
        std::cout << std::endl;
    }

    // Addings songs now:
    std::cout << "Adding songs to the playlists now ..." << std::endl;
    dllInsertEnd<std::string>("\"Softly\" by Clairo", &playlist);
    dllInsertEnd<std::string>("\"Ocean Eyes\" by Billie Eilish", &playlist);
    dllInsertEnd<std::string>("\"Paper Rings\" by Taylor Swift", &playlist);
    std::cout << std::endl;

    std::cout << "Current Playlist: " << std::endl;
    ListTraversal(playlist);
    std::cout << std::endl;

    // Getting the last song:
    DoublyList<std::string>* tail = playlist;
    while (tail->next != nullptr){
        tail = tail->next;}

    // Foward Playing
    std::cout << "Play Songs (Forward):" << std::endl;
    ListTraversal(playlist);
    std::cout << std::endl;

    // Backward Playing
    std::cout << "Previous Songs (Backward): " << std::endl;

    ReverseTraversal(tail);
    std::cout << std::endl;

    // Remove a song
    std::cout << "Removing the first song from the playlist..." << std::endl;
    dllDeleteNode<std::string>("\"Ocean Eyes\" by Billie Eilish", &playlist);
    std::cout << std::endl;
    
    // Adding more songs
    dllInsertEnd<std::string>("\"Sofia\" by Clairo", &playlist);
    dllInsertEnd<std::string>("\"Aftertaste\" by ROL3ERT, REJAY", &playlist);
    dllInsertEnd<std::string>("\"It's Not Living\" by The 1975", &playlist);
    dllInsertEnd<std::string>("\"Focus\" by NIKI", &playlist);
    dllInsertEnd<std::string>("\"Super\" by Seventeen", &playlist);
    dllInsertEnd<std::string>("\"Aju Nice\" by Seventeen", &playlist);
    dllInsertEnd<std::string>("\"Discover\" by Any Name's Okay", &playlist);
    std::cout << std::endl;

    std::cout << "Current Playlist: " << std::endl;
    ListTraversal(playlist);
    std::cout << std::endl;

    // Play the current song
    std::cout << "Current Song:" << std::endl;
    if (playlist != nullptr){
        std::cout << playlist->data << std::endl;}

    return 0;
}