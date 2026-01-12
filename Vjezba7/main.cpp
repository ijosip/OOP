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
