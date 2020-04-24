/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolTerminalWordFormat.hpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/18 14:56:29 by ldedier            #+#    #+#            */
/*   Updated: 2020/04/18 14:56:29 by ldedier           ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYMBOLTERMINALWORDFORMAT_HPP
# define SYMBOLTERMINALWORDFORMAT_HPP

# include "AbstractTerminal.hpp"
# include "CustomStack.hpp"

class SymbolTerminalWordFormat : public AbstractTerminal<int, CustomStack &>
{
	public:
		SymbolTerminalWordFormat(void);
		~SymbolTerminalWordFormat(void);
		virtual int traverse(ASTNode<int, CustomStack &> & ast, CustomStack & context) const;

	private:

};

#endif
