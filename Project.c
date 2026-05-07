#include <stdio.h>
#include <stdlib.h>
#include "my-header.h"

void menu();
int main()
{
    system("cls");
    int choice;
    do
    {
        menu(&choice);
        scanf("%d", &choice);
        printf("+------------------------------------------------------------+\n");

        switch (choice)
        {
        case 1:
            system("clear");
            load_doctor();
            break;

        case 2:
            system("clear");
            break;

        default:
            break;
        }

    } while (choice != 7);
}

void menu()
{
    printf("\n");
    printf("+------------------------------------------------------------+\n");
    printf("|             HOSPITAL MANAGEMENT SYSTEM                     |\n");
    printf("+------------------------------------------------------------+\n");
    printf("| 1. Load Doctors                                            |\n");
    printf("| 2. Add Patient                                             |\n");
    printf("| 3. Serve Patient                                           |\n");
    printf("| 4. Display Waiting Patients                                |\n");
    printf("| 5. Undo Last Served Patient                                |\n");
    printf("| 6. Save Patient History                                    |\n");
    printf("| 7. Exit                                                    |\n");
    printf("+------------------------------------------------------------+\n");
    printf("  Enter Your Choice : ");
}