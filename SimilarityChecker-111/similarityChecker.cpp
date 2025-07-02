#include <string>

using std::string;

class Checker {
public:
	int getLengthPoints(const string& str1, const string& str2) {
		if (str1.length() == str2.length())
			return 60;
		else
			return 0;
	}

};