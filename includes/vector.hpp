#pragma once

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>

# include "iterator.hpp"
# include "iterator_traits.hpp"
# include "util.hpp"

namespace	ft
{
	template <typename T, class Alloc = std::allocator<T> >
	class	vector {
		public:
			typedef T													value_type;
			typedef Alloc												allocator_type;
			typedef typename allocator_type::reference					reference;
			typedef typename allocator_type::const_reference			const_reference;
			typedef typename allocator_type::pointer					pointer;
			typedef typename allocator_type::const_pointer				const_pointer;
			typedef random_access_iterator<value_type>					iterator;
			typedef random_access_iterator<const value_type>			const_iterator;
			typedef reverse_iterator<const_iterator>					const_reverse_iterator;
			typedef reverse_iterator<iterator>							reverse_iterator;
			typedef typename iterator_traits<iterator>::difference_type	difference_type;
			typedef typename allocator_type::size_type					size_type;
		
		private:
			allocator_type	_alloc;
			pointer			_start;
			size_type		_size;
			size_type		_capacity;

			template <class InputIterator>
			size_type getSize(InputIterator first, InputIterator last) {
				size_type len = 0;
				for (InputIterator i = first; i != last; i++)
					len++;
				return len;
			}
		
		public:
			// default constructor
			explicit vector(const allocator_type& alloc = allocator_type()) : _alloc( alloc ), _start(NULL), _size(0), _capacity(0) {};
			// fill constructor
			explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
			: _alloc(alloc), _start(NULL), _size(n), _capacity(n) {
				_start = _alloc.allocate(capacity());
				for (size_type i = 0; i < n; i++)
					_alloc.construct(_start + i, val);
			}
			// range constructor
			template <class InputIterator>
			vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
				typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL)
			: _alloc(alloc), _start(NULL), _size(0), _capacity(0) {
				_size = getSize<InputIterator>(first, last);
				_capacity = _size;
				_start = _alloc.allocate(capacity());
				for (size_type i = 0; i < _capacity; i++)
					_alloc.construct(_start + i, *(first++));
			};
			// copy constructor
			vector(const vector& x) : _alloc(x._alloc), _start(NULL), _size(x._size), _capacity(x._capacity) {
				if (x._start) {
					_start = _alloc.allocate(_capacity);
					for (size_type i = 0; i < _size; i++)
						_alloc.construct(_start + i, x._start[i]);
				}
			}
			// destructor
			~vector() {
				clear();
				_alloc.deallocate(_start, capacity());
			};
			// operator=
			vector &operator=(const vector &x) {
				if (&x == this)
					return (*this);
				clear();
				insert(end(), x.begin(), x.end());
				return (*this);
			}

			// Iterators
			// begin : Return iterator to beginning
			iterator				begin(void) { return iterator(_start); };
			const_iterator			begin(void) const { return const_iterator(_start); };
			// end : Return iterator to end
			iterator				end(void) { return iterator(_start + _size); };
			const_iterator			end(void) const { return const_iterator(_start + _size); };
			// rbegin : Return reverse iterator to reverse beginning
			reverse_iterator		rbegin(void) { return reverse_iterator(_start + _size); };
			const_reverse_iterator	rbegin(void) const { return const_reverse_iterator(_start + _size); };
			// rend : Return reverse iterator to reverse end 
			reverse_iterator		rend(void) { return reverse_iterator(_start); };
			const_reverse_iterator	rend(void) const { return const_reverse_iterator(_start); };

			// capacity function
			// size : Return size
			size_type	size() const { return _size; }
			// max_size : Return maximum size 
			size_type	max_size() const { return _alloc.max_size(); }
			// resize : Change size
			void		resize(size_type n, value_type val = value_type()) {
				if (n > max_size())
					throw (std::length_error("vector::resize"));
				else if (n < _size) {
					for (pointer i = _start + _size - 1; i >= _start + n; i--)
						_alloc.destroy(i);
					_size = n;
				}
				else
					insert(end(), n - _size, val);
			}
			// capacity : Return size of allocated storage capacity
			size_type	capacity() const { return _capacity; }
			// empty : Test whether vector is empty
			bool empty() const { return (!size()); }
			// reserve : Request a change in capacity
			void reserve(size_type n) {
				if (n > max_size())
					throw std::length_error("vector::reserve");
				else if (n > _size) {
					value_type *tmp = _alloc.allocate(n);
					for (size_type i = 0; i < _size; ++i) {
						_alloc.construct(&tmp[i], _start[i]);
						_alloc.destroy(&_start[i]);
					}
					_alloc.deallocate(_start, _capacity);
					_start = tmp;
					_capacity = n;
				}
			}

			// Element access function
			// operator[] : Access element
			reference		operator[](size_type n) { return *(_start + n); };
			const_reference	operator[](size_type n) const { return *(_start + n); };
			// at : Access element
			reference		at( size_type n ) {
				if (n > size())
					throw (std::out_of_range("out of range"));
				return *(_start + n);
			};
			const_reference	at( size_type n ) const {
				if (n > size())
					throw (std::out_of_range("out of range"));
				return *(_start + n);
			};
			// front : Access first element
			reference		front() { return *(_start); };
			const_reference	front() const { return *(_start); };
			// back : Access last element
			reference		back() { return *(_start + _size - 1); };
			const_reference	back() const { return *(_start + _size - 1); };

			// Modifiers function
			// assign : Assign vector content
			// range version
			template <class InputIterator>
			void			assign(InputIterator first, InputIterator last,
				typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL) {
				size_type diff = getSize<InputIterator>(first, last);
				if (diff > _capacity)
					reserve(diff);
				for (size_type i = 0; i < _size; i++)
					_alloc.destroy(_start + i);
				for (size_type i = 0; i < diff; i++)
					_alloc.construct(_start + i, *(first++));
				_size = diff;
			};
			//  fill version
			void			assign(size_type n, const value_type &val) {
				if (n > _capacity)
					reserve(n);
				for (size_type i = 0; i < _size; i++)
					_alloc.destroy(_start + i);
				for (size_type i = 0; i < n; i++)
					_alloc.construct(_start + i, val);
				_size = n;
			};
			// push_back: Add element at the end
			void	push_back(const value_type& value) {
				if (_capacity < _size + 1) {
					if (_size == 0)
						reserve(1);
					else
						reserve(_size * 2);
				}
				_alloc.construct(&_start[_size], value);
				_size++;
			};
			// pop_back : Delete last element
			void		pop_back() {
				_size -= 1;
				_alloc.destroy(_start + _size);
			};
			// insert : Insert elements 
			// single element
			iterator	insert(iterator position, const value_type &val) {
				difference_type	pos = position - begin();

				insert(position, 1, val);
				return iterator(begin() + pos);
			};
			// Fill
			void		insert(iterator position, size_type n, const value_type& val) {
				difference_type diff = &(*end()) - &(*position);
				if (_size + n > _capacity)
					reserve(size() + n);
				for (pointer i = _start + _size - 1; i >= _start + _size - diff; i--) {
					_alloc.construct(i + n, *i);
					_alloc.destroy(i);
				}
				for (size_type i = 0; i < n; i++)
					_alloc.construct(_start + _size - diff + i, val);
				_size += n;
			}
			// range
			template <class InputIterator>
			void insert(iterator position, InputIterator first, InputIterator last,
					typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL) {
				difference_type n = getSize<InputIterator>(first, last);
				difference_type diff = &(*end()) - &(*position);
				if (_size + n > _capacity)
					reserve(size() + n);
				for (pointer i = _start + _size - 1; i >= _start + _size - diff; i--) {
					_alloc.construct(i + n, *i);
					_alloc.destroy(i);
				}
				for (int i = 0; i < n; i++)
					_alloc.construct(_start + _size - diff + i, *(first++));
				_size += n;
			}
			// erase : Erase elements
			iterator	erase(iterator position) {
				pointer p_pos = &(*position);
				_alloc.destroy(p_pos);
				for (pointer i = p_pos; i < _start + _size - 1; i++) {
					_alloc.construct(i, *(i + 1));
					_alloc.destroy(i + 1);
				}
				_size -= 1;
				return iterator(p_pos);
			}

			iterator	erase(iterator first, iterator last) {
				pointer p_first = &(*first);
				pointer p_last = &(*last);
				for (pointer i = p_first; i != p_last; i++)
					_alloc.destroy(i);
				for (int i = 0; i < &*end() - p_last; i++) {
					_alloc.construct(p_first + i, *(p_last + i));
					_alloc.destroy(p_last + i);
				}
				_size -= p_last - p_first;
				return iterator(p_first);
			}
			// swap : Swap content
			void swap(vector &x) {
				std::swap(_start, x._start);
				std::swap(_size, x._size);
				std::swap(_capacity, x._capacity);
				std::swap(_alloc, x._alloc);
			}
			// clear : 	Clear content
			void	clear(void) {
				for (size_type i=0; i < this->_size; i++)
					_alloc.destroy(_start + i);
				this->_size = 0;
			};

			// Allocator
			allocator_type	get_allocator() const { return _alloc; };
	};
	template <typename T, typename Alloc>
	bool operator==( const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs ) { return ( lhs.size() == rhs.size() && ft::equal( lhs.begin(), lhs.end(), rhs.begin() ) ); }
	template <typename T, typename Alloc>
	bool operator!=( const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs ) { return ( !( lhs == rhs ) ); }
	template <typename T, typename Alloc>
	bool operator<( const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs ) { return ( ft::lexicographical_compare( lhs.begin(), lhs.end(), rhs.begin(), rhs.end() ) ); }
	template <typename T, typename Alloc>
	bool operator<=( const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs ) { return ( !( rhs < lhs ) ); }
	template <typename T, typename Alloc>
	bool operator>( const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs ) { return ( rhs < lhs ); }
	template <typename T, typename Alloc>
	bool operator>=( const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs ) { return ( !( lhs < rhs ) ); }
}

#endif
