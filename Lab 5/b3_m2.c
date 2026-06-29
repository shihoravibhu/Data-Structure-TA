#include<stdio.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>

void main(){

    char words[5][50];

    for(int i= 0 ; i < 5 ; i++){

        printf("Enter Word %d" , i+1);
        scanf(" %[^\n]" , words[i]);

    }

    char anagram[50];

    printf("Enter Anagram :");
    scanf(" %[^\n]" , anagram);

    srand(time(NULL));

    int random = rand() % 5;

    printf("Word is : %s\n", words[random]);

    if(strlen(anagram) != strlen(words[random])){
        printf("Not Found");
        return;
    }

    int sum = 0;

    for(int i = 0 ; i < strlen(words[random]) ; i++){
        int found = 0;
        for(int j = 0 ; j < strlen(anagram) ; j++){

            if(words[random][i] == anagram[j]){
                anagram[j] = ' ';
                found = 1;
                sum++;
                break;
            }
        }

        if(found == 0){
            printf("Not Found");
            return;
        }


    }

    if(sum == strlen(words[random])){
        printf("ok");
    }


    
}