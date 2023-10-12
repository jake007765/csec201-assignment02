#include <stdio.h>
#include <string.h>
#include "hash.h"

int main() {
    // PART A

    // Test SHA-40 hash of strings
    const char* string1 = "Rob";
    const char* string2 = "James";
    const char* string3 = "Ahmed";
    const char* string4 = "CSEC";
    const char* string5 = "Jake";

    // Declare arrays to store hash values
    unsigned char hash1[DIGEST_SIZE];
    unsigned char hash2[DIGEST_SIZE];
    unsigned char hash3[DIGEST_SIZE];
    unsigned char hash4[DIGEST_SIZE];
    unsigned char hash5[DIGEST_SIZE];

    // Calculate SHA-40 hashes and store them in the arrays
    SHA_40((const unsigned char*)string1, strlen(string1), hash1);
    SHA_40((const unsigned char*)string2, strlen(string2), hash2);
    SHA_40((const unsigned char*)string3, strlen(string3), hash3);
    SHA_40((const unsigned char*)string4, strlen(string4), hash4);
    SHA_40((const unsigned char*)string5, strlen(string5), hash5);

    // Print SHA-40 hashes
    printf("SHA-40 Hash of 'Rob': ");
    for (int i = 0; i < DIGEST_SIZE; i++) {
        printf("%02x", hash1[i]);
    }
    printf("\n");

    printf("SHA-40 Hash of 'James': ");
    for (int i = 0; i < DIGEST_SIZE; i++) {
        printf("%02x", hash2[i]);
    }
    printf("\n");

    printf("SHA-40 Hash of 'Ahmed': ");
    for (int i = 0; i < DIGEST_SIZE; i++) {
        printf("%02x", hash3[i]);
    }
    printf("\n");

    printf("SHA-40 Hash of 'CSEC': ");
    for (int i = 0; i < DIGEST_SIZE; i++) {
        printf("%02x", hash4[i]);
    }
    printf("\n");

    printf("SHA-40 Hash of 'Jake': ");
    for (int i = 0; i < DIGEST_SIZE; i++) {
        printf("%02x", hash5[i]);
    }
    printf("\n");

    // PART B

    // PART C

    return 0;
}
