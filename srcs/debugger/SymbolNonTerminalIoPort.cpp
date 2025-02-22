/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolNonTerminalIoPort.cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 16:38:32 by ldedier           #+#    #+#             */
/*   Updated: 2021/06/04 13:29:26 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "SymbolNonTerminalIoPort.hpp"

SymbolNonTerminalIoPort::SymbolNonTerminalIoPort(void) : AbstractNonTerminal("ioport")
{
	
}

SymbolNonTerminalIoPort::~SymbolNonTerminalIoPort(void)
{
	
}

int	SymbolNonTerminalIoPort::traverse(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const
{
	static_cast<void>(ast);
	static_cast<void>(context);
	return (0);
}

void	SymbolNonTerminalIoPort::computeProductions(AbstractGrammar<int, DebuggerContext &> & cfg)
{
	addProduction(cfg, {"divoffset"});
	addProduction(cfg, {"timaoffset"});
}
