#ifndef __ELASTOS_APPS_DIALER_LIST_CSWIPEHELPER_H__
#define __ELASTOS_APPS_DIALER_LIST_CSWIPEHELPER_H__

#include "_Elastos_Apps_Dialer_List_CSwipeHelper.h"
#include "SwipeHelper.h"

namespace Elastos{
namespace Apps{
namespace Dialer {
namespace List {

CarClass(CSwipeHelper)
    , public SwipeHelper
{
public:
    CAR_OBJECT_DECL()
};

} // List
} // Dialer
} // Apps
} // Elastos

#endif //__ELASTOS_APPS_DIALER_LIST_CSWIPEHELPER_H__