#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

// using namespace std;

std::vector<std::string> scanText(const std::string& text, const std::string& filterWordsFile) {
    std::vector<std::string> foundWords;

    std::ifstream file(filterWordsFile);
    if (!file.is_open()) {
        std::cerr << "Fehler beim Öffnen der Filterwörterdatei." << std::endl;
        return foundWords;
    }

    std::string word;
    std::vector<std::string> filterWords;
    while (file >> word) {
        filterWords.push_back(word);
    }
    file.close();

    std::istringstream iss(text);
    std::string line;
    while (std::getline(iss, line)) { // Lese jede Zeile der Textdatei
        std::istringstream lineStream(line);
        std::string word;
        while (lineStream >> word) { // Trenne die Zeile in Wörter
            for (const std::string& filterWord : filterWords) {
                if (word == filterWord) {
					std::cout << "Found word: " << word << std::endl;
                    foundWords.push_back(word);
                    break;
                }
            }
        }
    }

    return foundWords;
}

int main() {
    std::cout << "- - - - - - - - - - - - - - - - " << std::endl;
    std::cout << "Willkommen zum Textscanner (C++)" << std::endl;
    std::cout << "- - - - - - - - - - - - - - - -" << std::endl;
	std::cout<<std::endl;
	std::cout<<"Copyright 2024 by lunatics975. All rights reserved."<<std::endl;
	std::cout<<std::endl;
	std::cout<<"Start checking..."<<std::endl;
	std::cout<<std::endl;
    std::ifstream textFile("input_text.txt");

    if (!textFile.is_open()) {
        std::cerr << "Fehler beim Öffnen der Textdatei." << std::endl;
        return 1;
    }

    std::string text;
    std::string line;
    while (std::getline(textFile, line)) {
        text += line + "\n"; // Lese den gesamten Text ein
    }
    textFile.close();

    std::string filterWordsFile = "filter_words.txt";

    std::vector<std::string> foundWords = scanText(text, filterWordsFile);

    if (foundWords.empty()) {
		std::cout<<std::endl;
        std::cout << "Keine Wörter gefunden." << std::endl;
    } else {
		std::cout<<std::endl;
        std::cout << "Gefundene Wörter:" << std::endl;
        for (const std::string& word : foundWords) {
            std::cout << word << std::endl;
        }
    }

    return 0;
}
