#include <stdio.h>
#include <windows.h> //For gotoxy()
#include <conio.h>   //Use for delay(), getch()
#include <ctype.h>   //Use for toupper(), tolower(), etc.
#include <string.h>  //Use for strcpy(), strcmp(), strlen(), etc.
#include <stdlib.h>

char ans = 0;
int ok;
int b, valid = 0;

void WelcomeScreen(void);
void Title(void);
void MainMenu(void);
void LoginScreen(void);
void Add_record(void);
void func_list(void);
void Search_record(void);
void Edit_record(void);
void Delete_record(void);
void ex_it(void);

void gotoxy(short x, short y)
{
    COORD pos = {x, y}; //Sets Coordinates in (x,y)
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

struct patient
{
    int age;
    char Gender;
    char First_Name[20];
    char Last_Name[20];
    char Contact_No[15];M
    char Address[30];
    char Email[30];
    char Doctor[20];
    char Problem[20];
};

struct patient p, temp_c;

void main()
{
    WelcomeScreen();
    Title();
    LoginScreen();
}

void WelcomeScreen(void)
{
    printf("\n\n\n\n\n\n\n\t\t\t\t###########################################");
    printf("\n\t\t\t\t##\t\t WELCOME TO \t\t##");
    printf("\n\t\t\t\t## BHOPAL CITY HOSPITAL MANAGEMENT SYSTEM ##");
    printf("\n\t\t\t\t###########################################");
    printf("\n\n\n\n\n\t\t\t\t Press any key to continue................\n");
    getch();       //Hold the screen and wait for user to print a key and does not return anything
    system("cls"); //Use to Clear Screen
}

void Title(void)
{
    printf("\n\n\t\t*********************************************************");
    printf("\n\t\t\t\t BHOPAL CITY HOSPITAL");
    printf("\n\t\t*********************************************************");
}

void LoginScreen(void)
{
    int e = 0;
    char Username[15];
    char Password[15];
    char original_Username[25] = "Anusha07";
    char original_Password[15] = "1909";

    do
    {
        printf("\n\n\n\n\t\t\t\t Enter your Username and Password: ");
        printf("\n\n\n\n\t\t\t\t USERNAME: ");
        scanf("%s", &Username);
        printf("\n\n\t\t\t\t PASSWORD: ");
        scanf("%s", &Password);

        if (strcmp(Username, original_Username) == 0 && strcmp(Password, original_Password) == 0)
        {
            printf("\n\n\n\n\t\t\t\t.....Login Successful.....");
            getch();
            MainMenu();
            break;
        }
        else
        {
            printf("\n\t\t\t\t Password is Incorrect: (Try Again:)");
            e++;
            getch();
        }
    } while (e <= 2);

    if (e > 2)
    {
        printf("\n\t\t\t\t You have cross the limit. You cannot Login.");
        getch();
        ex_it();
    }
    system("cls");
}

void MainMenu(void)
{
    system("cls");
    int choose;
    Title();
    printf("\n\n\n\n\t\t\t\t 1. Add Patient Record\n");
    printf("\n\t\t\t\t 2. List Patients Record\n");
    printf("\n\t\t\t\t 3. Search Patient Record\n");
    printf("\n\t\t\t\t 4. Edit Patient Record\n");
    printf("\n\t\t\t\t 5. Delete Patient Record\n");
    printf("\n\t\t\t\t 6. Exit\n");
    printf("\n\n\n\n\t\t\t\t Choose from 1 to 6: ");

    scanf("%d", &choose);
    switch (choose)
    {
    case 1:
        Add_record();
        break;

    case 2:
        func_list();
        break;

    case 3:
        Search_record();
        break;

    case 4:
        Edit_record();
        break;

    case 5:
        Delete_record();
        break;

    case 6:
        ex_it();
        break;

    default:
        printf("\t\t\t\t Invalid Entry. Please enter right option");
        system("cls");
        MainMenu();
        getch();
    }
}

void ex_it(void)
{
    system("cls");
    Title();
    printf("\n\n\n\n\t\t\t\t THANK YOU FOR VISITING:");
    getch();
}

void Add_record(void)
{
    system("cls");
    Title();

    char ans;
    FILE *ek; //File Pointer
    ek = fopen("Record.dat", "a"); //a = append, Use for adding record in file
    printf("\n\n\n\n\t\t\t\t !!!!!!!!!!!!!!!! Add Patients Record !!!!!!!!!!!!!!!!\n");

A: //label
    printf("\n\t\t\t\t First Name: ");
    scanf("%s", p.First_Name); //Structure Variable
    p.First_Name[0] = toupper(p.First_Name[0]);

    if (strlen(p.First_Name) > 20 || strlen(p.First_Name) < 3)
    {
        printf("\n\t Invalid: (\t The max range for the first name is 20 and min range is 2");
        goto A;
    }
    else
    {
        for (b = 0; b < strlen(p.First_Name); b++)
        {
            if (isalpha(p.First_Name[b])) //Check Alphabets, First_Name can contain only characters
            {
                valid = 1;
            }
            else
            {
                valid = 0;
                break;
            }
        }
        if (!valid)
        {
            printf("\n\t\t\t\t First Name contains Invalid Charaacters: (Enter again:)");
            goto A;
        }
    }

B:
    printf("\n\t\t\t\t Last Name: ");
    scanf("%s", p.Last_Name); //Structure Variable
    p.Last_Name[0] = toupper(p.Last_Name[0]);

    if (strlen(p.Last_Name) > 20 || strlen(p.Last_Name) < 3)
    {
        printf("\n\t Invalid: (\t The max range for the last name is 20 and min range is 2");
        goto B;
    }
    else
    {
        for (b = 0; b < strlen(p.Last_Name); b++)
        {
            if (isalpha(p.Last_Name[b])) //Check Alphabets, Last_Name can contain only characters
            {
                valid = 1;
            }
            else
            {
                valid = 0;
                break;
            }
        }
        if (!valid)
        {
            printf("\n\t\t\t\t Last Name contain Invalid Character: (Enter again:)");
            goto B;
        }
    }
    fflush(stdin); ///////////////////
    do
    {
        printf("\n\t\t\t\t Gender[F/M]: ");
        scanf("%c", &p.Gender);

        if (toupper(p.Gender) == 'M' || toupper(p.Gender) == 'F')
        {
            ok = 1;
        }
        if (!ok)
        {
            printf("\n\t\t\t\t Gender contain Invalid Character: (Enter either F or M):");
        }
    } while (!ok);

    fflush(stdin);
    printf("\n\t\t\t\t Age: ");
    scanf("%d", &p.age);

C:
    printf("\n\t\t\t\t Address: ");
    scanf("%s", p.Address);
    p.Address[0] = toupper(p.Address[0]);

    if (strlen(p.Address) > 30 || strlen(p.Address) < 4)
    {
        printf("\n\t Invalid: (\t The max range for address is 30 and min range is 3");
        goto C;
    }

D:
    printf("\n\t\t\t\t Contact No: ");
    scanf("%s", p.Contact_No);

    if (strlen(p.Contact_No) > 15 || strlen(p.Contact_No) < 5)
    {
        printf("\n\t Invalid: (\t The max range for Contact No is 30 and min range is 4");
        goto D;
    }
    else
    {
        for (b = 0; b < strlen(p.Contact_No); b++)
        {
            if (isdigit(p.Contact_No[b])) //Check Digits, Contact_No can contain only digits
            {
                valid = 1;
            }
            else
            {
                valid = 0;
                break;
            }
        }
        if (!valid)
        {
            printf("\n\t\t\t\t Contain Invalid Character: (Enter again:)");
            goto D;
        }
    }

    do
    {
        printf("\n\t\t\t\t Email: ");
        scanf("%s", p.Email);

        if (strlen(p.Email) > 30 || strlen(p.Email) < 8)
        {
            printf("\n\t Invalid: (\t The max range for email is 30 and min range is 8");
        }
    } while (strlen(p.Email) > 30 || strlen(p.Email) < 8);

E:
    printf("\n\t\t\t\t Problem: ");
    scanf("%s", p.Problem);
    p.Problem[0] == toupper(p.Problem[0]);

    if (strlen(p.Problem) > 15 || strlen(p.Problem) < 3)
    {
        printf("\n\t Invalid: (\t The max range for the Problem is 15 and min range is 2");
        goto E;
    }
    else
    {
        for (b = 0; b < strlen(p.Problem); b++)
        {
            if (isalpha(p.Problem[b]))
            {
                valid = 1;
            }
            else
            {
                valid = 0;
                break;
            }
        }
        if (!valid)
        {
            printf("n\t\t\t\t Problem contain Invalid Characters: (Enter again:)");
            goto E;
        }
    }

F:
    printf("\n\t\t\t\t Prescribed Doctor: ");
    scanf("%s", p.Doctor);
    p.Doctor[0] = toupper(p.Doctor[0]);

    if (strlen(p.Doctor) > 15 || strlen(p.Doctor) < 3)
    {
        printf("\n\t Invalid: (\t The max range for the Doctor is 15 and min range is 2");
        goto F;
    }
    else
    {
        for (b = 0; b < strlen(p.Doctor); b++)
        {
            if (isalpha(p.Doctor[b]))
            {
                valid = 1;
            }
            else
            {
                valid = 0;
                break;
            }
        }
        if (!valid)
        {
            printf("\n\t\t\t\t Doctor Contain Invalid Characters: (Enter again:)");
            goto F;
        }
    }
    fprintf(ek, "%s %s %c %d %s %s %s %s %s \n", p.First_Name, p.Last_Name, p.Gender, p.age, p.Address, p.Contact_No, p.Email, p.Problem, p.Doctor);
    printf("\n\n\t\t\t\t ..............INFORMATION RECORDED SUCCESSFULLY..............");
    fclose(ek);
sd:
    getch();
    printf("\n\n\t\t\t\t Do you want to add more [Y/N]");
    scanf("%c", &ans);

    if (toupper(ans) == 'Y')
    {
        Add_record();
    }
    else if (toupper(ans) == 'N')
    {
        printf("\n\t\t\t\t THANK YOU");
        getch();
        MainMenu();
    }
    else
    {
        printf("\n\t\t\t\t Invalid Input");
        goto sd;
    }
}

void func_list() //List Record ( choose = 2)
{
    int row;
    system("cls");
    Title();
    FILE *ek;
    ek = fopen("Record.dat", "r");
    printf("\n\n\n\t\t !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! List Patients Record !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
    gotoxy(1, 15);
    printf("Full Name");
    gotoxy(20, 15);
    printf("Gender");
    gotoxy(30, 15);
    printf("Age");
    gotoxy(40, 15);
    printf("Address");
    gotoxy(60, 15);
    printf("Contact No.");
    gotoxy(75, 15);
    printf("Email");
    gotoxy(95, 15);
    printf("Problem");
    gotoxy(110, 15);
    printf("Prescribed Doctor\n");
    printf("======================================================================================================================");
    row = 20;

    while (fscanf(ek, "%s %s %c %d %s %s %s %s %s \n", p.First_Name, p.Last_Name, &p.Gender, &p.age, p.Address, p.Contact_No, p.Email, p.Problem, p.Doctor) != EOF)
    {
        gotoxy(1, row);
        printf("%s %s", p.First_Name, p.Last_Name);
        gotoxy(20, row);
        printf("%c", p.Gender);
        gotoxy(30, row);
        printf("%d", p.age);
        gotoxy(40, row);
        printf("%s", p.Address);
        gotoxy(60, row);
        printf("%s", p.Contact_No);
        gotoxy(75, row);
        printf("%s", p.Email);
        gotoxy(95, row);
        printf("%s", p.Problem);
        gotoxy(110, row);
        printf("%s", p.Doctor);
        row++;
    }
    fclose(ek);
    getch();
    MainMenu();
}

void Search_record(void)
{
    int row;
    char name[20];
    system("cls");
    Title();
    FILE *ek;
    ek = fopen("Record.dat", "r");
    printf("\n\n\t\t !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! Search Patients Records !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
    gotoxy(12, 8);
    printf("\n Enter Patients Name to be viewed: ");
    scanf("%s", name);
    fflush(stdin); //Use after read string
    name[0] = toupper(name[0]);
    row = 19;

    while (fscanf(ek, "%s %s %c %d %s %s %s %s %s \n", p.First_Name, p.Last_Name, &p.Gender, &p.age, p.Address, p.Contact_No, p.Email, p.Problem, p.Doctor) != EOF)
    {
        if (strcmp(p.First_Name, name) == 0)
        {
            gotoxy(1, 15);
            printf("Full Name");
            gotoxy(20, 15);
            printf("Gender");
            gotoxy(30, 15);
            printf("Age");
            gotoxy(40, 15);
            printf("Address");
            gotoxy(60, 15);
            printf("Contact No.");
            gotoxy(75, 15);
            printf("Email");
            gotoxy(95, 15);
            printf("Problem");
            gotoxy(110, 15);
            printf("Prescribed Doctor\n");
            gotoxy(1, 17);
            printf("==================================================================================================================================");
            gotoxy(1, row);
            printf("%s %s", p.First_Name, p.Last_Name);
            gotoxy(20, row);
            printf("%c", p.Gender);
            gotoxy(30, row);
            printf("%d", p.age);
            gotoxy(40, row);
            printf("%s", p.Address);
            gotoxy(60, row);
            printf("%s", p.Contact_No);
            gotoxy(75, row);
            printf("%s", p.Email);
            gotoxy(95, row);
            printf("%s", p.Problem);
            gotoxy(110, row);
            printf("%s", p.Doctor);
            break;
        }
    }
    if (strcmp(p.First_Name, name) != 0)
    {
        gotoxy(5, 10);
        printf("Record not found");
        getch();
    }
    fclose(ek);

L:
    getch();
    printf("\n\n\t\t\t\t Do you want to view more [Y/N]");
    scanf("%c", &ans);

    if (toupper(ans) == 'Y')
    {
        Search_record();
    }
    else if (toupper(ans) == 'N')
    {
        printf("\n\n\t\t\t\t Thank You");
        getch();
        MainMenu();
    }
    else
    {
        printf("\n\t Invalid Input.\n");
        goto L;
    }
}

void Edit_record(void)
{
    FILE *ek, *ft;
    int i, b, valid = 0;
    char ch;
    char name[20];
    system("cls");
    Title();
    ft = fopen("temp.dat", "w+");
    ek = fopen("Record.dat", "r");

    if (ek == NULL)
    {
        printf("\n\t Cannot open file");
        getch();
        MainMenu();
    }
    printf("\n\n\t\t\t\t !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! Edit Patients Record !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
    gotoxy(12, 13);
    printf("Enter the First Name of the Patient: ");
    scanf("%s", &name);
    fflush(stdin);
    name[0] = toupper(name[0]);
    gotoxy(12, 15);

    if (ft == NULL)
    {
        printf("\n\t Cannot open file");
        getch();
        MainMenu();
    }

    while (fscanf(ek, "%s %s %c %d %s %s %s %s %s \n", p.First_Name, p.Last_Name, &p.Gender, &p.age, p.Address, p.Contact_No, p.Email, p.Problem, p.Doctor) != EOF)
    {
        if (strcmp(p.First_Name, name) == 0)
        {
            valid = 1;
            gotoxy(25, 17);
            printf("*************** Existing Record ***************");
            gotoxy(10, 19);
            printf("%s %s %c %d %s %s %s %s %s \n", p.First_Name, p.Last_Name, p.Gender, p.age, p.Address, p.Contact_No, p.Email, p.Problem, p.Doctor);
            gotoxy(12, 22);
            printf("Enter New First Name: ");
            scanf("%s", p.First_Name);
            gotoxy(12, 24);
            printf("Enter Last Name: ");
            scanf("%s", p.Last_Name);
            gotoxy(12, 26);
            fflush(stdin);
            printf("Enter Gender: ");
            scanf("%c", &p.Gender);  // edited
            p.Gender = toupper(p.Gender);
            gotoxy(12, 28);
            printf("Enter age: ");
            scanf("%d", &p.age);   // editedj
            gotoxy(12, 30);
            printf("Enter Address: ");
            scanf("%s", p.Address);
            p.Address[0] = toupper(p.Address[0]);
            gotoxy(12, 32);
            printf("Enter Contact No:");
            scanf("%s", p.Contact_No);
            gotoxy(12, 34);
            printf("Enter New Email: ");
            scanf("%s", p.Email);
            gotoxy(12, 36);
            printf("Enter Problem: ");
            scanf("%s", p.Problem);
            p.Problem[0] = toupper(p.Problem[0]);
            gotoxy(12, 38);
            printf("Enter Doctor: ");
            scanf("%s", p.Doctor);
            p.Doctor[0] = toupper(p.Doctor[0]);
            printf("\n Press U character for the updating operation");
            ch = getche(); //Get Character like scanf

            if (ch == 'u' || ch == 'U')
            {
                fprintf(ft, "%s %s %c %d %s %s %s %s %s \n", p.First_Name, p.Last_Name, p.Gender, p.age, p.Address, p.Contact_No, p.Email, p.Problem, p.Doctor);
                printf("\n\n\t\t\t\t PATIENT RECORD UPDATED SUCCESSFULLY..........");
            }
        }
        else
        {
            fprintf(ft, "%s %s %c %d %s %s %s %s %s \n", p.First_Name, p.Last_Name, p.Gender, p.age, p.Address, p.Contact_No, p.Email, p.Problem, p.Doctor);
        }
    }
    if (!valid)
    {
        printf("\n\t\t\t\t NO RECORD FOUND.............");
    }
    fclose(ft);
    fclose(ek);
    remove("Record.dat");
    rename("temp.dat", "Record.dat");
    getch();
    MainMenu();
}

void Delete_record()
{
    char name[20];
    int found = 0;
    system("cls");
    Title();
    FILE *ek, *ft;
    ft = fopen("temp.dat", "w+");
    ek = fopen("Record.dat", "r");
    printf("\n\n\t\t\t\t !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! Delete Patient Record !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
    gotoxy(12, 8);
    printf("\n Enter Patient Name to delete");
    fflush(stdin);
    gets(name);
    name[0] = toupper(name[0]);

    while (fscanf(ek, "%s %s %c %d %s %s %s %s %s \n", p.First_Name, p.Last_Name, &p.Gender, &p.age, p.Address, p.Contact_No, p.Email, p.Problem, p.Doctor) != EOF)
    {
        if (strcmp(p.First_Name, name) != 0)
        {
            fprintf(ft, "%s %s %c %d %s %s %s %s %s \n", p.First_Name, p.Last_Name, p.Gender, p.age, p.Address, p.Contact_No, p.Email, p.Problem, p.Doctor);
        }
        else
        {
            printf("%s %s %c %d %s %s %s %s %s \n", p.First_Name, p.Last_Name, p.Gender, p.age, p.Address, p.Contact_No, p.Email, p.Problem, p.Doctor);
            found = 1;
        }
    }
    if (found == 0)
    {
        printf("\n\n\t\t\t\t Record not found.......:");
        getch();
        MainMenu();
    }
    else
    {
        fclose(ek);
        fclose(ft);
        remove("Record.dat");
        rename("temp.dat", "Record.dat");
        printf("\n\n\t\t\t\t Record deleted successfully");
        getch();
        MainMenu();
    }
}
