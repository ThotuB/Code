#include "MoBase.hpp"
#include <iostream>

MoBase::MoBase(const DistName& distName)
    : distName(distName), local(true) {}

const DistName& MoBase::getDistName() const {
    return distName;
}

bool MoBase::isLocal() const {
    return local;
}

bool MoBase::operator==(const MoBase& other) const {
    return false;
}

bool MoBase::operator!=(const MoBase& other) const {
    return !(*this == other);
}

bool MoBase::haveEqualName(const MoBase& other) const {
    return distName == other.getDistName();
}

bool MoBase::haveEqualLocal(const MoBase& other) const {
    return local == other.isLocal();
}

void MoBase::validate(const DistName& distName, const ClassName& className) {
    if (distName.getClassName() != className) {
        std::cout << "Error: " << "dist name - " << distName.getString() << " - has wrong class name - " << className << std::endl;
    }
}

MoBase::MoBase(const DistName& distName, const bool local)
    : distName(distName), local(local) {}


// MoBaseT
template <class T>
MoBaseT<T>::MoBaseT(const DistName& distName)
    : MoBase(distName), data() {
        validate(distName, MoBaseT<T>::className);    
    }

template <class T>
MoBaseT<T>::MoBaseT(const DistName& distName, const T& data)
    : MoBase(distName), data(data) {
        validate(distName, MoBaseT<T>::className);
    }

template <class T>
std::shared_ptr<MoBaseT<T>> MoBaseT<T>::newUniqueObject(const boost::optional<DistName>& parent = boost::none) {
    auto maybeDistName = DistName::unique(MoBaseT<T>::className, parent);
    if (!maybeDistName) {
        return nullptr;
    }
    return std::make_shared<MoBaseT<T>>(*maybeDistName);
}

template <class T>
T& MoBaseT<T>::operator*() { 
    return data; 
}

template <class T>
const T& MoBaseT<T>::operator*() const { 
    return data; 
}

template <class T>
T* MoBaseT<T>::operator->() { 
    return &data; 
}

template <class T>
const T* MoBaseT<T>::operator->() const {
    return &data; 
}

template <class T>
const ClassName& MoBaseT<T>::getClassName() const { 
    return className;
}

template <class T>
MoBasePtr MoBaseT<T>::clone() const {
    return std::make_shared<MoBaseT<T>>(new MoBaseT<T>(getDistName(), isLocal(), data);
}

template <class T>
MoBasePtr MoBaseT<T>::cloneAs(const DistName& distName) const {
    return std::make_shared<MoBaseT<T>>(new MoBaseT<T>(distName, isLocal(), data);
}

template <class T>
bool MoBaseT<T>::operator==(const MoBase& other) const {
    return haveEqualName(other) && haveEqualData(other) && haveEqualLocal(other);
}

template <class T>
inline std::shared_ptr<T> CloneObject(std::shared_ptr<const T> object) {
    return std::static_pointer_cast<T>(object->clone());
}

template <class InputIterator, class OutputIterator, class T = InputIterator::value_type>
inline void CloneObjects(InputIterator first, InputIterator last, OutputIterator result) {
    using ObjectType = typename std::remove_const<typename T::element_type>::type;
    std::stransform(first, last, result, CloneObject<ObjectType>);
}

template <class T>
