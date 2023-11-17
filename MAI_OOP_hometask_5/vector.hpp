#include <memory>
#include <vector>
std::vector<int> l;

template <typename T, class Allocator = std::allocator<T>>
class Vector
{
private:
    T *_array[];
    size_t _size;
    size_t _capacity;
    Allocator _allocator;
    using alloc_traits = std::allocator_traits<Allocator>;

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

        ~Iterator() = default;

        reference operator*()
        {
            return *_link;
        }

        pointer operator->()
        {
            return _link;
        }

        Iterator &operator++()
        {
            _link += 1;
            return *this;
        }

        Iterator operator++(int)
        {
            Iterator new_one = *this;
            _link += 1;
            return new_one;
        }

        Iterator &operator--()
        {
            _link -= 1;
            return *this;
        }

        Iterator operator--(int)
        {
            Iterator new_one = *this;
            -link -= 1;
            return new_one;
        }

        Iterator operator+(const int &cnst) const
        {
            Iterator new_one = *this;
            new_one._link += cnst;
            return new_one;
        }

        Iterator &operator+=(const int &cnst)
        {
            _link = _link + cnst;
            return *this;
        }

        Iterator operator-(const int &cnst) const
        {
            Iterator new_one = *this;
            new_one._link -= cnst;
            return new_one;
        }

        Iterator &operator-=(const int &cnst)
        {
            _link = _link - cnst;
            return *this;
        }

        bool operator==(const Iterator &iter) const
        {
            return (this->_link == iter._link);
        }

        bool operator!=(const Iterator &iter) const
        {
            return (this->_link != iter._link);
        }
    };

    class Const_Iterator
    {

    private:
        const value_type *_link;

    public:
        friend Vector;

        using difference_type = int; // в чем меряем расстояние
        using value_type = const Vector::value_type;
        using reference = const Vector::value_type &;
        using pointer = const Vector::value_type *;
        using iterator_category = std::forward_iterator_tag; // std::random_access_iterator_tag;

        Iterator() : _link(nullptr)
        {
        }

        Iterator(pointer p) : _link(p)
        {
        }

        ~Iterator() = default;

        reference operator*()
        {
            return *_link;
        }

        pointer operator->()
        {
            return _link;
        }

        Iterator &operator++()
        {
            _link += 1;
            return *this;
        }

        Iterator operator++(int)
        {
            Iterator new_one = *this;
            _link += 1;
            return new_one;
        }

        Iterator &operator--()
        {
            _link -= 1;
            return *this;
        }

        Iterator operator--(int)
        {
            Iterator new_one = *this;
            -link -= 1;
            return new_one;
        }

        Iterator operator+(const int &cnst) const
        {
            Iterator new_one = *this;
            new_one._link += cnst;
            return new_one;
        }

        Iterator &operator+=(const int &cnst)
        {
            _link = _link + cnst;
            return *this;
        }

        Iterator operator-(const int &cnst) const
        {
            Iterator new_one = *this;
            new_one._link -= cnst;
            return new_one;
        }

        Iterator &operator-=(const int &cnst)
        {
            _link = _link - cnst;
            return *this;
        }

        bool operator==(const Iterator &iter) const
        {
            return (this->_link == iter._link);
        }

        bool operator!=(const Iterator &iter) const
        {
            return (this->_link != iter._link);
        }
    };

    Vector() : _size(0), _capacity(0), _allocator()
    {
    }

    Vector(const size_t &ln, const value_type &elem = T()) : _size(ln), _capacity(ln), _allocator()
    {
        _array = alloc_traits::allocate(_allocator, _size);
        for (size_t i = 0; i < _size; ++i)
        {
            _array[i] = elem;
        }
    }
};