/*
Purpose: This program aims to create a Course Class and the functions within it to create class ourses with 
//       different attributes including the capactity, current number of students, and name as well as functions
//       to be able to adjust each of these attributes. Course uses heap memory to store the names of the students
//       within each of these classes.
Date: April ,2024
developed by Z.Sevkli
*/
/*
Test 1: Test 1 which checks the arguements and opening the file works 
        but I forgot to implement some getter methods.
Test 2: Forgot 1 more fucntion to be implemented.
Test 3: Error in the dropStudent function. It wasn't properly moving the
        following student back and instead just left a spot blank where
        the student was removed.
Test 4: Fixed operator+=.  The array of students was not properly being implemented
        and I had to fix how the two arrays were bing combined.
Test 5 - 10: I had some minor errors when it came to the last test in printing everything out.
        I had a few typos or minor erros where the algorithm was correct and in place properly
        but wasn't printing things out correctly. For example in the dropStudent method,
        I had mistakenly forgot to put "Student: " in the print output.  
Test 11: I went back through and redocumented the cpp and header files.
*/
/*
Completed by Olivia Mellen
Date: 4/24/2024
*/

#include <iostream>
#include<fstream>
#include "course.h"

int main(int argc, char * argv[])
{
  // Check if number of command-line arguments is 2 or not. If not, print a error message
  if (argc != 2) {
      std::cout << "command-line arguments error!!" << std::endl;
      std::cout << "no outfile name was given" << std::endl;
      return 0;
  }
    
  // Create a ofstream object named outFile for the filename given in the command-line  
  // check if the file is able to open or not
  std::ofstream outFile(argv[1]);
  if (!outFile.is_open()) {
    std::cout << "no outfile name was given" << std::endl;;
  }
  
  // Create Data Structure SectionA course object
  Course courseDStA("Data Structures", "A", 3);

  
  // add three students 
  courseDStA.addStudent("Peter Jones");
  courseDStA.addStudent("Brian Smith");
  courseDStA.addStudent("Anne Kennedy");

  
  // print course information with its student list
  std::cout << courseDStA << std::endl;
  // shrink student list
  courseDStA.shrinkCapacity();
  // Create Data Structure SectionB course
  Course courseDStB("Data Structures", "B", 10);
  // add two students
  courseDStB.addStudent("Ahmad Nas");
  courseDStB.addStudent("Steve Smith");
  // print course info
  std::cout << courseDStB << std::endl;
  // merge two sections
  courseDStA += courseDStB;
  // print courses info
  std::cout << courseDStA << std::endl;
  std::cout << courseDStB << std::endl;
  // shrink student list
  courseDStA.shrinkCapacity();
  std::cout << courseDStA << std::endl;
  // add a student to database course
  courseDStA.addStudent("Khan Tran");
  // increase capacity
  courseDStA.increaseCapacity(3);
  courseDStA.addStudent("Khan Tran");
  std::cout << courseDStA << std::endl;
  // drop student
  courseDStA.dropStudent("Kaan Pease");
  std::cout << courseDStA<< std::endl;
  // create course using copy constructor
  Course courseDB(courseDStB);
  // change its name
  courseDB.setCourseName("Database Systems");
  courseDB.setSection("C");
  std::cout << courseDB << std::endl;
  // add student
  courseDB.addStudent("Ali Wattson");
  std::cout << courseDB << std::endl;
  std::cout << courseDStB << std::endl;
  // create copy object
  Course courseX("Special Topics", "X", 0);
  courseX = courseDB;
  courseX.setCourseName("Computer Network");
  std::cout << courseX << std::endl;
  // drop a student
  courseX.dropStudent("Ahmad Nas");
  std::cout << courseX << std::endl;
  std::cout << courseDB << std::endl;
  // drop all students from Computer Network
  courseX.dropStudent("Steve Smith");
  std::cout << courseX << std::endl;
  courseX.dropStudent("Ali Wattson");
  std::cout << courseX << std::endl;

  // write all course objects info to the file which was given as command-line argument
  outFile << courseDStA << courseDStB << courseDB << courseX;
  outFile.close();

  return 0;
}
