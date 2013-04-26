#include <iostream>
#include "mvfiles.h"

int main(int argc, char** argv)
{
	if(argc < 3)
	{
		std::cerr << "Usage: mvfiles <source path> <target path>" << std::endl;
		return -1;
	}

	std::string spath(argv[1]);
	if (spath.back() != '/')
		spath += '/';
	
	std::string tpath(argv[2]);

	if(tpath.back() != '/')
		tpath += '/';

	moveFiles(spath, tpath);

	return 0;
}
