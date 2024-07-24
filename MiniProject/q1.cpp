#include <iostream>
#include <vector>
using namespace std;

class Student
{
private:
    int ID;
    string name;
    int age;
    int marks[3];
    float avg = 0;

public:
    void get_info()
    {
        cout << "Enter name of student: ";
        cin >> name;
        cout << "Enter ID of student: ";
        cin >> ID;
        cout << "Enter age of student: ";
        cin >> age;
        for (int i = 0; i < 3; i++)
        {
            cout << "Enter mark of subject " << i + 1 << ": ";
            cin >> marks[i];
        }
        avg = average();
    }

    float average()
    {
        return (marks[0] + marks[1] + marks[2]) / 3.0;
    }

    void display()
    {
        cout << "Name: " << name << endl;
        cout << "ID: " << ID << endl;
        cout << "Age: " << age << endl;
        for (int i = 0; i < 3; i++)
        {
            cout << "Marks of subject " << i + 1 << ": " << marks[i] << endl;
        }
        cout << "Average is: " << average() << endl;
    }
    int get_id()
    {
        return ID;
    }
    int get_average()
    {
        return avg;
    }
    void change_mark(int new_mark, int index)
    {
        marks[index] = new_mark;
    }
};

int main()
{
    int n;
    int S_ID;
    int new_mark, pos;
    int index = 0;
    int choice, size;
    float max_avg;
    //////
    vector<Student> vector_student;

    while (1)
    {
        cout << "1.Add student." << endl;
        cout << "2.Display all student." << endl;
        cout << "3.Display Average all student." << endl;
        cout << "4.Display Topper" << endl;
        cout << "5.Search student by ID." << endl;
        cout << "6.Update student marks." << endl;
        cout << "7.Exit." << endl;
        cout << "Enter your choice, please:";
        try
        {
            cin >> choice;
            if (cin.fail())
            {
                throw 0;
            }
            switch (choice)
            {
            case 1:
                cout << "Enter number of student: ";
                cin >> n;

                for (int i = 0; i < n; i++)
                {
                    Student new_student;
                    new_student.get_info();
                    vector_student.push_back(new_student);
                }
                break;
            case 2:
                size = vector_student.size();
                for (int i = 0; i < size; i++)
                {
                    vector_student[i].display();
                }
                break;

            case 3:
                cout << "key 3" << endl;
                size = vector_student.size();
                for (int i = 0; i < size; i++)
                {
                    cout << "Average marks of student " << i + 1 << endl;
                    cout << vector_student[i].get_average() << endl;
                }
                break;
            case 4:
                max_avg = vector_student[0].get_average();
                size = vector_student.size();
                for (int i = 1; i < size; i++)
                {
                    if (vector_student[i].get_average() > max_avg)
                    {
                        max_avg = vector_student[i].get_average();
                        index = i;
                    }
                }

                cout << "Student with the highest average:" << endl;
                vector_student[index].display();
                cout << "Max Average: " << max_avg << endl;
                break;
            case 5:
                size = vector_student.size();
                cout << "Enter ID of student: ";
                cin >> S_ID;
                for (int i = 0; i < size; i++)
                {

                    if (S_ID == vector_student[i].get_id())
                    {
                        cout << "Student is: " << endl;
                        vector_student[i].display();
                    }
                }
                break;
            case 6:
                size = vector_student.size();
                cout << "Enter ID of student: ";
                cin >> S_ID;
                for (int i = 0; i < size; i++)
                {

                    if (S_ID == vector_student[i].get_id())
                    {
                        cout << "Update marks: " << endl;
                        cout << "Enter new_mark: ";
                        cin >> new_mark;
                        cout << "Enter object: ";
                        cin >> pos;
                        vector_student[i].change_mark(new_mark, pos);
                        vector_student[i].display();
                    }
                }
                break;
            case 7:
                return 0;
                break;
            default:
                cout << "Enter your choice, please!!!" << endl;
                break;
            }
        }
        catch (int e)
        {
            cin.clear();
            cin.ignore(100, '\n');
            cout << "Please enter valid number!!!!" << endl;
        }
    }
}
