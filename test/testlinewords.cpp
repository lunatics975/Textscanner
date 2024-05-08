#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

int main() {
    std::ifstream file("example.txt"); // Öffne die Textdatei

    if (!file.is_open()) {
        std::cerr << "Fehler beim Öffnen der Datei!" << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(file, line)) { // Lese jede Zeile der Datei
        std::istringstream iss(line);
        std::string word;
        while (iss >> word) { // Trenne die Zeile in Wörter
            // Hier kannst du den Code für die Filterung implementieren
            std::cout << word << std::endl; // Beispiel: Gib jedes Wort aus
        }
    }

    file.close(); // Schließe die Datei

    return 0;
}
