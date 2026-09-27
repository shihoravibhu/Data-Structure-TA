// 86. In an array of 20 elements, arrange 15 different values, which are generated 
// randomly between 1,00,000 to 9,99,999. Use hash function to generate key and 
// linear probing to avoid collision. H(x) = (x mod 18) + 2. Write a program to input 
// and display the final values of array. 

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>   

#define SIZE 20     // size hash table ni

int hashSet[SIZE];

// Empty initialization karva mate
void init() {

    for (int i = 0; i < SIZE; i++) {
        hashSet[i] = -1;
    }

}

int hashFunction(int key) {
    // ahiya apde hash function H(x) = (x mod 18) + 2 use kariye chiye
    return (key % 18) + 2;
}

bool add(int key) {
    
    int index = hashFunction(key);

    // Case 1: Empty slot che
    if (hashSet[index] == -1) {
        hashSet[index] = key;
        return true;
    }
    // Case 2: Duplicate key means apde insert nai kariee
    else if (hashSet[index] == key) {
        return false;
    }
    // Case 3: Collision Thayu To linear probing
    else {
        int i = (index + 1) % SIZE;

        for (int prob = 1; prob < SIZE; prob++) {

            if (hashSet[i] == -1) {       // empty slot madio
                hashSet[i] = key;
                return true;
            }

            else if (hashSet[i] == key) { // duplicate found thayo 
                return false;
            }

            else {
                i = (i + 1) % SIZE;       // keep probing
            }
        }
    }
    return false; 

    // return false means table full thai gyu che em
}

bool contains(int key) {

    int index = hashFunction(key);

    if (hashSet[index] == -1) {
        return false;
    }
    else if (hashSet[index] == key) {
        return true;
    }
    else {

        // Linear probing thi

        int i = (index + 1) % SIZE;
        
        for (int prob = 1; prob < SIZE; prob++) {

            if (hashSet[i] == -1) {
                return false;  // not found
            }
            else if (hashSet[i] == key) {
                return true;   // found
            }
            else {
                i = (i + 1) % SIZE;
            }
        }
    }
    return false;
}

// or

// bool find(int key)
// {
//     int idx = hashFunction(key);

//     for(int i = 0; i < SIZE; i++)
//     {
//         int pos = (idx + i) % SIZE;

//         if(hashSet[pos] == -1)
//             return false;

//         if(hashSet[pos] == key)
//             return true;
//     }

//     return false;
// }

void display() {

    printf("\nFinal Hash Table:\n");

    for (int i = 0; i < SIZE; i++) {

        if (hashSet[i] == -1)
            printf("Index %2d -> EMPTY\n", i);
        else
            printf("Index %2d -> %d\n", i, hashSet[i]);

    }
}

void main() {
    srand(time(NULL));   
    init();

    int count = 0;

    // ahoya apde random 15 different values generate karva mate loop chalu kariye chiye
    while (count < 15) {

        int num = (rand() % (999999 - 100000 + 1)) + 100000;

        if (add(num)) {
            count++;
        }

    }

    if (contains(123456)) {
        printf("\n123456 -> Found!\n");
    } else {
        printf("\n123456 -> Not Found!\n");
    }

    display();

}