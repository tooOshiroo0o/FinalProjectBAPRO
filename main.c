#include <stdio.h>
#include <time.h>

// Function declarations
void vaccineTracker();
int ageCalculator();

int main() {
    int ageInMonths = ageCalculator(); // Calculate child's age in months

    char menu;

    printf("Menu Options:\n");
    printf("A. Growth Tracker\n");
    printf("B. Vaccine Tracker\n");
    printf("C. Sleep Tracker\n");
    printf("D. Health Database\n");
    printf("Enter your choice: ");
    scanf(" %c", &menu);

    switch (menu) {
        case 'A':
            break;

        case 'B':
            vaccineTracker(ageInMonths); // Call the vaccine tracker
            break;

        case 'C':
            break;

        case 'D':
            break;

        default:
            printf("Invalid Input! Try Again!\n");
    }

    return 0;
}

// Function to calculate child's age in months
int ageCalculator() {
    int dates[2][3]; // Array to store birthdate [0][...] and current date [1][...]

    // Get child's birthdate
    printf("Enter child's birthdate (YYYY MM DD): ");
    scanf("%d %d %d", &dates[0][0], &dates[0][1], &dates[0][2]); // [0][0]=Year, [0][1]=Month, [0][2]=Day

    // Get current date
    time_t t = time(NULL);
    struct tm currentDate = *localtime(&t);

    dates[1][0] = currentDate.tm_year + 1900; // Current Year
    dates[1][1] = currentDate.tm_mon + 1;    // Current Month
    dates[1][2] = currentDate.tm_mday;      // Current Day

    // Calculate age in months
    int ageInYears = dates[1][0] - dates[0][0];
    int ageInMonths = (dates[1][1] - dates[0][1]) + (ageInYears * 12);
    if (dates[1][1] < dates[0][1] || (dates[1][1] == dates[0][1] && dates[1][2] < dates[0][2])) {
        ageInMonths -= 1; // Adjust if birthdate hasn't occurred yet this month
    }
    return ageInMonths;
}

// Function to calculate remaining months for a vaccine dosage
int vaccineCalculator(int interval, int ageInMonths) {
    int nextDose = interval - ageInMonths; // Remaining months until the dosage
    return (nextDose > 0) ? nextDose : 0; // If overdue, set remaining to 0
}

// Vaccine Tracker function
void vaccineTracker(int ageInMonths) {
    char VaccineMenu;
    int interval = 0;
    int i;
    int nextDose;

    //Menu of upcoming vaccines based on different age groups
    if (ageInMonths <= 6){
        printf ("A. BCG/Polio\n");
        printf ("B. Hepatitis B\n");
        printf ("C. Rotavirus\n");
        printf ("D. HiB\n");
        scanf (" %c", &VaccineMenu);

        switch (VaccineMenu){

            case 'A':
            printf ("-------- Polio/BCG -------\n");
            printf ("Dosage | Due in   | Status\n");
            interval = 2;
            for (i = 0; i < 3; i ++){
             nextDose = vaccineCalculator(interval, ageInMonths);
             printf("%d      |%d Months  |   %c  \n",i+1, nextDose, nextDose == 0 ? 'V' : 'X');
             interval +=2;              
            }
            break;

            case 'B':
            printf ("------- Hepatitis B ------\n");
            printf ("Dosage | Due in   | Status\n");
            interval = 1;
            for (i = 0; i < 4; i ++){
             nextDose = vaccineCalculator(interval, ageInMonths);
             printf("%d      |%d Months  |   %c  \n",i+1, nextDose, nextDose == 0 ? 'V' : 'X');
             interval ++;              
            }
            
            break;
            
            case 'C':
            printf ("-------- Rotavirus -------\n");
            printf ("Dosage | Due in   | Status\n");

            interval = 2;

            for (i = 0; i < 3; i ++){
             nextDose = vaccineCalculator(interval, ageInMonths);
             printf("%d      |%d Months  |   %c  \n",i+1, nextDose, nextDose == 0 ? 'V' : 'X');
             interval +=2;              
            }
            
            break;
            
            case 'D':
            printf ("----------- HiB ----------\n");
            printf ("Dosage | Due in   | Status\n");

            interval = 1;

            for (i = 0; i < 3; i ++){
             nextDose = vaccineCalculator(interval, ageInMonths);
             printf("%d      |%d Months  |   %c  \n",i+1, nextDose, nextDose == 0 ? 'V' : 'X');
             interval ++;              
            }
            
            break;
            
            default:
            printf ("Invalid Input! Try again!");
            }
    }
    else if (ageInMonths > 6 && ageInMonths <= 12){
        printf ("A. Influenza\n");
        printf ("B. MMR\n");
        scanf (" %c", &VaccineMenu);

        switch (VaccineMenu){
            case 'A':
            printf ("-------- Influenza -------\n");
            printf ("Dosage | Due in   | Status\n");

            interval = 12;

            for (i = 0; i < 3 ; i ++){
             nextDose = vaccineCalculator(interval, ageInMonths);
             printf("%d      |%d Months  |   %c  \n",i+1, nextDose, nextDose == 0 ? 'V' : 'X');
             interval ++;              
            }
            break;
            
            case 'B':
            printf ("----------- MMR ----------\n");
            printf ("Dosage | Due in   | Status\n");

            interval = 9;

            for (i = 0; i < 1; i ++){
             nextDose = vaccineCalculator(interval, ageInMonths);
             printf("%d      |%d Months  |   %c  \n",i+1, nextDose, nextDose == 0 ? 'V' : 'X');
             interval ++;              
            }

            break;
            
            default:
            printf ("Invalid Input! Try again!");
        }

    }
    else if (ageInMonths > 12 && ageInMonths <= 24){
        printf ("A. Hepatitis A\n");
        printf ("B. Varicella\n");
        scanf (" %c", &VaccineMenu);

        switch (VaccineMenu){
            case 'A':
            printf ("------ Hepatitis A -------\n");
            printf ("Dosage | Due in   | Status\n");

            interval = 6;

            for (i = 0; i < 2; i ++){
             nextDose = vaccineCalculator(interval, ageInMonths);
             printf("%d      |%d Months  |   %c  \n",i+1, nextDose, nextDose == 0 ? 'V' : 'X');
             interval ++;              
            }
            break;
            
            case 'B':
            printf ("-------- Varicella -------\n");
            printf ("Dosage | Due in   | Status\n");

            interval = 3;

            for (i = 0; i < 2; i ++){
             nextDose = vaccineCalculator(interval, ageInMonths);
             printf("%d      |%d Months  |   %c  \n",i+1, nextDose, nextDose == 0 ? 'V' : 'X');
             interval ++;              
            }
            break;
            
            default:
            printf ("Invalid Input! Try again!");
        }
    }
}
