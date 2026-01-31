#pragma once
#include <iostream>
#include <vector>
#include "Student.h"
#include "Teacher.h"
class Course
{
public:
	Course(int Id, std::string Name) :m_CourSeId(Id), m_CourseName(Name) {}
	int Getid()const { return m_CourSeId; }
	void NewId(int id) { m_CourSeId = id; }
	void NewName(const std::string& Name) { m_CourseName = Name; }
	void ShowMenu()const;//Ö»¶Á
private:
	int m_CourSeId;
	std::string m_CourseName;

};

class CourseManager
{
public:
	void AddCourse();
	void CoursePromptUser(int& Id,std::string&Name);
	void DeleteCourse();
	void ModiFyCourse();
	void QueryCourse()const;
	bool IsCourseExist(int courseId) const;
	const Course* GetCourseById(int courseId) const;
private:
	std::vector<Course>m_CoursseM;
};