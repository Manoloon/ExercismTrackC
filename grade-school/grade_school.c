#include "grade_school.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void init_roster(roster_t *new_roster)
{
    if(new_roster == NULL) return;
    new_roster->count = 0;
}

roster_t get_grade(roster_t *roster, uint8_t desiredGrade)
{
    roster_t* new_roster = malloc(sizeof(roster_t));
    if(new_roster == NULL) return *roster;
    student_t* student = malloc(sizeof(student_t));
    for(size_t i = 0; i < roster->count;++i)
    {
        if(roster->students[i].grade == desiredGrade)
        {
            student->grade = roster->students[i].grade;
            strcpy(student->name,roster->students[i].name);
            new_roster->students[i] = *student;
            new_roster->count++;
        }
    }
    return *new_roster;
}

bool add_student(roster_t *roster, char* name, uint8_t grade)
{
    if(roster == NULL || *name == '\0') return false;
    student_t* new_student = malloc(sizeof(student_t));
    if(new_student == NULL) return false;
    new_student->grade = grade;
    strcpy (new_student->name,name);
    size_t pos = 0; 
    for(size_t i = 0 ; i < roster->count;++i)
    {
        if(strcmp(roster->students[i].name,name) == 0) return false;
        if(roster->students[i].grade > grade)
        {
            pos = i-1;
        }
        else
        {
            pos = i + 1;
        }
    }
    // shift
    for(size_t i = 0; i > pos; i--)
    {
        roster->students[i] = roster->students[i - 1];
    }
    roster->students[pos] = *new_student;
    roster->count++;
    return true;
}
