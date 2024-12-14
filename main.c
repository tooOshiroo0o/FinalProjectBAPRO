#include <stdio.h>
#include <time.h>

// Function declarations
void vaccineTracker(int ageInMonths);
int ageCalculator();

int main() {
    char menu;

    printf("Menu Options:\n");
    printf("A. Growth Tracker\n");
    printf("B. Vaccine Tracker\n");
    printf("C. Sleep Tracker\n");
    printf("D. Health Database\n");
    printf("Enter your choice: ");
    scanf(" %c", &menu);

    int ageInMonths = ageCalculator(); // Calculate child's age in months

    switch (menu) {
        case 'A':
            break;

        case 'B': {
            break;
        }

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
    int birthYear, birthMonth, birthDay;

    // Get child's birthdate
    printf("Enter child's birthdate (YYYY MM DD): ");
    scanf("%d %d %d", &birthYear, &birthMonth, &birthDay);

    // Get current date
    time_t t = time(NULL);
    struct tm currentDate = *localtime(&t);

    // Extract current year, month, and day
    int currentYear = currentDate.tm_year + 1900;
    int currentMonth = currentDate.tm_mon + 1;
    int currentDay = currentDate.tm_mday;

    // Calculate age in months
    int ageInYears = currentYear - birthYear;
    int ageInMonths = (currentMonth - birthMonth) + (ageInYears * 12);
    if (currentMonth < birthMonth || (currentMonth == birthMonth && currentDay < birthDay)) {
        ageInMonths -= 1; // Adjust if birthdate hasn't occurred yet this month
    }

    return ageInMonths;
}
