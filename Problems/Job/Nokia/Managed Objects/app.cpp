#include <iostream>
#include <string>
#include <memory>
#include <functional>

#include "MoBase.hpp"
#include "Lim.hpp"

// Example
struct Student {
    Student();

    std::string name;
    std::string forename;
    int32_t year;
};

typedef MoBaseT<Student> MoStudent;
typedef std::shared_ptr<MoStudent> MoStudentPtr;
typedef std::shared_ptr<const MoStudent> MoStudentCPtr;

template<> const ClassName MoStudent::className = "STUDENT";

struct Room {
    Room();
    
    std::string name;
    std::string number;
};

typedef MoBaseT<Room> MoRoom;
typedef std::shared_ptr<MoRoom> MoRoomPtr;
typedef std::shared_ptr<const MoRoom> MoRoomCPtr;

template<> const ClassName MoRoom::className = "ROOM";

struct Course {
    Course();
    
    std::string name;
    std::string profName;
    int32_t teachingYear;
};

typedef MoBaseT<Course> MoCourse;
typedef std::shared_ptr<MoCourse> MoCoursePtr;
typedef std::shared_ptr<const MoCourse> MoCourseCPtr;

template<> const ClassName MoCourse::className = "COURSE";

struct College {
    College();
    
    std::string name;
    std::string address;
};

typedef MoBaseT<College> MoCollege;
typedef std::shared_ptr<MoCollege> MoCollegePtr;
typedef std::shared_ptr<const MoCollege> MoCollegeCPtr;

template<> const ClassName MoCollege::className = "COLLEGE";

struct Department {
    Department();
    
    std::string name;
};

typedef MoBaseT<Department> MoDepartment;
typedef std::shared_ptr<MoDepartment> MoDepartmentPtr;
typedef std::shared_ptr<const MoDepartment> MoDepartmentCPtr;

template<> const ClassName MoDepartment::className = "DEPARTMENT";


void OnCourseCreate(Log* log, const DistName& distName) {
    *log << "[main::OnCourseCreate] " << distName << " is created" << std::endl;
}

void OnStudentUpdate(Log* log, const DistName& distName) {
    *log << "[main::OnStudentUpdate] " << distName << " is updated" << std::endl;
}

void OnRoomRemove(Log* log, const DistName& distName) {
    *log << "[main::OnRoomRemove] " << distName << " is removed" << std::endl;
}

int main() {
    Log log("mo.log");
    Lim imView(log);

    // auto room1 = std::make_shared<MoRoom>("ROOM-1");
    // (*room1)->name = "Alan Turing";
    // (*room1)->number = "EMT-00.149";

    // imView.expand(MoRoom::className);
    // imView.commit(room1);

    // imView.expand(MoStudent::className);
    // imView.expand(MoCourse::className);

    // auto onCourseCreateId = imView.subscribe(SubscriptionType::Create, MoCourse::className, std::bind(OnCourseCreate, &log, std::placeholders::_1));

    // auto onStudentUpdateId = imView.subscribe(SubscriptionType::Update, MoStudent::className, std::bind(OnStudentUpdate, &log, std::placeholders::_1));

    // auto onRoomRemoveId = imView.subscribe(SubscriptionType::Remove, MoRoom::className, std::bind(OnRoomRemove, &log, std::placeholders::_1));

    // auto stud1 = std::make_shared<MoStudent>("STUDENT-1");
    // (*stud1)->name = "Popescu";
    // (*stud1)->forename = "Maria";
    // (*stud1)->year = 1;
    // imView.commit(stud1);

    // auto stud2 = std::make_shared<MoStudent>("STUDENT-2");
    // (*stud2)->name = "Nicolescu";
    // (*stud2)->forename = "Ion";
    // (*stud2)->year = 2;
    // imView.commit(stud2);

    // auto course1 = std::make_shared<MoCourse>("COURSE-1");
    // (*course1)->name = "C++";
    // (*course1)->profName = "Alin Han";
    // (*course1)->teachingYear = 1;
    // imView.commit(course1);

    // auto stud3 = std::make_shared<MoStudent>("STUDENT-3");
    // (*stud3)->name = "Petrescu";
    // (*stud3)->forename = "Gheorghe";
    // (*stud3)->year = 1;
    // imView.commit(stud3);

    // auto stud4 = std::make_shared<MoStudent>("STUDENT-4");
    // (*stud4)->name = "Iliescu";
    // (*stud4)->forename = "Petre";
    // (*stud4)->year = 2;
    // imView.commit(stud4);

    // auto mo = imView.fetch(stud2->getDistName());

    // if ( mo ) {
    //     auto moStud2 = std::static_pointer_cast<const MoStudent>(mo);
    //     log << "[main] " << "Name: " << (*moStud2)->name << std::endl;
    //     log << "[main] " << "Forename: " << (*moStud2)->forename << std::endl;
    //     log << "[main] " << "Year: " << (*moStud2)->year << std::endl;
    // }

    // auto mo1 = imView.fetch(stud1->getDistName());
    // if ( mo1 ) {
    //     auto newMo = mo1->clone(log);
    //     auto moStud1 = std::static_pointer_cast<MoStudent>(newMo);
    //     (*moStud1)->name = "Georgescu";
    //     imView.commit(moStud1);
    // }

    // auto mo2 = imView.fetch(course1->getDistName());
    // if ( mo2 ) {
    //     auto course2 = mo2->cloneAs(log, "COURSE-2");
    //     imView.commit(course2);
    // }

    // imView.logObjects();
    // imView.commit("ROOM-1");

    // imView.shrink({MoRoom::className});
    // imView.shrink({MoStudent::className});
    // imView.shrink({MoCourse::className});

    // auto mo4 = imView.fetch("COURSE-2");

    // imView.unsubscribe(onCourseCreateId);
    // imView.unsubscribe(onStudentUpdateId);
    // imView.unsubscribe(onRoomRemoveId);
}