#pragma once
#ifndef Exams_H
#define Exams_H
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>
#include "Subject.h"

class Subject;

class Exams
{
private:
	int mark;
	Subject* subject;
public:
	static std::vector<Subject> SubjectList1;
	static void OutSubject()
	{
		for (int i = 0; i < (Exams::SubjectList1.end() - Exams::SubjectList1.begin()); i++)
			std::cout << Exams::SubjectList1[i];
	}
	static Subject* ToFindSubject(std::string s_name)
	{
		for (int i = 0; i < (SubjectList1.end() - SubjectList1.begin()); i++)
		{
			if (Exams::SubjectList1[i] == s_name)
				return &Exams::SubjectList1[i];
		}
		return NULL;
	}
	Exams()
	{
		subject = NULL;
		mark = 0;
	}
	bool operator==(std::string name1) { return(*subject == name1); }
	friend std::ostream& operator<<(std::ostream & f, Exams &data);
	bool Scan(std::ifstream &f);
	void AddData();
	int getmark() { return mark; }
	void setmark(int inpmark) { mark = inpmark; }
	void setsubject(Subject *inpsubj) { subject = inpsubj; }
};

#endif