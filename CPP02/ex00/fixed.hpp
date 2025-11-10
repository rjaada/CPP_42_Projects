/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaada <rjaada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 15:58:39 by rjaada            #+#    #+#             */
/*   Updated: 2025/11/07 20:57:58 by rjaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <string>
# include <iostream>

class FixedPoint
{
	private:
		int fp_value;
		static const int frac_bits;
	public:
		FixedPoint();
		FixedPoint(FixedPoint const &copy);
		FixedPoint &operator=(const FixedPoint &copy);
		~FixedPoint();
		int getRawBits( void ) const;
		void setRawBits( int const raw );
};
#endif