/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolTerminalSeparator.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/18 15:33:38 by ldedier            #+#    #+#            */
/*   Updated: 2020/04/18 15:33:38 by ldedier           ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYMBOLTERMINALSEPARATOR_HPP
# define SYMBOLTERMINALSEPARATOR_HPP

# include "AbstractSeparatorTerminal.hpp"
# include "CustomStack.hpp"

class SymbolTerminalSeparator : public AbstractSeparatorTerminal<int, CustomStack &>
{
	public:
		SymbolTerminalSeparator(void);
		~SymbolTerminalSeparator(void);
		virtual int traverse(ASTNode<int, CustomStack &> & ast, CustomStack & context) const;

	private:

};

#endif
