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
	std::size_t len = spath.size();

	if (spath[len-1] != '/')
		spath += '/';
	
	std::string tpath(argv[2]);
	len = tpath.size();

	if(tpath[len-1] != '/')
		tpath += '/';

	moveFiles(spath, tpath);
	
	std::cout << "move completed" << std::endl;

	return 0;
}
