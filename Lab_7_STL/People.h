#pragma once
#ifndef People_H
#define People_H
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>
#include "Exams.h"
#include "Subject.h"

class Exams;
class Subject;

class People
{
protected:
	std::string name;
	int age;
public:
	bool operator==(std::string s_name) { return(name == s_name); }
	bool ScanPeople(std::ifstream &f);
	virtual std::ostream& OutData(std::ostream &f)
	{
		f << "Имя: " << name << "\nВозраст: " << age << "\n";
		return f;
	}
	virtual void AddData(std::string input_name)
	{
		name = input_name;
		std::cout << "Введите возраст: ";
		std::cin >> age;
	}
	friend std::ostream& operator<<(std::ostream & f, People &data);
};

class Student : public People
{
private:
	int size;
	float avg;
	std::vector<Exams> pass;
public:
	Student()
	{
		size = 0;
		avg = 0;
	}
	void DeleteEx();
	std::ostream& OutData(std::ostream &f)
	{
		f << "Student: " << name << "\nAge: " << age << "\nAverage: (" << avg << ")\n";
		OutPass(f);
		return f;
	}
	void AddEx();
	std::ostream& OutPass(std::ostream &f);
	bool Scan(std::ifstream &f);
	void average();
	void AddData(std::string input_name)
	{
		name = input_name;
		std::cout << "Введите возраст: ";
		std::cin >> age;
		AddEx();
	}
	void Edit();
};

class Teacher : public People
{
private:
	Subject *subj;
public:
	bool Scan(std::ifstream &f);
	std::ostream& OutData(std::ostream &f)
	{
		f << "Teacher: " << name << "\nAge: " << age << "\n" << subj << "\n";
		return f;
	}
	void AddData(std::string input_name)
	{
		name = input_name;
		std::cout << "Введите возраст: ";
		std::cin >> age;
		AddSubject();
	}
	void Delete();
	void AddSubject();
};


#endif