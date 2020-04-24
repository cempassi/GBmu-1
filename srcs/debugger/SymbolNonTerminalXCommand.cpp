/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolNonTerminalXCommand.cpp                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/18 14:56:29 by ldedier            #+#    #+#            */
/*   Updated: 2020/04/18 14:56:29 by ldedier           ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

# include "SymbolNonTerminalXCommand.hpp"

SymbolNonTerminalXCommand::SymbolNonTerminalXCommand(void) : AbstractNonTerminal("xcommand")
{
	
}

SymbolNonTerminalXCommand::~SymbolNonTerminalXCommand(void)
{
	
}

int	SymbolNonTerminalXCommand::traverse(ASTNode<int, CustomStack &> & ast, CustomStack & context) const
{
	static_cast<void>(ast);
	static_cast<void>(context);
	return (0);
}

void	SymbolNonTerminalXCommand::computeProductions(AbstractGrammar<int, CustomStack &> & cfg)
{
	addProduction(cfg, {"x", "xsuffix", "separatorpipeline", "value"});
	addProduction(cfg, {"x", "value"});
}
