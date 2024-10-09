
#include <iostream>
#include <string>

std::string decryptShiftCipher(const std::string& encryptedText, int shift) {
    std::string decryptedText = "";

    for (char c : encryptedText) {
        if (isupper(c)) {
            decryptedText += char(int(c - shift - 'A' + 26) % 26 + 'A');
        } else if (islower(c)) {
            decryptedText += char(int(c - shift - 'a' + 26) % 26 + 'a');
        } else {
            decryptedText += c;
        }
    }

    return decryptedText;
}

int main() {
    std::string encryptedText;

    std::cout << "Enter the encrypted text: ";
    std::getline(std::cin, encryptedText);

    for (int shift = 0; shift < 26; ++shift) {
        std::string decryptedText = decryptShiftCipher(encryptedText, shift);
        std::cout << "Shift " << shift << ": " << decryptedText << std::endl;
    }

    return 0;
}