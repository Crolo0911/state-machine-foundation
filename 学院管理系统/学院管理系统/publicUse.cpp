#include <iostream>
#include "publicUse.h"
UserInfo Showmenu()
{
	{

		std::cout << "=====================欢迎来到本管理系统==============" << std::endl;
		std::cout << "=====================1.学生管理====================" << std::endl;
		std::cout << "=====================2.老师管理====================" << std::endl;
		std::cout << "=====================3.课程管理====================" << std::endl;
		std::cout << "=====================4.退出系统====================" << std::endl;
		int choise = {};
		std::cin >> choise;
		switch (choise)
		{
		case 1:
			return UserInfo::Student;
		case 2:
			return UserInfo::Teacher;
		case 3:
			return UserInfo::Course;
		case 4:
			return UserInfo::Exit;
		default:
			std::cout << "输入的不存在或者不合法" << std::endl;
			return UserInfo::None;
		}
	}
}
UserInfo ShowStudentMenu(StudentManager& StuManager)//不能用const引用（实际操作中有"写"操作）
{

	std::cout << "=====================学生管理菜单=====================" << std::endl;
	std::cout << "=====================1.增加学生信息===================" << std::endl;
	std::cout << "=====================2.查询学生信息===================" << std::endl;
	std::cout << "=====================3.修改学生信息===================" << std::endl;
	std::cout << "=====================4.删除学生信息===================" << std::endl;
	std::cout << "=====================5.返回主菜单=====================" << std::endl;
	int choice = 0;
	std::cin >> choice;
	
	switch (choice)
	{
	case 1:
		StuManager.AddStudent();
		return UserInfo::Student;
	case 2:
		StuManager.QueryStudent();
		return UserInfo::Student;
		case 3:
		StuManager.ModiFyStudent();
		return UserInfo::Student;
		case 4:
		StuManager.DeleteStudent();
		return UserInfo::Student;
		case 5:
			return UserInfo::None;
	default:
		std::cout << "输入的不存在或者不合法请检查！" << std::endl;
		break;
	}
	
}

UserInfo ShowTeacherMenu(TeacherMannager& TeaManager)
{

	std::cout << "=====================老师管理菜单=====================" << std::endl;
	std::cout << "=====================1.增加老师信息===================" << std::endl;
	std::cout << "=====================2.查询老师信息===================" << std::endl;
	std::cout << "=====================3.修改老师信息===================" << std::endl;
	std::cout << "=====================4.删除老师信息===================" << std::endl;
	std::cout << "=====================5.返回主菜单=====================" << std::endl;
	int Choice = {};
	std::cin >> Choice;
	switch (Choice)
	{
	case 1:
		TeaManager.Addteacher();
		return UserInfo::Teacher;
	case 2:
		TeaManager.QueryTeacher();
		return UserInfo::Teacher;
	case 3:
		TeaManager.ModiFyTeacher();
		return UserInfo::Teacher;
	case 4:
		TeaManager.DeleTeTeacher();
		return UserInfo::Teacher;
	case 5:
		return UserInfo::None;
	default:
		std::cout << "输入的不存在或者不合法请检查！" << std::endl;
		break;
	}




}

UserInfo ShowCourseMenu(CourseManager& CouManager)
{
	std::cout << "=====================课程管理菜单=====================" << std::endl;
	std::cout << "=====================1.增加课程信息===================" << std::endl;
	std::cout << "=====================2.查询课程信息===================" << std::endl;
	std::cout << "=====================3.修改课程信息===================" << std::endl;
	std::cout << "=====================4.删除课程信息===================" << std::endl;
	std::cout << "=====================5.返回主菜单=====================" << std::endl;
	int Choice = {};
	std::cin >> Choice;
	switch (Choice)
	{
	case 1:
		CouManager.AddCourse();
		return UserInfo::Course;
	case 2:
		CouManager.QueryCourse();
		return UserInfo::Course;
	case 3:
		CouManager.ModiFyCourse();
		return UserInfo::Course;
	case 4:
		CouManager.DeleteCourse();
		return UserInfo::Course;
	case 5:
		return UserInfo::None;
	default:
		std::cout << "输入的不存在或者不合法，请检查"<<std::endl;
		break;
	}
}
