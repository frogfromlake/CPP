/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fquist <fquist@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 16:57:15 by fquist            #+#    #+#             */
/*   Updated: 2022/08/04 20:21:58 by fquist           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "StringReplace.hpp"

int main( int argc, char **argv ) {

	StringReplace func;

	if (argc == 4)
		func.ReplaceString(argv[1], argv[2], argv[3]);
	else
		GREEN "USAGE: ./StringReplace 'InFile' 'StringToBeReplaced' 'NewString'." RESET;
	system("leaks StringReplace");
	return (0);
}