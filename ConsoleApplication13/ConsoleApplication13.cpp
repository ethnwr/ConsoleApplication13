﻿#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cctype>
#include <algorithm>


using namespace std;

int countWordsStartingWith(const string& filename, char startChar) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Ошибка: Не удалось открыть файл " << filename << endl;
        return -1;
    }

    string line;
    int count = 0;
    while (getline(file, line)) {
        stringstream ss(line);
        string word;
        while (ss >> word) {
            string cleanedWord = "";
            for (char c : word) {
                if (isalpha(c)) {
                    cleanedWord += c;
                }
            }
            if (!cleanedWord.empty() && tolower(cleanedWord[0]) == tolower(startChar)) {
                count++;
            }
        }
    }
    file.close();
    return count;
}

int main() {
    setlocale(LC_ALL, "ru");
    string filename = "input1.txt";
    char startChar;

    cout << "Введите символ для поиска: ";
    cin >> startChar;

    int wordCount = countWordsStartingWith(filename, startChar);
    if (wordCount != -1) {
        cout << "Количество слов, начинающихся с '" << startChar << "': " << wordCount << endl;
    }

    return 0;
}