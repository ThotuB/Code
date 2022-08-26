#include <string>

typedef std::vector<ClassName> ClassNameVec;

class ClassName {
public:
    ClassName(const std::string&);
    ~ClassName() = default;

    boost::string_view getString() const;
    explicit operator std::string() const;

    friend bool operator==(const ClassName&, const ClassName&);
    friend bool operator<(const ClassName&, const ClassName&);
    friend std::ostream& operator<<(std::ostream&, const ClassName&);
};
