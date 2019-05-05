#include <vector>
#include <iostream>
#include "Exams.h"
#include "People.h"
#include "Subject.h"

#define INSTUDENTS "students.txt"
#define INPROFESSORS "professors.txt"
#define OUTLIST "output.txt"
#define INSUBJ "subjects.txt"

using namespace std;

std::vector<Subject> Exams::SubjectList1;

template<class T>
void FromFile(vector<T> &a, const char* file)
{
	ifstream fin(file);
	while (fin)
	{
		T newc;
		bool flag = newc.Scan(fin);
		if (!flag)
		{
			a.push_back(newc);
		}
	}
	fin.close();
}


template<class T>
void OutList(vector<T> &a)
{
	for (int i = 0; i < (a.end() - a.begin()); i++)
		cout << a[i];
}

template <class T>
T* FindPerson(vector<T> &a, string name1)
{
	for (int i = 0; i < (a.end() - a.begin()); i++)
	{
		if (a[i] == name1)
			return &a[i];
	}
	return NULL;
}

template <class T>
void ToFile(vector<T>& a)
{
	ofstream fout(OUTLIST);
	for (int i = 0; i < (a.end() - a.begin()); i++)
			fout << a[i];
	fout.close();
}

int main()
{
	char cntrl, ch;
	string name1;
	setlocale(LC_ALL, "");
	FromFile(Exams::SubjectList1, INSUBJ);
	vector<Student> S;
	vector<Teacher> P;
	do
	{

		cout << "1. Считать список из файла.\n";
		cout << "2. Вывести список на экран.\n";
		cout << "3. Записать список в файл.\n";
		cout << "4. Изменить информацию о студенте.\n";
		cout << "5. Удалить элемент из списка.\n";
		cout << "6. Добавить элемент в список.\n";
		cout << "7. Вывести общий список.\n";
		cout << "8. Выйти из программы\n";
		cin >> cntrl;
		switch (cntrl)
		{
		case'1':
			cout << "Выберите список для использования:\n1. Студенты.\n2. Преподаватели.\n";
			cin >> ch;
			if (ch == '1')
				FromFile(S, INSTUDENTS);
			if (ch == '2')
				FromFile(P, INPROFESSORS);
			break;
		case'2':
			cout << "Выберите список для использования:\n1. Студенты.\n2. Преподаватели.\n";
			cin >> ch;
			if (ch == '1')
			{
				if (S.empty())
				{
					cout << "Список пустой.\n"; break;
				}
				OutList(S);
			}
			if (ch == '2')
			{
				if (P.empty())
				{
					cout << "Список пустой.\n"; break;
				}
				OutList(P);
			}
			break;
		case'3':
			cout << "Выберите список для использования:\n1. Студенты.\n2. Преподаватели.\n";
			cin >> ch;
			if (ch == '1')
			{
				if (S.empty())
				{
					cout << "Список пустой.\n"; break;
				}
				ToFile(S);
			}
			if (ch == '2')
			{
				if (P.empty())
				{
					cout << "Список пустой.\n"; break;
				}
				ToFile(P);
			}
			break;
		case'4':
		{
			if (S.empty())
			{
				cout << "Список пустой.\n"; break;
			}
			cout << "Введите имя:\n";
			cin >> name1;
			Student* old_one = NULL;
			old_one = FindPerson(S, name1);
			if (old_one == NULL)
			{
				cout << "Студент не обнаружен.\n"; break;
			}
			old_one->Edit();
			break;
		}
		case'5':
		{
			cout << "Выберите список для использования:\n1. Студенты.\n2. Преподаватели.\n";
			cin >> ch;
			if (ch == '1')
			{
				if (S.empty())
				{
					cout << "Список пустой.\n"; break;
				}
				cout << "Введите имя:\n";
				cin >> name1;
				for (int i = 0; i < (S.end() - S.begin()); i++)
				{
					if (S[i] == name1)
					{
						S[i].DeleteEx();
						S.erase(S.begin() + i);
						break;
					}
				}
			}
			if (ch == '2')
			{
				if (P.empty())
				{
					cout << "Список пустой.\n"; break;
				}
				cout << "Введите имя:\n";
				cin >> name1;
				for (int i = 0; i < (P.end() - P.begin()); i++)
				{
					if (P[i] == name1)
					{
						P[i].Delete();
						P.erase(P.begin() + i);
						break;
					}
				}
			}
			break;
		}
		case'6':
		{
			cout << "Выберите список для использования:\n1. Студенты.\n2. Преподаватели.\n";
			cin >> ch;
			if (ch == '1')
			{
				cout << "Введите имя:\n";
				cin >> name1;
				Student new_comer;
				if (FindPerson(S, name1) == NULL)
				{
					new_comer.AddData(name1);
					S.push_back(new_comer);
				}
				else
					cout << "Такой студент уже есть в списке.\n";
			}
			if (ch == '2')
			{
				cout << "Введите имя:\n";
				cin >> name1;
				Teacher new_comer;
				if (FindPerson(P, name1) == NULL)
				{
					new_comer.AddData(name1);
					P.push_back(new_comer);
				}
				else
					cout << "Такой преподаватель уже есть в списке.\n";
			}
			break;
		}
		case'7':
		{
			if (P.empty() && S.empty())
			{
				cout << "Списки пустые.\n"; break;
			}
			vector<People*> H;
			for (int i = 0; i < (S.end() - S.begin()); i++)
			{
				H.push_back(&S[i]);
			}
			for (int i = 0; i < (P.end() - P.begin()); i++)
			{
				H.push_back(&P[i]);
			}
			for (int i = 0; i < (H.end() - H.begin()); i++)
				cout << *H[i];
			break;
		}
		}
	} while (cntrl != '8');
}