/*
*****************************************************************************
                        Assignment 1 - Milestone 3
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

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's appointment schedule headers (date-specific or all records)
void displayScheduleTableHeader(const struct Date* date, int isAllRecords)
{
    printf("Clinic Appointments for the Date: ");

    if (isAllRecords)
    {
        printf("<ALL>\n\n");
        printf("Date       Time  Pat.# Name            Phone#\n"
            "---------- ----- ----- --------------- --------------------\n");
    }
    else
    {
        printf("%04d-%02d-%02d\n\n", date->year, date->month, date->day);
        printf("Time  Pat.# Name            Phone#\n"
            "----- ----- --------------- --------------------\n");
    }
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display a single appointment record with patient info. in tabular format
void displayScheduleData(const struct Patient* patient,
    const struct Appointment* appoint,
    int includeDateField)
{
    if (includeDateField)
    {
        printf("%04d-%02d-%02d ", appoint->date.year, appoint->date.month,
            appoint->date.day);
    }
    printf("%02d:%02d %05d %-15s ", appoint->time.hour, appoint->time.min,
        patient->patientNumber, patient->name);

    displayFormattedPhone(patient->phone.number);

    printf(" (%s)\n", patient->phone.description);
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
            menuAppointment(data);
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


// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Appointment Management
void menuAppointment(struct ClinicData* data)
{
    int selection;

    do {
        printf("Appointment Management\n"
            "==============================\n"
            "1) VIEW   ALL Appointments\n"
            "2) VIEW   Appointments by DATE\n"
            "3) ADD    Appointment\n"
            "4) REMOVE Appointment\n"
            "------------------------------\n"
            "0) Previous menu\n"
            "------------------------------\n"
            "Selection: ");
        selection = inputIntRange(0, 4);
        putchar('\n');
        switch (selection)
        {
        case 1:
            viewAllAppointments(data);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 2:
            viewAppointmentSchedule(data);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 3:
            addAppointment(data->appointments, data->maxAppointments,
                data->patients, data->maxPatient);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 4:
            removeAppointment(data->appointments, data->maxAppointments,
                data->patients, data->maxPatient);  // ToDo: You will need to create this function!
            suspend();
            break;
        }
    } while (selection);
}


// ---------------------------------------------------------------------------
// !!! INSERT/COPY YOUR MS#2 FUNCTION DEFINITIONS BELOW... !!!
// Note: Maintain the same order/sequence as it is listed in the header file
//       Properly organize/categorize any new functions accordingly
// ---------------------------------------------------------------------------


// Display's all patient data in the FMT_FORM | FMT_TABLE format
// (Copy your code from MS#2)
void displayAllPatients(const struct Patient patient[], int max, int fmt) {
    displayPatientTableHeader();
    int i;
    int none = 0;
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
// (Copy your code from MS#2)
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
// (Copy your code from MS#2)
void addPatient(struct Patient patient[], int max) {
    int i, count = 0, a = 0;
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
        printf("*** New patient record added ***\n");
        putchar('\n');
    }

}

// Edit a patient record from the patient array
// (Copy your code from MS#2)
void editPatient(struct Patient patient[], int max) {
    int number, i;

    printf("Enter the patient number: ");
    scanf("%d", &number);
    putchar('\n');

    i = findPatientIndexByPatientNum(number, patient, max);

    if (i == -1) {
        printf("ERROR: Patient record not found!\n");
        putchar('\n');
    }
    else {
        menuPatientEdit(&patient[i]);
    }

}


// Remove a patient record from the patient array
// (Copy your code from MS#2)
void removePatient(struct Patient patient[], int max) {
    int number, i;
    char character = 'x';
    printf("Enter the patient number: ");
    number = inputInt();
    i = findPatientIndexByPatientNum(number, patient, max);

    if (i == -1) {
        putchar('\n');
        printf("ERROR: Patient record not found!\n");
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
            putchar('\n');
        }
        else {
            strcpy(patient[i].name, "");
            patient[i].patientNumber = 0;
            strcpy(patient[i].phone.description, "");
            strcpy(patient[i].phone.number, "");
            printf("Patient record has been removed!\n");
            putchar('\n');
        }
    }
}

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// Milestone #3 mandatory functions...
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

// View ALL scheduled appointments
// Todo:

//displayScheduleData(const struct Patient* patient,const struct Appointment* appoint,int includeDateField)
void viewAllAppointments(const struct ClinicData* data) {
    int i=0, ii=0;
    int size;
    displayScheduleTableHeader(NULL, isAllRecord);
    size = appointmentSize(data->appointments, data->maxAppointments);
    AppointmentSort(data->appointments, size);
    for (i = 0; i < data->maxAppointments; i++)
    {
        for (ii = 0; ii < data->maxPatient; ii++)
        {
            if (data->appointments[i].patientNum == data -> patients[ii].patientNumber){
                displayScheduleData(&data->patients[ii], &data -> appointments[i], includeField);
            }
        }
    }
    putchar('\n');
}

// View appointment schedule for the user input date
// Todo:
void viewAppointmentSchedule(const struct ClinicData* data) {
    int date[25] = { 0 };
    int num[25] = { 0 };
    int numindex[20] = { 0 };
    int year, month,i,y, day,count=0,count2=0;
    int size = appointmentSize(data->appointments, data->maxAppointments);
    AppointmentSort(data->appointments, size);
    printf("Year        : ");
    year = inputInt();
    printf("Month (1-12): ");
    month = inputIntRange(1, 12);
    
    if (month == 2 && year % 4 == 1) {
        printf("Day (1-28)  : ");
        day = inputIntRange(1, 28);
    }
    else {
        printf("Day (1-29)  : ");
        day = inputIntRange(1, 29);
    }
    for (i = 0; i < size; i++) {
        if (year == data->appointments[i].date.year && month == data->appointments[i].date.month && day == data->appointments[i].date.day) {
            date[count] = i;
            num[count] = data->appointments[i].patientNum;
            count++;
        }
    }
    for (i = 0; i < size; i++) {
        for (y = 0; y< size; y++) {
            if (num[i] == 0) {
                i = 100;
                y = 100;
            }
            if (num[i] == data->patients[y].patientNumber) {
                numindex[count2] = y;
                count2++;
            }
            
        }
    }
    putchar('\n');

    displayScheduleTableHeader(&data->appointments[date[0]].date, 0);
    for (i = 0; i < count2; i++) {
        displayScheduleData(&data->patients[numindex[i]], &data->appointments[date[i]], 0);
    }
    putchar('\n');

}

// Add an appointment record to the appointment array
// Todo:
void addAppointment( struct Appointment* data,int Amax, struct Patient* patient, int Pmax) {
    int size = appointmentSize(data,Amax);
    int i, y=0;
    int stop = 1;
    int TF;
    if (Amax > size) {
        printf("Patient Number: ");
        data[size].patientNum = inputInt();
        int a = findPatientIndexByPatientNum(data[size].patientNum, patient, Pmax);
        if (a == -1) {
            putchar('\n');
            printf("*** No records found ***\n");
            putchar('\n');
        }
        else {
            while (stop) {
                printf("Year        : ");
                data[size].date.year = inputInt();
                printf("Month (1-12): ");
                data[size].date.month = inputIntRange(1, 12);
                if (data[size].date.month  == 2 && data[size].date.year % 4 == 1) {
                    printf("Day (1-28)  : ");
                    data[size].date.day = inputIntRange(1, 28);
                }
                else {
                    printf("Day (1-31)  : ");
                    data[size].date.day = inputIntRange(1, 31);
                }
                do {
                    printf("Hour (0-23)  : ");
                    data[size].time.hour = inputIntRange(0, 23);
                    printf("Minute (0-59): ");
                    data[size].time.min = inputIntRange(0, 59);
                    TF = timetest(data[size].time.hour , data[size].time.min);
                } while (TF == -1);

                for (i = 0; i < size; i++) {
                    if (data[size].date.year == data[i].date.year && data[size].date.month == data[i].date.month && data[size].date.day == data[i].date.day && data[size].time.hour == data[i].time.hour && data[size].time.min == data[i].time.min) {
                        y++;
                    }
                }
                if (y != 0) {
                    putchar('\n');
                    printf("ERROR: Appointment timeslot is not available!\n");
                    putchar('\n');
                    y = 0;
                    TF = -1;
                }
                else {
                    putchar('\n');
                    printf("*** Appointment scheduled! ***\n");
                    putchar('\n');
                    

                    stop = 0;
                }
            }
        }
    }
    AppointmentSort(data, size);
}

// Remove an appointment record from the appointment array
// Todo:
void removeAppointment(struct Appointment* data, int Amax, struct Patient* patient, int Pmax) {
    int size = appointmentSize(data, Amax);
    int i, y,index;
    int stop = 1;
    int TF = 0;
    int year;
    int month;
    int day;
    int num;
    printf("Patient Number: ");
    num = inputInt();
    int a = findPatientIndexByPatientNum(num, patient, Pmax);
    if (a == -1) {
        printf("ERROR: Patient record not found!\n");
        putchar('\n');
    }
    else {
        while (stop) {
            printf("Year        : ");
            year = inputInt();
            printf("Month (1-12): ");
            month = inputIntRange(1, 12);
            if (month == 2 && year % 4 == 1) {
                printf("Day(1 - 28) : ");
                day = inputIntRange(1, 28);
            }
            else {
                printf("Day (1-29)  : ");
                day = inputIntRange(1, 31);
            }
            for (i = 0; i < size; i++) {
                if (data[i].date.year==year && data[i].date.month==month && data[i].date.day==day && data[i].patientNum==num) {
                    y = i;
                    TF++;
                    stop = 0;
                }
            }
            if (TF == 0) {
                printf("Appointment does not exist\n");
            }
            else {
                for (i = 0; i < SIZE; i++) {
                    if (patient[i].patientNumber == num) {
                        index = i;
                    }
                }
                putchar('\n');
                displayPatientData(&patient[index], 1);
                printf("Are you sure you want to remove this appointment (y,n): ");
                char character = inputCharOption("yn");
                if (character == 'n') {
                    printf("Operation aborted.\n");
                    clearInputBuffer();
                    putchar('\n');
                }
                else {
                    putchar('\n');
                    printf("Appointment record has been removed!\n");
                    data[y].date.year = 0;
                    data[y].date.month = 0;
                    data[y].date.day = 0;
                    data[y].time.hour = 0;
                    data[y].time.min = 0;
                    data[y].patientNum = 0;
                    putchar('\n');
                }
                stop = 0;
            }
        }
    }
    AppointmentSort(data, size);

}

//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////

// Search and display patient record by patient number (form)
// (Copy your code from MS#2)
void searchPatientByPatientNumber(const struct Patient patient[], int max) {
    int number, i;
    printf("Search by patient number: ");
    number = inputInt();
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
// (Copy your code from MS#2)
void searchPatientByPhoneNumber(const struct Patient patient[], int max) {
    char phone[10 + 1];
    int i, count = 0;
    printf("Search by phone number: ");
    scanf("%s", phone);
    putchar('\n');
    displayPatientTableHeader();
    for (i = 0; i < max; i++) {
        if (strcmp(patient[i].phone.number, phone) == 0) {
            displayPatientData(&patient[i], 2);
            count++;
        }
    }

    if (count == 0) {
        putchar('\n');
        printf("*** No records found ***\n");
        putchar('\n');
    }
    else {
        putchar('\n');
    }
}

// Get the next highest patient number
// (Copy your code from MS#2)

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
// (Copy your code from MS#2)
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
// (Copy your code from MS#2)
void inputPatient(struct Patient* patient) {
    printf("Patient Data Input\n");
    printf("------------------\n");
    printf("Number: %05d\n", patient->patientNumber);
    printf("Name  : ");
    scanf(" %[^\n]", patient->name);
    int stop = 1;
    while (stop) {
        int i = strlen(patient->name);
        if (i > 15) {
            printf("ERROR: String length must be no more than 15 chars: ");
            scanf(" %[^\n]", patient->name);
        }
        else {
            stop = 0;
        }
    }
    putchar('\n');
    inputPhoneData(&patient->phone);
}

// Get user input for phone contact information
// (Copy your code from MS#2)
void inputPhoneData(struct Phone* phone)
{
    int selection;
    printf("Phone Information\n");
    printf("-----------------\n");
    printf("How will the patient like to be contacted?\n");
    printf("1. Cell\n");
    printf("2. Home\n");
    printf("3. Work\n");
    printf("4. TBD\n");
    printf("Selection: ");
    selection = inputIntRange(1, 4);
    printf("\n");
    switch (selection)
    {
    case 1:
        strcpy(phone->description, "CELL");
        printf("Contact: %s", phone->description);
        printf("\nNumber : ");
        valid_phone(phone->number, 10, 10);
        clearInputBuffer();
        putchar('\n');
        break;
    case 2:
        strcpy(phone->description, "HOME");
        printf("Contact: %s", phone->description);
        printf("\nNumber : ");
        valid_phone(phone->number, 10, 10);
        clearInputBuffer();
        putchar('\n');

        break;
    case 3:
        strcpy(phone->description, "WORK");
        printf("Contact: %s", phone->description);
        printf("\nNumber : ");
        valid_phone(phone->number, 10, 10);
        clearInputBuffer();
        putchar('\n');

        break;
    case 4:
        strcpy(phone->description, "TBD");
        break;
    }
}


//////////////////////////////////////
// FILE FUNCTIONS
//////////////////////////////////////

// Import patient data from file into a Patient array (returns # of records read)
/// ToDo:
int importPatients(const char* datafile, struct Patient patients[], int max){
    int i=0;
    int stop = 1;
    FILE *Patients = fopen(datafile, "r");
    do{
        fscanf(Patients, "%d|%[^|]|%[^|]|%10[^\n]", &patients[i].patientNumber, patients[i].name,
            patients[i].phone.description, patients[i].phone.number);
        i++;
        if (i == max) {
            stop = 0;
        }
        
    } while (feof(Patients)==0&&stop!=0);
    return i;
}

// Import appointment data from file into an Appointment array (returns # of records read)
// ToDo:
int importAppointments(const char* datafile, struct Appointment appoints[], int max){
    int i=0;
    int stop = 1;
    FILE* Appointment = fopen(datafile, "r");
    
    do {
        fscanf(Appointment, "%d,%d,%d,%d,%d,%d", &appoints[i].patientNum, &appoints[i].date.year,
            &appoints[i].date.month, &appoints[i].date.day, &appoints[i].time.hour, &appoints[i].time.min);
        i++;
        if (i == max) {
            stop = 0;
        }
    } while (feof(Appointment)==0&&stop != 0);
    return i;
}



void  AppointmentSort(struct Appointment* data, int size) {
    int i , y;
    struct Appointment temp;
    for (i = 0; i < size; i++){
        for (y = 0; y < size; y++){
            if (data[i].date.year < data[y].date.year)
            {
                temp = data[i];
                data[i] = data[y];
                data[y] = temp;
            }
            if (data[i].date.year == data[y].date.year && data[i].date.day < data[y].date.day) {
                temp = data[i];
                data[i] = data[y];
                data[y] = temp; 
            }
             if (data[i].date.year == data[y].date.year && data[i].date.day == data[y].date.day && data[i].time.hour < data[y].time.hour) {
                temp = data[i];
                data[i] = data[y];
                data[y] = temp;
            }
             if (data[i].date.year == data[y].date.year && data[i].date.day == data[y].date.day && data[i].time.hour == data[y].time.hour && data[i].time.min < data[y].time.min) {
                temp = data[i];
                data[i] = data[y];
                data[y] = temp;
            }
        } 
    } 
}



int appointmentSize(const struct Appointment* data, int max){
    int size = 0;
    int i;
    for (i = 0; i < max; i++)
    {
        if (data[i].patientNum != 00000)
        {
            size++;
        }
    }
    return size;
}

int timetest(int a, int b) {
    int c = b % 30;
    if (a > 14 || a < 10 || c != 0 ||( a >= 14 && b>0)) {
        printf("ERROR: Time must be between 10:00 and 14:00 in 30 minute intervals.\n\n");
        return -1;
    }
    else {
        return 1;
    }
}

void valid_phone(char* string, int min, int max) {
    char str[9999];
    int stop = 1;
    int num = 0;
    int i;
    while (stop != 0) {
        scanf(" %9999[^\n]", str);
        int length = 0;
        length = strlen(str);
        for (i = 0; str[i] != '\0'; i++) {
            if (str[i] >= '0' && str[i] <= '9') {
                num++;
            }
        }
        if (min == max) {
            if (length > max || length < min || num != 10) {
                printf("Invalid 10-digit number! Number: ");
                clearInputBuffer();
                num = 0;
            }
            else {
                stop = 0;
            }
        }
        
    }

    strcpy(string, str);
}