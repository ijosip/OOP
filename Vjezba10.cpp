#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <cmath>
#include <fstream>
#include <string>

bool is_power_of_two(int x) {
    return x > 0 && (x & (x - 1)) == 0;
}

void task1() {
    std::vector<int> v{1, 3, 4, 6, 7, 8, 10, 15, 16, 21};

    auto first_odd = std::find_if(v.begin(), v.end(), [](int x) { return x % 2 != 0; });
    if (first_odd != v.end())
        std::cout << "Prvi neparni: " << *first_odd << '\n';

    int odd_count = std::count_if(v.begin(), v.end(), [](int x){ return x % 2 != 0; });
    int odd_sum = std::accumulate(v.begin(), v.end(), 0, [](int sum, int x){ return x % 2 != 0 ? sum + x : sum; });
    double odd_avg = odd_count > 0 ? static_cast<double>(odd_sum)/odd_count : 0.0;

    std::cout << "Broj neparnih: " << odd_count << '\n';
    std::cout << "Prosjek neparnih: " << odd_avg << '\n';

    std::replace_if(v.begin(), v.end(), is_power_of_two, 2);

    std::vector<int> even, odd;
    std::copy_if(v.begin(), v.end(), std::back_inserter(even), [](int x){ return x % 2 == 0; });
    std::copy_if(v.begin(), v.end(), std::back_inserter(odd), [](int x){ return x % 2 != 0; });

    std::sort(even.begin(), even.end());
    std::sort(odd.begin(), odd.end());

    std::cout << "Parni: ";
    std::copy(even.begin(), even.end(), std::ostream_iterator<int>(std::cout," "));
    std::cout << "\nNeparni: ";
    std::copy(odd.begin(), odd.end(), std::ostream_iterator<int>(std::cout," "));
    std::cout << "\n\n";
}

namespace math_utils {
    struct Point { double x{}, y{}; };

    double distance(const Point& a, const Point& b) {
        return std::hypot(a.x - b.x, a.y - b.y);
    }

    Point centroid(const std::vector<Point>& pts) {
        Point sum = std::accumulate(pts.begin(), pts.end(), Point{},
            [](Point acc, const Point& p){ acc.x+=p.x; acc.y+=p.y; return acc; });
        return {sum.x/static_cast<double>(pts.size()), sum.y/static_cast<double>(pts.size())};
    }
}

void task2() {
    using namespace math_utils;

    std::ifstream file("points.txt");
    std::vector<Point> points{ std::istream_iterator<Point>(file), std::istream_iterator<Point>() };

    std::sort(points.begin(), points.end(), [](const Point& a, const Point& b){ return distance(a,{0,0}) < distance(b,{0,0}); });

    int first_quadrant = std::count_if(points.begin(), points.end(), [](const Point& p){ return p.x>0 && p.y>0; });

    Point c = centroid(points);

    std::transform(points.begin(), points.end(), points.begin(), [](Point p){ p.x+=5; p.y+=3; return p; });

    points.erase(std::remove_if(points.begin(), points.end(), [](const Point& p){ return p.x<0 && p.y<0; }), points.end());

    std::cout << "Centroid: (" << c.x << ", " << c.y << ")\n";
    std::cout << "Prvi kvadrant: " << first_quadrant << "\n";
    for(const auto& p : points)
        std::cout << "(" << p.x << ", " << p.y << ")\n";
    std::cout << '\n';
}

namespace student_records {
    struct Student { std::string ime, prezime; int bodovi; };

    int bodovi_u_ocjenu(int b) {
        if (b<40) return 1;
        if (b<55) return 2;
        if (b<70) return 3;
        if (b<85) return 4;
        return 5;
    }
}

void task3() {
    using namespace student_records;

    std::ifstream file("studenti.txt");
    std::vector<Student> students{ std::istream_iterator<Student>(file), std::istream_iterator<Student>() };

    students.erase(std::remove_if(students.begin(), students.end(), [](const Student& s){ return s.bodovi < 40; }), students.end());

    std::transform(students.begin(), students.end(), students.begin(),
        [](Student s){ s.bodovi = bodovi_u_ocjenu(s.bodovi); return s; });

    double avg = std::accumulate(students.begin(), students.end(), 0.0,
        [](double sum, const Student& s){ return sum + s.bodovi; }) / static_cast<double>(students.size());

    std::sort(students.begin(), students.end(), [](const Student& a, const Student& b){ return a.prezime < b.prezime; });

    for(const auto& s : students)
        std::cout << s.ime << " " << s.prezime << " ocjena: " << s.bodovi << '\n';
    std::cout << "Prosjek ocjena: " << avg << "\n\n";
}

int main() {
    task1();
    task2();
    task3();
}
