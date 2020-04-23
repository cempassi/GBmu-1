/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolTerminalOpenParenthesis.hpp                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/18 16:30:57 by ldedier            #+#    #+#            */
/*   Updated: 2020/04/18 16:30:57 by ldedier           ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYMBOLTERMINALOPENPARENTHESIS_HPP
# define SYMBOLTERMINALOPENPARENTHESIS_HPP

# include "AbstractTerminal.hpp"
# include "CustomStack.hpp"

class SymbolTerminalOpenParenthesis : public AbstractTerminal<int, CustomStack &>
{
	public:
		SymbolTerminalOpenParenthesis(void);
		~SymbolTerminalOpenParenthesis(void);
		virtual int traverse(ASTNode<int, CustomStack &> & ast, CustomStack & context) const;

	private:

};

#endif
