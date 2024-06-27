#ifndef COURSE_H
#define COURSE_H
#include <string>

class Course
{
  // define operator<< as a friend function for Course
  friend std::ostream& operator<<(std::ostream &out, const Course &myCourse);
  
 public:
  Course(const std::string& courseName, const std::string& section, int capacity);
  ~Course();
  // overload copy constructor
  Course(const Course& newCourse);
  // overload copy assignment operator
  Course& operator=(const Course& newCourse);
  void setCourseName(const std::string& name);
  std::string getCourseName() const;
  void setSection(const std::string& section);
  std::string getSection() const;
  void addStudent(const std::string& name);
  void dropStudent(const std::string& name);
  int getNumberOfStudents() const;
  int getCourseCapacity()const;
  void shrinkCapacity();
  void increaseCapacity(unsigned inc);
  std::string getStudents(int index) const;
  //oveload operator+= as a member function
  void operator+=(Course& c);
 private:
  std::string courseName;
  std::string section;
  std::string* students;
  int numberOfStudents;
  int capacity;
  
};

#endif



 
