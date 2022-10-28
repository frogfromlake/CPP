/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelix <nelix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 21:01:47 by nelix             #+#    #+#             */
/*   Updated: 2022/08/21 22:46:12 by nelix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(___BRAIN_H___)
#define ___BRAIN_H___

#include <string>

class Brain
{
	private:
		/* Private Attributes */
		static const unsigned int _maxIdeas = 100;
		std::string _ideas[_maxIdeas];

	public:
		/* Constructors */
		Brain();
		Brain(const Brain &copy);
		/* Deconstructors */
		~Brain();

		/* Overloaded Operators */
		Brain &operator=(const Brain &op);

		/* Public Methods */
		void	addIdea(std::string idea);
		void	removeIdea(std::string idea);

		/* Getter */
		std::string getIdea(unsigned int index);

		/* Setter */
};

#endif // __BRAIN_H__