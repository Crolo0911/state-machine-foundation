#include "Course.h"

void CourseManager::AddCourse()
{
	int Id = {};
	std::string Name;
	CoursePromptUser(Id, Name);
	Course Cou(Id, Name);
	m_CoursseM.push_back(Cou);
}

void CourseManager::CoursePromptUser(int& Id, std::string& Name)
{
	std::cout << "请输入课程的ID" << std::endl;
	std::cin >> Id;
	std::cout << "请输入课程的名字" << std::endl;
	std::cin >> Name;
	std::cout << "添加完毕，所有数据已接收" << std::endl;
}

void CourseManager::DeleteCourse()
{
	if (m_CoursseM.empty())
	{
		std::cout << "没有数据或者没有被添加，请添加后重试" << std::endl;
		return;
	}
	
	int choiceId = {};
	std::cout << "请输入需要删除的的ID" << std::endl;
	std::cin >> choiceId;
	for (auto i = m_CoursseM.begin(); i < m_CoursseM.end(); i++)
	{
		if (i->Getid()==choiceId)
		{
			m_CoursseM.erase(i);
			std::cout << "删除成功" << std::endl;
			return;
		}
	}
	std::cout << "删除的ID不存在或不合法请重试" << std::endl;
}

void CourseManager::ModiFyCourse()
{
	if (m_CoursseM.empty())
	{
		std::cout << "没有数据或错误" << std::endl;
		return;
	}
	int Id = {};
	std::string NewName;
	int NewId = {};
	std::cout <<"请输入需要更改的ID" << std::endl;
	std::cin >> Id;
	for (auto i = m_CoursseM.begin(); i < m_CoursseM.end(); i++)
	{
		//Getid是const只读拿来比对
		if (i->Getid()==Id)
		{
			std::cout << "请输入更改的ID" << std::endl;
			std::cin >> NewId;
			std::cout << "请输入更改后的课程名" << std::endl;
			std::cin >> NewName;
			i->NewId(NewId);
			i->NewName(NewName);
			std::cout << "修改成功" << std::endl;
			return;
		}
	}
	std::cout << "未找到该ID的课程" << std::endl;
}

void CourseManager::QueryCourse() const
{
	if (m_CoursseM.empty())
	{
		std::cout << "课程列表为空，请先添加课程" << std::endl;
		return;
	}
	int ChoiceId;
	std::cout << "请输入要查询的ID：" << std::endl;
	std::cin >> ChoiceId;
	for (const auto& Cour : m_CoursseM)
	{
		if (Cour.Getid() == ChoiceId)
		{
			Cour.ShowMenu();
			return;
		}
	}
	std::cout << "未找到ID为 " << ChoiceId << " 的课程" << std::endl;
}
bool CourseManager::IsCourseExist(int courseId) const
{
	for (const auto& course : m_CoursseM)
	{
		if (course.Getid() == courseId)
		{
			return true;
		}
	}
	return false;
}
const Course* CourseManager::GetCourseById(int courseId) const
{
	for (const auto&Cour:m_CoursseM)
	{
		if (Cour.Getid()== courseId)
		{
			return &Cour;
		}
	}
	return nullptr;
}
void Course::ShowMenu() const
{
	std::cout << "ID:" << m_CourSeId << std::endl;
	std::cout << "Name:" << m_CourseName << std::endl;
}
