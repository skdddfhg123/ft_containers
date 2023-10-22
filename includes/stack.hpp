#pragma once

#ifndef STACK_H
# define STACK_H

# include <iostream>
# include "vector.hpp"

namespace ft
{
	template <class T, class Container = ft::vector<T> >
	class stack {
		protected:
			Container											c;

		public:
			typedef T											value_type;
			typedef Container									container_type;
			typedef typename container_type::reference			reference;
			typedef typename container_type::const_reference	const_reference;
			typedef typename container_type::size_type			size_type;

			explicit stack (const container_type& ctnr = container_type()) : c(ctnr) { };

			~stack(){ };

			bool			empty(void) const			{ return this->c.empty(); };
			size_type		size(void) const			{ return this->c.size(); };
			reference		top(void)					{ return this->c.back(); };
			const_reference	top(void) const 			{ return this->c.back(); };
			void			push(const_reference val)	{ this->c.push_back(val); };
			void			pop(void)					{ this->c.pop_back(); };
			void			swap(stack& ref) 			{ c.swap(ref.c); };

			friend bool operator == (const stack<T, Container> &lhs, const stack<T, Container> &rhs) { return lhs.c == rhs.c; };
			friend bool operator != (const stack<T, Container> &lhs, const stack<T, Container> &rhs) { return lhs.c != rhs.c; };
			friend bool operator < (const stack<T, Container> &lhs, const stack<T, Container> &rhs) { return lhs.c < rhs.c; };
			friend bool operator <= (const stack<T, Container> &lhs, const stack<T, Container> &rhs) { return lhs.c <= rhs.c; };
			friend bool operator > (const stack<T, Container> &lhs, const stack<T, Container> &rhs) { return lhs.c > rhs.c; };
			friend bool operator >= (const stack<T, Container> &lhs, const stack<T, Container> &rhs) { return lhs.c >= rhs.c; };
	};
}

#endif
