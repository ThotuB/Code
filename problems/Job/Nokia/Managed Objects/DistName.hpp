#include <string>
#include <vector>
#include <set>

#include "ClassName.hpp"

typedef boost::optional<DistName> MaybeDistName;
typedef std::vector<DistName> DistNameVec;
typedef std::set<DistName> DistNameSet;

class DistName {
public:
    explicit DistName(const std::string&);

    operator std::string() const;
    std::string getString() const;

    bool isRoot() const;
    DistName getParent() const;
    ClassName getClassName() const;
    InstanceId getInstanceId() const;
    std::string getName() const;
    boost::uuids::uuid getId() const;
    MaybeDistName getFirstAncestor(const ClassName&) const;
    bool startsWith(const DistName&) const;

    static MaybeDistName make(const std::string&);
    friend bool operator==(const DistName&, const DistName&);
    friend bool operator<(const DistName&, const DistName&);
    friend std::ostream& operator<<(std::ostream&, const DistName&);
};