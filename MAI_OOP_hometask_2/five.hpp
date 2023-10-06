#include <string>

class Five
{
private:
    unsigned char *_num;
    size_t _size;
    void _resize();

public:
    Five();
    Five(const size_t &n, unsigned char t = 0);
    Five(const std::initializer_list<unsigned char> &t);
    Five(const std::string &t);
    Five(const Five &other);
    Five(Five &&other) noexcept;
    virtual ~Five() noexcept;

    unsigned char *get_value();
    size_t get_size();
    std::string get_value_string();

    bool operator==(const Five &other);
    bool operator<(const Five &other);
    bool operator>(const Five &other);

    Five &operator=(const Five &other);
    Five operator+(const Five &other);
    Five operator-(const Five &other);
};