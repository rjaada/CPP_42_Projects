/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaada <rjaada@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-06-21 14:28:36 by rjaada            #+#    #+#             */
/*   Updated: 2026-06-21 14:28:36 by rjaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <exception>
# include <iostream>
# include <string>
# include <vector>
# include <algorithm>

class Span
{
  private:
	unsigned int N;
	std::vector<int> _vec;

  public:
	Span();
	Span(unsigned int num);
	Span(Span const &other);
	Span &operator=(Span const &other);
	~Span();

	void addNumber(int n);
	unsigned int shortestSpan();
	unsigned int longestSpan();

	template <typename Iterator> void addNumber(Iterator begin, Iterator end)
	{
		if (std::distance(begin, end) + _vec.size() > N)
			throw SpanFullException();
		_vec.insert(_vec.end(), begin, end);
	};

	class SpanFullException : public std::exception
	{
		public:
		virtual const char *what() const throw()
		{
			return ("the span is full!");
		}
	};

	class NotEnoughNumbersException : public std::exception
	{
		public:
		virtual const char *what() const throw()
		{
			return ("Need at least 2 numbers.");
		}
	};
};

#endif