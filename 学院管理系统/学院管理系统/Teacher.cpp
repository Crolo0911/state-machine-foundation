#include "Teacher.h"

void TeacherMannager::Addteacher()
{
	//只负责接收输入其他不管
	int id = {};
	int Sex = {};
	int age = {};
	std::string Name;
	TeacherPromptUser(id, Sex, age, Name);
	Teacher Teac(id, Sex, age, Name);
	m_Teacher.push_back(Teac);
}

void TeacherMannager::DeleTeTeacher()
{
	if (m_Teacher.empty())
	{
		//进来就是空不是空就是反的取反就是有数据
		std::cout << "数据不存在或者没有被添加，请添加后重试！" << std::endl;
		return;
	}
	for (auto i = m_Teacher.begin(); i < m_Teacher.end(); i++)
	{
		int id = {};
		std::cin >> id;
		if (i->GetId()==id)
		{
			m_Teacher.erase(i);
			std::cout << "删除成功！" << std::endl;
			return;
		}
		
	}
	std::cout << "删除失败！可能是ID不存在或输入有误！" << std::endl;
}

void TeacherMannager::ModiFyTeacher()
{
	int ModiFyId = {};
	std::cout << "请输入要更改的老师ID" << std::endl;
	std::cin >> ModiFyId;
	for (auto i = m_Teacher.begin(); i <m_Teacher.end(); i++)
	{
		if (i->GetId()== ModiFyId)
		{
			int nAge = {};
			std::cout << "请输入该ID更改后的年龄" << std::endl;
			std::cin >> nAge;
			if (nAge>=100||nAge<=20)
			{
				std::cout << "年龄不合法，修改失败" << std::endl;
				return;
			}
			std::string NewName;
			std::cout << "请输入该ID更改后的新老师" << std::endl;
			std::cin >> NewName;
			i->SetNewname(NewName);
			i->SetNewnAge(nAge);
			return;
		}
	}
	std::cout << "未找到该ID的老师" << std::endl;
}

void TeacherMannager::QueryTeacher() const
{
	//进来就先判断是不是空的没有数据
	if (m_Teacher.empty())
	{
		std::cout << "没有数据，或者输入错误" << std::endl;
		return;
	}
	int QueryId;
	std::cout << "请输入要查询的老师ID" << std::endl;
	std::cin >> QueryId;
	for (const auto& Stu : m_Teacher)
	{
		if (Stu.GetId() == QueryId)
		{
			Stu.Show();
			return;
		}

	}
}

void TeacherMannager::TeacherPromptUser(int& Id, int& Sex, int& Age, std::string& name)
{
	std::cout << "请输入老师的ID：" << std::endl;
	std::cin >> Id;
	std::cout << "请输入老师的性别：" << std::endl;
	std::cin >> Sex;
	std::cout << "请输入老师的年龄：" << std::endl;
	std::cin >> Age;
	std::cout << "请输入老师的姓名：" << std::endl;
	std::cin >> name;
	std::cout << "所有数据已接收存储，感谢使用" << std::endl;
}

void Teacher::Show() const
{
	std::cout << "ID:" << m_Id << std::endl;
	std::cout << "名字:" << m_Name << std::endl;
	std::cout << "年龄：" << m_nAge << std::endl;
	std::cout << "性别:" << m_nSex << std::endl;

}

void Teacher::SelectCourse(int courseId, const CourseManager& courseMgr)
{
	// 先判断课程是否存在
	if (!courseMgr.IsCourseExist(courseId))
	{
		std::cout << "输入的课程ID不存在" << std::endl;
		return;
	}

	// 检查是否已选过
	for (int id : m_CourseId)
	{
		if (id == courseId)
		{
			std::cout << "已经被选过了" << std::endl;
			return;
		}
	}

	// 没选过，就添加
	m_CourseId.push_back(courseId);
	std::cout << "选课已记录" << std::endl;
}


void Teacher::ShowCourses(const CourseManager& courseMgr)const
{
	if (m_CourseId.empty())
	{
		std::cout << m_Name << " 还没有选课程" << std::endl;
		return;
	}
	std::cout << m_Name << " 的课程列表：" << std::endl;
	for (int id : m_CourseId)
	{

		const Course* course = courseMgr.GetCourseById(id);
		if (course)
			course->ShowMenu();
	}

}
