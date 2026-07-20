#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    char songName[100];
    struct Node *lptr;
    struct Node *rptr;
};

struct Node *FIRST = NULL;
struct Node *CURRENT = NULL;

void addSong(char song[])
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    strcpy(newNode->songName, song);

    if (FIRST == NULL)
    {
        newNode->lptr = newNode;
        newNode->rptr = newNode;

        FIRST = newNode;
        CURRENT = newNode;

        return;
    }

    struct Node *last = FIRST->lptr;

    newNode->rptr = FIRST;
    newNode->lptr = last;

    last->rptr = newNode;
    FIRST->lptr = newNode;
}

int countSongs()
{
    if (FIRST == NULL)
    {
        return 0;
    }

    int cnt = 0;

    struct Node *save = FIRST;

    do
    {
        cnt++;
        save = save->rptr;

    } while (save != FIRST);

    return cnt;
}

void display()
{
    if (FIRST == NULL)
    {
        printf("Playlist Is Empty\n");
        return;
    }

    struct Node *save = FIRST;

    do
    {
        printf("%s -> ", save->songName);
        save = save->rptr;

    } while (save != FIRST);

    printf("%s\n", save->songName);
}

void playCurrent()
{
    if (CURRENT == NULL)
    {
        printf("Playlist Is Empty\n");
        return;
    }

    printf("Now Playing : %s\n", CURRENT->songName);
}

void playNext()
{
    if (CURRENT == NULL)
    {
        printf("Playlist Is Empty\n");
        return;
    }

    CURRENT = CURRENT->rptr;

    printf("Now Playing : %s\n", CURRENT->songName);
}

void playPrevious()
{
    if (CURRENT == NULL)
    {
        printf("Playlist Is Empty\n");
        return;
    }

    CURRENT = CURRENT->lptr;

    printf("Now Playing : %s\n", CURRENT->songName);
}

void searchSong(char song[])
{
    if (FIRST == NULL)
    {
        printf("Playlist Is Empty\n");
        return;
    }

    struct Node *save = FIRST;

    do
    {
        if (strcmp(save->songName, song) == 0)
        {
            printf("Song Found\n");
            return;
        }

        save = save->rptr;

    } while (save != FIRST);

    printf("Song Not Found\n");
}

void deleteAtFront()
{
    if (FIRST == NULL)
    {
        printf("Playlist Is Empty\n");
        return;
    }

    // Jyare Ek J Node Hase To Te Delete Karva Mate
    if (FIRST->rptr == FIRST)
    {
        free(FIRST);
        FIRST = NULL;
        CURRENT = NULL;
        return;
    }

    struct Node *last = FIRST->lptr;
    struct Node *temp = FIRST;

    FIRST = FIRST->rptr;

    FIRST->lptr = last;
    last->rptr = FIRST;

    if (CURRENT == temp)
    {
        CURRENT = FIRST;
    }

    free(temp);

    printf("First Song Deleted\n");
}

void main()
{
    int choice;
    char song[100];

    while (1)
    {
        printf("\n1. Add Song\n");
        printf("2. Display Playlist\n");
        printf("3. Play Current Song\n");
        printf("4. Play Next Song\n");
        printf("5. Play Previous Song\n");
        printf("6. Search Song\n");
        printf("7. Delete First Song\n");
        printf("8. Count Songs\n");
        printf("9. Exit\n");

        printf("Enter Your Choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            getchar();
            printf("Enter Song Name : ");
            fgets(song, sizeof(song), stdin);
            song[strcspn(song, "\n")] = '\0';
            addSong(song);
            break;

        case 2:
            display();
            break;

        case 3:
            playCurrent();
            break;

        case 4:
            playNext();
            break;

        case 5:
            playPrevious();
            break;

        case 6:
            getchar();
            printf("Enter Song Name : ");
            fgets(song, sizeof(song), stdin);
            song[strcspn(song, "\n")] = '\0';
            searchSong(song);
            break;

        case 7:
            deleteAtFront();
            break;

        case 8:
            printf("Total Songs : %d\n", countSongs());
            break;

        case 9:
            return;

        default:
            printf("Invalid Choice\n");
        }
    }
}