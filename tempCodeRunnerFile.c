#include <stdio.h>
#include <stdlib.h>
#include"my-header.h"

void menu(int *choice);
int main()
{
    system("cls");
    int choice;
    menu(&choice);

    switch (choice)
    {
    case 1:
        load_doctor();
        break;
    
    default:
        break;
    }


}

void menu(int *choice)
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
    printf("| Enter Your Choice :                                        |\n");
    scanf("%d",&choice);
    printf("+------------------------------------------------------------+\n");
}