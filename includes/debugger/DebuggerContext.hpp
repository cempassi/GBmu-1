/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DebuggerContext.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 16:38:32 by ldedier           #+#    #+#             */
/*   Updated: 2020/06/25 19:22:33 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUGGERCONTEXT_HPP
# define DEBUGGERCONTEXT_HPP

# include "Debugger.hpp"
# include "ASTNode.hpp"
# include <iostream>
# include "PrintCommandSuffixParams.hpp"
# include "DebuggerAddress.hpp"
# include "WatchModes.hpp"

enum e_address_descriptor_type
{
	ADDRESS_DESCRIPTOR_TYPE_VARIABLE,
	ADDRESS_DESCRIPTOR_TYPE_ADDRESS
};

typedef struct						s_address_descriptor
{
	enum e_address_descriptor_type type;

	DebuggerVariable			*variable;
	DebuggerAddress				address;
}									t_address_descriptor; // used for the set command (set *32 = 44 / set $af = 23)

class DebuggerContext
{
	public:

		DebuggerContext(Debugger *debugger);
		DebuggerContext(DebuggerContext const &instance);
		DebuggerContext & operator=(DebuggerContext const &rhs);
		int 			printError(void);
		~DebuggerContext(void);

		Debugger					*debugger;
		PrintCommandSuffixParams	printCommandSuffixParams;
		t_address_descriptor		address_descriptor;
		WatchModes					watchModes;
		bool						shouldSaveAsLastCommand;
		int							quit;

	private:
		DebuggerContext(void);
		

};

#endif
