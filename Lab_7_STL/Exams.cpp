#include "Exams.h"

bool Exams::Scan(std::ifstream &f)
{
	std::string subjectname;
	f >> (subjectname);
	if (subjectname.length() == 0)
		return 1;
	subject =ToFindSubject(subjectname);
	f >> (mark);
	return 0;
}

std::ostream& operator<<(std::ostream & f, Exams &data)
{
	f << data.subject << "(" << data.mark << ")\n";
	return f;
}

void Exams::AddData()
{
	OutSubject();
	std::cout << "Введите название предмета: ";
	std::string name;
	do {
		std::cin >> name;
		subject = ToFindSubject(name);
		if (subject == NULL)
			std::cout << "Предмет не найден, попробуйте ещё раз.\n";
	} while (subject == NULL);
	std::cout << "Введите оценку: ";
	std::cin >> mark;
}