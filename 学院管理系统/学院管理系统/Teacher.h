#pragma once
#include <iostream>
#include <vector>
#include "Course.h"
class CourseManager;
class Teacher
{
public:
	Teacher(int Sex,int Age,int Id, std::string name):m_nSex(Sex),m_nAge(Age),m_Id(Id),m_Name(name) {}
public:
	int GetId() const { return m_Id;}
	void SetNewname(const std::string& Name) { m_Name = Name; }
	void SetNewnAge(int age) { m_nAge = age; }
	void Show()const;
	void SelectCourse(int courseId, const CourseManager& courseMgr);
	void ShowCourses(const CourseManager& courseMgr)const;
private:
	int m_nAge;
	int m_nSex;
	int m_Id;
	std::string m_Name;
	std::vector<int>m_CourseId;
};
class TeacherMannager
{
public:
	void Addteacher();
	void DeleTeTeacher();
	void ModiFyTeacher();
	void QueryTeacher()const;//查询没有权限更改
	void TeacherPromptUser(int& Id, int& Sex, int& Age, std::string& name);

private:
	std::vector<Teacher>m_Teacher;

};