/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolNonTerminalCommand.hpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 19:16:33 by ldedier            #+#    #+#            */
/*   Updated: 2020/04/24 19:16:33 by ldedier           ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYMBOLNONTERMINALCOMMAND_HPP
# define SYMBOLNONTERMINALCOMMAND_HPP

# include "DebuggerGrammar.hpp"

class SymbolNonTerminalCommand : public AbstractNonTerminal<int, DebuggerContext &>
{
	public:
		SymbolNonTerminalCommand(void);
		~SymbolNonTerminalCommand(void);
		virtual int traverse(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const;
		virtual void computeProductions(AbstractGrammar<int, DebuggerContext &> & cfg);

	private:

};

#endif
