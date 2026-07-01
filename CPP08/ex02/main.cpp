/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaada <rjaada@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-07-01 14:58:12 by rjaada            #+#    #+#             */
/*   Updated: 2026-07-01 14:58:12 by rjaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>

int	main(void)
{
		std::cout << "------------42 examples-----------" << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);

	std::cout << "------------other examples-----------" << std::endl;

	MutantStack<int> myStack;
	myStack.push(-3);
	myStack.push(-2);
	myStack.push(-1);
	myStack.push(0);
	myStack.push(1);
	myStack.push(2);
	myStack.push(3);

	MutantStack<int>::iterator iter = myStack.begin();
	while (iter != myStack.end())
	{
		std::cout << *iter++ << std::endl;
	}

	std::cout << "------------list examples-----------" << std::endl;

	std::list<int> myList;
	myList.push_back(-3);
	myList.push_back(-2);
	myList.push_back(-1);
	myList.push_back(0);
	myList.push_back(1);
	myList.push_back(2);
	myList.push_back(3);

	std::list<int>::iterator iterator = myList.begin();
	while (iterator != myList.end())
	{
		std::cout << *iterator++ << std::endl;
	}
	return (0);
}