/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolTerminalRegisters.cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 16:38:32 by ldedier           #+#    #+#             */
/*   Updated: 2020/06/19 16:52:40 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "SymbolTerminalRegisters.hpp"

SymbolTerminalRegisters::SymbolTerminalRegisters(void) : SymbolTerminalCommand(REGISTERS_COMMAND)
{
	
}

SymbolTerminalRegisters::~SymbolTerminalRegisters(void)
{
	
}

int	SymbolTerminalRegisters::traverse(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const
{
	static_cast<void>(ast);
	static_cast<void>(context);
	return (0);
}

