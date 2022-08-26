#ifndef MO_BASE_HPP_
#define MO_BASE_HPP_

#include <string>
#include <memory>

#include "ClassName.hpp"
#include "DistName.hpp"
#include "Log.hpp"

typedef int32_t SubscriptionId;


// Managed Object Base Class
class MoBase {
public:
    MoBase(const DistName&);

    virtual ~MoBase() {}

    virtual MoBasePtr clone() const = 0;
    virtual MoBasePtr cloneAs(const DistName&) const = 0;

    virtual const ClassName& getClassName() const = 0;
    virtual const DistName& getDistName() const;

    bool isLocal() const;

    virtual bool operator==(const MoBase&) const;
    bool operator!=(const MoBase&) const;

protected:
    MoBase(const DistName&, const bool local);

    bool haveEqualName(const MoBase&) const;
    bool haveEqualLocal(const MoBase&) const;

    static void validate(const DistName&, const ClassName&);

private:
    DistName distName;
    mutable bool local;
};

using MoBasePtr = std::shared_ptr<MoBase>;
using MoBaseCPtr = std::shared_ptr<const MoBase>;

using MoBasePtrVec = std::vector<MoBasePtr>;
using MoBaseCPtrVec = std::vector<MoBaseCPtr>;

using MoBasePtrSet = std::set<MoBasePtr>;
using MoBaseCPtrSet = std::set<MoBaseCPtr>;

// Managed Object Base Class Template
template <class T>
class MoBaseT : public MoBase {
public:
    using DataType = T;

    explicit MoBaseT(const DistName&);
    MoBaseT(const DistName& distName, const DataType& data);

    static std::shared_ptr<MoBaseT<DataType>> newUniqueObject(const boost::optional<DistName>& parent = boost::none);

    DataType& operator*();
    const DataType& operator*() const;

    DataType* operator->();
    const DataType* operator->() const;

    const ClassName& getClassName() const override;

    MoBasePtr clone() const override;
    MoBasePtr cloneAs(const DistName& distName) const override;

    bool operator==(const MoBase&) const override;

    static const ClassName className;

private:
    template<class A = DataType>
    typename std::enable_if<boost::has_equal_to<A, A, bool>::value, bool>::type haveEqualData(const MoBase&) const;

    template<class A = DataType>
    typename std::enable_if<!boost::has_equal_to<A, A, bool>::value, bool>::type haveEqualData(const MoBase&) const;

    DataType data;
};

template <class T>
inline std::shared_ptr<T> CloneObject(std::shared_ptr<const T>);

template <class InputIterator, class OutputIterator, class T = InputIterator::value_type>
inline void CloneObjects(InputIterator first, InputIterator last, OutputIterator result);

#endif // MO_BASE_HPP_