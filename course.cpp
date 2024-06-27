/*
Purpose: 
Date: 4/24/2024
by Olivia Mellen
*/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "course.h"

//This is the initial constructor for the Course object.  It sets the course's name, section
//and capacity.  It also sets the pointer array and its size to the capacity.
Course::Course(const std::string& courseName, const std::string& section, int capacity) {
    this->courseName = courseName;
    this->section = section;
    this->capacity = capacity;
    this->numberOfStudents = 0;

    this->students = new std::string[capacity];
    std::cout << this->courseName << "-" << this->section << " has been created!" << std::endl;
}

//This is the destructor which deletes the course
//object when done with the program.
Course::~Course() {
    delete[] this->students;
    std::cout << this->courseName << "-" << this->section << " has been deleted!" << std::endl;
}

//This is a copy constructor that will copy all the contents
//including capacity, name, section, and students into the current
//course object.
Course::Course(const Course& newCourse) {
    this->courseName = newCourse.courseName;
    this->numberOfStudents = newCourse.numberOfStudents;
    this->capacity = newCourse.capacity;
    this->section = newCourse.section;

    students = new std::string[newCourse.capacity];
    std::copy(newCourse.students, newCourse.students + capacity, students);
    std::cout << "New " << courseName << "-" << section << " has been created by the copy constructor!" << std::endl;
}

//Overloading the operator= to copy object using =
//Same as the copy constructor but makes sure that its
//not the same memory location to prevent a memory
//leak. Copies the contents into the current course
//object.
Course& Course::operator=(const Course& newCourse) {
    if (this != &newCourse) {
        std::cout << "The content of " << newCourse.courseName << "-" << newCourse.section << " was copied to " << courseName << "-" << section << " using operator=" << std::endl;
        this->courseName = newCourse.courseName;
        this->numberOfStudents = newCourse.numberOfStudents;
        this->section = newCourse.section;

        delete[] students;
        this->capacity = newCourse.capacity;
        students = new std::string[newCourse.capacity];
        std::copy(newCourse.students, newCourse.students + newCourse.capacity, students);
    }

    return *this;
}

//This will set the current course name
void Course::setCourseName(const std::string& name) {
    std::string temp = this->courseName;
    this->courseName = name;
    std::cout << "Course name " << temp << "-" << section << " has been changed to " << courseName << "-" << section << std::endl;
}

//The is a getter method to send the name of the course
std::string Course::getCourseName() const {
    return this->courseName;
}

//This sets the name of the section of the current course
void Course::setSection(const std::string& section) {
    std::string temp = this->section;
    this->section = section;
    std::cout << "Course section " << courseName << "-" << temp << " has been changed to " << section << std::endl;
}

//Getter method returning the name of the section
std::string Course::getSection() const {
    return this->section;
}

//Returns the name of the student at the index
//sent in the parameter
std::string Course::getStudents(int index) const {
    std::string name = students[index];
    return name;
}

//Getter method returning the number of students
int Course::getNumberOfStudents() const {
    return this->numberOfStudents;
}

//Adds a students to the end of students pointer array
//if it is not at the maximum capacity
void Course::addStudent(const std::string& name) {
    size_t size = sizeof(students) / sizeof(students[0]);
    //prints the capacity being at max otherwise
    //add to the array and printing a verification message
    if (numberOfStudents >= capacity) {
        std::cout << "The course " << courseName << "-" << section << " has reached maximum capacity!" << std::endl;
        std::cout << "You need to increase the capacity!!" << std::endl;
    } else {
        students[numberOfStudents] = name;
        std::cout << name << " was added to " << this->courseName << "-" << this->section << " successfully" << std::endl;
        numberOfStudents++;
    }    
}

//Finds the name of the student in the students pointer array,
//if it was found, it drops the student from the array and replaces 
//the spot with whatever is the last element in array. If it wasn't
//found then it will print that.
void Course::dropStudent(const std::string& name) {
    std::string* temp = new std::string[capacity];
    int num = numberOfStudents;
    for (int i = 0; i < numberOfStudents; i++) {
        if (students[i] != name) {
            temp[i] = students[i];
        } else {
            temp[i] = students[numberOfStudents - 1];
            std::cout<< "Student: " << name << " dropped the course " << courseName << "-" << section << std::endl;
            numberOfStudents--;
        }
    }
    //checks to see if the array is smaller than it was
    if (num == numberOfStudents)
        std::cout << "Student: " << name << " was not found!" << std::endl;
   
    delete[] students;
    this->students = new std::string[capacity];
    std::copy(temp, temp + capacity, this->students);
}

//Getter method to retun the capacity
int Course::getCourseCapacity()const {
    return this->capacity;
}

//Shrinks the capacity down to the total number
//of students in the array.
void Course::shrinkCapacity() {
    if (capacity > numberOfStudents) {
        capacity = numberOfStudents;
        std::string* temp = new std::string[numberOfStudents];
        std::copy(students, students + capacity, temp);
        delete[] students;
        students = new std::string[numberOfStudents];
        std::copy(temp, temp + capacity, students);
        std::cout << "The capacity of " << courseName << "-" << section << " is now equal to the number of students" << std::endl;
    } else  
        std::cout << "No need to shrink !! Capacity is equal to the number of students for " << courseName << "-" << section << std::endl;

}

//Sends the additional number of spots in the parameter
//and adds that number to the capacity.  This increases the elements
//in the students array.
void Course::increaseCapacity(unsigned inc) {
    capacity += inc;
    std::string* temp = new std::string[capacity];
    std::copy(students, students + numberOfStudents, temp);
    delete[] students;
    students = new std::string[capacity];
    std::copy(temp, temp + capacity, students);
    std::cout << "The capacity of " << courseName << "-" << section << " has been increased by " << inc << std::endl;
}

//Overloads the operator += to merge the two 
//course students array into the current Course 
//array. This wll in doing so increase the capacity
void Course::operator+=(Course& c) {
    //copies everything into the current object
    this->capacity += c.capacity;
    std::string* temp = new std::string[capacity];
    std::copy(students, students + numberOfStudents, temp);
    std::copy(c.students, c.students + c.numberOfStudents, temp + numberOfStudents);
    this->numberOfStudents += c.numberOfStudents;
    //creates the new students array pointer
    delete[] students;
    students = new std::string[capacity];
    std::copy(temp, temp + capacity, students);
    std::cout << "The students of " << c.courseName << "-" << c.section << " have been added to " << courseName << "-" << section << " with the operator+=" << std::endl;
}

//Overloading the << operator to print out a specific 
//outline.  Displays all known characteristics 
//in the current Course
std::ostream& operator<<(std::ostream &out, const Course &myCourse) {
    out << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
    out << "Course Name: " << myCourse.courseName << std::endl;
    out << "Section    : " << myCourse.section << std::endl;
    out << "Capacity   : " << myCourse.capacity << std::endl;
    out << "#ofStudents: " << myCourse.numberOfStudents << std::endl;
    out << "---------Student List------------" << std::endl;
    if (myCourse.numberOfStudents > 0) {
        for (int i = 0; i < myCourse.numberOfStudents; i++) {
            out << i + 1 << ". " << myCourse.students[i] << std::endl;
        }
    } else 
        out << "(no students to list)" << std::endl;
    return out;
}