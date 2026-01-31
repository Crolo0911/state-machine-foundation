#include <iostream>
#include "publicUse.h"


int main()
{
	MyState State = MyState::MainMenu;
	StudentManager Studen;
	TeacherMannager Teacher;
	CourseManager   Course;

	
	while (State!=MyState::Exit)
	{
		UserInfo cmd = Showmenu();
	
	switch (cmd)
	{
	case UserInfo::Student:
		ShowStudentMenu(Studen);
		State = MyState::StudentMenu;
		break;
	case UserInfo::Teacher:
		ShowTeacherMenu(Teacher);
		State = MyState::TeacherMenu;
		break;
	case UserInfo::Course:
		ShowCourseMenu(Course);
		State = MyState::CourseMenu;
		break;
	case UserInfo::Exit:
		State = MyState::Exit;
		break;
	case UserInfo::None:
		break;
	default:
		std::cout << "输入有误或不存在" << std::endl;
		break;
	}
      }

}