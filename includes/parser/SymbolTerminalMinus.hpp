/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolTerminalMinus.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 19:16:33 by ldedier            #+#    #+#            */
/*   Updated: 2020/04/24 19:16:33 by ldedier           ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYMBOLTERMINALMINUS_HPP
# define SYMBOLTERMINALMINUS_HPP

# include "AbstractTerminal.hpp"
# include "DebuggerContext.hpp"

class SymbolTerminalMinus : public AbstractTerminal<int, DebuggerContext &>
{
	public:
		SymbolTerminalMinus(void);
		~SymbolTerminalMinus(void);
		virtual int traverse(ASTNode<int, DebuggerContext &> & ast, DebuggerContext & context) const;

	private:

};

#endif
