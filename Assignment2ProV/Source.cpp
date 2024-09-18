#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

struct STUDENT_DATA
{
    std::string FirstNameOfStudent;
    std::string LastNameOfStudent;
};

int main()
{
   
    std::ifstream file("C:\\Users\\jiyap\\source\\repos\\Assignment2ProV\\StudentData.txt");

    std::string line;
    std::vector<STUDENT_DATA> Students;

  
    if (file.is_open())

    {
        
        while (std::getline(file, line))
        {
            std::istringstream ss(line);

            std::string FirstNameOfStudent, LastNameOfStudent;

            
            std::getline(ss, FirstNameOfStudent, ',');

            std::getline(ss, LastNameOfStudent, ',');

            
            STUDENT_DATA Student{ FirstNameOfStudent, LastNameOfStudent };

            Students.push_back(Student);
        }

        file.close();  
    }

    else

    {
        std::cerr << "Sorry, we are not able to open the file!!!";

        return 1;  
    }

    
    for (const auto& student : Students)

    {
        std::cout << "First Name: " << student.FirstNameOfStudent<< ", Last Name: " << student.LastNameOfStudent << std::endl;
    }

    return 0;
}
