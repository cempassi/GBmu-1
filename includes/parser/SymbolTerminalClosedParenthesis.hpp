/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolTerminalClosedParenthesis.hpp                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 19:16:33 by ldedier            #+#    #+#            */
/*   Updated: 2020/04/24 19:16:33 by ldedier           ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYMBOLTERMINALCLOSEDPARENTHESIS_HPP
# define SYMBOLTERMINALCLOSEDPARENTHESIS_HPP

# include "AbstractTerminal.hpp"
# include "DebuggerContext.hpp"

class SymbolTerminalClosedParenthesis : public AbstractTerminal<int, DebuggerContext &>
{
	public:
		SymbolTerminalClosedParenthesis(void);
		~SymbolTerminalClosedParenthesis(void);
		virtual int traverse(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const;

	private:

};

#endif
