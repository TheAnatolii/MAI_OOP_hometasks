#include <memory>

template <typename T, class Allocator = std::allocator<T>>
class Vector
{
private:
public:
    using value_type = T;

    class Iterator
    {

    private:
        value_type *_link;

    public:
        friend Vector;

        using difference_type = int; // в чем меряем расстояние
        using value_type = Vector::value_type;
        using reference = Vector::value_type &;
        using pointer = Vector::value_type *;
        using iterator_category = std::forward_iterator_tag; // std::random_access_iterator_tag;

        Iterator() : _link(nullptr)
        {
        }

        Iterator(pointer p) : _link(p)
        {
        }
    };
};