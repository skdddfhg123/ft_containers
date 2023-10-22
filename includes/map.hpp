#pragma once

#ifndef MAP_HPP
# define MAP_HPP

# include <stdlib.h>
# include <memory>
# include "_rbt.hpp"
# include "util.hpp"

namespace	ft
{
	template < class Key, class T, class Compare = less<Key>, class Alloc = std::allocator<pair<Key,T> > >
	class	map {
		public:
			class value_compare;
			typedef Key																	key_type;
			typedef T																	mapped_type;
			typedef pair<const key_type,mapped_type>									value_type;
			typedef Compare																key_compare;
			typedef Alloc																allocator_type;
			typedef typename allocator_type::reference									reference;
			typedef typename allocator_type::const_reference							const_reference;
			typedef typename allocator_type::pointer									pointer;
			typedef typename allocator_type::const_pointer								const_pointer;
			typedef typename RBT<value_type, value_compare>::iterator					iterator;
			typedef typename RBT<value_type, value_compare>::const_iterator				const_iterator;
			typedef reverse_iterator<const_iterator>									const_reverse_iterator;
			typedef reverse_iterator<iterator>											reverse_iterator;
			typedef typename allocator_type::size_type									size_type;

			class value_compare : public std::binary_function<value_type, value_type, bool>{
				friend class map;
				protected:
				Compare comp;
				value_compare(Compare const& c) : comp(c) {}
			public:
				typedef bool result_type;
				typedef value_type first_argument_type;
				typedef value_type second_argument_type;
				bool operator()(const value_type& x, const value_type& y) const{
					return comp(x.first, y.first);
				}
			};

		private:
			allocator_type						_alloc;
			key_compare							_comp;
			RBT<value_type, value_compare>		_tree;

		public:
			//	Member functions
			//	constrcutor
			explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _alloc(alloc) , _comp(comp),  _tree(value_compare(_comp), _alloc) { }
			template<typename InputIterator>
			map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
			: _alloc(alloc), _comp(comp), _tree(value_compare(_comp), _alloc) { insert(first, last); }
			map (const map &x) : _alloc(x._alloc), _comp(x._comp), _tree(x._tree){}
			// deconstructor
			~map() {};
			// operator=
			map& operator=(const map& x) {
				_alloc = x._alloc;
				_comp = x._comp;
				_tree = x._tree;
				return (*this);
			}

			// Iterators
			iterator				begin(void) { return _tree.begin(); };
			const_iterator			begin(void) const { return _tree.begin(); };
			iterator				end(void) { return _tree.end(); };
			const_iterator			end(void) const { return _tree.end(); };
			reverse_iterator		rbegin(void) { return _tree.rbegin(); };
			const_reverse_iterator	rbegin(void) const { return _tree.rbegin(); };
			reverse_iterator		rend(void) { return _tree.rend(); };
			const_reverse_iterator	rend(void) const { return _tree.rend(); };

			// Capacity
			bool			empty(void) const	{ return _tree.empty(); };
			size_type		size(void) const	{ return _tree.size(); };
			size_type		max_size(void) const	{ return _tree.max_size(); };

			// Element access:
			// operator[]
			mapped_type&	operator[](const key_type& k) { return (*(insert(ft::make_pair(k, mapped_type())).first)).second; };

			// Modifiers
			// insert
			pair<iterator,bool>	insert(const value_type& val) { return _tree.insert1(val); };
			iterator			insert(iterator position, const value_type& val) { return _tree.insert2(position, val); };
			template <class InputIterator>
			void				insert(InputIterator first, InputIterator last) {
				for (InputIterator i = first; i != last; i++)
					_tree.insert1(*i);
			};
			// erase
			void				erase(iterator position) { _tree.erase(position); };
			size_type			erase(const key_type& k) { 
				iterator result = find(k);
				if (result != _tree.end())
					return _tree.erase(find(k));
				return (0);
			};
			void				erase(iterator first, iterator last) {
				iterator i = first;
				while (i != last) _tree.erase(i++);
			};
			void				swap(map &x) {
				_tree.swap(x._tree);
				std::swap(_comp, x._comp);
				std::swap(_alloc, x._alloc);
			};
			void		clear() { _tree.clear(); };

			// observers
			key_compare		key_comp() const					{ return key_compare(); };
			value_compare	value_comp() const					{ return value_compare(key_compare()); };

			// operations
			iterator		find(const key_type &k)				{ return _tree.find(ft::make_pair(k, mapped_type())); };
			const_iterator	find(const key_type &k) const		{ return _tree.find(ft::make_pair(k, mapped_type())); };
			size_type		count(const key_type &k) const		{ 
				const_iterator lower = lower_bound(k);
				const_iterator upper = upper_bound(k);
				size_type i = 0;
				while (lower++ != upper) i++;
				return i;
			};
			iterator		lower_bound(const key_type &k)		{ return (_tree.lower_bound(ft::make_pair(k, mapped_type()))); };
			const_iterator	lower_bound(const key_type &k) const	{ return (_tree.lower_bound(ft::make_pair(k, mapped_type()))); };
			iterator		upper_bound(const key_type &k)		{ return (_tree.upper_bound(ft::make_pair(k, mapped_type()))); };
			const_iterator	upper_bound(const key_type &k) const	{ return (_tree.upper_bound(ft::make_pair(k, mapped_type()))); };
			pair<iterator, iterator>				equal_range(const key_type &k)
			{ return (pair<iterator, iterator>(lower_bound(k), upper_bound(k))); }
			pair<const_iterator, const_iterator>	equal_range(const key_type &k) const
			{ return (pair<const_iterator, const_iterator>(lower_bound(k), upper_bound(k))); }
			// Allocator
			Alloc		get_allocator() const { return allocator_type(); };

	};
	template <class Key, class T, class Compare, class Alloc>
	bool operator==(const map<Key, T, Compare, Alloc>& x, const map<Key, T, Compare, Alloc>& y) {
		if (x.size() != y.size())
			return false;
		return ft::equal(x.begin(), x.end(), y.begin());
	}
	template <class Key, class T, class Compare, class Alloc>
	bool operator!=(const map<Key, T, Compare, Alloc>& x, const map<Key, T, Compare, Alloc>& y) { return !(x == y); }
	template <class Key, class T, class Compare, class Alloc>
	bool operator<(const map<Key, T, Compare, Alloc>& x, const map<Key, T, Compare, Alloc>& y) { return ft::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end()); }
	template <class Key, class T, class Compare, class Alloc>
	bool operator<=(const map<Key, T, Compare, Alloc>& x, const map<Key, T, Compare, Alloc>& y) { return !(y < x); }
	template <class Key, class T, class Compare, class Alloc>
	bool operator>(const map<Key, T, Compare, Alloc>& x, const map<Key, T, Compare, Alloc>& y) { return y < x; }
	template <class Key, class T, class Compare, class Alloc>
	bool operator>=(const map<Key, T, Compare, Alloc>& x, const map<Key, T, Compare, Alloc>& y) { return !(x < y); }
	template <class Key, class T, class Compare, class Alloc>
	void swap(map<Key, T, Compare, Alloc>& x, map<Key, T, Compare, Alloc>& y) { x.swap(y); }
}

#endif
