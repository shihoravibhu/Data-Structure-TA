// 87. Implement Hash set.

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define size 10

int hashSet[size];


void init()
{

    for (int i = 0; i < size; i++)
    {
        hashSet[i] = -1;
    }
}

int hashFunction(int key)
{

    return key % size;
}

bool add(int key)
{

    int idx = hashFunction(key);

    if (hashSet[idx] == -1)
    {
        hashSet[idx] = key;
        return true;
    }
    else if (hashSet[idx] == key)
    {
        printf("Duplicate Value Cannot Insert.\n");
        return false;
    }
    else
    { // colision linear probing

        idx = (idx + 1) % size;

        for (int prob = 2; prob < size; prob++)
        {
            if (hashSet[idx] == -1)
            {
                hashSet[idx] = key;
                return true;
            }
            else if (hashSet[idx] == key)
            {
                printf("Duplicate Value Cannot Insert.\n");
                return false;
            }
            else{
                idx = (idx + 1) % size;
            }
        }
    }
    return false; // full the table
}

bool find(int key)
{
    int idx = hashFunction(key);

    for(int i = 0; i < size; i++)
    {
        int pos = (idx + i) % size;

        if(hashSet[pos] == -1)
            return false;

        if(hashSet[pos] == key)
            return true;
    }

    return false;
}

void main(){

    init();

    add(1);
    add(2);
    add(12); // collision with 2
    add(22); // collision with 12

    printf("Find 1: %s\n", find(1) ? "Found" : "Not Found");
    printf("Find 2: %s\n", find(2) ? "Found" : "Not Found");
    printf("Find 12: %s\n", find(12) ? "Found" : "Not Found");
    printf("Find 22: %s\n", find(22) ? "Found" : "Not Found");
    
}