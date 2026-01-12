#include "StudentOffice.h"
#include "UniversityConstants.h"

void StudentOffice::moveStudent(Student& s, std::string new_program)
{
    s.study_program = std::move(new_program);
}

void StudentOffice::enroll_student(Student& s, const Course& c)
{
    int ects = 0;
    for (size_t i = 0; i < s.enrolled_count; ++i)
        ects += s.enrolled_courses[i].get_ects();

    if (ects + c.get_ects() <= UniversityConstants::MAX_ETCS_PER_YEAR)
        s += c;
}

void StudentOffice::process_exam_results(Student& s, const Course& c)
{
    Course* tmp = new Course[s.completed_count + 1];
    for (size_t i = 0; i < s.completed_count; ++i)
        tmp[i] = s.completed_courses[i];
    tmp[s.completed_count++] = c;

    delete[] s.completed_courses;
    s.completed_courses = tmp;
}

void StudentOffice::update_student_years(std::vector<Student>& students)
{
    for (auto& s : students)
        ++s;
}
