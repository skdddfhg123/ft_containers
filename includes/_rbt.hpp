#pragma once

#ifndef _RBT_HPP
# define _RBT_HPP

# include "iterator.hpp"
# include "_rbt_node.hpp"
# include "_rbt_iterator.hpp"
# include "util.hpp"

namespace ft
{
	template < class T, class Compare, class Alloc = std::allocator<RBT_Node<T> > >
	class RBT {
		public:
			typedef T																	value_type;
			typedef Alloc																allocator_type;
			typedef Compare																value_compare;
			typedef RBT_Node<value_type>												*node_ptr;
			typedef RBT_Node<const value_type>											*const_node_ptr;
			typedef typename allocator_type::size_type									size_type;
			typedef typename allocator_type::reference									reference;
			typedef typename allocator_type::const_reference							const_reference;
			typedef typename allocator_type::pointer									pointer;
			typedef typename allocator_type::const_pointer								const_pointer;
			typedef rbt_iterator<value_type>											iterator;
			typedef rbt_iterator<const value_type>										const_iterator;
			typedef reverse_iterator<const_iterator>									const_reverse_iterator;
			typedef reverse_iterator<iterator>											reverse_iterator;
			typedef typename iterator_traits<iterator>::difference_type					difference_type;
		private:
			node_ptr							NIL;
			node_ptr							_root_Node;
			allocator_type						_alloc;
			value_compare						_comp;
			size_type							_size;

			node_ptr	new_Node(const T& value) {
				_size += 1;
				node_ptr new_node = _alloc.allocate(1);
				_alloc.construct(new_node, value);
				new_node->parent = NIL;
				new_node->right = NIL;
				new_node->left = NIL;
				return new_node;
			}

			node_ptr	first(void) const {
				node_ptr _first = _root_Node;
				if (_first == NIL) return NIL;
				while (_first->left != NIL) _first = _first->left;
				return _first;
			}

			node_ptr	find_left(node_ptr target) {
				if (target->left) {
					target = target->left;
					while (target->right != NIL)
						target = target->right;
					return (target);
				}
				while (target->parent != NIL && target->parent->left == target) 
					target = target->parent;
				return target->parent;
			}

			node_ptr	find_right(node_ptr target) {
				if (target->right) {
					target = target->right;
					while (target->left != NIL) target = target->left;
					return (target);
				}
				while (target->parent != NIL && target->parent->right == target)
					target = target->parent;
				return target->parent;
			}

			void	rotate_left(node_ptr target) {
				node_ptr right_node = target->right;
				target->right = right_node->left;
				if (right_node->left != NIL)
					right_node->left->parent = target;
				right_node->parent = target->parent;
				if (target->parent == NIL) 
					_root_Node = right_node;
				else {
					if (target == (target->parent)->left)
						target->parent->left = right_node;
					else
						target->parent->right = right_node;
				}
				right_node->left = target;
				target->parent = right_node;
			}

			void	rotate_right (node_ptr target) {
				node_ptr left_node = target->left;
				target->left = left_node->right;
				if (left_node->right != NIL)
					left_node->right->parent = target;
				left_node->parent = target->parent;
				if (target->parent == NIL)
					_root_Node = left_node;
				else
					if (target == (target->parent)->right)
						target->parent->right = left_node;
					else
						target->parent->left = left_node;
				left_node->right = target;
				target->parent = left_node;
			}


			pair<iterator, bool>	insert_recur(node_ptr current, const T&  value) {
				if (current->value == value) 
					return pair<iterator, bool>(iterator(NIL, _root_Node, current), false);
				if (_comp(current->value, value)) {
					if (current->right != NIL)
						return insert_recur(current->right, value);
					current->right = new_Node(value);
					current->right->parent = current;
					return pair<iterator, bool>(iterator(NIL, _root_Node, current->right), true);
				} else {
					if (current->left != NIL) 
						return insert_recur(current->left, value);
					current->left = new_Node(value);
					current->left->parent = current;
					return pair<iterator, bool>(iterator(NIL, _root_Node, current->left), true);
				}
			};

			void	erase_recur(node_ptr current) {
				if (current->left != NIL) erase_recur(current->left);
				if (current->right != NIL) erase_recur(current->right);
				_alloc.destroy(current);
				_alloc.deallocate(current, 1);
			};

			void	copy_recur(node_ptr current, node_ptr ref_NIL) {
				if (current == ref_NIL) 
					return ;
				insert1(current->value);
				if (current->left != NIL) copy_recur(current->left, ref_NIL);
				if (current->right != NIL) copy_recur(current->right, ref_NIL);
			};

			void		connect_pointer(node_ptr x, node_ptr y) {
				if (x->parent == NIL) _root_Node = y;
				else if (x == x->parent->left) x->parent->left = y;
				else x->parent->right = y;
				if (y != NIL) y->parent = x->parent;
			}

			void		display(node_ptr x) {
				if (x == _root_Node) {
					std::cout << "size : " << _size<< std::endl;
					std::cout << std::endl << "Display :" << std::endl;
				}
				if (x->left != NIL) display(x->left);
				std::cout << "- " << x->value.first << " " << x->value.second << " " << x->color << std::endl;
				if (x->right != NIL) display(x->right);
			}

			void Insert_fixup(node_ptr target) {
				// while의 안걸리면 case 2
				while (target->parent && target->parent->color == RED) {
					node_ptr	grandpa = target->parent->parent;
					if (target->parent == grandpa->right) {
						node_ptr	uncle = grandpa->left;
						if (uncle->color == RED) {
							uncle->color = BLACK;
							target->parent->color = BLACK;
							grandpa->color = RED;
							target = grandpa;
						} else {
							// case 4
							if (target == target->parent->left) {
								target = target->parent;
								rotate_right(target);
							}
							// case 5
							target->parent->color = BLACK;
							grandpa->color = RED;
							rotate_left(grandpa);
						}
					} else {
						node_ptr	uncle = grandpa->right;
						if (uncle->color == RED) {
							uncle->color = BLACK;
							target->parent->color = BLACK;
							grandpa->color = RED;
							target = grandpa;
						} else {
							// case 4
							if (target == target->parent->right) {
								target = target->parent;
								rotate_left(target);
							}
							// case 5
							target->parent->color = BLACK;
							grandpa->color = RED;
							rotate_right(grandpa);
						}
					}
				}
				_root_Node->color = BLACK;
			}

			void Erase_Fixup (node_ptr n) {
				if (n == NIL)
					return;
				node_ptr p = n->parent;
				while (n != _root_Node && (n->color == BLACK)) {
					if (n == p->left) {
						node_ptr s = p->right;
						//case 2
						if (s->color == RED) { 
							s->color = BLACK;
							p->color = RED;
							rotate_left(p);
						}
						// case 3, 4
						if ((s->left->color == BLACK) && 
						(s->right->color == BLACK)) { 
							s->color = RED;
							n = p;
							p = p->parent;
						}
						else {
							// case 5
							if (s->right->color == BLACK) { 
								s->left->color = BLACK;
								s->color = RED;
								rotate_right(s);
								s = p->right;
							}
							// case 6
							s->color = p->color; 
							p->color = BLACK;
							s->right->color = BLACK;
							rotate_left(p);
							break;
						}
					} else {
						node_ptr s = p->left;
						if (s->color == RED) {
							s->color = BLACK;
							p->color = RED;
							rotate_right(p);
						}
						if ((s->right->color == BLACK) && (s->left->color == BLACK)) {
							s->color = RED;
							n = p;
							p = p->parent;
						}
						else {
							if (s->left->color == BLACK) {
								s->right->color = BLACK;
								s->color = RED;
								rotate_left(s);
								s = p->left;
							}
							s->color = p->color;
							p->color = BLACK;
							s->left->color = BLACK;
							rotate_right(p);
							break ;
						}
					}
				}
				if (n == NIL)
					n->color = BLACK;
			}

		public:
			explicit RBT (const value_compare& comp = value_compare(), const allocator_type& alloc = allocator_type())
			: _root_Node(nullptr), _alloc(alloc), _comp(comp), _size(-1) {
				NIL = new_Node(T());
				NIL->color = BLACK;
				_root_Node = NIL;
			};

			RBT (const RBT &ref) : _root_Node(nullptr), _alloc(allocator_type()), _comp(ref._comp), _size(-1) {
				NIL = new_Node(T());
				NIL->color = BLACK;
				_root_Node = NIL;
				copy_recur(ref._root_Node, ref.NIL);
			};

			RBT& operator=(const RBT &ref) {
				clear();
				copy_recur(ref._root_Node, ref.NIL);
				return (*this);
			}

			~RBT() {
				if (_root_Node != NIL)
					erase_recur(_root_Node);
				_alloc.destroy(NIL);
				_alloc.deallocate(NIL, 1);
			};

			void	clear() {
				if (_root_Node != NIL)
					erase_recur(_root_Node);
				_root_Node = NIL;
				_size = 0;
			};

			pair<iterator, bool>	insert1(const T& value) {
				// case 1
				if (_root_Node == NIL) {
					_root_Node = new_Node(value);
					_root_Node->color = BLACK;
					return pair<iterator, bool>(begin(), true);
				}
				pair<iterator, bool> result = insert_recur(_root_Node, value);
				if (result.second == true)
					Insert_fixup(result.first.base());
				return result;
			};

			iterator	insert2(iterator position, const T& value) {
				(void)position;
				return insert1(value).first;
			};

			size_type	erase(iterator position_iter) {
				node_ptr position = position_iter.base();
				if (position == NIL)
					return 0;
				node_ptr n;
				if (position->left == NIL && position->right == NIL) {
					if (position == _root_Node)
						_root_Node = NIL;
					else if (position->parent->right == position)
						position->parent->right = NIL;
					else
						position->parent->left = NIL;
					n = NIL;
				} else if (position->left == NIL) {
					n = position->right;
					connect_pointer(position, position->right);
				} else if (position->right == NIL) {
					n = position->left;
					connect_pointer(position, position->left);
				} else {
					position_iter++;
					node_ptr next = position_iter.base();
					n = next->right;
					next->color = position->color;
					connect_pointer(next, next->right);
					connect_pointer(position, next);
					next->right = position->right;
					next->left = position->left;
					next->right->parent = next;
					next->left->parent = next;
				}
				if (position->color == BLACK)
					Erase_Fixup(n);
				_alloc.destroy(position);
				_alloc.deallocate(position, 1);
				_size--;
				// display(_root_Node);
				return 1;
			}

			void swap(RBT &ref) {
				node_ptr tmp;
				tmp = NIL; NIL = ref.NIL; ref.NIL = tmp;
				tmp = _root_Node; _root_Node = ref._root_Node; ref._root_Node = tmp;
				size_type tmp_size;
				tmp_size = _size; _size = ref._size; ref._size = tmp_size;
			}

			bool					empty(void) const { return (_root_Node == NIL); };
			size_type				size(void) const	{ return _size; };
			size_type				max_size(void) const	{ return _alloc.max_size(); };

			iterator				begin(void) { return iterator(NIL, _root_Node, first()); };
			const_iterator			begin(void) const { return const_iterator((const_node_ptr)&*NIL, (const_node_ptr)&*_root_Node, (const_node_ptr)&*first()); };
			iterator				end(void) { return iterator(NIL, _root_Node, NIL); };
			const_iterator			end(void) const { return const_iterator((const_node_ptr)&*NIL, (const_node_ptr)&*_root_Node, (const_node_ptr)&*NIL); };
			reverse_iterator		rbegin(void) { return reverse_iterator(end());	};
			const_reverse_iterator	rbegin(void) const { return const_reverse_iterator(end()); };
			reverse_iterator		rend(void) { return reverse_iterator(begin());	};
			const_reverse_iterator	rend(void) const { return const_reverse_iterator(begin()); };


			iterator		find(const T& value) {
				node_ptr cur = _root_Node;
				while(cur != NIL) {
					if (_comp(value, cur->value)) {
						cur = cur->left;
					} else if (_comp(cur->value, value)) {
						cur = cur->right;
					} else return iterator(NIL, _root_Node, cur);
				}
				return iterator(NIL, _root_Node, NIL);
			};
			const_iterator	find(const T& value) const {
				node_ptr cur = _root_Node;
				while(cur != NIL) {
					if (_comp(value, cur->value)) {
						cur = cur->left;
					} else if (_comp(cur->value, value)) {
						cur = cur->right;
					} else return const_iterator((const_node_ptr)&*NIL, (const_node_ptr)&*_root_Node, (const_node_ptr)&*cur);
				}
				return const_iterator((const_node_ptr)&*NIL, (const_node_ptr)&*_root_Node, (const_node_ptr)&*NIL);
			};
			iterator		upper_bound(const T& value) {
				for (iterator it = begin(); it != end(); it++)
					if (_comp(value, *it))
						return it;
				return iterator(NIL, _root_Node, NIL);
			};
			const_iterator	upper_bound(const T& value) const {
				for (const_iterator it = begin(); it != end(); it++)
					if (_comp(value, *it))
						return it;
				return const_iterator((const_node_ptr)&*NIL, (const_node_ptr)&*_root_Node, (const_node_ptr)&*NIL);
			};
			iterator		lower_bound(const T& value) {
				for (iterator it = begin(); it != end(); it++)
					if (_comp(value, *it) || _comp(*it, value) == 0)
						return it;
				return iterator(NIL, _root_Node, NIL);
			};
			const_iterator	lower_bound(const T& value) const {
				for (const_iterator it = begin(); it != end(); it++)
					if (_comp(value, *it) || _comp(*it, value) == 0)
						return it;
				return const_iterator((const_node_ptr)&*NIL, (const_node_ptr)&*_root_Node, (const_node_ptr)&*NIL);
			};
	};
}

#endif