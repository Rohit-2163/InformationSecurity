#include <iostream>

// Function to calculate the parity bit for a given position
int calculateParity(const int* data, int size, int position) {
    int parity = data[0]; // Initialize with first bit
    for (int i = 1; i < size; ++i) {
        // XOR operation to calculate parity
        if ((i & position) != 0) {
            parity ^= data[i];
        }
    }
    return parity;
}

// Function to encode a 4-bit message into a 7-bit Hamming code
void hammingEncode(const int* message, int* encodedMessage) {
    // Calculate parity bits
    encodedMessage[2] = calculateParity(message, 4, 0b001); // P1
    encodedMessage[4] = calculateParity(message, 4, 0b010); // P2
    encodedMessage[5] = calculateParity(message, 4, 0b100); // P3

    // Place message bits and parity bits into the encoded message
    encodedMessage[0] = message[0];
    encodedMessage[1] = message[1];
    encodedMessage[3] = message[2];
    encodedMessage[6] = message[3];
}

// Function to decode a 7-bit Hamming code into a 4-bit message
// void hammingDecode(const int* received, int* decodedMessage) {
//     // Calculate syndrome bits
//     int s1 = received[2] ^ received[0] ^ received[1] ^ received[3]; // P1
//     int s2 = received[4] ^ received[0] ^ received[1] ^ received[5]; // P2
//     int s3 = received[5] ^ received[0] ^ received[2] ^ received[3]; // P3

//     // Determine error position
//     int errorPosition = s1 + s2 * 2 + s3 * 4;

//     // Correct error
//     if (errorPosition > 0) {
//         received[errorPosition - 1] ^= 1; // Flip the erroneous bit
//     }

//     // Retrieve original message bits
//     decodedMessage[0] = received[0];
//     decodedMessage[1] = received[1];
//     decodedMessage[2] = received[3];
//     decodedMessage[3] = received[6];
// }

// Function to decode a 7-bit Hamming code into a 4-bit message
void hammingDecode(int* received, int* decodedMessage) {
    // Calculate syndrome bits
    int s1 = received[2] ^ received[0] ^ received[1] ^ received[3]; // P1
    int s2 = received[4] ^ received[0] ^ received[1] ^ received[5]; // P2
    int s3 = received[5] ^ received[0] ^ received[2] ^ received[3]; // P3

    // Determine error position
    int errorPosition = s1 + s2 * 2 + s3 * 4;

    // Correct error
    if (errorPosition > 0) {
        received[errorPosition - 1] ^= 1; // Flip the erroneous bit
    }

    // Retrieve original message bits
    decodedMessage[0] = received[0];
    decodedMessage[1] = received[1];
    decodedMessage[2] = received[3];
    decodedMessage[3] = received[6];
}

int main() {
    // Example usage
    int originalMessage[4] = {1, 0, 1, 1}; // 4-bit message
    int encodedMessage[7]; // 7-bit encoded message
    int decodedMessage[4]; // Decoded message

    hammingEncode(originalMessage, encodedMessage);

    // Simulate error by flipping a bit
    encodedMessage[2] ^= 1; // Flip one bit

    hammingDecode(encodedMessage, decodedMessage);

    std::cout << "Original Message:";
    for (int i = 0; i < 4; ++i) {
        std::cout << " " << originalMessage[i];
    }
    std::cout << std::endl;

    std::cout << "Encoded Message: ";
    for (int i = 0; i < 7; ++i) {
        std::cout << " " << encodedMessage[i];
    }
    std::cout << std::endl;

    std::cout << "Decoded Message: ";
    for (int i = 0; i < 4; ++i) {
        std::cout << " " << decodedMessage[i];
    }
    std::cout << std::endl;

    return 0;
}


