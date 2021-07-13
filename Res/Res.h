
#pragma once
#include <iostream>
#include <unordered_map>
#include <fstream>
#include <string>

enum ResType
{
	shader,
	mp3,
	jpg,
	png
};
using namespace std;
class Resources
{

private:

	unordered_map<string, string> shaderMaps;

public:
	static string prefix;
	string getShader(string name);
	Resources();
	~Resources();

private:

};