#include <iostream>
#include <string>

std::string::iterator stringpbrk(std::string &s, const std::string &accept) {
    for (auto it = s.begin(); it != s.end(); ++it) {
        if (accept.find(*it) != std::string::npos) {
            return it;
        }
    }
    return s.end();
}

bool containsForbiddenChars(const std::string& word) {
    std::string forbiddenChars = "bdfhkt";
    for (char ch : word) {
        if (forbiddenChars.find(ch) != std::string::npos) {
            return true;
        }
    }
    return false;
}

int main() {
    std::string input;
    std::string longestWord;

    while (std::cin >> input) {
        std::string word;
        auto it = input.begin();
        while (it != input.end()) {
            
            auto wordBegin = it;
            while (it != input.end() && !isspace(*it)) {
                ++it;
            }
            auto wordEnd = it;
            word = std::string(wordBegin, wordEnd);

            if (!containsForbiddenChars(word)) {

                if (word.length() > longestWord.length()) {
                    longestWord = word;
                }
            }
        }
    }

    std::cout << longestWord << std::endl;

    return 0;
}
