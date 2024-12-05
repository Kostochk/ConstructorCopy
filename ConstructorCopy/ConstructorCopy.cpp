#include <iostream>
#include <string>

using namespace std;

class Student {
private:
    string name;
    int age;

public:
    Student() : name("Noname"), age(0) {}

    Student(string name, int age) : name(name), age(age) {}

    void PrintInfo() const {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

class Group {
private:
    Student* students; 
    int studentCount;  
public:
    Group() : students(nullptr), studentCount(0) {}

    Group(int count) : studentCount(count) {
        students = new Student[studentCount];
    }

    ~Group() {
        delete[] students;
    }

    Group(const Group& other) : studentCount(other.studentCount) {
        students = new Student[studentCount];
        for (int i = 0; i < studentCount; ++i) {
            students[i] = other.students[i];
        }
    }

    void AddStudent(int index, string name, int age) {
        if (index >= 0 && index < studentCount) {
            students[index] = Student(name, age);
        }
    }

    void PrintGroupInfo() const {
        cout << "Grop got " << studentCount << " Students:" << endl;
        for (int i = 0; i < studentCount; ++i) {
            cout << "Student " << i + 1 << ": ";
            students[i].PrintInfo();
        }
    }
};

int main() {
    Group group1(3);

    group1.AddStudent(0, "Olena", 20);
    group1.AddStudent(1, "Kostya", 22);
    group1.AddStudent(2, "Boris", 19);

    cout << "Info about first group:" << endl;
    group1.PrintGroupInfo();

    Group group2 = group1;

    cout << "\nInfo from secong group: " << endl;
    group2.PrintGroupInfo();

    return 0;
}
