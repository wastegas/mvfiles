#include <boost/filesystem.hpp>
#include <vector>
#include <iostream>

using boost::filesystem::path;
using boost::filesystem::filesystem_error;
using boost::filesystem::directory_iterator;
using boost::filesystem::rename;
using std::vector;
using std::cout;
using std::endl;

int main(int argc, char** argv)
{
	if(argc < 3)
	{
		cout << "Usage: fmv <source> <target>" << endl;
		return -1;
	}
	
	path p(argv[1]);
	std::string tpath(argv[2]);
	std::string spath(argv[1]);
	
	try
	{

		if(exists(p))
		{
			if(is_directory(p))
			{
				typedef vector<path> vec;
				vec v;
				std::string fn;
				copy(directory_iterator(p), 
						directory_iterator(), 
						back_inserter(v));

				std::string s, t;
				for (vec::const_iterator it(v.begin()); it != v.end(); ++it)
				{
					fn = it->filename().string();
					s = spath+fn; 
					t = tpath+fn;
					rename(s, t);
					
				}

			}
		}
	}
	catch (const filesystem_error& ex)
	{
		cout << ex.what() << endl;
	}
	return 0;
}
