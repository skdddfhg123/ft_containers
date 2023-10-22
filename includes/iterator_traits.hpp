#pragma once

#ifndef ITERATOR_TRAITS_HPP
# define ITERATOR_TRAITS_HPP

namespace	ft
{
	// Iterator_tag
	struct input_iterator_tag { };
	struct output_iterator_tag { };
	struct forward_iterator_tag : public input_iterator_tag, output_iterator_tag { };
	struct bidirectional_iterator_tag : public forward_iterator_tag { };
	struct random_access_iterator_tag : public bidirectional_iterator_tag { };
	// Iterator base class
	template <class Category,class T,class Distance = ptrdiff_t, class Pointer = T*,class Reference = T&>
		struct iterator {
		typedef T				value_type;
		typedef Distance		difference_type;
		typedef Pointer			pointer;
		typedef Reference		reference;
		typedef Category		iterator_category;
	};
	// Iterator_traits
	template <class iterator>
	struct iterator_traits {
		typedef typename iterator::difference_type		difference_type;
		typedef typename iterator::value_type			value_type;
		typedef typename iterator::pointer				pointer;
		typedef typename iterator::reference			reference;
		typedef typename iterator::iterator_category	iterator_category;
	};

	template <class T>
	struct iterator_traits<T*> {
		typedef ptrdiff_t						difference_type;
		typedef T								value_type;
		typedef T*								pointer;
		typedef T&								reference;
		typedef random_access_iterator_tag		iterator_category;
	};
}

#endif
