#include "inverted_search.h"  // Make sure filename matches exactly

char *fname;

void create_database(Flist *f_head, Wlist *head[])
{
    // Traverse through the file linked list 
    while (f_head)
    {
        read_datafile(f_head, head, f_head->file_name);
        f_head = f_head->link;
    }
}

int read_datafile(Flist *file, Wlist *head[], char *filename)
{
    fname = filename;
    int flag = 0;

    // Open the file in read mode 
    FILE *fptr = fopen(filename, "r");
    if (fptr == NULL)
    {
        perror("File open error");
        return FAILURE;
    }

    char word[WORD_SIZE];

    while (fscanf(fptr, "%s", word) != EOF)
    {
        // Convert first character to lowercase and find index
        int index = tolower(word[0]) - 'a';

        // For non-alphabetic, use last bucket 26
        if (!(index >= 0 && index <= 25))
            index = 26;

        flag = 0;  // Reset flag for each word

        // Check if the word already exists in linked list at index
        if (head[index] != NULL)
        {
            Wlist *temp = head[index];
            while (temp)
            {
                if (strcmp(temp->word, word) == 0)
                {
                    update_word_count(&temp, filename);
                    flag = 1;
                    break;
                }
                temp = temp->link;
            }
        }

        // Insert new word if not found
        if (flag == 0)
        {
            insert_at_last(&head[index], word);
        }
    }

    fclose(fptr);
    return SUCCESS;
}
//updating word count
int update_word_count(Wlist **head, char *file_name)
{
    Ltable *temp = (*head)->Tlink;

    while (temp)
    {
        if (strcmp(temp->file_name, file_name) == 0)
        {
            // File already exists for this word, increase word count
            temp->word_count += 1;
            return SUCCESS;
        }
        temp = temp->table_link;  // Correct the pointer name 
    }

    // New file for this word -> create the new L table node
    Ltable *new_node = malloc(sizeof(Ltable));
    if (new_node == NULL)
        return FAILURE;

    new_node->word_count = 1;
    strcpy(new_node->file_name, file_name);  // Use the stringcopy to copy the string

    // Insert at beginning of the linked list
    new_node->table_link = (*head)->Tlink;
    (*head)->Tlink = new_node;

    (*head)->file_count += 1;

    return SUCCESS;
}
