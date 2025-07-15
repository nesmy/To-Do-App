#include "config.h"

class Console{
 public:
  Console();
  ~Console();

  void SaveTasks();
  void ShowTasks();
  void AddTask();
  void DeleteTask();

  void Running();
 private:
  void LoadTasks();
 private:
  std::vector<std::string> m_Tasks;
};
