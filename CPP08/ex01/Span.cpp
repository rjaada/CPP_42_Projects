/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaada <rjaada@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-06-21 17:24:40 by rjaada            #+#    #+#             */
/*   Updated: 2026-06-21 17:24:40 by rjaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : N(0)
{
}

Span::Span(unsigned int num) : N(num)
{
}

Span::Span(Span const &other) : N(other.N), _vec(other._vec)
{
}

Span &Span::operator=(Span const &other)
{
	if (this != &other)
	{
		N = other.N;
		_vec = other._vec;
	}
	return (*this);
}

Span::~Span()
{
}

// Core Methods
void Span::addNumber(int n)
{
	if (_vec.size() >= N)
		throw SpanFullException();
	_vec.push_back(n);
}

unsigned int Span::shortestSpan()
{
	unsigned int	min_span;
	unsigned int	diff;

	if (_vec.size() < 2)
		throw NotEnoughNumbersException();
	// Copy and sort so we don't mess up the original stash
	std::vector<int> sorted = _vec;
	std::sort(sorted.begin(), sorted.end());
	// Start with the max possible unsigned int
	min_span = static_cast<unsigned int>(-1);
	for (size_t i = 1; i < sorted.size(); ++i)
	{
		diff = sorted[i] - sorted[i - 1];
		if (diff < min_span)
			min_span = diff;
	}
	return (min_span);
}

unsigned int Span::longestSpan()
{
	if (_vec.size() < 2)
		throw NotEnoughNumbersException();

	int min = *std::min_element(_vec.begin(), _vec.end());
	int max = *std::max_element(_vec.begin(), _vec.end());

	return (static_cast<unsigned int>(max - min));
}