/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolNonTerminalCommand.cpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 19:16:33 by ldedier            #+#    #+#            */
/*   Updated: 2020/04/24 19:16:33 by ldedier           ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

# include "SymbolNonTerminalCommand.hpp"

SymbolNonTerminalCommand::SymbolNonTerminalCommand(void) : AbstractNonTerminal("command")
{
	
}

SymbolNonTerminalCommand::~SymbolNonTerminalCommand(void)
{
	
}

int	SymbolNonTerminalCommand::traverse(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const
{
	static_cast<void>(ast);
	static_cast<void>(context);
	return (0);
}

void	SymbolNonTerminalCommand::computeProductions(AbstractGrammar<int, DebuggerContext &> & cfg)
{
	addProduction(cfg, {"printcommand"});
	addProduction(cfg, {"xcommand"});
	addProduction(cfg, {"stepcommand"});
	addProduction(cfg, {"nextcommand"});
	addProduction(cfg, {"breakpointcommand"});
	addProduction(cfg, {"deletecommand"});
	addProduction(cfg, {"infocommand"});
	addProduction(cfg, {"registerscommand"});
	addProduction(cfg, {"quitcommand"});
	addProduction(cfg, {"verbosecommand"});
	addProduction(cfg, {});
}
