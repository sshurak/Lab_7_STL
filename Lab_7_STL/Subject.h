#pragma once
#ifndef Subject_H
#define Subject_H
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

class Subject
{
private:
	std::string SubjName;
public:
	bool operator==(std::string subjectname) { return(SubjName == subjectname); }
	friend std::ostream& operator<<(std::ostream & f, Subject *data);
	friend std::ostream& operator<<(std::ostream & f, Subject &data);
	std::string GetSubjectName() { return SubjName; }
	bool Scan(std::ifstream &f);
};

#endif