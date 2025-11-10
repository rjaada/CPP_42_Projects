/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaada <rjaada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 21:15:10 by rjaada            #+#    #+#             */
/*   Updated: 2025/11/07 23:38:12 by rjaada           ###   ########.fr       */
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
		Fixed &operator=(const Fixed &Fixed);
		friend std::ostream& operator<<(std::ostream& out, const Fixed& fixed);
		float toFloat( void ) const;
		int toInt( void ) const;
		~Fixed();
};

#endif