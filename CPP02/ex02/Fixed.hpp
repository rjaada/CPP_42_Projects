/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaada <rjaada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 16:51:35 by rjaada            #+#    #+#             */
/*   Updated: 2025/11/08 18:04:40 by rjaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>
# include <cmath>

class Fixed
{
	private:
		int fp_value;
		static const int frac_bits;
	public:
		Fixed();
		Fixed(const int num);
		Fixed(const float f_num);
		Fixed(const Fixed &copy);
		
		Fixed &operator=(const Fixed &copy);
		
		bool operator<(const Fixed &copy) const;
		bool operator>(const Fixed &copy) const;
		bool operator==(const Fixed &copy) const;
		bool operator<=(const Fixed &copy) const;
		bool operator>=(const Fixed &copy) const;
		bool operator!=(const Fixed &copy) const;
		
		Fixed operator+(const Fixed &copy) const;
		Fixed operator-(const Fixed &copy) const;
		Fixed operator*(const Fixed &copy) const;
		Fixed operator/(const Fixed &copy) const;
		
		Fixed &operator++();
		Fixed operator++(int);
		Fixed &operator--();
		Fixed operator--(int);
		
		friend std::ostream& operator<<(std::ostream& out, const Fixed& copy);
		float toFloat( void ) const;
		int toInt( void ) const;

		static Fixed &min(Fixed &a, Fixed &b);
		static const Fixed &min(const Fixed &a, const Fixed &b);
		static Fixed &max(Fixed &a, Fixed &b);
		static const Fixed &max(const Fixed &a, const Fixed &b);
		
		~Fixed();
	
};
	

#endif