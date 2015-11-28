#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <process.h>
#define MAX_SIZE 100
#define ARRAY_SIZE 1
//#include "minunit.h"

//#define USERNAME 10
//#define PASSWORD 20

//MU_TEST(test_check) {
//    int x = 0;
//    int y = 20;
//    int total = x + y;
//    mu_check(total == 21);
//}
//MU_TEST_SUITE(test_suite) {
//    MU_RUN_TEST(test_check);
//}


// Method definitions
void cls();
void welcome_message();
void sign_in_or_sign_up();
int sign_in();
int write_user_file(char* filename);
int access_granted = 0;
void print_menu();
char view_profile(char username[MAX_SIZE]);
int generate_exercise(char* filename);
void about();
//void enter_account();
//void sign_in();
//void sign_up();
//char view_profile(char username[USERNAME]);

// User struct
typedef struct user
{
	char username[MAX_SIZE];
	char password[MAX_SIZE];
  int points;
  int level;
} user;

// Sign in username & password globals to compare to signed up text vars
char da_username[MAX_SIZE];
char da_password[MAX_SIZE];

// Text Vars
char compare_name[MAX_SIZE];
char compare_password[MAX_SIZE];

// Write/Read User Files
int write_user_file(char* filename);
int read_user_file(char* filename);

// Users array
user users[ARRAY_SIZE];

// Main
int main() {
    
    //    MU_RUN_SUITE(test_suite);
    //    MU_REPORT();
    
    welcome_message();
    //    enter_account();
    //    print_menu();
    
    sign_in_or_sign_up();
    
    if (access_granted) {
      print_menu();
    } else {
      printf("Sorry, wrong username/password... Try again!\n");
    }
 
    return 0;
}

// Clear screen method
void cls()
{
    int x;
    for(x = 0; x < 10; x++)
    {
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    }
}

//typedef struct ninja {
//
//    char name[USERNAME];
//    int level;
//    char badges[10];
//
//} ninja;

// Welcome message method
void welcome_message() {
    char enter;
    
    printf(" ________  ___  ___  ___  ___  ________  ___  ___  __    _______   ________         \n");
    printf("|\\   ____\\|\\  \\|\\  \\|\\  \\|\\  \\|\\   __  \\|\\  \\|\\  \\|\\  \\ |\\  ___ \\ |\\   ___  \\       \n");
    printf("\\ \\  \\___|\\ \\  \\\\\\  \\ \\  \\\\\\  \\ \\  \\|\\  \\ \\  \\ \\  \\/  /|\\ \\   __/|\\ \\  \\\\ \\  \\      \n");
    printf(" \\ \\_____  \\ \\   __  \\ \\  \\\\\\  \\ \\   _  _\\ \\  \\ \\   ___  \\ \\  \\_|/_\\ \\  \\\\ \\  \\     \n");
    printf("  \\|____|\\  \\ \\  \\ \\  \\ \\  \\\\\\  \\ \\  \\\\  \\\\ \\  \\ \\  \\\\ \\  \\ \\  \\_|\\ \\ \\  \\\\ \\  \\    \n");
    printf("    ____\\_\\  \\ \\__\\ \\__\\ \\_______\\ \\__\\\\ _\\\\ \\__\\ \\__\\\\ \\__\\ \\_______\\ \\__\\\\ \\__\\   \n");
    printf("   |\\_________\\|__|\\|__|\\|_______|\\|__|\\|__|\\|__|\\|__| \\|__|\\|_______|\\|__| \\|__|   \n");
    printf("   \\|_________|                                                                                       ");
    
    
    
    printf("\n");
    printf("\nVersion (BETA)");
    printf("\nWelcome aboard!");
    printf("\nPress Enter to continue...\n");
    scanf("%c", &enter);
    cls();
}


// Sign in method
int sign_in() {
  int i = 0;
  char c;
  FILE* file = fopen("user.txt", "r"); /* should check the result */
  int lineCounter = 0;
  
  if(file==NULL)
  {
    printf("Error: can't open file.\n");
    
  }
  else
  {    
    for(lineCounter = 0; lineCounter < 1;  )
    {
  
      c = fgetc(file);
      if(c == EOF)
      {
         break;                           
      }
      else if(c =='\n')
      {
         compare_name[i] = c;
         //printf("%c", c);
         lineCounter++;
         i++;
      }
      else
      {
        //printf("%c", c);
      }
    }

    fclose(file);
  }


  printf("What's your username? ");
  scanf(" %s", &da_username[MAX_SIZE]);
  printf("What's your password? ");
  scanf(" %s", &da_password[MAX_SIZE]);


  for (int x = 0; x < sizeof(compare_name); x++) {
    if (compare_name[x] == da_username[x]) {
      access_granted = 1;
    } else {
      access_granted = 0;
    }
  }

  return 0;

}

// Sign up method
void sign_up() {

  printf("Enter your ninja username: ");
  scanf( "%s", users[0].username);
  printf("Enter your password: ");
  scanf( "%s", users[0].password);

  users[0].points = 0;
  users[0].level = 1;

  char* filename = "user.txt";
  write_user_file(filename);

}

// Write user file method
int write_user_file(char* filename)
{
	FILE* filePtr;

	filePtr = fopen(filename, "w");
	if (filePtr == NULL)
	{
		printf("Could not open file '%s' for writing.\n", filename);
		return 1;
	}

	fprintf(filePtr, "%s\n", users[0].username);
	fprintf(filePtr, "%s\n", users[0].password);
  fprintf(filePtr, "%d\n", users[0].points);
  fprintf(filePtr, "%d\n", users[0].level);

	fclose(filePtr);

	return 0;
}

void about() {

  printf("Shuriken v. BETA by @bntzio\n");
  printf("We are currently in beta version so you may encounter some bugs, please report them to a01021888@itesm.mx\n");
  printf("Right now, we only hold 1 exercise and 1 language, the C programming language.\n"); 
  printf("We are going to release more exercises for the final version, so stay tuned.\n");
  printf("If you'd like to contribute to the project go to https://github.com/bntzio/shuriken, pull requests are welcome!\n");
  printf("\n");
  printf("\n");

}


// Sign in or Sign up
void sign_in_or_sign_up() {
    
    char option = 'z';
    
    while (option != 'q') {
        printf("Select an option, fellow ninja\n");
        printf("a. Sign in\n");
        printf("b. Sign up\n");
        printf("q. Quit\n");
        scanf(" %c", &option);
        
        switch (option) {
            case 'a':
            case 'A':
                sign_in();
                if (sign_in()) {
                  access_granted = 1;
                }
                printf("Signing in...\n");
                break;
            case 'b':
            case 'B':
                sign_up();
                printf("Signing up...\n");
                break;
            case 'q':
            case 'Q': 
                //go_out();
                printf("Quitting...\n");
                break;
            default:
                printf("Incorrect option, try again!\n");
                break;
        }
    }
}


// Generate exercise
int generate_exercise(char* filename) {
 
  
  FILE* filePtr;
  //FILE* filePtr2;

  //char a;

  //filePtr2 = fopen("exercise01.txt", "r");
  //if (filePtr2 == NULL) {
  //    puts("cannot open this file");
  //    return 1;
  //}


	filePtr = fopen("ex01.txt", "w");
	if (filePtr == NULL)
	{
		printf("Could not open file '%s' for writing.\n", filename);
		return 1;
	}

   //do {
   //   a = fgetc(filePtr2);
   //   fputc(a, filePtr);
   //} while (a != EOF);
 
   //fcloseall();
   //getch();


	fprintf(filePtr, "%s\n", "Check out the ex01.c file...");
	
	fclose(filePtr);

	return 0;


}



// Print menu method
void print_menu() {

   cls();

   char option = 'a';

   while(option != 'q') {
       printf("What do you want to do now %s?\n", users[0].username);
       printf("-----------------------------------------\n");
       printf("a. View Profile\n");
       //printf("b. See All Levels\n");
       //printf("c. See All Badges\n");
       //printf("d. View Roadmap\n");
       printf("e. Start Training\n");
       printf("f. Sign Out\n");
       printf("g. About Shuriken\n");
       printf("Select the option number and press Enter: ");
       scanf(" %c", &option);

       switch(option) {
           case 'a':
               cls();
               view_profile(users[0].username);
               break;
           case 'b':
           case 'B':
               printf("GOODBYE!\n");
               break;
           case 'c':
           case 'C':
               printf("......\n");
               break;
           case 'e':
           case 'E':
               cls();
               printf("Generating exercise...\n\n\n");
               generate_exercise("exercise01.txt");
               break;
           case 'g':
           case 'G':
               cls();
               about();
               break;
           case 'f':
           case 'F':
               cls();
               printf("See you later fellow ninja!\n");
               exit(0);
               break;
           default:
               printf("Incorrect option, try again!\n");
               break;
       }
   }

}


char view_profile(char username[MAX_SIZE]) {


    cls();
    printf("Stats for %s\n", username);
    

    return *username;
}



//int write_file(char* filename)
//{
//    FILE* filePtr;
//    char* name = "Gilberto";
//    float height = 0;
//
//    filePtr = fopen(filename, "w");
//    if (filePtr == NULL)
//    {
//        printf("Could not open file '%s' for writing.\n", filename);
//        return 1;
//    }
//
//    fprintf(filePtr, "%s\n", name);
//    fprintf(filePtr, "%d\n", 789456123);
//    fprintf(filePtr, "%f\n", 1.76);
//    fprintf(filePtr, "%f\n", 72.5);
//
//    fprintf(filePtr, "%s\n", "Andres");
//    fprintf(filePtr, "%d\n", 4561859753);
//    fprintf(filePtr, "%f\n", 1.69);
//    fprintf(filePtr, "%f", 70.1);
//
//    fclose(filePtr);
//
//    return 0;
//}
//
//int read_file(char* filename)
//{
//    FILE* filePtr;
//    patient patients[ARRAY_SIZE];
//    int i = 0;
//
//    filePtr = fopen(filename, "r");
//    if (filePtr == NULL)
//    {
//        printf("Could not open file '%s' for reading.\n", filename);
//        return 1;
//    }
//
//    while (1)
//    {
//        fscanf(filePtr, " %s", patients[i].name);
//        printf("\nPatient name: %s\n", patients[i].name);	// No & when reading strings
//        fscanf(filePtr, " %d", &patients[i].telephone);
//        printf("Patient telephone: %d\n", patients[i].telephone);
//        fscanf(filePtr, " %f", &patients[i].height);
//        printf("Patient height: %.2f\n", patients[i].height);
//        fscanf(filePtr, " %f", &patients[i].weight);
//        printf("Patient weight: %.2f\n", patients[i].weight);
//        i++;
//
//        if (feof(filePtr) || i > ARRAY_SIZE)
//            break;
//    }
//
//    fclose(filePtr);
//    return 0;
//}
































































