#pragma once

#ifndef SET_HPP
# define SET_HPP

# include <stdlib.h>
# include <memory>
# include "_rbt.hpp"
# include "util.hpp"

namespace	ft
{
	template < class T, class Compare = less<T>, class Alloc = std::allocator<T> >
	class	set {
		public:
			typedef const T																key_type;
			typedef const T																value_type;
			typedef Compare																key_compare;
			typedef Compare																value_compare;
			typedef Alloc																allocator_type;
			typedef typename allocator_type::reference									reference;
			typedef typename allocator_type::const_reference							const_reference;
			typedef typename allocator_type::pointer									pointer;
			typedef typename allocator_type::const_pointer								const_pointer;
			typedef typename RBT<const value_type, key_compare>::iterator				iterator;
			typedef typename RBT<const value_type, key_compare>::const_iterator			const_iterator;
			typedef reverse_iterator<const_iterator>									const_reverse_iterator;
			typedef reverse_iterator<iterator>											reverse_iterator;
			typedef typename allocator_type::size_type									size_type;

		private:
			allocator_type								_alloc;
			key_compare									_key_comp;
			RBT<value_type, key_compare>				_tree;

		public:
			//	Member functions
			//	constrcutor
			explicit set (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _alloc(alloc), _key_comp(comp), _tree() { };
			template <class InputIterator>
			set (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _alloc(alloc), _key_comp(comp), _tree() { insert(first, last); }
			set (const set &x) : _alloc(x._alloc), _key_comp(x._key_comp), _tree(x._tree) { };
			// deconstructor
			~set() {};
			// operator=
			set& operator=(const set& x) {
				_alloc = x._alloc;
				_key_comp = x._key_comp;
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
			size_type		size(void) const	{ return (_tree.size()); };
			size_type		max_size(void) const	{ return (_tree.max_size()); };
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
			size_type			erase(const value_type& k) {
				iterator result = find(k);
				if (result != _tree.end())
					return _tree.erase(find(k));
				return (0);
			};
			void				erase(iterator first, iterator last) {
				iterator i = first;
				while (i != last) _tree.erase(i++);
			};
			void				swap(set &x) {
				_tree.swap(x._tree);
				std::swap(_key_comp, x._key_comp);
				std::swap(_alloc, x._alloc);
			};
			void		clear(void) { _tree.clear(); };
			// observers
			value_compare	value_comp(void) const					{ return (_key_comp); };
			key_compare		key_comp(void) const					{ return (_key_comp); };
			// operations
			iterator		find(const value_type &k)				{ return (_tree.find(k)); };
			const_iterator	find(const value_type &k) const			{ return (_tree.find(k)); };
			size_type		count(const value_type &k) const {
				const_iterator lower = lower_bound(k);
				const_iterator upper = upper_bound(k);
				size_type i = 0;
				while (lower++ != upper) i++;
				return i;
			};
			iterator		lower_bound(const value_type &k)		{ return (_tree.lower_bound(k)); };
			const_iterator	lower_bound(const value_type &k) const	{ return (_tree.lower_bound(k)); };
			iterator		upper_bound(const value_type &k)		{ return (_tree.upper_bound(k)); };
			const_iterator	upper_bound(const value_type &k) const	{ return (_tree.upper_bound(k)); };
			pair<iterator, iterator>				equal_range(const value_type &k)
			{ return (pair<iterator, iterator>(lower_bound(k), upper_bound(k))); }
			pair<const_iterator, const_iterator>	equal_range(const value_type &k) const
			{ return (pair<const_iterator, const_iterator>(lower_bound(k), upper_bound(k))); }
			// Allocator
			Alloc		get_allocator() const { return _alloc; };
	};
	template<class T, class Compare, class Allocator>
	bool operator==(const set<T, Compare, Allocator> &x, const set<T, Compare, Allocator> &y) {
		if (x.size() != y.size())
			return false;
		return ft::equal(x.begin(), x.end(), y.begin());
	}
	template<class T, class Compare, class Allocator>
	bool operator!=(const set<T, Compare, Allocator> &x, const set<T, Compare, Allocator> &y) { return (!(y == x)); }
	template<class T, class Compare, class Allocator>
	bool operator<(const set<T, Compare, Allocator> &x, const set<T, Compare, Allocator> &y) { return (ft::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end())); }
	template<class T, class Compare, class Allocator>
	bool operator<=(const set<T, Compare, Allocator> &x, const set<T, Compare, Allocator> &y) { return (!(y < x)); }
	template<class T, class Compare, class Allocator>
	bool operator>(const set<T, Compare, Allocator> &x, const set<T, Compare, Allocator> &y) { return (y < x); }
	template<class T, class Compare, class Allocator>
	bool operator>=(const set<T, Compare, Allocator> &x, const set<T, Compare, Allocator> &y) { return (!(x < y)); }
}

#endif
