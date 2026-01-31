#pragma once
#include <iostream>
#include <vector>
#include "Course.h"
class CourseManager;
class Student
{
public:
	Student(int Id,int Age, const std::string& Name):m_Id(Id),m_nAge(Age),m_Name(Name) {}
	int Getid() const { return m_Id; }
	void SetName(const std::string& Name) { m_Name = Name; }
	void SetnAge(int age) { m_nAge = age; }
	void Show()const;
	void SelectCourse(int courseId, const CourseManager& courseMgr);
	void ShowCourses(const CourseManager& courseMgr)const;
private:
	int m_Id;
	int m_nAge;
	std::string m_Name;
	std::vector<int>m_CourseId;
};
class StudentManager
{
public:
	void AddStudent();
	void DeleteStudent();
	void ModiFyStudent();
	void QueryStudent()const;
	void StudentPromptUser(int& id, int& Age, std::string& name);
private:
	std::vector<Student>m_student;
};

