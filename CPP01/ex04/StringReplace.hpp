/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StringReplace.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fquist <fquist@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 16:15:22 by fquist            #+#    #+#             */
/*   Updated: 2022/08/04 20:20:58 by fquist           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __STRINGREPLACE_H__
#define __STRINGREPLACE_H__

#include <string>
#include <iostream>
#include <fstream>

# define GREEN std::cout << "\033[1;32m"
# define LGREEN std::cout << "\033[0;32m"
# define RED std::cout << "\033[0;31m"
# define YELLOW std::cout << "\033[0;33m"
# define RESET "\033[0m" << std::endl

class StringReplace
{
	private:

	public:

		StringReplace();
		~StringReplace();
		bool 	CompareStrings(std::string s1, std::string s2);
		void	ReplaceString( std::string const &FileName, std::string s1, std::string s2 );

};


#endif // __STRINGREPLACE_H__