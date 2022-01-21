#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

struct Student
{
	std::string Name;//имя студента
	std::string GroupId;//id группы
	std::vector<unsigned> Ratings;//оценки по соответствующему предмету из поля Subjects
	std::vector<std::string> Subjects;//предмет
};

//Задача 1. Сортировка по имени------------------------
bool comparatorByName(Student student1, Student student2) {
	std::string str1 = student1.Name;
	std::string str2 = student2.Name;

	if (str1 == str2)//если имена совпадают
		return false;

	for (int i = 0; i < str1.length() && i < str2.length(); i++) {
		if (str1[i] != str2[i]) {
			if (str1[i] < str2[i])//если символ не совпал
				return true;
			else
				return false;
		}
	}
	//если первая часть строки совпала, то выбираем ту, что короче
	if (str1.length() < str2.length())
		return true;
	else
		return false;
}

void SortByName(std::vector<Student>& students) {//сортировка всех студентов по именам
	std::sort(students.begin(), students.end(), comparatorByName);
}
//--------------------------------------------------------------------



//Задача 2. Сортировка по средней оценке---------------------

double averageRating(Student student) {
	double rating1 = 0;
	double amount1 = 0;
	std::vector<unsigned>::iterator iterRatings = student.Ratings.begin();

	for (; iterRatings != student.Ratings.end(); iterRatings++) {
		rating1 += (*iterRatings);
		amount1++;
	}
	return rating1 / amount1;
}

bool comparatorByRating(Student student1, Student student2) {

	double average1 = averageRating(student1);
	double average2 = averageRating(student2);

	if (average1 < average2)
		return true;
	else
		return false;
}

void SortByRating(std::vector<Student>& students) {
	std::sort(students.begin(), students.end(), comparatorByRating);
}
//--------------------------------------------------------------------




//Задача 3. Количество студентов, имеющих неудовлетворительную оценку хотя бы по одному предмету

size_t CountTwoness(const std::vector<Student>& students) {

	size_t amount = 0;
	std::vector<Student> notConstCopy = students;
	for (std::vector<Student>::iterator iter = notConstCopy.begin(); iter != notConstCopy.end(); iter++) {
		std::vector<unsigned>::iterator iterRatings = (*iter).Ratings.begin();
		bool excellent = true;
		for (; iterRatings != (*iter).Ratings.end(); iterRatings++) {
			if ((*iterRatings) < 3) {//если у студента хоть одна оценка ниже тройки
				excellent = false;
				break;
			}
		}
		if (!excellent)
			amount++;
	}
	return amount;
}

//--------------------------------------------------------------------

//Задача 4. Определит, сколько студентов сдали все экзамены на 5----------

size_t CountExcellent(const std::vector<Student>& students) {

	size_t amount = 0;
	std::vector<Student> notConstCopy = students;
	for (std::vector<Student>::iterator iter = notConstCopy.begin(); iter != notConstCopy.end(); iter++) {
		std::vector<unsigned>::iterator iterRatings = (*iter).Ratings.begin();
		bool excellent = true;
		for (; iterRatings != (*iter).Ratings.end(); iterRatings++) {
			if ((*iterRatings) != 5) {//если у студента хоть одна оценка не пятерка
				excellent = false;
				break;
			}
		}
		if (excellent)
			amount++;
	}
	return amount;
}

//--------------------------------------------------------------------


//Задача 5. Создает массив std::vector<Student>, в который идут студенты имеющие отметку отлично по предмету "Math";----------

std::vector<Student> VectorMathExcellent(const std::vector<Student>& students) {

	size_t amount = 0;
	std::vector<Student> excellentStudents;
	std::vector<Student> notConstCopy = students;
	for (std::vector<Student>::iterator iter = notConstCopy.begin(); iter != notConstCopy.end(); iter++) {

		std::vector<unsigned>::iterator iterRatings = (*iter).Ratings.begin();
		std::vector<std::string>::iterator iterSubjects = (*iter).Subjects.begin();
		bool excellentMath = false;

		for (; iterRatings != (*iter).Ratings.end() && iterSubjects != (*iter).Subjects.end(); iterRatings++, iterSubjects++) {
			if ((*iterSubjects) == "Math" && (*iterRatings) == 5) {
				excellentMath = true;
				break;
			}
		}

		if (excellentMath)
			excellentStudents.push_back(*iter);

	}
	return excellentStudents;
}

//--------------------------------------------------------------------

//Задача 6. Вернет массив уникальных названий групп студентов из списка students----------

std::vector<std::string> GroupsId(const std::vector<Student>& students) {

	size_t amount = 0;
	std::vector<std::string> groups;
	std::vector<Student> notConstCopy = students;

	for (std::vector<Student>::iterator iter = notConstCopy.begin(); iter != notConstCopy.end(); iter++) {

		std::string id = (*iter).GroupId;
		bool unique = true;
		for (std::vector<std::string>::iterator iterString = groups.begin(); iterString != groups.end(); iterString++) {
			if (id == (*iterString))
				unique = false;
		}

		if (unique)
			groups.push_back(id);
	}
	return groups;
}

//--------------------------------------------------------------------


//Задача 7. Вернет массив уникальных названий групп студентов из списка students----------


struct Group
{
	std::string Id;
	std::vector<Student> Students;
};

std::vector<Group> Groups(const std::vector<Student>& students) {

	std::vector<std::string> idVec = GroupsId(students);//получаем массив уникальных названий группы
	std::vector<Group> groups;
	for (std::vector<std::string>::iterator iterString = idVec.begin(); iterString != idVec.end(); iterString++) {
		Group group;
		group.Id = *iterString;//присваиваем новой группе id и добавляем в вектор
		groups.push_back(group);
	}

	std::vector<Student> notConstCopy = students;

	for (std::vector<Student>::iterator iter = notConstCopy.begin(); iter != notConstCopy.end(); iter++) {

		std::string id = (*iter).GroupId;

		for (std::vector<Group>::iterator iterGroup = groups.begin(); iterGroup != groups.end(); iterGroup++) {
			if (id == (*iterGroup).Id) {
				(*iterGroup).Students.push_back(*iter);//добавляем студента в группу
				break;
			}
		}

	}

	return groups;

}

//--------------------------------------------------------------------
