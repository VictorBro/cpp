#include <iostream>
#include <string>
#include <fstream>

int main(int argc, char **argv)
{
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <filename> <str1> <str2>" << std::endl;
        return 1;
    }
    std::string filename = argv[1];
    std::string str1 = argv[2];
    std::string str2 = argv[3];

    if (filename.empty() || str1.empty())
    {
        std::cerr << "Error: Filename and str1 must not be empty." << std::endl;
        return 1;
    }
    if (str1 == str2)
    {
        std::cerr << "Error: The two strings must be different." << std::endl;
        return 1;
    }
    std::ifstream from(filename.c_str());
    if (!from.is_open())
    {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return 1;
    }
    std::ofstream to((filename + ".replace").c_str());
    if (!to.is_open())
    {
        std::cerr << "Error: Could not create output file " << filename + ".replace" << std::endl;
        from.close();
        return 1;
    }
    // replace all occurrences of str1 with str2 without using std::string::replace
    std::string line;
    while (std::getline(from, line))
    {
        std::size_t pos = 0;
        while ((pos = line.find(str1, pos)) != std::string::npos)
        {
            line.erase(pos, str1.length());
            line.insert(pos, str2);
            pos += str2.length();
        }
        
        to << line << std::endl;
        if (to.fail())
        {
            std::cerr << "Error: Failed to write to file " << filename + ".replace" << std::endl;
            from.close();
            to.close();
            return 1;
        }
    }
    
    if (from.fail() && !from.eof())
    {
        std::cerr << "Error: Failed to read from file " << filename << std::endl;
        from.close();
        to.close();
        return 1;
    }
    
    from.close();
    to.close();
    return 0;
}
