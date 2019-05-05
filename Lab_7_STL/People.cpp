#include "People.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>
#include "Exams.h"
#include "Subject.h"

bool People::ScanPeople(std::ifstream &f)
{
	try
	{
		f >> name;
		if (name.length() == 0)
			return 1;
		f >> age;
		return 0;
	}
	catch (...)
	{
		return 1;
	}
}

std::ostream& operator<<(std::ostream & f, People &data)
{
	data.OutData(f);
	return f;
}

bool Student::Scan(std::ifstream &f)
{
	try
	{
		if (ScanPeople(f))
			return 1;
		f >> size;
		for (int i = 0; i < size; i++)
		{
			Exams newex;
			bool flag = newex.Scan(f);
			if (!flag)
			{
				pass.push_back(newex);
			}
		}
		average();
		return 0;
	}
	catch (...)
	{
		return 1;
	}
}

void Student::average()
{
	float res = 0;
	for(int i = 0; i < (pass.end() - pass.begin()); i++)
		res += pass[i].getmark();
	avg = round((res/size) * 10) / 10;
}

void Student::Edit()
{
	char c = '0';
	do {
		std::cout << "1.Добавить экзамен.\n2.Исправить экзамен.\n";
		std::cin >> c;
	} while ((c != '1') && (c != '2'));
	std::cout << "Список экзаменов:\n";
	OutPass(std::cout);
	std::string name1;
	std::cout << "Список предметов:\n";
	Exams::OutSubject();
	Subject *subject = new Subject;
	std::cout << "Название предмета, по которому сдан экзамен: ";
	do
	{
		std::cin >> name1;
		subject = Exams::ToFindSubject(name1);
		if (subject == NULL)
			std::cout << "Предмет не найден, попробуйте ещё раз.\n";
	} while (subject == NULL);
	switch (c)
	{
	case '1':
	{
		for (int i = 0; i < (pass.end() - pass.begin()); i++)
		{
			if (pass[i] == name1)
			{
				std::cout << "Этот экзамен уже сдан.\n";
				return;
			}
		}
		Exams a;
		a.setsubject(subject);
		int mark;
		std::cout << "Введите оценку: ";
		std::cin >> mark;
		a.setmark(mark);
		pass.push_back(a);
		size++;
		break;
	}
	case '2':
	{
		for (int i = 0; i < (pass.end() - pass.begin()); i++)
		{
			if (pass[i] == name1)
			{
				int mark;
				std::cout << "Введите оценку: ";
				std::cin >> mark;
				pass[i].setmark(mark);
				break;
			}
		}
		std::cout << "Экзамен не найден.\n";
		return;
	}
	}
	average();
}

void Student::DeleteEx()
{ pass.~vector(); }

bool Teacher::Scan(std::ifstream &f)
{
	try
	{
		if (ScanPeople(f))
			return 1;
		std::string subjectname;
		f >> (subjectname);
		if (subjectname.length() == 0)
			return 1;
		subj = Exams::ToFindSubject(subjectname);
		return 0;
	}
	catch (...)
	{
		return 1;
	}
}

std::ostream& Student::OutPass(std::ostream &f)
{
	for (int i = 0; i < (pass.end() - pass.begin()); i++)
		f << pass[i];
	f << std::endl;
	return f;
}

void Student::AddEx()
{
	std::cout << "Введите количество экзаменов: ";
	std::cin >> size;
	for (int i = 0; i < size; i++)
	{
		Exams newex;
		newex.AddData();
		pass.push_back(newex);
	}
	average();
}

void Teacher::Delete()
{
	subj = NULL;
}

void Teacher::AddSubject()
{
	Exams::OutSubject();
	std::cout << "Введите название предмета: ";
	std::string name;
	do {
		std::cin >> name;
		subj = Exams::ToFindSubject(name);
		if (subj == NULL)
			std::cout << "Предмет не найден, попробуйте ещё раз.\n";
	} while (subj == NULL);
}