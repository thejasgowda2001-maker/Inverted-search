#include "inverted_Search.h"


// using extern try using filename inside this file 
extern char *fname;


int insert_at_last(Wlist **head, data_t *data)
{
    //create a node 
    Wlist *new = malloc(sizeof(Wlist));
    if(new == NULL)
    {
        return e_false;
    }
    new->file_count = 1;
    strcpy(new->word,data);
    new->Tlink = NULL;
    new->link = NULL;

    //call fun() to update link table 

    update_link_table(&new);

    //check Wlist is empty or not
    if(*head == NULL)
    {
        *head = new;
        return SUCCESS;
    }
    //non - empty 

    Wlist *temp = *head;
    while(temp->link)
    {
        temp = temp->link;
    }

    temp->link = new;
    return SUCCESS;

}

int update_link_table(Wlist **head)
{
    //create Ltable node

    Ltable *new = malloc(sizeof(Ltable));
    if(new == NULL)
    {
        return e_false;
    }
    new->word_count = 1;
    strcpy(new->file_name ,fname); 
    new->table_link = NULL;

    (*head) ->Tlink = new;
    return SUCCESS;

}
