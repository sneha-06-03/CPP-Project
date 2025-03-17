#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Structure to store song details
struct Song {
    string title;
    string artist;
    string album;
    string genre;
};

// Function to add a new song
void addSong(vector<Song> &collection) {
    Song newSong;
    cout << "Enter song title: ";
    getline(cin, newSong.title);
    cout << "Enter artist name: ";
    getline(cin, newSong.artist);
    cout << "Enter album name: ";
    getline(cin, newSong.album);
    cout << "Enter genre: ";
    getline(cin, newSong.genre);
    collection.push_back(newSong);
    cout << "Song added successfully!\n";
}

// Function to display all songs
void displaySongs(const vector<Song> &collection) {
    if (collection.empty()) {
        cout << "No songs in the collection.\n";
        return;
    }
    for (size_t i = 0; i < collection.size(); ++i) {
        cout << "\nSong " << i + 1 << ":" << endl;
        cout << "Title: " << collection[i].title << endl;
        cout << "Artist: " << collection[i].artist << endl;
        cout << "Album: " << collection[i].album << endl;
        cout << "Genre: " << collection[i].genre << endl;
    }
}

// Function to search for a song by title
void searchSong(const vector<Song> &collection) {
    string searchTitle;
    cout << "Enter the song title to search: ";
    getline(cin, searchTitle);
    for (const auto &song : collection) {
        if (song.title == searchTitle) {
            cout << "Song found:\n";
            cout << "Title: " << song.title << endl;
            cout << "Artist: " << song.artist << endl;
            cout << "Album: " << song.album << endl;
            cout << "Genre: " << song.genre << endl;
            return;
        }
    }
    cout << "Song not found.\n";
}

// Function to remove a song by title
void removeSong(vector<Song> &collection) {
    string removeTitle;
    cout << "Enter the song title to remove: ";
    getline(cin, removeTitle);
    for (size_t i = 0; i < collection.size(); ++i) {
        if (collection[i].title == removeTitle) {
            collection.erase(collection.begin() + i);
            cout << "Song removed successfully!\n";
            return;
        }
    }
    cout << "Song not found.\n";
}

int main() {
    vector<Song> musicCollection;
    int choice;
    do {
        cout << "\nMusic Collection Organizer\n";
        cout << "1. Add Song\n";
        cout << "2. Display Songs\n";
        cout << "3. Search Song\n";
        cout << "4. Remove Song\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();  // To clear newline from input buffer
        
        switch (choice) {
            case 1:
                addSong(musicCollection);
                break;
            case 2:
                displaySongs(musicCollection);
                break;
            case 3:
                searchSong(musicCollection);
                break;
            case 4:
                removeSong(musicCollection);
                break;
            case 5:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);
    
    return 0;
}
