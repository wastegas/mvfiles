#include "mvfiles.h"
#include <vector>

void moveFiles(std::string &spath, std::string &tpath)
{
	boost::filesystem::path p(spath);

	try
	{
		if(exists(p))
		{
			if(is_directory(p))
			{
				typedef std::vector<boost::filesystem::path> vec;
				vec v;
				std::string fn;
				std::copy(boost::filesystem::directory_iterator(p),
						boost::filesystem::directory_iterator(),
						std::back_inserter(v));

				std::string s, t;
				for(vec::const_iterator it(v.begin());
						it != v.end(); ++it)
				{
					fn = it->filename().string();
					s = spath + fn;
					t = tpath + fn;

#ifndef NDBUG
					std::cout << "Moving " << s << " to " << t << std::endl;
#endif
					
					boost::filesystem::rename(s, t);
				}
			}			
		}
	}
	catch(const boost::filesystem::filesystem_error& ex)
	{
		std::cerr << ex.what() << std::endl;
	}
}

