#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

class Student {
   
private:
    string name;
    string surname;
    int grade;
        
public:
    Student(string name, string surname, int grade) :name(name), surname(surname), grade(grade) {};
    Student(const Student& student) :name(student.name), surname(student.surname), grade(student.grade) {};

   
public:
    Student& operator=(const Student& student)
    {
        name = student.name;
        surname = student.surname;
        grade = student.grade;
        return *this;
    }

    int CompareName(const Student& student) const 
    {        
        return name.compare(student.name);
    }

    int CompareSurname(const Student& student) const 
    {
        return surname.compare(student.surname);
    }
    int CompareGrade(const Student& student) const 
    {
        if (grade < student.grade)
            return -1;
        if (grade > student.grade)
            return 1;
        return 0;
    }

    friend ostream& operator<< (ostream& stream, const Student& student) {
        stream << "Grade:" << setw(2) << student.grade;
        stream << "   Name:" << setw(10) << student.name;
        stream << "   Surname:" << setw(10) << student.surname << endl;
        return stream;
    }
};

void Init(vector<Student>& students)
{
    students.emplace_back("Юрий", "Иванов", 2);
    students.emplace_back("Николай", "Семёнов", 1);
    students.emplace_back("Юлия", "Мирошниченко", 3);
    students.emplace_back("Сергей", "Найдёнов", 4);
    students.emplace_back("Василий", "Алехин", 5);
    students.emplace_back("Инна", "Самсонова", 2);
}

void Print(const vector<Student>& students)
{
    for (const Student& student : students)
        cout << student;
}
int main()
{
    setlocale(LC_ALL, "ru");
    vector<Student> students;

    Init(students);
    cout << "Начальный список: :" << endl;
    Print(students);

    //Сортировка по имени по возрастанию  
    sort(students.begin(), students.end(), [](const Student& left, const Student& right) {return left.CompareName(right) < 0; });
    cout << "\nСортировка по имени по возрастанию:" << endl;
    Print(students);

    //Стабильная сортировка по фамилии по возрастанию 
    sort(students.begin(), students.end(), [](const Student& left, const Student& right) {return left.CompareSurname(right) < 0; });
    cout << "\nСортировка по фамилии по возрастанию:" << endl;
    Print(students);
        
    sort(students.begin(), students.end(), [](const Student& left, const Student& right) {return left.CompareGrade(right) < 0; });
    cout << "\nПервые три студента учатся на меньшем курсе:" << endl;
    Print(students);
    system("pause");
    return 0;
}
