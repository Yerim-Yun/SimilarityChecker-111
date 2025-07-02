#include <string>
#include <map>

using std::string;
using std::map;

class Checker {
public:
	Checker(const string& str1, const string& str2)
		: str1(str1), str2(str2)
	{
		for (char c : str1)
			strmap1[c]++;
		
		for (char c : str2)
			strmap2[c]++;
	}

	int getLengthPoints() {
		int lengthStr1 = str1.length();
		int lengthStr2 = str2.length();
		int minLength = std::min(lengthStr1, lengthStr2);
		int maxLength = std::max(lengthStr1, lengthStr2);
		int gap = maxLength - minLength;

		if (lengthStr1 == lengthStr2)
			return MAX_LENGTH_POINT;
		else if (maxLength >= (minLength * 2))
			return MIN_LENGTH_POINT;
		else {
			return getPartialPoints(gap, minLength);
		}
	}

	int getAlphaPoints() {
		int alphaCnt1 = strmap1.size();
		int alphaCnt2 = strmap2.size();
		int sameAlphaCnt = 0;

		for (auto targetStr : strmap1) {
			if (targetStr.second != strmap2[targetStr.first]) continue;
				sameAlphaCnt++;
		}

		if (sameAlphaCnt == alphaCnt1) return 40;
		else return 0;
	}

private:
	int getPartialPoints(int gap, int minLeng) {
		return (1 - (double)gap / minLeng) * 60;
	}
	const int MAX_LENGTH_POINT = 60;
	const int MIN_LENGTH_POINT = 0;

	const int MAX_ALPHA_POINT = 40;
	const int MIN_ALPHA_POINT = 0;

	map<char, int> strmap1;
	map<char, int> strmap2;
	string str1;
	string str2;
};