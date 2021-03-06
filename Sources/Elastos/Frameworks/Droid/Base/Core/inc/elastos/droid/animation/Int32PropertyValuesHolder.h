//=========================================================================
// Copyright (C) 2012 The Elastos Open Source Project
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//=========================================================================

#ifndef __ELASTOS_DROID_ANIMATION_INT32PROPERTYVALUESHOLDER_H__
#define __ELASTOS_DROID_ANIMATION_INT32PROPERTYVALUESHOLDER_H__

#include "PropertyValuesHolder.h"

using Elastos::Droid::Utility::IInt32Property;

namespace Elastos {
namespace Droid {
namespace Animation {

class Int32PropertyValuesHolder
    : public PropertyValuesHolder
    , public IInt32PropertyValuesHolder
{
public:
    CAR_INTERFACE_DECL()

    Int32PropertyValuesHolder(
        /* [in] */ const String& propertyName,
        /* [in] */ IInt32Keyframes* keyframes);

    Int32PropertyValuesHolder(
        /* [in] */ IProperty* property,
        /* [in] */ IInt32Keyframes* keyframes);

    Int32PropertyValuesHolder(
        /* [in] */ const String& propertyName,
        /* [in] */ ArrayOf<Int32>* values);

    Int32PropertyValuesHolder(
        /* [in] */ IProperty* property,
        /* [in] */ ArrayOf<Int32>* values);

    CARAPI SetInt32Values(
        /* [in] */ ArrayOf<Int32>* values);

    CARAPI CalculateValue(
        /* [in] */ Float fraction);

    CARAPI GetAnimatedValue(
        /* [out] */ IInterface** value);

    CARAPI Clone(
        /* [out] */ IInterface** holder);

    CARAPI SetAnimatedValue(
        /* [in] */ IInterface* target);

    CARAPI SetupSetter(
        /* [in] */ IClassInfo* targetClass);

    CARAPI SetupGetter(
        /* [in] */ IClassInfo* target);

private:
    CARAPI CallGetter(
        /* [in] */ IInterface* target,
        /* [out] */ IInterface** value);

protected:
    AutoPtr<IMethodInfo> mNativeSetter;
    AutoPtr<IInt32Keyframes> mInt32Keyframes;
    Int32 mInt32AnimatedValue;

private:
    typedef HashMap<String, AutoPtr<IMethodInfo> > MethodMap;
    typedef typename MethodMap::Iterator MethodMapIterator;

    typedef HashMap<AutoPtr<IClassInfo>, AutoPtr<MethodMap> > ClassMethodMap;
    typedef typename ClassMethodMap::Iterator ClassMethodMapIterator;

    static ClassMethodMap sNativeGetterSetterPropertyMap;
    AutoPtr<IInt32Property> mInt32Property;
};

} // namespace Animation
} // namepsace Droid
} // namespace Elastos

#endif // __ELASTOS_DROID_ANIMATION_INT32PROPERTYVALUESHOLDER_H__
