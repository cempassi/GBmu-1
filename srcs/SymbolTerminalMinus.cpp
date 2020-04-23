/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolTerminalMinus.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/18 16:30:57 by ldedier            #+#    #+#            */
/*   Updated: 2020/04/18 16:30:57 by ldedier           ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

# include "SymbolTerminalMinus.hpp"

SymbolTerminalMinus::SymbolTerminalMinus(void) : AbstractTerminal("-")
{
	
}

SymbolTerminalMinus::~SymbolTerminalMinus(void)
{
	
}

int	SymbolTerminalMinus::traverse(ASTNode<int, CustomStack &> & ast, CustomStack & context) const
{
	static_cast<void>(ast);
	static_cast<void>(context);
	return (0);
}

