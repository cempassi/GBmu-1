/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolTerminalRightShift.cpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/18 16:30:57 by ldedier            #+#    #+#            */
/*   Updated: 2020/04/18 16:30:57 by ldedier           ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

# include "SymbolTerminalRightShift.hpp"

SymbolTerminalRightShift::SymbolTerminalRightShift(void) : AbstractTerminal(">>")
{
	
}

SymbolTerminalRightShift::~SymbolTerminalRightShift(void)
{
	
}

int	SymbolTerminalRightShift::traverse(ASTNode<int, CustomStack &> & ast, CustomStack & context) const
{
	static_cast<void>(ast);
	static_cast<void>(context);
	return (0);
}

