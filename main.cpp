#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

std::vector<std::string> letters {
    "C",
    "D",
    "E",
    "F",
    "G",
    "A",
    "B",
};

std::vector<std::string> notes {
    "DO",
    "RE",
    "MI",
    "FA",
    "SOL",
    "LA",
    "SI",
};

bool compareChar(char & c1, char & c2)
{
	if (c1 == c2)
		return true;
	else if (std::toupper(c1) == std::toupper(c2))
		return true;
	return false;
}
 
/*
 * Case Insensitive String Comparision
 */
bool caseInSensStringCompare(std::string & str1, std::string &str2)
{
	return ( (str1.size() == str2.size() ) &&
			 std::equal(str1.begin(), str1.end(), str2.begin(), &compareChar) );
}

int main(int argc, char const *argv[])
{
    std::string answer;
    int right = 0, wrong = 0, total = 0;
    std::function<float(int, int)> division_int = [=](int a, int b) -> float { return (float)a / (float)b; };

    while(true)
    {
        auto r = rand() % letters.size();
        std::cout << letters[r] << " ";
        getline(std::cin, answer);
        if (caseInSensStringCompare(answer, notes[r]))
        {
            right++;
            std::cout << std::endl << notes[r] << " RIGHT ";
        }
        else
        {
            wrong++;
            std::cout << std::endl << notes[r] << " WRONG ";
        }
        total++;
        std::cout << right << "/" << wrong << " " << division_int(right, total) << " - " << division_int(wrong, total) << std::endl;
    }

    return 0;
}
