/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaada <rjaada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 16:37:55 by rjaada            #+#    #+#             */
/*   Updated: 2025/12/19 00:57:55 by rjaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain* brain;
	
	public:
		Cat();
		Cat(const Cat &other);
		Cat& operator=(Cat const &other);
		virtual void makeSound() const;
		void setIdea(int i, std::string idea);
        std::string getIdea(int i) const;
		virtual ~Cat();
};

#endif