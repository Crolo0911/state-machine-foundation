#include "Student.h"
#include "publicUse.h"

void StudentManager::AddStudent()
{
	int Id;
	int nAge;
	std::string Name;
	StudentPromptUser(Id,nAge,Name);
	Student Stu(Id, nAge, Name);
	m_student.push_back(Stu);
}
void StudentManager::DeleteStudent()
{

	if (m_student.empty())//当前是否为空
	{
		//进来就是为空除非取反
		std::cout << "当前没有学生信息，请添加后重试或检查哪里是否出错" << std::endl;
		return;
	}
	int Id;
	std::cout << "请输入需要删除的学生Id" << std::endl;
	std::cin >> Id;
	for (auto i = m_student.begin(); i < m_student.end(); i++)
	{
		if (i->Getid()==Id)
		{
			m_student.erase(i);
			std::cout << "删除成功！" << std::endl;
			return;
		}
		
	}
	std::cout << "删除失败，未找到该学生！可能是Id输入有误或者其他未知原因" << std::endl;
}

void StudentManager::ModiFyStudent()
{
	int Part_Id = {};
	std::cout << "请输入要修改的学生ID：" << std::endl;
	std::cin >> Part_Id;

	for (auto& stu: m_student)
	{
		if (stu.Getid()==Part_Id)
		{
			std::string NewName;
			std::cout << "请输入该ID学生更新后的名字：" << std::endl;
			std::cin >> NewName;
			int nAge;
			std::cout << "请输入该学生更新后的年龄：" << std::endl;
			std::cin >> nAge;
			stu.SetnAge(nAge);
			stu.SetName(NewName);

		}
	}
	std::cout << "未找到该ID的学生" << std::endl;
}

void StudentManager::QueryStudent()const
{
	if (m_student.empty())
	{
		std::cout << "当前没有学生或输入有误" << std::endl;
		return;
	}
	int Id = {};
	std::cout << "请输入要查询的学生ID：" << std::endl;
	std::cin >> Id;
	for (const auto& Stu:m_student)
	{
		if (Stu.Getid()==Id)
		{
			Stu.Show();
			return;
		}

	}
}
void StudentManager::StudentPromptUser(int& id,int& Age,std::string& name)
{
	std::cout << "请输入学生ID：" << std::endl;
	std::cin >> id;
	std::cout << "请输入学生年龄：" << std::endl;
	std::cin >> Age;
	std::cout << "请输入学生姓名：" << std::endl;
	std::cin >> name;
	std::cout << "所有数据已接收存储，感谢使用！" << std::endl;
}
void Student::Show() const
{
	std::cout << "ID:" << m_Id << std::endl;
	std::cout << "名字:" << m_Name << std::endl;
	std::cout << "年龄：" << m_nAge << std::endl;
}

void Student::SelectCourse(int courseId, const CourseManager& courseMgr)
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

void Student::ShowCourses(const CourseManager& courseMgr)const 
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





