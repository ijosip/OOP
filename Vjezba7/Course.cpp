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
