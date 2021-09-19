#include <map>
#include <string>
#include <tuple>
using namespace std;

enum class TaskStatus {
  NEW,          // �����
  IN_PROGRESS,  // � ����������
  TESTING,      // �� ������������
  DONE          // ���������
};

// ��������� ���-������� ��� map<TaskStatus, int>,
// ������������ ������� ���������� ����� ������� �������
using TasksInfo = map<TaskStatus, int>;

class TeamTasks {
public:
  // �������� ���������� �� �������� ����� ����������� ������������
  const TasksInfo& GetPersonTasksInfo(const string& person) const;

  // �������� ����� ������ (� ������� NEW) ��� ����������� �������������
  void AddNewTask(const string& person);

  // �������� ������� �� ������� ���������� ����� ����������� ������������,
  // ����������� ��. ����
  tuple<TasksInfo, TasksInfo> PerformPersonTasks(const string& person, int task_count);
};



int main(){
	return 0;
}
