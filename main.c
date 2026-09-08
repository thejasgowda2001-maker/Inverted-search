/*
*Name : Thejas
*Date : Mon 10 sep 2025 14:00:05 IST
*File : main.c
*/

#include "inverted_Search.h"

int main(int argc , char *argv[])
{
    system("clear");

    // 27 heads: 26 for 'a'-'z', 1 for non-alphabetic
    Wlist *head[27] = {NULL};    

    // Input validation
    if(argc <= 1)
    {
        printf("Enter valid number of arguments\n");
        printf("./a.out file1.txt file2.txt ...\n");
        return 0;
    }

    // Create file linked list
    Flist *f_head = NULL;
    file_validation_n_file_list(&f_head , argv);

    if(f_head == NULL)
    {
        printf("No valid files added to file linked list\n");
        printf("Terminating the process.\n");
        return 1;
    }

    int choice;
    char option;

    do
    {
        printf("\nSelect your choice among the following options:\n");
        printf("1. Create DATABASE\n");
        printf("2. Display DATABASE\n");
        printf("3. Update DATABASE\n");
        printf("4. Search Word in DATABASE\n");
        printf("5. Save DATABASE to File\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                if (choice == 1)
                {
                   create_database(f_head, head);
                   printf("-----------------------------\n");
                   printf("DATABASE created successfully\n");
                   printf("-----------------------------\n");
                }
                else
                {
                   printf("Something went wrong\n");
                }
                break;

            case 2:
                display_database(head);
                break;

            case 3:
                if (update_database(head, &f_head) == SUCCESS)
                {
                    printf("-------------------------------\n");
                    printf("DATABASE updated successfully.\n");
                    printf("-------------------------------\n");
                }
                else
                {
                    printf("Failed to update the database.\n");
                }
                break;

            case 4:
                search_word(head);
                break;

            case 5:
                save_database(head);
                printf("----------------------------\n");
                printf("DATABASE saved successfully\n");
                printf("----------------------------\n");
                break;

            case 6:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }

        printf("\nDo you want to continue? (y/n): ");
        scanf(" %c", &option);

    } while(option == 'y' || option == 'Y');

    return 0;
}
