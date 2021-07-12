#pragma once

#include <vector>
#include <algorithm>

namespace lesson_4 {

    template <typename Container, typename Value>
    typename Container::iterator insert_sorted(Container& container, Value const& value) {
        return container.insert(
            std::upper_bound(container.cbegin(), container.cend(), value), value
        );
    }
