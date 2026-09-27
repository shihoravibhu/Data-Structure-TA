// 88. Implement a Dictionary (key, value) pair using Hash-table. 

#include <stdio.h>

#define SIZE 20

struct Dict
{
    int key;
    int value;
};

struct Dict hashMap[SIZE];

void init()
{
    for(int i = 0; i < SIZE; i++)
    {
        hashMap[i].key = -1;   // Empty slot
    }
}

int hashFunction(int key)
{
    return key % SIZE;
}

void put(int key, int value)
{
    int idx = hashFunction(key);

    while(hashMap[idx].key != -1 &&
          hashMap[idx].key != key)
    {
        idx = (idx + 1) % SIZE;   // Linear probing
    }

    hashMap[idx].key = key;
    hashMap[idx].value = value;
}

int get(int key)
{
    int idx = hashFunction(key);

    while(hashMap[idx].key != -1)
    {
        if(hashMap[idx].key == key)
        {
            return hashMap[idx].value;
        }

        idx = (idx + 1) % SIZE;
    }

    return -1;   // Not found
}

void display()
{
    for(int i = 0; i < SIZE; i++)
    {
        if(hashMap[i].key != -1)
        {
            printf("(%d , %d)\n",
                   hashMap[i].key,
                   hashMap[i].value);
        }
    }
}

int main()
{
    init();

    put(1, 10);
    put(2, 20);
    put(22, 40);

    display();

    printf("Value of key 22 = %d\n",
           get(22));

    return 0;
}

// or

// #include <stdio.h>
// #include <stdbool.h>
// #include <stdlib.h>

// #define SIZE 20   // size of hash table

// // Structure to store key-value pair
// struct Dict {
//     int key;
//     int value;
// };

// // Hash table (array of pointers to Dict)
// struct Dict* hashMap[SIZE];

// // Initialize hash table with NULL
// void init() {
//     for (int i = 0; i < SIZE; i++) {
//         hashMap[i] = NULL;
//     }
// }

// // Hash function (maps key to index)
// int hashFunction(int key) {
//     return (key % 18) + 2;   // simple hash
// }

// // Insert or update (key, value) pair
// bool put(int key, int value) {
//     int index = hashFunction(key);

//     // Create new key-value pair
//     struct Dict* newPair = (struct Dict*)malloc(sizeof(struct Dict));
//     newPair->key = key;
//     newPair->value = value;

//     // Case 1: Empty slot
//     if (hashMap[index] == NULL) {
//         hashMap[index] = newPair;
//         return true;
//     }
//     // Case 2: Same key exists → update value
//     else if (hashMap[index]->key == key) {
//         hashMap[index]->value = value;
//         free(newPair);  // free unused node
//         return true;
//     }
//     // Case 3: Collision → linear probing
//     else {
//         int i = (index + 1) % SIZE;
//         for (int prob = 1; prob < SIZE; prob++) {
//             if (hashMap[i] == NULL) { // empty slot found
//                 hashMap[i] = newPair;
//                 return true;
//             }
//             else if (hashMap[i]->key == key) { // update value
//                 hashMap[i]->value = value;
//                 free(newPair);
//                 return true;
//             }
//             else {
//                 i = (i + 1) % SIZE;  // keep probing
//             }
//         }
//     }

//     // Table full → insertion failed
//     free(newPair);
//     return false;
// }

// // Print the entire hash table
// void printHashTable() {
//     for (int i = 0; i < SIZE; i++) {
//         if (hashMap[i] != NULL) {
//             printf("Index: %d -> (Key: %d, Value: %d)\n", i, hashMap[i]->key, hashMap[i]->value);
//         }
//         else {
//             printf("Index: %d -> NULL\n", i);
//         }
//     }
// }

// // Main function
// int main() {
//     init();

//     // Insert some (key, value) pairs
//     put(1, 10);
//     put(2, 20);
//     put(3, 30);
//     put(22, 40);   // collision with 2 → linear probing
//     put(42, 50);   // collision with 2 & 22 → more probing
//     put(2, 200);   // update existing key

//     // Print hash table
//     printHashTable();

//     return 0;
// }
