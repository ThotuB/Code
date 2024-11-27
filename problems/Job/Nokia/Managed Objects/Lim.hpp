#ifndef LIM_HPP_
#define LIM_HPP_

#include <functional>

#include "ClassName.hpp"
#include "DistName.hpp"
#include "MoBase.hpp"

typedef std::function<void (const DistName&)> Subscriber;

using Predicate = std::function<bool (const MoBasePtr&)>;

// Local Info Model - Stores Managed Objects
class Lim {
public:
    void expand(const ClassName&);
    void shrink(const ClassName&);

    void commit(const MoBaseCPtr&);
    void commit(const DistName&);

    void expand(const ClassNameVec&);
    void shrink(const ClassNameVec&);
    void commit(const MoBaseCPtrVec&, const DistNameVec&);

    MoBaseCPtr fetch(const DistName&) const;
    MoBaseCPtrVec fetch(const ClassName&) const;
    MoBaseCPtrVec fetch(const Predicate&) const;
    MoBaseCPtrVec fetch(const ClassName&, const Predicate&) const;

    SubscriptionId subscribe(const ClassName&, Subscriber);
    bool unsubscribe(const SubscriptionId);
    
    void logObjects() const;
};

#endif // LIM_HPP_