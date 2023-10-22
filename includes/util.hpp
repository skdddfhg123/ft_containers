#ifndef UTILS_HPP
# define UTILS_HPP

namespace	ft
{
	// enable_if / SFINAE
	template<bool Cond, class T = void>
	struct enable_if {};
	template<class T>
	struct enable_if<true, T> { typedef T type; };

	struct true_type {
		static const bool value = true;
		operator bool() const { return value; }
	};
	struct false_type {
		static const bool value = false;
		operator bool() const { return value; }
	};
	
	template <typename T>
	struct is_integral_base : false_type {};

	template <>
	struct is_integral_base<bool> : true_type {};
	template <>
	struct is_integral_base<char> : true_type {};
	template <>
	struct is_integral_base<signed char> : true_type {};
	template <>
	struct is_integral_base<short int> : true_type {};
	template <>
	struct is_integral_base<int> : true_type {};
	template <>
	struct is_integral_base<long int> : true_type {};
	template <>
	struct is_integral_base<long long int> : true_type {};
	template <>
	struct is_integral_base<unsigned short int> : true_type {};
	template <>
	struct is_integral_base<unsigned int> : true_type {};
	template <>
	struct is_integral_base<unsigned long int> : true_type {};
	template <>
	struct is_integral_base<unsigned long long int> : true_type {};

	template <typename T>
	struct is_integral : is_integral_base<T> {};
	// pair
	template <class T1, class T2>
	struct pair {
		typedef T1 first_type;
		typedef T2 second_type;
		first_type	first;
		second_type	second;
		pair() : first(), second() {};
		template<class U, class V>
		pair(const pair<U, V> &ref) : first(ref.first), second(ref.second) {};
		pair(const first_type &a, const second_type &b) : first(a), second(b) {};
		operator pair<const T1, const T2>() const { return (pair<const T1, const T2>(first, second)); };
		pair& operator=(const pair& ref) {
			this->first = ref.first;
			this->second = ref.second;
			return *this;
		}
	};
	template< class T1, class T2 >
	bool operator==( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs ) { return (lhs.first == rhs.first) && (rhs.second == rhs.second); }
	template< class T1, class T2 >
	bool operator!=( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs ) { return !((lhs.first == rhs.first) && (rhs.second == rhs.second)); }
	template< class T1, class T2 >
	bool operator>( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs ) {
		if (lhs.first == rhs.first)
			return (lhs.second > rhs.second);
		return (lhs.first > rhs.first);
	}
	template< class T1, class T2 >
	bool operator>=( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs ) {
		if (lhs.first == rhs.first)
			return (lhs.second >= rhs.second);
		return (lhs.first > rhs.first);
	}
	template< class T1, class T2 >
	bool operator<( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs ) { return !(lhs >= rhs); }
	template< class T1, class T2 >
	bool operator<=( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs ) { return !(lhs > rhs); }
	// binary_function
	template <class Arg1, class Arg2, class Result>
	struct binary_function {
		/* The first argument type */
		typedef Arg1 first_argument_type;

		/* The second arguement type */
		typedef Arg2 second_argument_type;

		/* The result type */
		typedef Result result_type;
	};
	// less
	template <class T>
	struct less : binary_function<T, T, bool> {
		bool operator() (const T& x, const T& y) const { return (x < y); }
	};
	// make_pair
	template <class T1, class T2>
	ft::pair<T1,T2> make_pair(T1 x, T2 y) { return ft::pair<T1, T2>(x, y); }
	// lexicographical_compare
	template<class InputIt1, class InputIt2>
	bool lexicographical_compare(InputIt1 first1, InputIt1 last1,
								InputIt2 first2, InputIt2 last2)
	{
		for ( ; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2 ) {
			if (*first1 < *first2) return true;
			if (*first2 < *first1) return false;
		}
		return (first1 == last1) && (first2 != last2);
	}
	template<class InputIt1, class InputIt2, class Compare>
	bool lexicographical_compare(InputIt1 first1, InputIt1 last1,
								InputIt2 first2, InputIt2 last2,
								Compare comp)
	{
		for ( ; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2 ) {
			if (comp(*first1, *first2)) return true;
			if (comp(*first2, *first1)) return false;
		}
		return (first1 == last1) && (first2 != last2);
	}
	//equal
	template <class InputIterator1, class InputIterator2>
	bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2) {
		while (first1!=last1) {
			if (!(*first1 == *first2))
				return false;
			++first1; ++first2;
		}
		return true;
	}
	template <class InputIterator1, class InputIterator2, class BinaryPredicate>
	bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, BinaryPredicate pred) {
		while (first1!=last1) {
			if (!pred(*first1,*first2))
				return false;
			++first1; ++first2;
		}
		return true;
	}
}

#endif