#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <filesystem>
#include <Windows.h>
#include <locale>
#include <codecvt>

using namespace std;
namespace fs = std::experimental::filesystem;

std::string to_string(const std::wstring& wstr)
{
	static std::wstring_convert< std::codecvt_utf8<wchar_t>, wchar_t > converter;

	return converter.to_bytes(wstr);
}

string getFileExt(const string& s) {

	size_t i = s.rfind('.', s.length());
	if (i != string::npos) {
		return(s.substr(i + 1, s.length() - i));
	}

	return("");
}

bool ExtCompare(const fs::path file_path, const string& ext) {
	bool ok = 0;
	if (ext == "*")
		ok = 1;
	else
	{
		std::string path_string = file_path.u8string();
		size_t found = path_string.find(ext);
		if (found != string::npos)
			ok = 1;
	}
	if (ok == 1)
		return true;
	else
		return false;
}

bool StringCompare(const string& line, const string& search) {
	bool ok = 0;
	size_t found = line.find(search);
	if (found != string::npos)
		ok = 1;
	return ok;
}


void SearchFile(string directory_path, string file_mask, string search_phrase, string output_file)
{
	if (!fs::exists(directory_path) || !fs::is_directory(directory_path)) return;

	fs::recursive_directory_iterator it(directory_path);
	fs::recursive_directory_iterator endit;

	while (it != endit)
	{
		
		if (fs::is_regular_file(*it) && ExtCompare( it->path().extension(), file_mask))
		{
			ofstream writeFile(output_file);
			wifstream readFile;
			wstring line;
			readFile.open(it->path());
			int lnNumber = 0;
			while (readFile.good())
			{
				getline(readFile, line);
				lnNumber++;				
				if(StringCompare(to_string(line), search_phrase)==true)
				{
					writeFile <<it->path()<<" ("<<lnNumber<<") "<< to_string(line)<<endl;
				}
			}
			readFile.close();
			writeFile.close();
		}
		++it;
	}
}

int main(string dir_path,string exts,string searchph,string output)
{
	SearchFile(dir_path, exts, searchph, output);
	return 0;
}