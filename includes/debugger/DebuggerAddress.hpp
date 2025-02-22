/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DebuggerAddress.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 14:49:12 by ldedier           #+#    #+#             */
/*   Updated: 2020/06/21 17:19:00 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUGGERADDRESS_HPP
# define DEBUGGERADDRESS_HPP

# include <iostream>

class DebuggerAddress
{
	public:
		DebuggerAddress(void);
		DebuggerAddress(uint16_t value);
		DebuggerAddress(DebuggerAddress const &instance);
		DebuggerAddress &operator=(DebuggerAddress const &rhs);
		~DebuggerAddress(void);

		bool operator<(const DebuggerAddress & debuggerAddress) const;
		bool operator!=(const DebuggerAddress & debuggerAddress) const;
		void operator+=(const int toAdd);
		DebuggerAddress operator++(int dummy);
		uint16_t getValue(void) const;
		void setValue(uint16_t value);

	private:

		uint16_t _value;

};

std::ostream &operator<<(std::ostream &o, DebuggerAddress const &instance);
#endif