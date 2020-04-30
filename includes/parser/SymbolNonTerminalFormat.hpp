/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolNonTerminalFormat.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 16:25:25 by ldedier            #+#    #+#            */
/*   Updated: 2020/04/30 16:25:25 by ldedier           ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYMBOLNONTERMINALFORMAT_HPP
# define SYMBOLNONTERMINALFORMAT_HPP

# include "DebuggerGrammar.hpp"

class SymbolNonTerminalFormat : public AbstractNonTerminal<int, DebuggerContext &>
{
	public:
		SymbolNonTerminalFormat(void);
		~SymbolNonTerminalFormat(void);
		virtual int traverse(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const;
		virtual void computeProductions(AbstractGrammar<int, DebuggerContext &> & cfg);

	private:

};

#endif
