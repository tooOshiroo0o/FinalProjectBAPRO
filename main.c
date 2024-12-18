#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// Define WHO standards for growth tracker
typedef struct
{
    float minWeight;
    float maxWeight;
    float minHeight;
    float maxHeight;
    float minHeadCircumference;
    float maxHeadCircumference;
} GrowthStandards;

// WHO growth standards data for boys and girls (in kg and cm)
const GrowthStandards boysStandards[6] = {
    {2.5, 4.4, 46.0, 54.0, 31.5, 36.5},  // 0-1 months
    {3.4, 5.8, 52.0, 60.0, 34.0, 38.0},  // 1-3 months
    {5.1, 7.8, 58.0, 66.0, 37.0, 42.0},  // 3-6 months
    {6.4, 9.4, 64.0, 72.0, 39.0, 44.5},  // 6-9 months
    {7.4, 10.5, 68.0, 76.0, 41.0, 46.0}, // 9-12 months
    {8.4, 12.0, 72.0, 80.0, 42.0, 47.0}  // 12-18 months
};

const GrowthStandards girlsStandards[6] = {
    {2.4, 4.2, 45.5, 53.0, 31.0, 36.0}, // 0-1 months
    {3.2, 5.4, 51.0, 59.0, 33.5, 37.5}, // 1-3 months
    {4.8, 7.3, 57.0, 65.0, 36.5, 41.5}, // 3-6 months
    {6.0, 8.8, 63.0, 71.0, 38.5, 43.5}, // 6-9 months
    {7.0, 9.9, 67.0, 75.0, 40.5, 45.5}, // 9-12 months
    {8.0, 11.5, 71.0, 79.0, 41.5, 46.5} // 12-18 months
};

<<<<<<< HEAD
// Function declarations
void vaccineTracker(int ageInMonths);
int ageCalculator();
void growthTracker(int ageInMonths);
int isWithinRange(float value, float min, float max);

=======
// Define WHO standards for growth tracker
typedef struct
{
    float minWeight;
    float maxWeight;
    float minHeight;
    float maxHeight;
    float minHeadCircumference;
    float maxHeadCircumference;
} GrowthStandards;

// WHO growth standards data for boys and girls (in kg and cm)
const GrowthStandards boysStandards[6] = {
    {2.5, 4.4, 46.0, 54.0, 31.5, 36.5},  // 0-1 months
    {3.4, 5.8, 52.0, 60.0, 34.0, 38.0},  // 1-3 months
    {5.1, 7.8, 58.0, 66.0, 37.0, 42.0},  // 3-6 months
    {6.4, 9.4, 64.0, 72.0, 39.0, 44.5},  // 6-9 months
    {7.4, 10.5, 68.0, 76.0, 41.0, 46.0}, // 9-12 months
    {8.4, 12.0, 72.0, 80.0, 42.0, 47.0}  // 12-18 months
};

const GrowthStandards girlsStandards[6] = {
    {2.4, 4.2, 45.5, 53.0, 31.0, 36.0}, // 0-1 months
    {3.2, 5.4, 51.0, 59.0, 33.5, 37.5}, // 1-3 months
    {4.8, 7.3, 57.0, 65.0, 36.5, 41.5}, // 3-6 months
    {6.0, 8.8, 63.0, 71.0, 38.5, 43.5}, // 6-9 months
    {7.0, 9.9, 67.0, 75.0, 40.5, 45.5}, // 9-12 months
    {8.0, 11.5, 71.0, 79.0, 41.5, 46.5} // 12-18 months
};

// Function declarations
void vaccineTracker(int ageInMonths);
int ageCalculator();
void growthTracker(int ageInMonths);
int isWithinRange(float value, float min, float max);

>>>>>>> 6d81ef8134cd24c759460e9e15f0911e0ce39e19
int main()
{
    int ageInMonths = ageCalculator(); // Calculate child's age in months
    char menu;

<<<<<<< HEAD
    do
    {
        printf("\nMenu Options:\n");
        printf("A. Vaccine Tracker\n");
        printf("B. Growth Tracker\n");
        printf("C. Sleep Tracker\n");
        printf("D. Health Database\n");
        printf("E. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &menu);

        switch (menu)
        {
        case 'A':
            vaccineTracker(ageInMonths); // Call the Vaccine Tracker
            break;

        case 'B':
            growthTracker(ageInMonths); // Call the Growth Tracker
            break;
=======
    printf("\nMenu Options:\n");
    printf("A. Growth Tracker\n");
    printf("B. Vaccine Tracker\n");
    printf("C. Sleep Tracker\n");
    printf("D. Health Database\n");
    printf("Enter your choice: ");
    scanf(" %c", &menu);

    switch (menu)
    {
    case 'A':
        growthTracker(ageInMonths); // Call the Growth Tracker
        break;

    case 'B':
        vaccineTracker(ageInMonths); // Call the Vaccine Tracker
        break;
>>>>>>> 6d81ef8134cd24c759460e9e15f0911e0ce39e19

    case 'C':
        printf("Sleep Tracker is under development.\n");
        break;

    case 'D':
        printf("Health Database is under development.\n");
        break;

<<<<<<< HEAD
        case 'E':
            printf("Exiting program. Thank you!\n");
            break;

        default:
            printf("Invalid Input! Try Again.\n");
        }
    } while (menu != 'E');
=======
    default:
        printf("Invalid Input! Try Again!\n");
    }
>>>>>>> 6d81ef8134cd24c759460e9e15f0911e0ce39e19

    return 0;
}

// Function to calculate child's age in months
int ageCalculator()
{
    int dates[2][3]; // Array to store birthdate [0][...] and current date [1][...]

    // Get child's birthdate
    printf("Enter child's birthdate (YYYY MM DD): ");
    scanf("%d %d %d", &dates[0][0], &dates[0][1], &dates[0][2]);

    // Get current date
    time_t t = time(NULL);
    struct tm currentDate = *localtime(&t);

    dates[1][0] = currentDate.tm_year + 1900; // Current Year
    dates[1][1] = currentDate.tm_mon + 1;     // Current Month
    dates[1][2] = currentDate.tm_mday;        // Current Day

    // Calculate age in months
    int ageInYears = dates[1][0] - dates[0][0];
    int ageInMonths = (dates[1][1] - dates[0][1]) + (ageInYears * 12);
    if (dates[1][1] < dates[0][1] || (dates[1][1] == dates[0][1] && dates[1][2] < dates[0][2]))
    {
        ageInMonths -= 1; // Adjust if birthdate hasn't occurred yet this month
    }

    printf("The child's age is %d months.\n", ageInMonths);
    return ageInMonths;
}

<<<<<<< HEAD
// Vaccine Tracker function
void vaccineTracker(int ageInMonths)
{
    printf("\nVaccine Tracker for %d-month-old child:\n", ageInMonths);

    if (ageInMonths <= 1)
    {
        printf("Recommended: BCG, Hepatitis B\n");
    }
    else if (ageInMonths <= 3)
    {
        printf("Recommended: Polio, Rotavirus\n");
    }
    else if (ageInMonths <= 6)
    {
        printf("Recommended: DTaP, Hib, Hepatitis B\n");
    }
    else if (ageInMonths <= 12)
    {
        printf("Recommended: Measles, Mumps, Rubella (MMR)\n");
    }
    else
    {
        printf("Please consult with a pediatrician for additional vaccines.\n");
    }
}

// Function to check if a value is within a range
int isWithinRange(float value, float min, float max)
{
    return value >= min && value <= max;
}

// Growth Tracker function
void growthTracker(int ageInMonths)
{
    if (ageInMonths < 0 || ageInMonths > 18)
    {
        printf("Growth Tracker supports ages 0 to 18 months only.\n");
        return;
    }
=======
// Function to check if a value is within a range
int isWithinRange(float value, float min, float max)
{
    return value >= min && value <= max;
}

// Growth Tracker function
void growthTracker(int ageInMonths)
{
    if (ageInMonths < 0 || ageInMonths > 18)
    {
        printf("Growth Tracker supports ages 0 to 18 months only.\n");
        return;
    }
>>>>>>> 6d81ef8134cd24c759460e9e15f0911e0ce39e19

    char gender;
    do
    {
        printf("Enter child's gender (M for male, F for female): ");
        scanf(" %c", &gender);
        if (gender != 'M' && gender != 'F')
        {
            printf("Invalid input! Enter 'M' for male or 'F' for female.\n");
        }
    } while (gender != 'M' && gender != 'F');

    const GrowthStandards *standards = (gender == 'M') ? boysStandards : girlsStandards;
    int index = (ageInMonths <= 1) ? 0 : (ageInMonths <= 3) ? 1
                                     : (ageInMonths <= 6)   ? 2
                                     : (ageInMonths <= 9)   ? 3
                                     : (ageInMonths <= 12)  ? 4
                                                            : 5;

    float weight, height, headCircumference;

    // Input validation
    do
    {
        printf("Enter baby's weight (kg, positive value): ");
        scanf("%f", &weight);
        if (weight <= 0)
        {
            printf("Invalid input! Weight must be a positive value.\n");
        }
    } while (weight <= 0);

    do
    {
        printf("Enter baby's height (cm, positive value): ");
        scanf("%f", &height);
        if (height <= 0)
        {
            printf("Invalid input! Height must be a positive value.\n");
        }
    } while (height <= 0);

    do
    {
        printf("Enter baby's head circumference (cm, positive value): ");
        scanf("%f", &headCircumference);
        if (headCircumference <= 0)
        {
            printf("Invalid input! Head circumference must be a positive value.\n");
        }
    } while (headCircumference <= 0);

    // Check measurements against standards
    const GrowthStandards currentStandards = standards[index];
    printf("\nGrowth Tracker Results:\n");

    if (isWithinRange(weight, currentStandards.minWeight, currentStandards.maxWeight))
    {
        printf("Weight is within the healthy range (%.1f - %.1f kg).\n", currentStandards.minWeight, currentStandards.maxWeight);
    }
    else
    {
        printf("Weight is outside the healthy range (%.1f - %.1f kg).\n", currentStandards.minWeight, currentStandards.maxWeight);
    }

    if (isWithinRange(height, currentStandards.minHeight, currentStandards.maxHeight))
    {
        printf("Height is within the healthy range (%.1f - %.1f cm).\n", currentStandards.minHeight, currentStandards.maxHeight);
    }
    else
    {
        printf("Height is outside the healthy range (%.1f - %.1f cm).\n", currentStandards.minHeight, currentStandards.maxHeight);
    }

    if (isWithinRange(headCircumference, currentStandards.minHeadCircumference, currentStandards.maxHeadCircumference))
    {
        printf("Head circumference is within the healthy range (%.1f - %.1f cm).\n", currentStandards.minHeadCircumference, currentStandards.maxHeadCircumference);
    }
    else
    {
        printf("Head circumference is outside the healthy range (%.1f - %.1f cm).\n", currentStandards.minHeadCircumference, currentStandards.maxHeadCircumference);
    }
}

// Placeholder for Vaccine Tracker
void vaccineTracker(int ageInMonths)
{
    printf("Vaccine Tracker is under development.\n");
}
