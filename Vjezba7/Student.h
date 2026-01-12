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









