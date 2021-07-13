#include "Res.h"

string Resources::prefix;

const std::string WHITESPACE = " \n\r\t\f\v";
std::string ltrim(const std::string &s)
{
	size_t start = s.find_first_not_of(WHITESPACE);
	return (start == std::string::npos) ? "" : s.substr(start);
}

std::string rtrim(const std::string &s)
{
	size_t end = s.find_last_not_of(WHITESPACE);
	return (end == std::string::npos) ? "" : s.substr(0, end + 1);
}

std::string trim(const std::string &s) {
	return rtrim(ltrim(s));
}
string&  replace_all_distinct(string&  str, const string& old_value, const  string&  new_value)
{
	for (string::size_type pos(0); pos != string::npos; pos += new_value.length())
	{
		if ((pos = str.find(old_value, pos)) != string::npos)
		{
			str.replace(pos, old_value.length(), new_value);
		}
		else { break; }
	}
	return  str;
}

string Resources::getShader(string name)
{
	if (shaderMaps[name] != "") {
		return shaderMaps[name];
	}
	string exePath(_pgmptr);
	prefix = replace_all_distinct(exePath, "build\\QKEngine\\Debug\\QKEngine.exe", "");
	string path = prefix + "Resources\\" + name + ".shader";
	string ans = "";
	ifstream ifs(path);
	string line;
	string process;
	bool flag = false;
	if (ifs.is_open())
	{
		while (getline(ifs, line))
		{
			string tt = trim(line);
			ans += tt+"\n";
		}
		ifs.close();
	}
	ifs.close();
	shaderMaps[name] = ans;
	return shaderMaps[name];
}

Resources::Resources()
{

}

Resources::~Resources()
{
}
