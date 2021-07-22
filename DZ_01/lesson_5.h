#pragma once

#include <iostream>
#include <algorithm>
#include <iterator>
#include <unordered_set>

namespace lesson_5 {

	// --------------------------------------------------------------------------------------
	template <typename It>
	void printUnique(It begin, It end) {
		using ValueType = typename std::iterator_traits<It>::value_type;
		std::unordered_set<ValueType> v_set{ begin, end };
		std::copy(v_set.cbegin(), v_set.cend(), std::ostream_iterator<ValueType>(std::cout, " "));
	}

}