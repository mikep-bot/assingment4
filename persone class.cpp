#include <iostream>
#include <cstring>

class Person {
private:
    char name[100];
    int studentID;
    int age;

public:
    void init(const char* inputName, int inputID, int inputAge) {
        strcpy(name, inputName);
        studentID = inputID;
        age = inputAge;
    }

    void printStudentInfo() {
        std::cout << "Name: " << name << std::endl;
        std::cout << "Student ID: " << studentID << std::endl;
        std::cout << "Age: " << age << std::endl;
    }

    int getID() { return studentID; }
    int getAge() { return age; }
    
    // Change this to return non-const pointer
    char* getName() { 
        return name; 
    }
    
    // OR better: Add setter methods
    void setName(const char* newName) {
        strcpy(name, newName);
    }
    void setID(int newID) {
        studentID = newID;
    }
    void setAge(int newAge) {
        age = newAge;
    }
};

// CORRECTED personSwap function
void personSwap(Person& p1, Person& p2) {
    // Method 1: Using setter methods (Recommended)
    // Swap names
    char tempName[100];
    strcpy(tempName, p1.getName());  // Get name from p1
    p1.setName(p2.getName());         // Set p1's name to p2's name
    p2.setName(tempName);             // Set p2's name to temp
    
    // Swap student IDs
    int tempID = p1.getID();
    p1.setID(p2.getID());
    p2.setID(tempID);
    
    // Swap ages
    int tempAge = p1.getAge();
    p1.setAge(p2.getAge());
    p2.setAge(tempAge);
}

// OR Method 2: Using temporary Person object (Simpler)
void personSwap2(Person& p1, Person& p2) {
    Person temp;
    temp.init(p1.getName(), p1.getID(), p1.getAge());
    p1.init(p2.getName(), p2.getID(), p2.getAge());
    p2.init(temp.getName(), temp.getID(), temp.getAge());
}

int main() {
    Person person1, person2;
    
    person1.init("MIKE", 2420022, 20);
    person2.init("ROOBIE", 2420090, 22);
    
    std::cout << "Before swap:" << std::endl;
    person1.printStudentInfo();
    std::cout << std::endl;
    person2.printStudentInfo();
    std::cout << std::endl;
    
    personSwap(person1, person2);
    
    std::cout << "After swap:" << std::endl;
    person1.printStudentInfo();
    std::cout << std::endl;
    person2.printStudentInfo();
    
    return 0;
}