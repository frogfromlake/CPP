/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fquist <fquist@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 17:40:47 by fquist            #+#    #+#             */
/*   Updated: 2022/08/04 20:15:44 by fquist           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __HARL_H__
#define __HARL_H__

#include <string>
#include <iostream>
#include <fstream>

# define GREEN std::cout << "\033[1;32m"
# define LGREEN std::cout << "\033[0;32m"
# define YELLOW std::cout << "\033[0;33m"
# define RED std::cout << "\033[0;31m"
# define LBLUE std::cout << "\033[0;34m"
# define RESET "\033[0m" << std::endl

class	Harl {

	private:

		void debug( void );
		void info( void );
		void warning( void );
		void error( void );

	public:
		
		enum levels { DEBUG, INFO, WARNING, ERROR };
		void complain( std::string level );

};

#endif // __HARL_H__