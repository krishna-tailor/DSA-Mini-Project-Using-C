#include <stdio.h>
#include <stdlib.h>

void menu();
void loadDoctor();
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
            loadDoctor();
            break;

        case 2:
            system("clear");
            break;

        case 7:
            system("clear");
            printf("Exiting....\n");
            break;

        default:
        system("clear");
        printf("<<<<< Invalid Choice >>>>>>\n");
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

 void loadDoctor()                                           
    {                                                           
        FILE *fp = fopen("Doctors.txt", "a");                   
        char name[200];                                         
        int n;                                                  
        printf("Enter Number Of Doctors To Enter At A Time: "); 
        scanf("%d", &n);                                        
        getchar();                                              
        for (int i = 0; i < n; i++)                             
        {                                                       
                                                                
            printf("Enter Name Of Doctor %d: ", i + 1);         
            fgets(name,200,stdin);                            
            fprintf(fp, "Name: %s", name);                    
        }                                                       
        fclose(fp);                                             
        system("clear");                                        
        printf("<<<<<<< Details Sotred SuccessFully <<<<<<<\n\n"); 
        printf("\n////////////////////////////////////////////////////////"); 
    }

