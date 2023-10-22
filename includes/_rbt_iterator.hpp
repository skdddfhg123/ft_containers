#pragma once

#ifndef _RBT_ITERATOR_HPP
# define _RBT_ITERATOR_HPP

# include "_rbt_node.hpp"
# include "iterator_traits.hpp"

namespace	ft
{
	template <typename T>
		struct rbt_iterator : ft::iterator<bidirectional_iterator_tag, T>
		{
			public:
				typedef typename iterator<bidirectional_iterator_tag, T>::iterator_category		iterator_category;
				typedef typename iterator<bidirectional_iterator_tag, T>::value_type			value_type;
				typedef typename iterator<bidirectional_iterator_tag, T>::difference_type		difference_type;
				typedef typename iterator<bidirectional_iterator_tag, T>::pointer				pointer;
				typedef typename iterator<bidirectional_iterator_tag, T>::reference				reference;
				typedef RBT_Node<value_type>													*node_ptr;
				typedef RBT_Node<const value_type>												*const_node_ptr;

				rbt_iterator(void) : NIL(nullptr), _root_Node(nullptr), _cur_Node(nullptr) {};
				rbt_iterator(node_ptr NIL, node_ptr root, node_ptr node) : NIL(NIL), _root_Node(root), _cur_Node(node) {};
				operator rbt_iterator<const T>() const { return (rbt_iterator<const T>((const_node_ptr)&*NIL, (const_node_ptr)&* this->_root_Node, (const_node_ptr)&*this->_cur_Node)); };
				~rbt_iterator() {}
				rbt_iterator	&operator=(rbt_iterator const &ref) {
					_cur_Node = ref._cur_Node;
					_root_Node = ref._root_Node;
					NIL = ref.NIL;
					return *this;
				};
				bool		operator==(const rbt_iterator &ref) { return this->_cur_Node == ref._cur_Node; };
				bool		operator!=(const rbt_iterator &ref) { return this->_cur_Node != ref._cur_Node; };

				reference operator*() const { return _cur_Node->value; }
				pointer operator->() const { return (&this->_cur_Node->value); }
				node_ptr base() const { return _cur_Node; }

				rbt_iterator &operator++() {
					if (_cur_Node != NIL) 
						_cur_Node = find_next(_cur_Node);
					return *this;
				}
				rbt_iterator operator++(int) {
					rbt_iterator tmp(*this);
					++(*this);
					return tmp;
				}
				rbt_iterator &operator--() {
					if (_cur_Node != NIL) 
						_cur_Node = find_back(_cur_Node);
					else {
						_cur_Node = _root_Node;
						while (_cur_Node->right != NIL)
							_cur_Node = _cur_Node->right;
					}
					return *this;
				}
				rbt_iterator operator--(int) {
					rbt_iterator tmp(*this);
					--(*this);
					return tmp;
				}

			private:
				node_ptr	NIL;
				node_ptr	_root_Node;
				node_ptr	_cur_Node;

				node_ptr	find_back(node_ptr target) {
					if (target->left != NIL) {
						target = target->left;
						while (target->right != NIL)
							target = target->right;
						return (target);
					}
					while (target->parent != NIL && target->parent->left == target) target = target->parent;
					return target->parent;
				}

				node_ptr	find_next(node_ptr target) {
					if (target->right != NIL) {
						target = target->right;
						while (target->left != NIL) target = target->left;
							return (target);
					}
					while (target != NIL && target->parent->right == target) target = target->parent;
						return target->parent;
				}
		};
}

#endif
