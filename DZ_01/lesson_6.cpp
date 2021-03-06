#include "lesson_6.h"
#include <iomanip>

using namespace std;

namespace lesson_6 {

    // --------------------------------------------------------------------------------------
    std::ostream& operator<<(ostream& stream, const Home::Item& item) {
        return stream << "{ name = " << quoted(item.name) << ", worth = " << item.worth << "}";
    }

    // --------------------------------------------------------------------------------------
    void Home::addItem(const Home::Item& item, const std::string& person) {
        std::lock_guard guard{ m_mutex };
        m_items.emplace(make_pair(item.worth, item));
        cout << "Add to item [" << person << "]: " << item << endl;
    }

    // --------------------------------------------------------------------------------------
    Home::Item Home::takeWorthItem(const std::string& person) {
        std::lock_guard guard{ m_mutex };
        if (!m_items.empty()) {
            Home::Item item{ m_items.rbegin()->second };
            m_items.erase(--m_items.end());
            cout << "Take item from home [" << person << "]: " << item << endl;
            return item;
        }
        cout << "It's nothing to take from home [" << person << "]" << endl;
        return {};
    }

}