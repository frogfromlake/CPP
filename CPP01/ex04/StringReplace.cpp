/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StringReplace.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fquist <fquist@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 16:14:41 by fquist            #+#    #+#             */
/*   Updated: 2022/09/12 18:27:29 by fquist           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "StringReplace.hpp"

StringReplace::StringReplace() {
	return ;
}

StringReplace::~StringReplace() {
	return ;
}

bool StringReplace::CompareStrings(std::string s1, std::string s2)
{
	if (s1.compare(s2) != 0)
		return (false);
	else
		return (true);
}

void StringReplace::ReplaceString(std::string const &FileName, std::string s1, std::string s2)
{
	std::string line;
	int len = s1.length();
	char *str1 = &s1[0];
	std::string result;

	std::ifstream InFile(FileName);
	std::ofstream OutFile(FileName + ".replace" , std::ios::trunc);
	if (!InFile.is_open() || !OutFile.is_open())
		RED "Error: Unable to open file." RESET;
	else if (CompareStrings(s1, s2) == false)
	{
		if (len != 0) {

			std::string::size_type pos = 0;
			result = s1.substr(pos, len);
			while (std::getline(InFile, line)) {
				pos = line.find(s1);
				std::cout << line;
				while (pos != std::string::npos) {

					line.erase(pos, len);
					line.insert(pos, s2);
					if (result.compare(s1) == 0)
						break ;
					pos = line.find(str1, pos, len);
				}
				if (InFile.eof())
					OutFile << line;
				else
					OutFile << line << std::endl;
			}
			GREEN "Copy finished." RESET;
		}
		else
			RED "Error: empty string." RESET;
	}
	InFile.close();
	OutFile.close();
}
