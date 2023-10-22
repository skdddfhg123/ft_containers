#ifndef _RBT_NODE_H
# define _RBT_NODE_H

# include <iostream>

namespace	ft
{
	typedef enum { BLACK, RED } RBT_Node_color;
	template <class T>
	class RBT_Node {
		public:
			typedef T		value_type;
			RBT_Node		*left;
			RBT_Node		*right;
			RBT_Node		*parent;
			RBT_Node_color	color;
			value_type		value;

			operator RBT_Node<const T>() const { return (RBT_Node<const T>(this->_node)); };

			RBT_Node () : left(NULL), right(NULL), parent(NULL), color(RED), value() {};
			RBT_Node (const T& _val) : left(NULL), right(NULL), parent(NULL), color(RED), value(_val) {};
			RBT_Node(RBT_Node const &ref) {
				this->left = ref.left;
				this->right = ref.right;
				this->parent = ref.parent;
				this->value = ref.value;
				this->color = ref.color;
			};
			~RBT_Node () {};

			RBT_Node	&operator=(RBT_Node const &ref) {
				if (this != &ref) {
					this->left = ref.left;
					this->right = ref.right;
					this->parent = ref.parent;
					this->value = ref.value;
					this->color = ref.color;
				}
				return (*this);
			};

	};
	template <class T1, class T2>
	bool operator==(const RBT_Node<T1> &lhs, const RBT_Node<T2> &rhs) { return lhs.value == rhs.value; }
}

#endif
