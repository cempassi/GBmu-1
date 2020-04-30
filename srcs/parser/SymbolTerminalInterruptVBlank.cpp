/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolTerminalInterruptVBlank.cpp                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 16:25:25 by ldedier            #+#    #+#            */
/*   Updated: 2020/04/30 16:25:25 by ldedier           ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

# include "SymbolTerminalInterruptVBlank.hpp"

SymbolTerminalInterruptVBlank::SymbolTerminalInterruptVBlank(void) : AbstractTerminal("vblank")
{
	
}

SymbolTerminalInterruptVBlank::~SymbolTerminalInterruptVBlank(void)
{
	
}

int	SymbolTerminalInterruptVBlank::traverse(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const
{
	static_cast<void>(ast);
	static_cast<void>(context);
	return (0);
}

