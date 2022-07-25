#include <iostream>
#include <iterator>
#include <memory>
#include <vector>
#include <unistd.h>

class Progress {
   private:
    std::vector<int> elements;
    unsigned size;
    unsigned count = 0;

    char tick = '*';
    char l_bound = '[';
    char r_bound = ']';

    void increment() {
        ++count;
        print();
    }

    void print() {
        system("clear");
        std::cout << l_bound;
        for (unsigned i = 0; i < count; ++i) {
            std::cout << tick;
        }
        for (unsigned i = count; i < size; ++i) {
            std::cout << ' ';
        }
        std::cout << r_bound << std::flush;
    }

   public:
    struct Iterator {
        using iterator_category = std::forward_iterator_tag;
        using value_type = int;
        using difference_type = std::ptrdiff_t;
        using pointer = int*;
        using reference = int&;

       private:
        pointer _ptr;
        Progress* _progress;

       public:
        Iterator(pointer p)
            : _ptr(p) {}

        void attach(Progress* progress) {
            _progress = progress;
        }

        virtual ~Iterator() {}

        reference operator*() {
            return *_ptr;
        }

        Iterator& operator++() {
            _progress->increment();
            ++_ptr;
            return *this;
        }

        bool operator!=(const Iterator& rhs) {
            return _ptr != rhs._ptr;
        }
    };

    Progress(std::vector<int> elements)
        : elements(elements), size(elements.size()) {}

    virtual ~Progress() {
        elements.clear();
    }

    Progress& with_bounds(char l_bound, char r_bound) {
        this->l_bound = l_bound;
        this->r_bound = r_bound;
        return *this;
    }

    Progress& with_tick(char tick) {
        this->tick = tick;
        return *this;
    }

    Iterator begin() {
        print();
        Iterator it = Iterator(elements.data());
        it.attach(this);
        return it;
    }

    Iterator end() {
        return Iterator(elements.data() + elements.size());
    }
};

void expensive_computation() {
    sleep(1);
}

int main() {
    std::vector<int> elements = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Progress progress(elements);
    progress.with_bounds('<', '>').with_tick('|');
    for (auto it : progress) {
        expensive_computation();
    }
}