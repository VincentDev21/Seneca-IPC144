/*
*****************************************************************************
                        Assignment 1 - Milestone 2
Full Name  : Vincent Le
Student ID#: 131117228
Email      : vle21@myseneca.ca
Section    : NJJ

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
// include the user library "core" so we can use those functions
#include "core.h"
// include the user library "clinic" where the function prototypes are declared
#include "clinic.h"


//////////////////////////////////////
// DISPLAY FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's the patient table header (table format)
void displayPatientTableHeader(void)
{
    printf("Pat.# Name            Phone#\n"
        "----- --------------- --------------------\n");
}
// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Displays a single patient record in FMT_FORM | FMT_TABLE format
void displayPatientData(const struct Patient* patient, int fmt)
{
    if (fmt == FMT_FORM)
    {
        printf("Name  : %s\n"
            "Number: %05d\n"
            "Phone : ", patient->name, patient->patientNumber);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
    else
    {
        printf("%05d %-15s ", patient->patientNumber,
            patient->name);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
}


//////////////////////////////////////
// MENU & ITEM SELECTION FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// main menu
void menuMain(struct ClinicData* data)
{
    int selection;

    do {
        printf("Veterinary Clinic System\n"
            "=========================\n"
            "1) PATIENT     Management\n"
            "2) APPOINTMENT Management\n"
            "-------------------------\n"
            "0) Exit System\n"
            "-------------------------\n"
            "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');
        switch (selection)
        {
        case 0:
            printf("Are you sure you want to exit? (y|n): ");
            selection = !(inputCharOption("yn") == 'y');
            putchar('\n');
            if (!selection)
            {
                printf("Exiting system... Goodbye.\n\n");
            }
            break;
        case 1:
            menuPatient(data->patients, data->maxPatient);
            break;
        case 2:
            printf("<<< Feature not yet available >>>\n\n");
            break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient Management
void menuPatient(struct Patient patient[], int max)
{
    int selection;

    do {
        printf("Patient Management\n"
            "=========================\n"
            "1) VIEW   Patient Data\n"
            "2) SEARCH Patients\n"
            "3) ADD    Patient\n"
            "4) EDIT   Patient\n"
            "5) REMOVE Patient\n"
            "-------------------------\n"
            "0) Previous menu\n"
            "-------------------------\n"
            "Selection: ");
        selection = inputIntRange(0, 5);
        putchar('\n');
        switch (selection)
        {
        case 1:
            displayAllPatients(patient, max, FMT_TABLE);
            suspend();
            break;
        case 2:
            searchPatientData(patient, max);
            break;
        case 3:
            addPatient(patient, max);
            suspend();
            break;
        case 4:
            editPatient(patient, max);
            break;
        case 5:
            removePatient(patient, max);
            suspend();
            break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient edit
void menuPatientEdit(struct Patient* patient)
{
    int selection;

    do {
        printf("Edit Patient (%05d)\n"
            "=========================\n"
            "1) NAME : %s\n"
            "2) PHONE: ", patient->patientNumber, patient->name);

        displayFormattedPhone(patient->phone.number);

        printf("\n"
            "-------------------------\n"
            "0) Previous menu\n"
            "-------------------------\n"
            "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');

        if (selection == 1)
        {
            printf("Name  : ");
            inputCString(patient->name, 1, NAME_LEN);
            putchar('\n');
            printf("Patient record updated!\n\n");
        }
        else if (selection == 2)
        {
            inputPhoneData(&patient->phone);
            printf("Patient record updated!\n\n");
        }

    } while (selection);
}


// ---------------------------------------------------------------------------
// !!! Put all the remaining function definitions below !!!
// Note: Maintain the same order/sequence as it is listed in the header file
// ---------------------------------------------------------------------------

// Display's all patient data in the FMT_FORM | FMT_TABLE format
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void displayAllPatients(const struct Patient patient[], int max, int fmt) {
    displayPatientTableHeader();
    int i;
    int none=0;
    for (i = 0; i < max; i++) {
        if (patient[i].patientNumber != 00000) {
            displayPatientData(&patient[i], fmt);
        }
        else {
            none++;
        }
    }
    if (none == 7) {
        printf("*** No records found ***");
    }
    printf("\n");
}

// Search for a patient record based on patient number or phone number
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void searchPatientData(const struct Patient patient[], int max) 
{
    int selection;

    do {
        printf("Search Options\n");
        printf("==========================\n");
        printf("1) By patient number\n");
        printf("2) By phone number\n");
        printf("..........................\n");
        printf("0) Previous menu\n");
        printf("..........................\n");
        printf("Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');
        switch (selection)
        {
        case 1:
            searchPatientByPatientNumber(patient, max);
            clearInputBuffer();
            suspend();
            break;
        case 2:
            searchPatientByPhoneNumber(patient, max);
            clearInputBuffer();
            suspend();
            break;
        }
    } while (selection);
}



// Add a new patient record to the patient array
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void addPatient(struct Patient patient[], int max) {
    int i,count=0, a=0;
    int number[7];
    for (i = 0; i < max; i++) {
        if (patient[i].patientNumber == 00000) {
            count++;
            number[a] = i;
            a++;
        }
    }
    if (count == 0) {
        printf("ERROR: Patient listing is FULL!\n");
        putchar('\n');
    }
    else {
        patient[number[0]].patientNumber = nextPatientNumber(patient, max);
        inputPatient(&patient[number[0]]);
        clearInputBuffer();
        printf("\n*** New patient record added ***\n");
        putchar('\n');
    }
    
}


// Edit a patient record from the patient array
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)

void editPatient(struct Patient patient[], int max) {
    int number,i,Selection,stop=0;
    
    printf("Enter the patient number: ");
    scanf("%d", &number);
    
    i= findPatientIndexByPatientNum(number, patient, max);

    if (i == -1) {
        putchar('\n');
        printf("ERROR: Patient record not found!\n");
        putchar('\n');
    }
    else {
        while (stop != 1) {
            putchar('\n');
            printf("Edit Patient (%05d)\n", patient[i].patientNumber);
            printf("=========================\n");
            printf("1) NAME : %s\n", patient[i].name);
            printf("2) PHONE: ");
            displayFormattedPhone(patient[i].phone.number);
            printf("\n-------------------------\n");
            printf("0) Previous menu\n");
            printf("-------------------------\n");
            printf("Selection: ");
            Selection = inputIntRange(0, 2);
            switch (Selection)
            {
            case 0:
                putchar('\n');
                stop += 1;
                break;
            case 1:
                putchar('\n');
                printf("Name  : ");
                scanf(" %[^\n]", patient[i].name);
                putchar('\n');
                printf("Patient record updated!");
                putchar('\n');
                break;
            case 2:
                inputPhoneData(&patient[i].phone);
                putchar('\n');
                printf("Patient record updated!");
                putchar('\n');
                break;
            }
            
        }
    }
    
}

// Remove a patient record from the patient array
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void removePatient(struct Patient patient[], int max) {
    int number, i;
    char character = 'x';
    printf("Enter the patient number: ");
    scanf("%d", &number);
    i = findPatientIndexByPatientNum(number, patient, max);

    if (i == -1) {
        putchar('\n');
        printf("ERROR: Patient record not found!\n");
        clearInputBuffer();
        putchar('\n');
    }
    else {
        putchar('\n');
        displayPatientData(&patient[i], 1);
        putchar('\n');
        printf("Are you sure you want to remove this patient record? (y/n): ");
        character = inputCharOption("yn");
        if (character == 'n') {
            printf("Operation aborted.\n");
            clearInputBuffer();
            putchar('\n');
        }
        else {
            strcpy(patient[i].name, "");
            patient[i].patientNumber = 0;
            strcpy(patient[i].phone.description, "");
            strcpy(patient[i].phone.number, "");
            printf("Patient record has been removed!\n");
            putchar('\n');
            clearInputBuffer();
        }
    }
}


//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////

// Search and display patient record by patient number (form)
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void searchPatientByPatientNumber(const struct Patient patient[], int max) {
    int number,i;
    printf("Search by patient number: ");
    scanf("%d", &number);
    putchar('\n');

    i = findPatientIndexByPatientNum(number, patient, max);
    if (i == -1) {
        printf("*** No records found ***\n");
        putchar('\n');
    }
    else {
        displayPatientData(&patient[i], 1);
        putchar('\n');
    }
}


// Search and display patient records by phone number (tabular)
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void searchPatientByPhoneNumber(const struct Patient patient[], int max) {
    char phone[10+1];
    int i,count=0;
    printf("Search by phone number: ");
    scanf("%s", phone);
    putchar('\n');
    displayPatientTableHeader();
    for (i = 0; i < max; i++) {
        if (strcmp(patient[i].phone.number, phone)==0) {
            displayPatientData(&patient[i], 2);
            count++;
        }
    }
    
    if (count==0){
        putchar('\n');
        printf("*** No records found ***\n");
        putchar('\n');
    }
    else {
        putchar('\n');
    }
}

// Get the next highest patient number
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
int nextPatientNumber(const struct Patient patient[], int max) {
    int i;
    int arr[1];
    for (i = 1; i < max; ++i) {
        if (arr[0] < patient[i].patientNumber) {
            arr[0] = patient[i].patientNumber;
        }
    }
    arr[0] += 1;
    int Number = arr[0];
    return Number;
}

// Find the patient array index by patient number (returns -1 if not found)
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
int findPatientIndexByPatientNum(int Number, const struct Patient patient[], int max) {
    int i;
    for (i = 0; i < max; i++) {
        if (patient[i].patientNumber == Number) {
            return i;
        }
    }
    return -1;
}



//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

// Get user input for a new patient record
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void inputPatient(struct Patient* patient) {
    printf("Patient Data Input\n");
    printf("------------------\n");
    printf("Number: %05d\n",patient->patientNumber);
    printf("Name  : ");
    scanf(" %[^\n]", patient->name);
    inputPhoneData(&patient->phone);
}

// Get user input for phone contact information
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void inputPhoneData(struct Phone* phone) {
    int selection,stop=1;
    printf("\nPhone Information\n");
    printf("-----------------\n");
    printf("How will the patient like to be contacted?\n");
    printf("1. Cell\n");
    printf("2. Home\n");
    printf("3. Work\n");
    printf("4. TBD\n");
    printf("Selection: ");
    scanf("%d", &selection);
    while (stop != 0) {
        if (selection > 4 || selection < 0) {
            printf("ERROR! Value must be between %d and %d inclusive: ", 1,4);
            scanf("%d", &selection);
        }
        else {
            switch (selection)
            {
            case 1:
                putchar('\n');
                printf("Contact: CELL\n");
                strcpy(phone->description, "CELL");
                printf("Number : ");
                scanf(" %[^\n]", phone->number);
                break;
            case 2:
                putchar('\n');
                printf("Contact: HOME\n");
                strcpy(phone->description, "HOME");
                printf("Number : ");
                scanf(" %[^\n]", phone->number);
                break;
            case 3:
                putchar('\n');
                printf("Contact: WORK\n");
                strcpy(phone->description, "WORK");
                printf("Number : ");
                scanf(" %[^\n]", phone->number);
                break;
            case 4:
                strcpy(phone->description, "TBD");
                break;
            }
            stop = 0;
        }
    }
}