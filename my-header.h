#define load_doctor()                                           \
    {                                                           \
        FILE *fp = fopen("Doctors.txt", "a");                   \
        char name[200];                                         \
        int n;                                                  \
        printf("Enter Number Of Doctors To Enter At A Time: "); \
        scanf("%d", &n);                                        \
        getchar();                                              \
        for (int i = 0; i < n; i++)                             \
        {                                                       \
                                                                \
            printf("Enter Name Of Doctor %d: ", i + 1);         \
            scanf(" %[^\n]", name);                             \
            fprintf(fp, "Name: %s\n", name);                    \
        }                                                       \
        fclose(fp);                                             \
        system("clear");                                        \
        printf("<<<<<<< Details Sotred SuccessFully <<<<<<<");  \
    }

#define registration \
    {                \
    }