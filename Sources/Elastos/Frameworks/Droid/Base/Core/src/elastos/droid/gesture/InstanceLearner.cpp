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

#include <Elastos.CoreLibrary.Utility.h>
#include "elastos/droid/gesture/CPrediction.h"
#include "elastos/droid/gesture/GestureUtils.h"
#include "elastos/droid/gesture/InstanceLearner.h"
#include <elastos/core/Math.h>

using Elastos::Core::EIID_IComparator;
using Elastos::Utility::CArrayList;
using Elastos::Utility::IArrayList;
using Elastos::Utility::CCollections;
using Elastos::Utility::ICollections;
using Elastos::Utility::IList;
using Elastos::Utility::INavigableMap;

namespace Elastos {
namespace Droid {
namespace Gesture {

CAR_INTERFACE_IMPL(InstanceLearner, Object, IComparator);
CAR_INTERFACE_IMPL(InstanceLearner::PredictionComparator, Object, IComparator);

ECode InstanceLearner::constructor()
{
    return NOERROR;
}

ECode InstanceLearner::PredictionComparator::Compare(
    /* [in] */ IInterface* object1,
    /* [in] */ IInterface* object2,
    /* [out] */ Int32* result)
{
    Double score1;
    IPrediction::Probe(object1)->GetScore(&score1);
    Double score2;
    IPrediction::Probe(object2)->GetScore(&score2);
    if (score1 > score2) {
        *result = -1;
    } else if (score1 < score2) {
        *result = 1;
    } else {
        *result = 0;
    }
    return NOERROR;
}

InstanceLearner::InstanceLearner()
{
    mComparator = new PredictionComparator();
}

InstanceLearner::~InstanceLearner()
{}

AutoPtr<IArrayList> InstanceLearner::Classify(
    /* [in] */ Int32 sequenceType,
    /* [in] */ Int32 orientationType,
    /* [in] */ ArrayOf<Float>* vec)
{
    return NULL;
/*
    AutoPtr<IArrayList> predictions;
    CArrayList::New((IArrayList**)&predictions);

    AutoPtr<IArrayList> instances = Learner::GetInstances();

    AutoPtr<INavigableMap> label2score;
    CTreeMap::New((INavigableMap**)&label2score);

    Int32 count;
    instances->GetSize(&count);

    for (int i = 0; i < count; i++) {
        AutoPtr<IInstance> sample;

        instances->Get(i, (IInterface *)&sample);

        if (sample->mVector->GetLength() != vec->GetLength()) {
            continue;
        }
        Double distance;
        if (sequenceType == IGestureStore::SEQUENCE_SENSITIVE) {
            distance = GestureUtils::MinimumCosineDistance(sample->mVector, vec, orientationType);
        } else {
            distance = GestureUtils::SquaredEuclideanDistance(sample->mVector, vec);
        }
        Double weight;
        if (distance == 0) {
            weight = Elastos::Core::Math::DOUBLE_MAX_VALUE;
        } else {
            weight = 1 / distance;
        }
        Double score = NULL;
        Map<String, Double>::Iterator mapit = label2score.Find(sample->mLabel);
        if (mapit != label2score.End()) score = mapit->mSecond;
        if (score == NULL || weight > score) {
            label2score[sample->mLabel] = weight;
        }
    }

    label2score->GetSize(&count);
    for (int i = 0; i < count; i++) {
        AutoPtr<IInstance> sample;

        label2score->Get(i, (IInterface *)&sample);


    Map<String, Double>::Iterator iter;
    for (iter = label2score.Begin(); iter != label2score.End(); ++iter) {
        String name = iter->mFirst;
        Double score = iter->mSecond;
        AutoPtr<IPrediction> prediction;
        CPrediction::New(name, score, (IPrediction**)&prediction);
        Boolean result;
        predictions->Add(prediction, &result);
    }

    AutoPtr<ICollections> collections;
    CCollections::AcquireSingleton((ICollections**)&collections);
    collections->Sort(IList::Probe(predictions), mComparator);

    return predictions;
*/
}

ECode InstanceLearner::AddInstance(
    /* [in] */ IInstance *instance)
{
    mInstances->Add(instance);
    return NOERROR;
}

ECode InstanceLearner::Classify(
    /* [in] */ Int32 sequenceType,
    /* [in] */ Int32 orientationType,
    /* [in] */ ArrayOf<Float>* vec,
    /* [out] */ IArrayList** predictions)
{
    AutoPtr<IArrayList> list = Classify(sequenceType, orientationType, vec);
    *predictions = list;
    REFCOUNT_ADD(*predictions)
    return NOERROR;
}

ECode InstanceLearner::GetInstances(
    /* [in] */ IArrayList** instances)
{
/*
    AutoPtr<IArrayList> ret = Learner::GetInstances();
    *instances = ret;
*/
    return NOERROR;
}

} // namespace Gesture
} // namespace Droid
} // namespace Elastos
