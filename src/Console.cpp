#include "Console.h"


Console::Console() { LoadTasks(); }

Console::~Console() {}

void Console::LoadTasks(){
  std::ifstream file("Resources/tasks.txt");
  std::string line;
  while(std::getline(file, line)){
    m_Tasks.push_back(line);
  }
}

void Console::SaveTasks(){
  std::ofstream file("Resources/tasks.txt");
  for(const auto& task : m_Tasks){
    file << task << "\n";
  }
}

void Console::ShowTasks(){
  std::cout << "\n--- To-Do List ---\n";
  if(m_Tasks.empty()){
    std::cout << "No tasks yet. \n";
  } else {
    for(size_t i = 0; i < m_Tasks.size(); i++){
      std::cout << i + 1 << ". " << m_Tasks[i] << "\n";
    }
  }

  std::cout << "-------------------\n";
}

void Console::AddTask(){
  std::cout << "Enter task: ";
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  std::string task;
  std::getline(std::cin, task);
  m_Tasks.push_back(task);
  std::cout << "Task added!\n";
}

void Console::DeleteTask(){
  ShowTasks();
  std::cout << "Enter task number to delete: ";
  size_t index;
  std::cin >> index;
  if (index > 0 && index <= m_Tasks.size()) {
    m_Tasks.erase(m_Tasks.begin() + index - 1);
    std::cout << "Task deleted.\n";
  } else {
    std::cout << "Invalid task number.\n";
  }
}

void Console::Running(){
  int choice;
  do {
    std::cout << "\nTo-Do List Menu:\n"
	      << "1. Show tasks\n"
	      << "2. Add task\n"
	      << "3. Delete task\n"
	      << "4. Save & Exit\n"
	      << "Choose an option: ";
    std::cin >> choice;
    
    switch (choice) {
    case 1: ShowTasks(); break;
    case 2: AddTask(); break;
    case 3: DeleteTask(); break;
    case 4: SaveTasks(); std::cout << "Saved. Goodbye!\n"; break;
    default: std::cout << "Invalid choice.\n"; break;
    }
  } while (choice != 4);
}
