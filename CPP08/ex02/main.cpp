/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fquist <fquist@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 21:00:57 by nelix             #+#    #+#             */
/*   Updated: 2022/09/16 21:04:57 by fquist           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

#include <iostream>
#include <list>

void printStack(MutantStack<int> mstack, bool iter_test)
{
	MutantStack<int>::iterator begin = mstack.begin();
	MutantStack<int>::iterator end = mstack.end();

	if (iter_test == true)
	{
		++begin;
		--begin;
	}
	
	while (begin != end)
	{
		std::cout << *begin << std::endl;
		++begin;
	}
}

void printList(std::list<int> lst, bool iter_test)
{
	std::list<int> begin = lst.begin();
	std::list<int>::iterator end = lst.end();

	if (iter_test == true)
	{
		++begin;
		--begin;
	}
	
	while (begin != end)
	{
		std::cout << *begin << std::endl;
		++begin;
	}
}

void CheckingMStack()
{
	std::cout << "~~~~~~~~~~~~ Checking MutantStack ... ~~~~~~~~~~~~~" << std::endl;

	MutantStack<int> mstack;

	std::cout << "~~~~~~ Pushing 2 Elements to mstack [5, 17] ~~~~~~~" << std::endl;
	mstack.push(5);
	mstack.push(17);
	printStack(mstack, false);

	std::cout << "~~~~~~~~ View Top Element from mstack [17] ~~~~~~~~" << std::endl;
	std::cout << mstack.top() << std::endl;
	
	std::cout << "~~~~~~~ Pop last Element from mstack [17] ~~~~~~~~~" << std::endl;
	mstack.pop();
	
	std::cout << "\t>> MutantStack Size: " << mstack.size() << std::endl;
	std::cout << "\t>> MutantStack Content: ";
	printStack(mstack, false);

	std::cout << "~~~ Pushing 4 Elements to mstack [3, 5, 737, 0] ~~~" << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	printStack(mstack, false);

	std::cout << "~~~~~ Incrementing and Decrementing Iterators ~~~~~" << std::endl;
	std::cout << "\t>> Should print mstack from beginning:" << std::endl;
	printStack(mstack, true);

	std::cout << "~~~ Print Stack from std::stack<int> s(mstack); ~~~" << std::endl;
	std::stack<int> s(mstack);
	printStack(s, false);
}

void CompareWithList()
{
	std::cout << "~~~~~~~~~~~~~~ Comparing with std::list ... ~~~~~~~~~~~~~~~~" << std::endl;

	std::list<int> comparisonStack;

	std::cout << "~~~~~~ Pushing 2 Elements to comparisonStack [5, 17] ~~~~~~~" << std::endl;
	comparisonStack.push_back(5);
	comparisonStack.push_back(17);
	printList(comparisonStack, false);

	std::cout << "~~~~~~~~ View Top Element from comparisonStack [17] ~~~~~~~~" << std::endl;
	std::cout << comparisonStack.back() << std::endl;

	std::cout << "~~~~~~~ Pop last Element from comparisonStack [17] ~~~~~~~~~" << std::endl;
	comparisonStack.pop_back();

	std::cout << "\t>> MutantStack Size: " << comparisonStack.size() << std::endl;
	std::cout << "\t>> MutantStack Content: ";
	printList(comparisonStack, false);

	std::cout << "~~~ Pushing 4 Elements to comparisonStack [3, 5, 737, 0] ~~~~" << std::endl;
	comparisonStack.push_back(3);
	comparisonStack.push_back(5);
	comparisonStack.push_back(737);
	comparisonStack.push_back(0);

	printList(comparisonStack, false);

	std::cout << "~~~~~~~~~~ Incrementing and Decrementing Iterators ~~~~~~~~~~" << std::endl;
	std::cout << "\t>> Should print comparisonStack from beginning:" << std::endl;
	printList(comparisonStack, true);
}

int main(void)
{
	CheckingMStack();

	CompareWithList();

	system("leaks mstack");
	return 0;
}