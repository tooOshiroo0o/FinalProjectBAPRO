#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LOGS 100

typedef struct{
    time_t timeStart;
    time_t timeEnd;
    int durationInmin;
    char notes[99];
} sleepLog;

typedef struct {
    sleepLog logs[MAX_LOGS];
    int logCount;
    float sleepTotal; // in hours
    int ageInMonth; // baby's age in months
} babySleep;

// Function declarations
int ageCalculator();
void sleepTracker();
void startSleep();
void endSleep();
void sleepHistory();
void sleepSummary();


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

// Define diseases and their treatment data
typedef struct {
    char name[50];
    char description[500];
    char treatment[500];
} Disease;

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
void HealthDatabase();

int main()
{
    int ageInMonths = ageCalculator(); // Calculate child's age in months
    char menu;
    babySleep tracker = {0};

    do
    {
        printf("\nMenu Options:\n");
        printf("A. Growth Tracker\n");
        printf("B. Vaccine Tracker\n");
        printf("C. Sleep Tracker\n");
        printf("D. Health Database\n");
        printf("E. Exit\n");
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

        case 'C':
            sleepTracker(&tracker); // call the sleep tracker
            break;

        case 'D':
            HealthDatabase(); // Call the Health Database
            break;

        case 'E':
            printf("Exiting program. Thank you!\n");
            break;

        default:
            printf("Invalid Input! Try Again.\n");
        }
    } while (menu != 'E');

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

// Vaccine Tracker function
void vaccineTracker(int ageInMonths)
{
    // Example vaccine data, modify as needed
    const char *vaccines[] = {
        "Hepatitis B",    // Birth
        "DTP",            // 2 months
        "Polio",          // 2 months
        "Hib",            // 2 months
        "Rotavirus",      // 2 months
        "Pneumococcal",   // 2 months
        "MMR",            // 12 months
        "Chickenpox"      // 12 months
    };

    printf("\nVaccine Tracker for %d months old:\n", ageInMonths);

    if (ageInMonths < 2)
    {
        printf("Vaccines: %s\n", vaccines[0]); // Only Hepatitis B for 0 months
    }
    else if (ageInMonths < 3)
    {
        printf("Vaccines: %s, %s, %s, %s, %s\n", vaccines[1], vaccines[2], vaccines[3], vaccines[4], vaccines[5]);
    }
    else if (ageInMonths >= 12)
    {
        printf("Vaccines: %s, %s\n", vaccines[6], vaccines[7]);
    }
    else
    {
        printf("Vaccines: %s, %s, %s\n", vaccines[1], vaccines[2], vaccines[3]);
    }
}
  // this is for the  maximum number of diseases that can be stored
int n, p,options;

// this is for the  maximum number of diseases that can be stored
#define MAX_DISEASES 100 

// Array to store diseases and a counter
Disease diseaseDatabase[MAX_DISEASES];
int diseaseCount = 0;

void AddNewDisease() {
    if (diseaseCount >= MAX_DISEASES) {
        printf("\nThe disease database is full! Cannot add more diseases.\n");
        return;
    }

    printf("\nEnter the name of the disease: ");
    getchar(); // To consume the newline left by previous scanf
    fgets(diseaseDatabase[diseaseCount].name, 50, stdin);
    diseaseDatabase[diseaseCount].name[strcspn(diseaseDatabase[diseaseCount].name, "\n")] = '\0'; // Remove trailing newline

    printf("Enter the description of the disease: ");
    fgets(diseaseDatabase[diseaseCount].description, 500, stdin);
    diseaseDatabase[diseaseCount].description[strcspn(diseaseDatabase[diseaseCount].description, "\n")] = '\0'; // Remove trailing newline

    printf("Enter the treatment for the disease: ");
    fgets(diseaseDatabase[diseaseCount].treatment, 500, stdin);
    diseaseDatabase[diseaseCount].treatment[strcspn(diseaseDatabase[diseaseCount].treatment, "\n")] = '\0'; // Remove trailing newline

    diseaseCount++;
    printf("\nDisease added successfully!\nw");
    
    }

void ViewDiseases() {
    if (diseaseCount == 0) {
        printf("\nNo new diseases report have been added yet.\n");
        return;
    }

    printf("\nList of Diseases:\n");
    for (int i = 0; i < diseaseCount; i++) {
        printf("\nDisease %d:\n", i + 1);
        printf("Name: %s\n", diseaseDatabase[i].name);
        printf("Description: %s\n", diseaseDatabase[i].description);
        printf("Treatment: %s\n", diseaseDatabase[i].treatment);
    }
    printf("Thank you for the report!!, new disease updates coming very soon");
}

void HealthDatabase () {
    printf("Welcome to the Health Database!\n");
    printf("What would you like to ask for?\n\n");
    printf("1. Common Health Diseases on babies and treatment\n");
    printf("2. Add a new disease but u dont know what it is\n");
    printf("3. View new disease report\n");
    printf("4. Emergency Contact number\n\n");
    printf("Please enter your choice (1-4): ");
    scanf("%d", &options);

    switch (options) {
        case 1:
            printf("\n\nFOR YOUR INFORMATION : Those who categorized as babies are \nfrom 0 Days - 12 months since birth\n");
            printf(" - Is your baby cries too long??\n");
            printf(" - Is your baby have a high fever, struggled to breath and whining too long?\n");
            printf(" - Is your baby cannot lying on the bed but only 1 sided?\n");
            printf(" - Is your baby coughing when feeding or drinking?\n");
            printf(" - Is your baby had a red irritated skin on the diaper area?\n\n");
            printf("Choose option : ");
            scanf("%d", &n);
            if (n== 1) {
                printf("\nYour babies could be affected by Colic, Here's the explanation : \n");
                printf("Colic is a condition that causes a healthy baby to cry excessively and for long periods of time, often for no apparent reason.\nIt can be difficult for parents, but colic usually goes away on its own by the time a baby is 6 months old\n\n");
                printf("Causes : \n");
                printf("The cause of colic is unknown. It may result from numerous contributing factors.\n");
                printf("While a number of causes have been explored, it's difficult for researchers\nto account for all the important features, such as why it usually begins late in the first month of life, how it varies among infants, and others.\n");
                printf("Possible factors that cause colic : \n - Digestive system that isn't fully developed\n - Imbalance of healthy bacteria in the digestive tract\n - Food allergies or intolerances\n\n");
                printf("Treatment :\n");
                printf(" - Keep tracking what does the baby eat and drink to prevent unwanted things come through babies digest.\n");
                printf(" - Always try to comfort the baby so the baby will less often to cry.\n");
                printf(" - Some baby formula could be very sensitive into some babies, try to consult with doctor for a best solution\n\n");
                printf("Additional information : Although a bout of colic can be frightening to watch — especially for first-time parents — it isnt harmful to your baby health. Babies with the condition will eventually outgrow it. Typically, colic goes away by the time your baby is 3 to 4 months old. \n\n");
            }
            else if ( n== 2) {
                printf("\nYour babies could be affected by Bronchiolitis, Here's the explanation : \n");
                printf("Bronchiolitis is a common lung infection in babies and young children, caused by a virus.\nIt leads to inflammation and congestion in the small airways (bronchioles) of the lungs.\n\n");
                printf("Causes : \n");
                printf("Bronchiolitis is most often caused by the respiratory syncytial virus (RSV), but other viruses, such as influenza, can also cause it.\n");
                printf("It is spread through droplets from coughs or sneezes, or by touching contaminated surfaces.\n");
                printf("Infants under 6 months and those born prematurely are at higher risk of severe bronchiolitis.\n\n");
                printf("Possible symptoms of bronchiolitis : \n - Runny or stuffy nose\n - Cough\n - Fever\n - Wheezing or difficulty breathing\n - Decreased appetite\n\n");
                printf("Treatment :\n");
                printf(" - Make sure your baby stays hydrated by providing small, frequent feedings of breast milk, formula, or water (as recommended by your doctor).\n");
                printf(" - Use a cool-mist humidifier to keep the air moist and make breathing easier.\n");
                printf(" - Keep your baby upright to help with breathing.\n");
                printf(" - If symptoms worsen (e.g., severe breathing difficulties or dehydration), consult a doctor immediately.\n\n");
                printf("Additional information : While bronchiolitis can be distressing, most cases are mild and resolve within 1 to 2 weeks. Severe cases may require hospitalization for oxygen or other supportive care.\n\n");
            }
            else if ( n== 3) {
                printf("\nYour babies could be affected by an Ear Infection, Here's the explanation : \n");
                printf("An ear infection (otitis media) is a common condition in babies and young children. \nIt occurs when the middle ear becomes inflamed, often due to a bacterial or viral infection.\n\n");
                printf("Causes : \n");
                printf("Ear infections are often caused by bacteria or viruses that enter the middle ear, usually following a cold, sore throat, or upper respiratory infection.\n");
                printf("Babies are more prone to ear infections because their eustachian tubes are shorter and more horizontal, making it easier for fluid to get trapped.\n\n");
                printf("Possible symptoms of an ear infection : \n - Tugging or pulling at the ear\n - Fussiness or crying more than usual\n - Trouble sleeping\n - Fever (often mild but can be high)\n - Difficulty hearing or responding to sounds\n\n");
                printf("Treatment :\n");
                printf(" - Use a warm compress to soothe the baby's ear pain.\n");
                printf(" - Administer pain relievers, such as infant acetaminophen or ibuprofen, as recommended by your doctor.\n");
                printf(" - If the infection is bacterial, a doctor may prescribe antibiotics to clear it up.\n");
                printf(" - Keep your baby hydrated to help the immune system fight the infection.\n\n");
                printf("Additional information : Most ear infections improve on their own within a few days, but repeated infections may require further evaluation. \nIf your baby experiences recurrent ear infections, consult a doctor to discuss preventive measures or possible ear tube placement.\n\n");

            }
            else if ( n==4) {
                printf("\nYour babies could be affected by Reflux (GERD), Here's the explanation : \n");
                printf("Reflux, also known as gastroesophageal reflux disease (GERD), is a common condition in babies. \nIt occurs when stomach contents, including food and stomach acid, flow back into the esophagus, causing discomfort.\n\n");
                printf("Causes : \n");
                printf("Reflux happens because the lower esophageal sphincter (the muscle between the stomach and esophagus) is not fully developed in infants.\n");
                printf("As a result, stomach contents can easily flow back up into the esophagus, especially after eating.\n");
                printf("In some cases, reflux can be aggravated by food allergies, overfeeding, or lying flat after feeding.\n\n");
                printf("Possible symptoms of reflux : \n - Frequent spitting up or vomiting after feeding\n - Irritability or crying during or after feedings\n - Poor weight gain or feeding difficulties\n - Coughing, choking, or gagging during feedings\n - Arching the back or stiffening during or after feedings\n\n");
                printf("Treatment :\n");
                printf(" - Feed your baby in an upright position and keep them upright for 20-30 minutes after feeding.\n");
                printf(" - Offer smaller, more frequent feedings to avoid overfeeding.\n");
                printf(" - If you're breastfeeding, consider keeping a food diary to identify possible triggers.\n");
                printf(" - In severe cases, your doctor may recommend medications to reduce acid or treat the reflux.\n\n");
                printf("Additional information : Reflux is very common in babies, and most babies outgrow it by 12-18 months as their digestive systems mature. \nHowever, if your baby shows signs of severe discomfort, poor weight gain, or respiratory issues, consult your pediatrician for advice and possible treatment.\n\n");

            }
            else if ( n==5) {
                printf("\nYour babies could be affected by Diaper Rash, Here's the explanation : \n");
                printf("Diaper rash is a common condition that causes irritation and redness in the diaper area. \nIt usually occurs when a baby's skin becomes irritated by prolonged exposure to wet or dirty diapers.\n\n");
                printf("Causes : \n");
                printf("The most common cause of diaper rash is prolonged contact with urine or stool in a diaper.\n");
                printf("Other causes include chafing from the diaper, a yeast infection (commonly caused by Candida), or an allergic reaction to diaper products, wipes, or soaps.\n");
                printf("Antibiotics or a change in diet can sometimes lead to diaper rash as well.\n\n");
                printf("Possible symptoms of diaper rash : \n - Red, inflamed skin in the diaper area\n - Small bumps or pimples on the skin\n - Skin that appears shiny or raw\n - Irritation and discomfort, especially during diaper changes\n\n");
                printf("Treatment :\n");
                printf(" - Change diapers frequently to keep the skin dry and clean.\n");
                printf(" - Use a barrier cream or ointment with zinc oxide or petroleum jelly to protect the skin.\n");
                printf(" - Let your baby have some diaper-free time to allow the skin to heal.\n");
                printf(" - Avoid using scented or alcohol-based wipes, which can irritate the skin further.\n");
                printf(" - If the rash doesn’t improve within a few days, consult your pediatrician for advice or possible treatment.\n\n");
                printf("Additional information : Diaper rash is very common and usually not serious. Most cases can be managed at home with proper care and attention. However, if the rash is accompanied by blisters, fever, or doesn't improve with treatment, it may indicate a yeast infection or bacterial infection that requires medical attention.\n\n");

            }
            else {
                printf("wrong input, go back please\n");
            }
            break;
        case 2:
        AddNewDisease();
        break;
        case 3: 
        ViewDiseases();
        break;
        case 4 : 
            printf("In which region u are right now?\n");
            printf("1. Europe\n2.America\n3.Asia\n4.Other continent\n");
            printf("Choose option : ");
            scanf("%d", &p);
            if ( p == 1) {
                printf("Europe emergency contact number : 112 ");
            }
            else if ( p == 2) {
                printf("America emergency contact number : 911 ");
            }
            else if ( p == 3) {
                printf("Asia emergency contact number : 112 ");
            }
            else if ( p == 4 ) {
                printf("Sadly, we havent updated this one yet ( coming very soon )");
            }
            else {
                printf("wrong input, go back");
            }
        break;
        default :
        printf("Wrong input, go back please\n");

    }
    
}

// Sleep Tracker function
void startSleep(babySleep *tracker){
    if(tracker -> logCount >= MAX_LOGS){
        printf("Log is more than its capacity!");
        return;
    }

    sleepLog *session = &tracker -> logs[tracker -> logCount];
    session -> timeStart = time(NULL);

    printf("Shhh! The baby starts to sleep. Monitor: %s\n", ctime(&session->timeStart));
}

void endSleep(babySleep *tracker){
    if(tracker -> logCount >= MAX_LOGS){
        printf("No active sleep sessions needs to be monitored.\n");
        return;
    }

    sleepLog *session = &tracker -> logs[tracker -> logCount];
    session -> timeEnd = time(NULL);

    // calculate the duration in minutes
    session -> durationInmin = (session -> timeEnd - session -> timeStart) / 60;

    // convert from minutes into hours
    tracker->sleepTotal += (float)session->durationInmin / 60.0;

    printf("Baby is now fresh and awake! Duration: %d\n", session->durationInmin);

    tracker -> logCount++;
}

void sleepHistory(babySleep *tracker){
    if (tracker -> logCount == 0){
        printf("No logs or history of baby sleeping.\n");
        return;
    }

    printf("\n==== Baby Sleep History ====\n");
    for(int i = 0; i < tracker -> logCount; i++){
        sleepLog *session = &tracker -> logs[i];  
        printf("Session %d: \n", i+1);
        printf("   Started: %s\n", ctime(&session -> timeStart));
        printf("   Ended: %s\n", ctime(&session -> timeEnd));
        printf("   Duration: %d minutes\n", session->durationInmin);  
    }
}

void sleepSummary(babySleep *tracker){
    int recommHours = 0;  

    if (tracker -> logCount == 0){
        printf("No sleep data.\n");
        return;
    }

    int totalBabySleeps = tracker -> logCount;
    float avgDuration = tracker -> sleepTotal / totalBabySleeps;

    printf("\n===== Baby Sleep Summary =====\n");
    printf("Total Sleep Sessions: %d\n", tracker -> logCount);
    printf("Total Sleep Time: %.2f hours\n", tracker->sleepTotal);
    printf("Average Sleep Duration: %.2f hours\n", avgDuration);

    // monitoring total sleep hours of the baby
    if (tracker -> ageInMonth <= 3){         
        recommHours = 14; 
        printf("Newborns needs a very long time to sleep!\n");              
    }       
    else if (tracker->ageInMonth > 3 && tracker -> ageInMonth <= 12){         
        recommHours = 12;
        printf("The baby needs more time to be asleep!\n");    
    }      
    else if(tracker->ageInMonth > 12){         
        recommHours = 10;
        printf("The baby still needs more time to be asleep!\n");         
            
    }  
    else{             
        printf("Your baby is now a toddler, but still needs more sleep!\n");         
    }  

    printf("Recommended Sleep Duration: %d hours\n", recommHours);
    if (tracker->sleepTotal < recommHours) {  
        printf("Notice: Total sleep duration is below normal.\nPlease consult to a doctor.\n");
    } else {
        printf("Total sleep duration is within the healthy range.\n");
    }
}

void sleepTracker(babySleep *tracker){ 
    int choice;

   while (1){
    printf("\n--- Baby Sleep Tracker ---\n");
        printf("1. Start Sleep Session\n");
        printf("2. End Sleep Session\n");
        printf("3. View Sleep History\n");
        printf("4. Sleep Summary\n");
        printf("5. Exit\n");
        printf("Choose option: ");
        scanf("%d", &choice);
        getchar(); 

    switch(choice){
        case 1:
           startSleep(tracker);
           break;
        case 2: 
           endSleep(tracker);
           break;
        case 3:
           sleepHistory(tracker);
           break;
        case 4:
           sleepSummary(tracker);
           break;
        case 5:
           return;
        default:
           printf("Invalid option!");
    }
   }
} 