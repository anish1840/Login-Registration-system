#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Function prototypes
void registerUser();
void loginUser();
bool userExists(const string &username);

int main() {
    int choice;
    do {
        cout << "\n========= LOGIN & REGISTRATION SYSTEM =========";
        cout << "\n1. Register";
        cout << "\n2. Login";
        cout << "\n3. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                cout << "\nThank you for using the system. Goodbye!\n";
                break;
            default:
                cout << "\nInvalid choice. Try again.\n";
        }
    } while (choice != 3);

    return 0;
}

// Function to check if a user already exists
bool userExists(const string &username) {
    ifstream file("users.txt");
    string storedUser, storedPass;

    while (file >> storedUser >> storedPass) {
        if (storedUser == username) {
            return true;
        }
    }
    return false;
}

// Function to register a new user
void registerUser() {
    string username, password;

    cout << "\nEnter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    if (userExists(username)) {
        cout << "\n⚠️ Username already exists. Try a different one.\n";
        return;
    }

    ofstream file("users.txt", ios::app);
    file << username << " " << password << endl;
    file.close();

    cout << "\n✅ Registration successful! You can now log in.\n";
}

// Function to log in an existing user
void loginUser() {
    string username, password;
    cout << "\nEnter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    ifstream file("users.txt");
    string storedUser, storedPass;
    bool found = false;

    while (file >> storedUser >> storedPass) {
        if (storedUser == username && storedPass == password) {
            found = true;
            break;
        }
    }

    file.close();

    if (found) {
        cout << "\n✅ Login successful! Welcome, " << username << "!\n";
    } else {
        cout << "\n❌ Invalid username or password. Please try again.\n";
    }
}
