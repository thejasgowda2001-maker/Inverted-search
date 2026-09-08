#include"inverted_Search.h"

void file_validation_n_file_list(Flist **f_head, char *argv[])
{
    //loop
    int i= 1 , empty ;
    while(argv[i] != NULL)
    {
        empty = isFileEmpty(argv[i]);
        if(empty == FILE_NOTAVAILABLE)
        {
            printf("File : %s is not available\n" , argv[i]);
            printf("Hence we are not adding that file into file linked list\n");
            i++;
            continue;
        }
        else if(empty == FILE_EMPTY)
        {
            printf("File : %s is not having contents\n" , argv[i]);
            printf("Hence we are not adding that file into file linked list\n");
            i++;
            continue;
        }
        else
        {
            int ret_val = to_create_list_of_files(f_head , argv[i]);
            if(ret_val == SUCCESS)
            {
                printf("Successfully inserted the file %s into file linked list\n", argv[i]);
            }
            else if(ret_val == REPEATATION)
            {
                printf("This file %s is repeated , hence we are not adding that file into file linked list\n" ,argv[i]);
            }
            else
            {
                printf("Failure\n");
            }
            i++;
            continue;
        }
    }
}

//check for file availability and file contents
int isFileEmpty(char *filename)
{
    FILE *fp = fopen(filename, "r");
    if (fp == NULL)
        return FILE_NOTAVAILABLE;

    fseek(fp, 0, SEEK_END);
    int size = ftell(fp);
    fclose(fp);

    if (size == 0)
        return FILE_EMPTY;

    return SUCCESS;
}


int isfileexist(char *filename)
{
    FILE *fp = fopen(filename, "r");
    if (fp)
    {
        fclose(fp);
        return 1;  // File exists
    }
    return 0;      // File does not exist
}


int to_create_list_of_files(Flist **f_head, char *name)
{
    // Check for repetition
    Flist *temp = *f_head;
    while (temp != NULL)
    {
        if (strcmp(temp->file_name, name) == 0)
        {
            return REPEATATION;
        }
        temp = temp->link;
    }

    // Create a new node
    Flist *new = malloc(sizeof(Flist));
    if (new == NULL)
        return FAILURE;

    strcpy(new->file_name, name); // Allocate and copy string
    new->link = NULL;

    // Insert at end
    if (*f_head == NULL)
    {
        *f_head = new;
    }
    else
    {
        temp = *f_head;
        while (temp->link != NULL)
            temp = temp->link;
        temp->link = new;
    }

    return SUCCESS;
}

#include "inverted_search.h"

int isFileValid(char *filename)
{
    FILE *fp = fopen(filename, "r");
    if (fp == NULL)
    {
        return FAILURE;
    }
    fclose(fp);
    return SUCCESS;
}

int isFileDuplicate(Flist **f_head, char *filename)
{
    Flist *temp = *f_head;
    while (temp != NULL)
    {
        if (strcmp(temp->file_name, filename) == 0)
        {
            return SUCCESS; // duplicate found
        }
        temp = temp->link;
    }
    return FAILURE; // no duplicate
}


int insert_at_last_file(Flist **f_head, char *filename)
{
    Flist *new = malloc(sizeof(Flist));
    if (new == NULL)
        return FAILURE;

    strcpy(new->file_name, filename);
    new->link = NULL;

    if (*f_head == NULL)
    {
        *f_head = new;
        return SUCCESS;
    }

    Flist *temp = *f_head;
    while (temp->link != NULL)
    {
        temp = temp->link;
    }
    temp->link = new;

    return SUCCESS;
}

