/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolNonTerminalComparison.hpp                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/18 14:56:29 by ldedier            #+#    #+#            */
/*   Updated: 2020/04/18 14:56:29 by ldedier           ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYMBOLNONTERMINALCOMPARISON_HPP
# define SYMBOLNONTERMINALCOMPARISON_HPP

# include "DebuggerGrammar.hpp"

class SymbolNonTerminalComparison : public AbstractNonTerminal<int, CustomStack &>
{
	public:
		SymbolNonTerminalComparison(void);
		~SymbolNonTerminalComparison(void);
		virtual int traverse(ASTNode<int, CustomStack &> & ast, CustomStack & context) const;
		virtual void computeProductions(AbstractGrammar<int, CustomStack &> & cfg);

	private:

};

#endif
