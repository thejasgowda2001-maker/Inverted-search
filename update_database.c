#include "inverted_Search.h"

int update_database(Wlist *head[], Flist **f_head)
{
    char file_name[FNAME_SIZE];

    // prompt user for new file
    printf("Enter the new file name: ");
    scanf("%s", file_name);

    // validate the file
    if (isFileValid(file_name) == FAILURE)
    {
        printf("Error: %s is not a valid file\n", file_name);
        return FAILURE;
    }

    // check duplicate file
    if (isFileDuplicate(f_head, file_name) == SUCCESS)
    {
        printf("Error: %s is already present in database\n", file_name);
        return FAILURE;
    }

    // add that file to file linked list
    if (insert_at_last_file(f_head, file_name) == FAILURE)
    {
        printf("Error: failed to insert %s into file list\n", file_name);
        return FAILURE;
    }

    // create database for the new file only
    Flist *temp = *f_head;
    while (temp != NULL)
    {
        if (strcmp(temp->file_name, file_name) == 0)
        {
            create_database(temp, head);
            break;
        }
        temp = temp->link;
    }

    return SUCCESS;
}