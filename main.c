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
            printf("Growth Tracker is under development.\n");
            break;

        case 'B':
            vaccineTracker(ageInMonths); // Call the vaccine tracker
            break;

        case 'C':
            printf("Sleep Tracker is under development.\n");
            break;

        case 'D':
            printf("Health Database is under development.\n");
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

    printf("The child's age is %d months.\n", ageInMonths);
    return ageInMonths;
}

// Vaccine Tracker function
void vaccineTracker() {
    char VaccineMenu;

    //Show overview of upcoming vaccines
    printf ("Upcoming vaccinations: \n");
    if ageInMonths == 1{
        printf ("")
    }

    printf("More information:\n");
    printf("A. BCG/Polio\n");
    printf("B. Hepatitis B\n");
    printf("C. Rotavirus\n");
    printf("D. DTaP\n");

    scanf("%c",&VaccineMenu);
    
    switch (VaccineMenu){
        case 'A':
        break;

        case 'B':
        break;

        case 'C':
        break;

        case 'D':
        break;

        default:
        printf ("Invalid Input! Try Again!")
    }
}
