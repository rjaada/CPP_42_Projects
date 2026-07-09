/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaada <rjaada@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-07-08 17:45:50 by rjaada            #+#    #+#             */
/*   Updated: 2026-07-08 17:45:50 by rjaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() : stk(){}

RPN::RPN(RPN const &other) : stk(other.stk){}

RPN& RPN::operator=(RPN const &other)
{
	if(this != &other)
		this->stk = other.stk;
	return *this;
}

RPN::~RPN(){}

int RPN::CalcRpn(std::string tokens)
{
	std::istringstream ss(tokens);

	while (ss >> tokens)
	{
		if (tokens == "+" || tokens == "-" || tokens == "*" || tokens == "/")
		{
			if (stk.size() < 2)
				throw std::runtime_error("Error");
			int a = stk.top();
			stk.pop();
			int b = stk.top();
			stk.pop();
			
			if(tokens == "+")
				stk.push(b + a);
			else if(tokens == "-")
				stk.push(b - a);
			else if(tokens == "*")
				stk.push(b * a);
			else if(tokens == "/")
			{
				if(a == 0)
					throw std::runtime_error("Error");
				else
					stk.push(b / a);
			}
		}
		else
		{
			if (tokens.length() != 1 || !isdigit(tokens[0]))
        		throw std::runtime_error("Error");
			stk.push(atoi(tokens.c_str()));
		}
	}
	if (stk.size() != 1)
    	throw std::runtime_error("Error");

	return stk.top();

}