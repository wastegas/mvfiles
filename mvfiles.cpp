#include <boost/filesystem.hpp>
#include <vector>
#include <iostream>

int main(int argc, char** argv)
{
	if(argc < 3)
	{
		std::cerr << "Usage: mvfiles <source> <target>" << std::endl;
		return -1;
	}
	
	boost::filesystem::path p(argv[1]);
	std::string tpath(argv[2]);
	std::string spath(argv[1]);
	
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
				for (vec::const_iterator it(v.begin()); it != v.end(); ++it)
				{
					fn = it->filename().string();
					s = spath+fn; 
					t = tpath+fn;
					std::cout << "Moving " << s << " to " << t << std::endl;
					boost::filesystem::rename(s, t);
					
				}

			}
		}
		else
		{
			std::cerr << argv[1] << " not found." << std::endl;
			return -1;
		}
	}
	catch (const boost::filesystem::filesystem_error& ex)
	{
		std::cerr << ex.what() << std::endl;
	}

	return 0;
}
