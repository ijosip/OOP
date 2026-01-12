# Student.h

```cpp
#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>
#include <iostream>
#include "Course.h"

class StudentOffice;

class Student {
    friend class StudentOffice;
    friend std::ostream& operator<<(std::ostream&, const Student&);
    friend std::istream& operator>>(std::istream&, Student&);

private:
    int id;
    std::string name;
    std::string study_program;
    int year;

    Course* enrolled_courses;
    size_t enrolled_count;

    Course* completed_courses;
    size_t completed_count;

    static int total_students;

public:
    Student(int id = 0,
            const std::string& name = "",
            const std::string& study_program = "",
            int year = 1);

    Student(const Student& other);
    Student(Student&& other) noexcept;
    Student& operator=(const Student& other);
    Student& operator=(Student&& other) noexcept;
    ~Student();

    static int get_total_students();

    Student& operator+=(const Course& c);
    Student& operator++();      // prefix
    Student operator++(int);    // postfix
};

#endif
```

# Student.cpp

```cpp
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
```

# Course.h

```cpp
#ifndef COURSE_H
#define COURSE_H

#include <string>
#include <iostream>

class Course {
private:
    std::string name;
    std::string code;
    int ects;

public:
    Course(const std::string& n = "", const std::string& c = "", int e = 5)
        : name(n), code(c), ects(e) {}

    int get_ects() const { return ects; }

    friend std::ostream& operator<<(std::ostream&, const Course&);
    friend std::istream& operator>>(std::istream&, Course&);
};

#endif
```

# Course.cpp

```cpp
#include "Course.h"

std::ostream& operator<<(std::ostream& os, const Course& c)
{
    os << c.name << " (" << c.code << ", " << c.ects << " ECTS)";
    return os;
}

std::istream& operator>>(std::istream& is, Course& c)
{
    is >> c.name >> c.code >> c.ects;
    return is;
}
```

# UniversityConstants.h

```cpp
#ifndef UNIVERSITY_CONSTANTS_H
#define UNIVERSITY_CONSTANTS_H

#include <iostream>

struct UniversityConstants {
    static const int MAX_ETCS_PER_YEAR = 60;
    static const int REQUIRED_ECTS_PER_YEAR = 45;

    static void print_university_rules()
    {
        std::cout << "MAX_ETCS_PER_YEAR=" << MAX_ETCS_PER_YEAR << "\n";
        std::cout << "REQUIRED_ECTS_PER_YEAR=" << REQUIRED_ECTS_PER_YEAR << "\n";
    }
};

#endif
```

# StudentOffice.h

```cpp
#ifndef STUDENT_OFFICE_H
#define STUDENT_OFFICE_H

#include <vector>
#include "Student.h"

class StudentOffice {
public:
    static void moveStudent(Student& s, std::string new_program);
    static void enroll_student(Student& s, const Course& c);
    static void process_exam_results(Student& s, const Course& c);
    static void update_student_years(std::vector<Student>& students);
};

#endif
```

# StudentOffice.cpp

```cpp
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
```

# main.cpp

```cpp
#include <vector>
#include "Student.h"
#include "StudentOffice.h"
#include "UniversityConstants.h"

int main()
{
    UniversityConstants::print_university_rules();

    Student s1(1, "Ana", "CS", 1);
    Student s2(2, "Marko", "Math", 1);

    std::vector<Student> students{ s1, s2 };

    Course c1("OOP", "CS101", 5);
    Course c2("ALG", "CS102", 5);

    StudentOffice::enroll_student(students[0], c1);
    StudentOffice::process_exam_results(students[0], c1);
    StudentOffice::update_student_years(students);

    for (const auto& s : students)
        std::cout << s << "\n";

    std::cout << "Total students: " << Student::get_total_students() << "\n";
}
```
