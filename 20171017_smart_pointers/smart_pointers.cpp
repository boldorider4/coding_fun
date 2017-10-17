#include <iostream>
#include <memory>


class teacher;

class student {
 public:
  student(std::string name) : name(name) {};
  ~student() { std::cout << "calling student destructor for " << name << std::endl; };
  void register_teacher(const std::shared_ptr<teacher>& teacher) {
    wp_myteacher = teacher;
  }
  std::weak_ptr<teacher> getTeacherPointer() {
    return wp_myteacher;
  };

 private:
  std::weak_ptr<teacher> wp_myteacher;
  std::string name;
};

class teacher {
 public:
  teacher(std::string name) : sp_mystudents(nullptr), name(name) {};
  ~teacher() { std::cout << "calling teacher destructor for " << name << std::endl; };
  void setStudentPointer(const std::shared_ptr<student>& students) {
    sp_mystudents = students;
  };
  std::shared_ptr<student> getStudentPointer() {
    return sp_mystudents;
  };

 private:
  std::shared_ptr<student> sp_mystudents;
  std::string name;
};


int main() {
  {
    std::shared_ptr<teacher> teacher_0 = std::make_shared<teacher>("teacher_0");
    {
      teacher_0->setStudentPointer(std::make_shared<student>("student_0"));
      (teacher_0->getStudentPointer())->register_teacher(teacher_0);
    }
    std::cout << "the students should have been destroyed if it "
              << "wasn't for the shared pointer that the teacher holds" << std::endl;
    std::cout << "use count of student is " << teacher_0->getStudentPointer().use_count() << std::endl;
  }


  std::cout << "now teacher has been destroyed too so student should be released!" << std::endl;
  std::cout << std::endl;
  std::cout << std::endl;
  std::cout << std::endl;

  {
    student student_1("student_1");
    {
      std::shared_ptr<teacher> teacher_1 = std::make_shared<teacher>("teacher_1");
      teacher_1->setStudentPointer(std::make_shared<student>(student_1));
      (teacher_1->getStudentPointer())->register_teacher(teacher_1);
    }
    std::cout << "teacher_1 is now destroyed because the student has a weak pointer to it" << std::endl;
    std::cout << "use count of teacher is " << student_1.getTeacherPointer().use_count() << std::endl;
  }

  std::cout << "now student has been destroyed too!" << std::endl;

  return 0;
}
