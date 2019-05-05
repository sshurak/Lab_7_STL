#include "Subject.h"

bool Subject::Scan(std::ifstream &f)
{
	try
	{
		f >> (SubjName);
		if (SubjName.length() == 0) return 1;
		return 0;
	}
	catch (...)
	{
		return 1;
	}
}

std::ostream& operator<<(std::ostream & f, Subject *data)
{
	f << data->SubjName;
	return f;
}

std::ostream& operator<<(std::ostream & f, Subject &data)
{
	f << data.SubjName << "\n";
	return f;
}
