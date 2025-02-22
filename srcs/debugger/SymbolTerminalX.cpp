/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolTerminalX.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 19:29:45 by ldedier           #+#    #+#             */
/*   Updated: 2020/06/19 16:52:00 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "SymbolTerminalX.hpp"

SymbolTerminalX::SymbolTerminalX(void) : SymbolTerminalPrintingCommand(X_COMMAND)
{
	
}

SymbolTerminalX::~SymbolTerminalX(void)
{
	
}

int	SymbolTerminalX::traverse(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const
{
	static_cast<void>(ast);
	static_cast<void>(context);
	return (0);
}

