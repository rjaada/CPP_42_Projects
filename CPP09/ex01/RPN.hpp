/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaada <rjaada@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-07-08 16:36:24 by rjaada            #+#    #+#             */
/*   Updated: 2026-07-08 16:36:24 by rjaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <string>
# include <map>
# include <stack>
# include <cstdlib>
# include <sstream>

class RPN
{
	private:
		std::stack<int> stk;
	public:
		RPN();
		RPN(RPN const &other);
		RPN& operator=(RPN const &other);
		~RPN();
		
		int CalcRpn(std::string tokens);
};




#endif