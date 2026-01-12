#include "Student.h"
#include "UniversityConstants.h"

int Student::total_students = 0;

Student::Student(int id, const std::string& name,
                 const std::string& study_program, int year)
    : id(id), name(name), study_program(study_program), year(year),
      enrolled_courses(nullptr), enrolled_count(0),
      completed_courses(nullptr), completed_count(0)
{
    ++total_students;
}

Student::Student(const Student& other)
    : id(other.id), name(other.name), study_program(other.study_program),
      year(other.year), enrolled_count(other.enrolled_count),
      completed_count(other.completed_count)
{
    enrolled_courses = enrolled_count ? new Course[enrolled_count] : nullptr;
    for (size_t i = 0; i < enrolled_count; ++i)
        enrolled_courses[i] = other.enrolled_courses[i];

    completed_courses = completed_count ? new Course[completed_count] : nullptr;
    for (size_t i = 0; i < completed_count; ++i)
        completed_courses[i] = other.completed_courses[i];

    ++total_students;
}

Student::Student(Student&& other) noexcept
    : id(other.id), name(std::move(other.name)),
      study_program(std::move(other.study_program)), year(other.year),
      enrolled_courses(other.enrolled_courses), enrolled_count(other.enrolled_count),
      completed_courses(other.completed_courses), completed_count(other.completed_count)
{
    other.enrolled_courses = nullptr;
    other.completed_courses = nullptr;
    other.enrolled_count = other.completed_count = 0;
    ++total_students;
}

Student& Student::operator=(const Student& other)
{
    if (this == &other) return *this;

    delete[] enrolled_courses;
    delete[] completed_courses;

    id = other.id;
    name = other.name;
    study_program = other.study_program;
    year = other.year;

    enrolled_count = other.enrolled_count;
    completed_count = other.completed_count;

    enrolled_courses = enrolled_count ? new Course[enrolled_count] : nullptr;
    for (size_t i = 0; i < enrolled_count; ++i)
        enrolled_courses[i] = other.enrolled_courses[i];

    completed_courses = completed_count ? new Course[completed_count] : nullptr;
    for (size_t i = 0; i < completed_count; ++i)
        completed_courses[i] = other.completed_courses[i];

    return *this;
}

Student& Student::operator=(Student&& other) noexcept
{
    if (this == &other) return *this;

    delete[] enrolled_courses;
    delete[] completed_courses;

    id = other.id;
    name = std::move(other.name);
    study_program = std::move(other.study_program);
    year = other.year;

    enrolled_courses = other.enrolled_courses;
    completed_courses = other.completed_courses;
    enrolled_count = other.enrolled_count;
    completed_count = other.completed_count;

    other.enrolled_courses = nullptr;
    other.completed_courses = nullptr;
    other.enrolled_count = other.completed_count = 0;

    return *this;
}

Student::~Student()
{
    delete[] enrolled_courses;
    delete[] completed_courses;
    --total_students;
}

int Student::get_total_students()
{
    return total_students;
}

Student& Student::operator+=(const Course& c)
{
    Course* tmp = new Course[enrolled_count + 1];
    for (size_t i = 0; i < enrolled_count; ++i)
        tmp[i] = enrolled_courses[i];
    tmp[enrolled_count++] = c;

    delete[] enrolled_courses;
    enrolled_courses = tmp;
    return *this;
}

Student& Student::operator++()
{
    int ects = 0;
    for (size_t i = 0; i < completed_count; ++i)
        ects += completed_courses[i].get_ects();

    if (ects >= UniversityConstants::REQUIRED_ECTS_PER_YEAR)
        ++year;

    return *this;
}

Student Student::operator++(int)
{
    Student temp(*this);
    ++(*this);
    return temp;
}

std::ostream& operator<<(std::ostream& os, const Student& s)
{
    os << s.id << " " << s.name << " " << s.study_program << " year:" << s.year;
    return os;
}

std::istream& operator>>(std::istream& is, Student& s)
{
    is >> s.id >> s.name >> s.study_program >> s.year;
    return is;
}
