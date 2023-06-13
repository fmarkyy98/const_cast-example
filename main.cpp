#include <iostream>

class Foo {
public:
    void heck_val(int val) const {
        auto mutable_this = const_cast<Foo*>(this);
        mutable_this->val = val;
    }

    int get_val() const {
        return val;
    }

    Foo& set_val(int val) {
        this->val = val;
        return *this;
    }

private:
    int val;
};

int main() {
    Foo f;
    f.set_val(10);

    std::cout << f.get_val() << '\n';

    const Foo c_f = f;
    c_f.heck_val(20);

    std::cout << f.get_val() << '\n';
}