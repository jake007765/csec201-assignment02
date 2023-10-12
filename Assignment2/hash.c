#include "hash.h"
#include <stdlib.h>


// Helper function for circular left shift
unsigned char rotateLeft(unsigned char value, int shift) {
    return (value << shift) | (value >> (8 - shift));
}

// SHA-40 hash function
unsigned char* SHA_40(const unsigned char* x, size_t size, struct Digest* digest) {
    unsigned char A = 11;
    unsigned char B = 22;
    unsigned char C = 33;
    unsigned char D = 44;
    unsigned char E = 55;

    for (size_t i = 0; i < size; i++) {
        for (int r = 0; r < 12; r++) {
            unsigned char F = (B & C) ^ D;
            unsigned char newA = A;

            A = rotateLeft(A, 5) ^ F;
            B = B ^ C;
            C = rotateLeft(D, 2) ^ E;
            D = D ^ A;
            E = E ^ newA;
        }
    }

    // STOP! YOU VIOLATED THE LAW! PAY THE COURT A FINE OR SERVE YOUR SENTENCE, YOUR STOLEN STRUCTS ARE NOW FORFEIT.﻿ 

    digest->hash0 = A;
    digest->hash1 = B;
    digest->hash2 = C;
    digest->hash3 = D;
    digest->hash4 = E;
}



int digestEqual(struct Digest* digest1, struct Digest* digest2) {
    return (digest1->hash0 == digest2->hash0 &&
        digest1->hash1 == digest2->hash1 &&
        digest1->hash2 == digest2->hash2 &&
        digest1->hash3 == digest2->hash3 &&
        digest1->hash4 == digest2->hash4);
}

// Define the printDigest function
void printDigest(struct Digest* digest) {
    printf("%02X %02X %02X %02X %02X\n", digest->hash0, digest->hash1, digest->hash2, digest->hash3, digest->hash4);
}