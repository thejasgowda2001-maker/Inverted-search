#include "inverted_Search.h"

void display_database(Wlist *head[])
{
    printf("\n[Index]    [key]      File_function     File_Name -> key_function\n");
    printf("---------------------------------------------------------------\n");

    for (int i = 0; i < 27; i++)
    {
        if (head[i] != NULL)
        {
            print_word_count(head[i]);
        }
    }
}

int print_word_count(Wlist *head)
{
    while (head)
    {
        // Calculate and print the index
        int index = tolower(head->word[0]) - 'a';
        if (index < 0 || index > 25)
            index = 26;

        printf("[%2d]      %-10s   %3d file(s)   ", index, head->word, head->file_count);

        Ltable *Thead = head->Tlink;

        while (Thead)
        {
            printf("%s -> %d   ", Thead->file_name, Thead->word_count);
            Thead = Thead->table_link;  // fixed: changed from table_link to link
        }

        printf("\n");

        head = head->link;
    }

    return SUCCESS;
}

