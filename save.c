/*
*Author         :Hp
*Date           : 10 sep 2025 14:15:06 IST
*File           :save.c
*Title          :To store the words one by one
*Description    :This function saves the word by word
*/
#include "inverted_search.h"

// Function to save the entire database (array of Wlist* heads) into a file
int save_database(Wlist *head[])
{
    FILE *databasefile = fopen("database.txt", "w");
    if (!databasefile)
    {
        perror("Failed to open database file");
        return FAILURE;
    }

    // Iterate over each hash bucket
    for (int i = 0; i < 26; i++)  // Assuming 26 buckets for letters a-z
    {
        Wlist *curr = head[i];
        while (curr != NULL)
        {
            write_databasefile(curr, &databasefile);
            curr = curr->link;
        }
    }

    fclose(databasefile);
    return SUCCESS;
}

// Function to write a single word node and its link table info to file
void write_databasefile(Wlist *head, FILE **databasefile)
{
    if (head == NULL || databasefile == NULL || *databasefile == NULL)
        return;

    // Write the word and file_count
    fprintf(*databasefile, "%s %d\n", head->word, head->file_count);

    // Write the link table entries for this word
    Ltable *lt = head->Tlink;
    while (lt != NULL)
    {
        fprintf(*databasefile, "%s %d\n", lt->file_name, lt->word_count);
        lt = lt->table_link;
    }

    // Use a separator line for clarity between words
    fprintf(*databasefile, "#\n");
}
