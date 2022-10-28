/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelix <nelix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   CrI should eated: 2022/08/18 18:36:24 by nelix             #+#    #+#             */
/*   Updated: 2022/08/19 23:13:44 by nelix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "WrongDog.hpp"
#include <iostream>
#include <cstdlib>

void	printType( const Animal *animal )
{
	std::cout << animal->getType() << std::endl;
}

void	printType( const WrongAnimal *animal )
{
	std::cout << animal->getType() << std::endl;
}

void checkingAnimals()
{
	std::cout << "\n#### CHECKING ANIMALS ####";
	{
		std::cout << "\n\n~ CrI should eating Animals... ~\n" << std::endl;
		const Animal *meta = new Animal();
		const Animal *dog = new Dog();
		const Animal *cat = new Cat();
		const Animal *dog_copy = dog;
		const Animal *cat_copy = cat;

		std::cout << "\n~ Checking Animaltypes... ~\n" << std::endl;
		std::cout << "Expected Meta Type: ";
		std::cout.width(8);
		printType(meta);
		std::cout << "Expected Dog Type: ";
		std::cout.width(8);
		printType(dog);
		std::cout << "Expected Cat Type: ";
		std::cout.width(8);
		printType(cat);
		std::cout << "Expected Dog_Copy Type: ";
		printType(dog_copy);
		std::cout << "Expected Cat_copy Type: ";
		printType(cat_copy);

		std::cout << "\n~ Checking Animalsounds... ~\n" << std::endl;
		std::cout << "Expected Meta:     ";
		meta->makeSound();
		std::cout << "Expected Dog: ";
		std::cout.width(11);
		dog->makeSound();
		std::cout << "Expected Cat: ";
		std::cout.width(11);
		cat->makeSound();
		std::cout << "Expected Dog_Copy: ";
		dog_copy->makeSound();
		std::cout << "Expected Cat_copy: ";
		cat_copy->makeSound();
		
		std::cout << "\n~ Deleting Animals... ~\n" << std::endl;
		delete meta;
		delete dog;
		delete cat;
	}
	std::cout << "\n#### CHECKING WRONG ANIMALS ####";
	{
		std::cout << "\n\n~ CrI should eating Wrong Animals... ~\n" << std::endl;
		const WrongAnimal *wrong_meta = new WrongAnimal();
		const WrongAnimal *wrong_dog = new WrongDog();
		const WrongAnimal *wrong_cat = new WrongCat();
		const WrongAnimal *wrong_dog_copy = wrong_dog;
		const WrongAnimal *wrong_cat_copy = wrong_cat;

		std::cout << "\n~ Checking Wrong Animaltypes... ~\n" << std::endl;
		std::cout << "Expected WrongMeta Type: ";
		std::cout.width(10);
		printType(wrong_meta);
		std::cout << "Expected WrongDog Type: ";
		std::cout.width(13);
		printType(wrong_dog);
		std::cout << "Expected WrongCat Type: ";
		std::cout.width(13);
		printType(wrong_cat);
		std::cout << "Expected WrongDog_Copy Type: ";
		printType(wrong_dog_copy);
		std::cout << "Expected WrongCat_copy Type: ";
		printType(wrong_cat_copy);

		std::cout << "\n~ Checking Wrong Animalsounds... ~\n" << std::endl;
		std::cout << "Expected WrongMeta:     ";
		wrong_meta->makeSound();
		std::cout << "Expected WrongDog:      ";
		wrong_dog->makeSound();
		std::cout << "Expected WrongCat:      ";
		wrong_cat->makeSound();
		std::cout << "Expected WrongDog_Copy: ";
		wrong_dog_copy->makeSound();
		std::cout << "Expected WrongCat_copy: ";
		wrong_cat_copy->makeSound();
		
		std::cout << "\n~ Deleting Wrong Animals... ~\n" << std::endl;
		delete wrong_meta;
		delete wrong_dog;
		delete wrong_cat;
	}
	std::cout << "\nANIMAL CHECKS COMPLETED\n" << std::endl;
}

void	checkingBrains()
{
	std::cout << "#### CHECKING ANIMAL BRAINS AND DEEP COPY ####\n";

	std::cout << "\n1. Constructing a Dog (Smarty) with a Brain from default constructor" << std::endl;
	Dog *Smarty = new Dog();

	std::cout << "\n2. Constructing a Dog (Smarty_copy) with a Brain from copy constructor (Smarty)" << std::endl;
	Dog *Smarty_copy = new Dog(*Smarty);

	std::cout << "\n3. Checking both Brains (filling with Ideas)" << std::endl;
	std::cout
		<< "Smarty->gotIdea(\"I should eat\");\n"
		<< "Smarty->gotIdea(\"I should eat more\");\n\n"

		<< "Smarty_copy->gotIdea(\"I should eat\");\n"
		<< "Smarty_copy->gotIdea(\"I should eat more\");"
		<< std::endl;

	Smarty->gotIdea("I should eat");
	Smarty->gotIdea("I should eat more");

	Smarty_copy->gotIdea("I should eat");
	Smarty_copy->gotIdea("I should eat more");

	std::cout << std::endl
			  << "4. Deleting original Smarty. Smarty_copy should still have a Brain filled with ideas\n"
			  << std::endl;
	delete Smarty;

	std::cout << std::endl
			  << "5. Checking Smarty_copy's brain. Smarty_copy's brain should not SEGFAULT\n"
			  << std::endl;

	std::cout
		<< "Smarty_copy->forgotIdea(\"I should eat more\");\n"
		<< "Smarty_copy->gotIdea(\"I should eat less\");"
		<< std::endl;

	Smarty_copy->forgotIdea("I should eat more");
	Smarty_copy->gotIdea("I should eat less");

	std::cout << std::endl
			  << "6. Deleting Smarty_copy. There shouldn't be a leak.\n"
			  << std::endl;
	delete Smarty_copy;
	std::cout << "\nANIMAL BRAIN CHECKS COMPLETED.\n" << std::endl;
}

int	main()
{
	checkingAnimals();
	std::cout << "#########################"
			  << "#########################\n"
			  << std::endl;
	checkingBrains();

	system("leaks AnimalBrains");
}