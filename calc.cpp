#include <iostream>
#include <fstream>
#include <string>
#include <vector>

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
	
	for (const std::string& filterWord : filterWords) {
		size_t pos = text.find(filterWord);
		std::cout<<"word being processed: "+filterWord<<std::endl;
		if (pos != std::string::npos) {
			foundWords.push_back(filterWord);
		}
	}
	
	return foundWords;
}

int main() {
	std::cout<<"- - - - - - - - - - - - - "<<std::endl;
	std::cout<<"Willkommen zum textscanner (C++)"<<std::endl;
	std::cout<<"- - - - - - - - - - - - -"<<std::endl;
	std::ifstream textFile("input_text.txt");
	
	if (!textFile.is_open()) {
		std::cerr << "Fehler beim Öffnen der Textdatei." << std::endl;
		return 1;
	}
	
	std::string text;
	getline(textFile, text);
	textFile.close();
	
	std::string filterWordsFile = "filter_words.txt";
	
	std::vector<std::string> foundWords = scanText(text, filterWordsFile);
	
	if (foundWords.empty()) {
		std::cout << "Keine Wörter gefunden." << std::endl;
	} else {
		std::cout << "Gefundene Wörter:" << std::endl;
		for (const std::string& word : foundWords) {
			std::cout << word << std::endl;
		}
	}
	
	return 0;
}
