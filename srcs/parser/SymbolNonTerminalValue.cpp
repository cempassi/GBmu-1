/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolNonTerminalValue.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 15:36:19 by ldedier           #+#    #+#             */
/*   Updated: 2020/04/24 17:01:12 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "SymbolNonTerminalValue.hpp"

SymbolNonTerminalValue::SymbolNonTerminalValue(void) : AbstractNonTerminal("value")
{
	
}

SymbolNonTerminalValue::~SymbolNonTerminalValue(void)
{
	
}

int	SymbolNonTerminalValue::traverse(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const
{
	if (ast.getChildren().size() == 1)
		return ast.getChild(0)->getTraversed(context);
	else
		return context.cpu.cycle; //TODO use true value
	return (0);
}

void	SymbolNonTerminalValue::computeProductions(AbstractGrammar<int, DebuggerContext &> & cfg)
{
	addProduction(cfg, {"andor"});
	addProduction(cfg, {});
}
