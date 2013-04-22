#include <iostream>
#include "mvfiles.h"

int main(int argc, char** argv)
{
	std::string spath(argv[1]);
	std::string tpath(argv[2]);

	moveFiles(spath, tpath);

	return 0;
}
