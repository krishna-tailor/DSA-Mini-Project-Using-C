#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Patient
{
    int age, Token_number;
    char Name[200], Diseas[200], Doctor_choice[200];
} P;

void menu();
void loadDoctor();
void Patinet_Information();

void delete_doctor(char doctor[100]); // Removing Doctor After Getting Hireed
int check_doctor(char Doctor[100]);   // Checking Doctor If Available For Hireing

int main()
{
    system("cls");
    int choice;
    do
    {
        menu();
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
            Patinet_Information();
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

// ============= Loading Name Of Doctors In File =============

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
        scanf(" %[^\n]", name);
        fprintf(fp, "Name: %s\n", name);
    }
    fclose(fp);
    system("clear");
    printf("<<<<<<< Details Sotred SuccessFully <<<<<<<\n");
    printf("\n////////////////////////////////////////////////////////\n\n");
}

// ============= Taking Patient Information Without validaion =============

void Patinet_Information()
{
    int flag = 0;
    P p, temp;
    p.Token_number = 100; // Starting Token From 101 If File Is Empty
    char name[200];

    FILE *fp = fopen("Doctors.txt", "r");
    FILE *fp1;

    getchar();

    // ============= Taking Patient Information =============
    printf("Enter Name Of Patient: ");
    fgets(p.Name, 200, stdin);

    printf("Enter Age Of Patient: ");
    scanf("%d", &p.age);

    getchar();
    printf("Enter Diesase Of Patient: ");
    fgets(p.Diseas, 200, stdin);

    // ============= Printing Name Of Doctor For Hireing =============

    while ((fscanf(fp, "Name: %[^\n]\n", name) != EOF))
    {
        if (flag == 0)
            printf("\n<<<<<  DOCTORS AVAILABLE >>>>>\n");

        flag = 1;
        printf("Dr.%s\n", name);
        printf("\n----------------------\n");
    }
    printf("\n\n");
    fclose(fp);

    if (flag == 0)
    {
        printf("\n<<<<<  NO DOCTORS AVAILABLE >>>>>");
        printf("\n\n////////////////////////////////////////////////////////\n\n");
        return;
    }

    else
    {
        printf("Enter Name Of Doctor To Hire: ");
        scanf("%[^\n]",p.Doctor_choice);

        if (check_doctor(p.Doctor_choice) == 0) // This Function Is After The Funciton Patient Information Funciton
        {
            printf("\n-------- Name Of Doctor Is Improper --------");
            printf("\n\n////////////////////////////////////////////////////////\n\n");
            return;
        }
    }
    
    // ========= Storing The Data Of Patient In File Using Token System =========
    
    fp1 = fopen("Appointment.txt", "r");
    while ((fscanf(fp1, "Token No: %d \nPatient Name: %[^\n]\nPatient Age: %d \nPatient Disease: %[^\n]\nDoctor Name: Dr.%[^\n]\n\n", &temp.Token_number, temp.Name, &temp.age, temp.Diseas, temp.Doctor_choice) != EOF))
    {
        if (temp.Token_number > p.Token_number)
        p.Token_number = temp.Token_number;
    }
    fclose(fp1);
    p.Token_number++; // Increasing Token Number By One
    
    fp1 = fopen("Appointment.txt", "a");
    fprintf(fp1, "Token No: %d \nPatient Name: %sPatient Age: %d \nPatient Disease: %sDoctor Name: Dr.%s\n\n", p.Token_number, p.Name, p.age, p.Diseas, p.Doctor_choice);
    fclose(fp1);
    
    delete_doctor(p.Doctor_choice);
    

    printf("\n\n////////////////////////////////////////////////////////\n\n");
}

//  ========= Function To Check Name Of Doctor If Enterd Correctly Or Not =========

int check_doctor(char Doctor[100])
{
    char name[100];
    FILE *fp2;

    fp2 = fopen("Doctors.txt", "r");
    if (fp2 == NULL)
    {
        printf("\nEnter In Opening File\n");
        exit(0);
    }

    while ((fscanf(fp2, "Name: %[^\n]\n", name) != EOF))
    {
        printf("%d %d ",strlen(name),strlen(Doctor));
        if (strcmp(name, Doctor) == 0)
        {
            printf("%s\n", name);
            fclose(fp2);
            return 1;
        }
    }
    fclose(fp2);
    return 0;
}

//  ========= Function To Delete A Doctor Temporar From File After Geting Hired =========

void delete_doctor(char doctor[100])
{
    FILE *fp1, *fp2;
    char name[100];

    fp1 = fopen("Copy_Doctor.txt", "a");
    fp2 = fopen("Doctors.txt", "r");

    while ((fscanf(fp2, "Name: %[^\n]\n", name) != EOF))
    {
        if (strcmp(name, doctor) != 0)
        {
            fprintf(fp1, "Name: %s\n", name);
        }
    }
    fclose(fp1);
    fclose(fp2);
    remove("Doctors.txt");
    rename("Copy_Doctor.txt","Doctors.txt");
}
