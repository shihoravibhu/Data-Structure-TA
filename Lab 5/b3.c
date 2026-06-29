// Design anagram game using array.
// • Allow a user to enter N words and store it in an array.
// • Generate a random number between 0 to N-1.
// • Based on the random number generated display the word stored at that
// index of an array and allow user to enter its anagram.
// • Check whether the word entered by the user is an anagram of displayed
// number or not and display an appropriate message.
// • Given a word A and word B. B is said to be an anagram of A if and only if
// the characters present in B is same as characters present in A,

// irrespective of their sequence. For ex: “LISTEN” == “SILENT”

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void main()
{

    int n;
    printf("Enter numbers of words :");
    scanf("%d", &n);

    char ch[n][100];

    for (int i = 0; i < n; i++)
    {
        printf("Enter Words ch[%d] :", i);
        scanf(" %[^\n]s", ch[i]);
    }

    srand(time(NULL));
    int random = rand() % n;
    printf("%s\n", ch[random]);

    char anagram[100];

    printf("Enter anagram : ");
    scanf(" %[^\n]s", anagram);

    int len = strlen(ch[random]);
    int length_anagram = strlen(anagram);

    int sum = 0;

    /* This part of the code is checking if the length of the randomly selected word (`len`) is equal
    to the length of the user-inputted word (`length_anagram`). If the lengths are equal, it then
    iterates over each character of the selected word and tries to find a matching character in the
    user-inputted word. */
    if (len == length_anagram)
    {
        for (int i = 0; i < len; i++)
        {
            int found = 0;

            for (int j = 0; j < len; j++)
            {

                if (ch[random][i] == anagram[j])
                {
                    anagram[j] = ' ';
                    sum++;
                    found = 1;
                    break;
                }
            }

            if (!found)
            {
                break;
            }
        }
        if (sum == len)
        {
            printf("Right It's Anagram\n");
        }
        else
        {
            printf("Not Anagram\n");
        }
    }

    else
    {
        printf("Not Anagram\n");
    }
}