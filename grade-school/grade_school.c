#include "grade_school.h"
#include <stdlib.h>

void init_roster(roster_t *new_roster)
{
    student_t* students = malloc(sizeof(student_t)* MAX_STUDENTS);
    new_roster->count = 0;
}

roster_t get_grade(roster_t *roster, uint8_t desiredGrade)
{
    roster_t new_roster;
    return new_roster;
}

bool add_student(roster_t *roster, char* name, uint8_t grade)
{
    return false;
}
