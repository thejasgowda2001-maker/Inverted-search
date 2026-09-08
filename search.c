/***************************************************************************************************************************************************
*Author         :HP
*Date           : 10 sep 2025 
*File           :search.c
*Title          :To search the words.
*Description    :Each word is now used to search in the linkedlist. The word has to be compared with
		:each word in the linked list. When found, the file details can be retrieved. Since the
		:linkedlist is in sorted order, the complexity of searching the word in the complete list
		:can be avoided. While string comparison, if the word in linkedlist is greater than the
		:word to be search, it shows the word doesnt exists in the list,
   */

   #include "inverted_search.h"

// Prompt the user and call search
void search_word(Wlist *head[])
{
    char word[WORD_SIZE];
    printf("Enter the word to search: ");
    scanf("%s", word);
    search(head, word);
}

// Search for a word in the hash table and print its file occurrences
int search(Wlist *head[], char *word)
{
    if (word == NULL)
        return FAILURE;

    int index = hash_function(word);
    if (index < 0 || index >= 27) // 26 for a-z + 1 for non-alpha
        return FAILURE;

    Wlist *curr = head[index];

    while (curr != NULL)
    {
        if (strcmp(curr->word, word) == 0)
        {
            printf("Word \"%s\" found in %d file(s):\n", word, curr->file_count);
            Ltable *lt = curr->Tlink;
            while (lt != NULL)
            {
                printf("  File: %s, Count: %d\n", lt->file_name, lt->word_count);
                lt = lt->table_link;
            }
            return SUCCESS;
        }
        curr = curr->link;
    }

    printf("Word \"%s\" not found in database.\n", word);
    return FAILURE;
}

// Simple hash function assuming only lowercase letters a-z
int hash_function(const char *word)
{
    if (word == NULL || word[0] == '\0')
        return -1;

    char ch = tolower(word[0]);
    if (ch < 'a' || ch > 'z')
        return 26; // Use last index for non-alpha characters

    return ch - 'a';
}
