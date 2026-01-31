#pragma once
#include "Student.h"
#include "Teacher.h"
#include "Course.h"

enum class MyState
{
	Init,
	MainMenu,
	StudentMenu,
	TeacherMenu,
	CourseMenu,
	Exit

};
enum class UserInfo
{
	Student,
	Teacher,
	Course,
	None,
	Exit
};

UserInfo Showmenu();
UserInfo ShowStudentMenu(StudentManager& StuManager);
UserInfo ShowTeacherMenu(TeacherMannager& TeaManager);
UserInfo ShowCourseMenu(CourseManager& CouManager);
