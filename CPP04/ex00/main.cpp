/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fquist <fquist@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 18:36:24 by nelix             #+#    #+#             */
/*   Updated: 2022/08/31 16:06:41 by fquist           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "WrongDog.hpp"
#include <iostream>

void	printType( const Animal *animal )
{
	std::cout << animal->getType() << std::endl;
}

void	printType( const WrongAnimal *animal )
{
	std::cout << animal->getType() << std::endl;
}

int main()
{
	std::cout << "\n#### CHECKING ANIMALS ####";
	{
		std::cout << "\n\n~ Creating Animals... ~\n" << std::endl;
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
		std::cout << "\n\n~ Creating Wrong Animals... ~\n" << std::endl;
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
	std::cout << "\nChecks completed!\n" << std::endl;

	system("leaks Animal");
	return 0;
}