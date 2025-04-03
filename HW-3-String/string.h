#ifndef STRING_H
#define STRING_H 

#include <iostream>
#include <cstddef>
#include <cstring>

struct String
{
    private:
        size_t size;
        char *str;

    public:
        String(const char *str = "");
        String(const String &other);
        ~String();

        String &operator=(const String &other);
        String operator[](size_t index) const;
        friend std::ostream& operator<<(std::ostream& stream, const String& str);
};
#endif //STRING_H