#include<stdio.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

void main(){

    char words[5][50];

    for(int i= 0 ; i < 5 ; i++){

        printf("Enter Word %d : " , i+1);
        scanf("%s" , words[i]);

    }

    char anagram[50];

    printf("Enter Anagram :");
    scanf("%s" , anagram);

    srand(time(NULL));

    int random = rand() % 5;

    printf("Index is : %d\n", random);
    printf("Word is : %s\n", words[random]);

    if(strlen(anagram) != strlen(words[random])){
        printf("Not Found");
        return;
    }

    
    int chArray[26] = {0};

    for(int i = 0 ; i < strlen(words[random]) ; i++){

        char ch = words[random][i];
        ch = toupper(ch);

        chArray[ch-'A']++;
        
    }

    int chArray2[26] = {0};

    for(int i = 0 ; i < strlen(anagram) ; i++){

        char ch = anagram[i];
        ch = toupper(ch);

        chArray2[ch-'A']++;

    }

    for(int i = 0 ; i < 26 ; i++){
       
        if(chArray[i] != chArray2[i]){
            printf("\nNot Anagram");
            return;
        }

    }
    
    printf("\nAnagram");

    
}