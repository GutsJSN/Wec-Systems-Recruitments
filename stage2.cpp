#include <iostream>
#include <string>
#include <cmath>

// Function to calculate modular exponentiation
long long int modExp(long long int base, long long int exponent, long long int modulus) {
    long long int result = 1;
    base = base % modulus;

    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % modulus;
        }
        base = (base * base) % modulus;
        exponent = exponent / 2;
    }

    return result;
}

// Function to encrypt a message using RSA
std::string encryptRSA(const std::string& message, long long int n, long long int e) {
    std::string encryptedMessage = "";

    for (char c : message) {
        // Convert each character to its ASCII value
        long long int asciiValue = static_cast<long long int>(c);

        // Encrypt the ASCII value using modular exponentiation
        long long int encryptedValue = modExp(asciiValue, e, n);

        // Append the encrypted value to the encrypted message
        encryptedMessage += std::to_string(encryptedValue) + " ";
    }

    return encryptedMessage;
}

int main() {
    // Known values of n and e
    long long int n = 421649;  // Replace with the actual value of n
    long long int e = 17;     // Replace with the actual value of e

    // Message to encrypt
    std::string message = "Web.Club";

    // Encrypt the message using RSA
    std::string encryptedMessage = encryptRSA(message, n, e);

    // Print the encrypted message
    std::cout << "Encrypted Message: " << encryptedMessage << std::endl;

    return 0;
}