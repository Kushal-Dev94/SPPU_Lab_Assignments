#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <cctype>
using namespace std;

// Helper to convert word to lowercase
string toLower(string word) {
    transform(word.begin(), word.end(), word.begin(), ::tolower);
    return word;
}

// Basic stemming function (not as advanced as PorterStemmer)
string simpleStem(string word) {
    if (word.length() > 4) {
        if (word.substr(word.length() - 3) == "ing") word = word.substr(0, word.length() - 3);
        else if (word.substr(word.length() - 2) == "ed") word = word.substr(0, word.length() - 2);
        else if (word.back() == 's') word = word.substr(0, word.length() - 1);
    }
    return word;
}

// Tokenize and clean text
vector<string> tokenize(string line) {
    vector<string> words;
    string word;
    for (char ch : line) {
        if (isalnum(ch))
            word += tolower(ch);
        else if (!word.empty()) {
            words.push_back(word);
            word.clear();
        }
    }
    if (!word.empty()) words.push_back(word);
    return words;
}

int main() {
    unordered_set<string> stopwords;
    unordered_map<string, int> freq;

    // Load stopwords
    ifstream stopFile("Group_A_1_Conflation_Algorithm/C++/stopwords.txt");
    string sw;
    while (getline(stopFile, sw)) {
        stopwords.insert(toLower(sw));
    }
    stopFile.close();

    // Process document
    ifstream doc("Group_A_1_Conflation_Algorithm/C++/document.txt");
    string line;
    while (getline(doc, line)) {
        vector<string> words = tokenize(line);
        for (auto& word : words) {
            if (stopwords.find(word) == stopwords.end()) {
                string stemmed = simpleStem(word);
                freq[stemmed]++;
            }
        }
    }
    doc.close();

    // Write output
    ofstream out("Group_A_1_Conflation_Algorithm/C++/output.txt");
    for (auto& [word, count] : freq) {
        if (count >= 1) {
            out << word << ": " << count << endl;
        }
    }
    out.close();

    cout << "Output saved to output.txt" << endl;
    return 0;
}
