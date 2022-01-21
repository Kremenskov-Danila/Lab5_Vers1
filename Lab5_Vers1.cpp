// Lab5_Vers1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <vector>

#include "header.hpp"


void output(std::vector<Student> students) {
	for (std::vector<Student>::iterator iter = students.begin(); iter != students.end(); iter++) {
		std::cout << "Name: " << (*iter).Name << std::endl;
		std::cout << "GroupId: " << (*iter).GroupId << std::endl;
		std::vector<unsigned>::iterator iterRatings = (*iter).Ratings.begin();
		std::vector<std::string>::iterator iterSubjects = (*iter).Subjects.begin();

		for (; iterRatings != (*iter).Ratings.end() && iterSubjects != (*iter).Subjects.end(); iterRatings++, iterSubjects++) {
			std::cout << (*iterSubjects) << " " << (*iterRatings) << std::endl;
		}
		std::cout << std::endl << std::endl;
	}
}

void input(std::vector<Student>& students) {
	Student student1;
	student1.Name = "Sergey";
	student1.GroupId = "3682";
	
	student1.Ratings.push_back(5);
	student1.Ratings.push_back(5);
	student1.Ratings.push_back(5);
	student1.Subjects.push_back("Math");
	student1.Subjects.push_back("Geo");
	student1.Subjects.push_back("Eng");

	Student student2;
	student2.Name = "Anna";
	student2.GroupId = "5721";
	student2.Ratings.push_back(5);
	student2.Ratings.push_back(3);
	student2.Ratings.push_back(5);
	student2.Subjects.push_back("Math");
	student2.Subjects.push_back("Geo");
	student2.Subjects.push_back("Eng");

	Student student3;
	student3.Name = "Michail";
	student3.GroupId = "3682";
	student3.Ratings.push_back(2);
	student3.Ratings.push_back(5);
	student3.Ratings.push_back(5);
	student3.Subjects.push_back("Math");
	student3.Subjects.push_back("Geo");
	student3.Subjects.push_back("Eng");

	students.push_back(student1);
	students.push_back(student2);
	students.push_back(student3);
}

void outputGroups(std::vector<Group> groups) {
	for (std::vector<Group>::iterator iterGroup = groups.begin(); iterGroup != groups.end(); iterGroup++) {
		std::cout << "-----------------------" << (*iterGroup).Id << "-----------------------" << std::endl;
		for (std::vector<Student>::iterator iterStudents = (*iterGroup).Students.begin(); iterStudents != (*iterGroup).Students.end(); iterStudents++) {
			std::cout << "Name: " << (*iterStudents).Name << std::endl;
			std::cout << "GroupId: " << (*iterStudents).GroupId << std::endl;
			std::vector<unsigned>::iterator iterRatings = (*iterStudents).Ratings.begin();
			std::vector<std::string>::iterator iterSubjects = (*iterStudents).Subjects.begin();

			for (; iterRatings != (*iterStudents).Ratings.end() && iterSubjects != (*iterStudents).Subjects.end(); iterRatings++, iterSubjects++) {
				std::cout << (*iterSubjects) << " " << (*iterRatings) << std::endl;
			}
			std::cout << std::endl << std::endl;

		}
		std::cout << "---------------------------------------------------------" << std::endl;
	}
}





int main()
{
    setlocale(LC_ALL, "ru");

	std::vector<Student> students;
	input(students);

	//output(students);
	//std::cout << CountExcellent(students);
	//output(VectorMathExcellent(students));

	/*
	std::vector<std::string> groups = GroupsId(students);
	for (std::vector<std::string>::iterator iterString = groups.begin(); iterString != groups.end(); iterString++) {
		std::cout << (*iterString) << " ";
	}
	*/
	
	std::vector<Group> groups = Groups(students);
	outputGroups(groups);

	/*
	std::cout << "1. Sort\n";
	SortByName(students);
	output(students);
	
	*/
	/*
	std::cout << "2. SortByRating\n"; 
	SortByRating(students);
	output(students);
	*/

	/*
	std::cout << "3. CountTwoness\n";
	std::cout << CountTwoness(students);
	output(students);
	*/

	
	//output(VectorMathExcellent(students));

	return 0;




}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
