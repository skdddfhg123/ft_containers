#pragma once

#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include "iterator_traits.hpp"

namespace	ft
{
	template <typename T>
	struct random_access_iterator : ft::iterator<random_access_iterator_tag, T>
	{
		public:
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::difference_type		difference_type;
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::value_type			value_type;
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::pointer				pointer;
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::reference				reference;
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::iterator_category		iterator_category;

		private:
			pointer	_ptr;

		public:
			//  default-constructible, copy-constructible, copy-assignable and destructible
			random_access_iterator() : _ptr() { };
			random_access_iterator(pointer ptr) : _ptr(ptr) { };
			random_access_iterator( const random_access_iterator& other ) : _ptr( other.base() ) {}
			operator random_access_iterator<const T>() const { return _ptr; };
			random_access_iterator	&operator=(random_access_iterator<T> const &ref) {
				_ptr = &*ref;
				return (*this);
			};
			~random_access_iterator() { };

			// base : Return a copy of the base iterator
			pointer		base() const { return _ptr; }

			reference 	operator*() const {	return *_ptr; }
			pointer		operator->(void) const { return _ptr; };
			reference	operator[](difference_type n) const { return *(_ptr + n); };

			random_access_iterator	&operator++() { ++_ptr; return *this; };
			random_access_iterator	operator++(int) { random_access_iterator tmp(*this); ++_ptr; return tmp; };
			random_access_iterator	&operator--() { --_ptr; return *this; };
			random_access_iterator	operator--(int) { random_access_iterator tmp = _ptr; --_ptr; return tmp; }
			random_access_iterator	&operator+=(difference_type n) { _ptr += n; return *this; };
			random_access_iterator	&operator-=(difference_type n) { _ptr -= n; return *this; };
			random_access_iterator	operator+(difference_type n) { return random_access_iterator(_ptr + n); };
			random_access_iterator	operator-(difference_type n) { return random_access_iterator(_ptr - n); };

	};
	// random_access_iterator non-member function
	template <typename T1, typename T2>
	bool operator== (const random_access_iterator<T1>& lhs, const random_access_iterator<T2>& rhs) { return lhs.base() == rhs.base(); };
	template <typename T1, typename T2>
	bool operator!= (const random_access_iterator<T1>& lhs, const random_access_iterator<T2>& rhs) { return lhs.base() != rhs.base(); };
	template <typename T1, typename T2>
	bool operator< (const random_access_iterator<T1>& lhs, const random_access_iterator<T2>& rhs) { return lhs.base() < rhs.base(); };
	template <typename T1, typename T2>
	bool operator<= (const random_access_iterator<T1>& lhs, const random_access_iterator<T2>& rhs) { return lhs.base() <= rhs.base(); };
	template <typename T1, typename T2>
	bool operator> (const random_access_iterator<T1>& lhs, const random_access_iterator<T2>& rhs) { return lhs.base() > rhs.base(); };
	template <typename T1, typename T2>
	bool operator>= (const random_access_iterator<T1>& lhs, const random_access_iterator<T2>& rhs) { return lhs.base() >= rhs.base(); };
	
	template <typename T1, typename T2>
	typename random_access_iterator<T1>::difference_type operator- (const random_access_iterator<T1>& lhs,	const random_access_iterator<T2>& rhs)
		{ return lhs.base() - rhs.base(); };
	template <typename T>
	random_access_iterator<T> operator+ (typename random_access_iterator<T>::difference_type n, const random_access_iterator<T>& ref)
		{ return ref.base() + n; };


	template <typename Iterator>
	class reverse_iterator
	{
		public:
			typedef typename iterator_traits<Iterator>::difference_type		difference_type;
			typedef typename iterator_traits<Iterator>::value_type			value_type;
			typedef typename iterator_traits<Iterator>::pointer				pointer;
			typedef typename iterator_traits<Iterator>::reference			reference;
			typedef typename iterator_traits<Iterator>::iterator_category	iterator_category;

		private:
			Iterator	_current;

		public:
			//  default-constructible, copy-constructible, copy-assignable and destructible
			reverse_iterator() : _current() { };
			reverse_iterator(const Iterator &it): _current(it) {};
			template <class Iter>
			reverse_iterator (const reverse_iterator<Iter>& other) : _current(other.base()) {};
			template <class Iter>
			reverse_iterator& operator=( const reverse_iterator<Iter>& ref ) { _current = ref.base(); return *this; };
			~reverse_iterator() { };

			// base : Returns a copy of the base iterator
			Iterator	base() const { return _current; };

			reference	operator*() const { Iterator tmp = _current; return *(--tmp); };
			reverse_iterator	operator+(difference_type n) { return reverse_iterator(_current - n); };
			reverse_iterator	&operator+=(difference_type n) { _current -= n; return *this; };
			reverse_iterator	&operator++() { --_current; return *this; };
			reverse_iterator	operator++(int) { reverse_iterator	tmp(*this); --_current; return tmp; };
			reverse_iterator	operator-(difference_type n) { return reverse_iterator(_current + n); };
			reverse_iterator	&operator-=(difference_type n) { _current += n; return *this; };
			reverse_iterator	&operator--() { ++_current; return *this; };
			reverse_iterator	operator--(int) { reverse_iterator	tmp(*this); ++_current; return tmp; };
			pointer				operator->(void) const { return &(operator*()); };
			reference			operator[](difference_type n) const { return _current[-n-1]; };
	};
	// reverse_iterator non-member function
	template<class Iter1, class Iter2>
	bool operator== (const reverse_iterator<Iter1>& lhs, const reverse_iterator<Iter2>& rhs)	{ return lhs.base() == rhs.base(); };
	template<class Iter1, class Iter2>
	bool operator!= (const reverse_iterator<Iter1>& lhs, const reverse_iterator<Iter2>& rhs)	{ return lhs.base() != rhs.base(); };
	template<class Iter1, class Iter2>
	bool operator< (const reverse_iterator<Iter1>& lhs, const reverse_iterator<Iter2>& rhs)		{ return lhs.base() > rhs.base(); };
	template<class Iter1, class Iter2>
	bool operator<= (const reverse_iterator<Iter1>& lhs, const reverse_iterator<Iter2>& rhs)	{ return lhs.base() >= rhs.base(); };
	template<class Iter1, class Iter2>
	bool operator> (const reverse_iterator<Iter1>& lhs, const reverse_iterator<Iter2>& rhs)		{ return lhs.base() < rhs.base(); };
	template<class Iter1, class Iter2>
	bool operator>= (const reverse_iterator<Iter1>& lhs, const reverse_iterator<Iter2>& rhs)	{ return lhs.base() <= rhs.base(); };

	template<class Iter>
	reverse_iterator<Iter> operator+ (typename reverse_iterator<Iter>::difference_type n, const reverse_iterator<Iter>& ref)
		{ return reverse_iterator<Iter>(ref.base() - n); };
	template<class Iter>
	typename reverse_iterator<random_access_iterator<Iter> >::difference_type operator- (const reverse_iterator<random_access_iterator<Iter> >& lhs,	const reverse_iterator<random_access_iterator<Iter> >& rhs)
		{ return lhs.base() - rhs.base(); };
	template<class Iter>
	typename reverse_iterator<random_access_iterator<Iter> >::difference_type operator- (const reverse_iterator<random_access_iterator<const Iter> >& lhs,	const reverse_iterator<random_access_iterator<Iter> >& rhs)
		{ return rhs.base() - lhs.base(); };
}

#endif
