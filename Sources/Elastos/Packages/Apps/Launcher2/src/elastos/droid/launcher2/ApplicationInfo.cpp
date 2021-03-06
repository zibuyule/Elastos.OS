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

#include "elastos/droid/launcher2/ApplicationInfo.h"
#include "elastos/droid/launcher2/ShortcutInfo.h"
#include "Elastos.Droid.Service.h"
#include "Elastos.CoreLibrary.Core.h"
#include <elastos/core/CoreUtils.h>
#include <elastos/core/StringBuilder.h>
#include <elastos/utility/logging/Slogger.h>

using Elastos::Droid::Content::CIntent;
using Elastos::Droid::Content::IIntent;
using Elastos::Core::CoreUtils;
using Elastos::Core::StringBuilder;
using Elastos::Utility::Logging::Slogger;

namespace Elastos {
namespace Droid {
namespace Launcher2 {

const String ApplicationInfo::TAG("Launcher2.ApplicationInfo");

CAR_INTERFACE_IMPL(ApplicationInfo, ItemInfo, IApplicationInfo);

ApplicationInfo::ApplicationInfo()
    : mFirstInstallTime(0)
    , mFlags(0)
{
}

ECode ApplicationInfo::constructor()
{
    ItemInfo::constructor();
    mItemType = ILauncherSettingsBaseLauncherColumns::ITEM_TYPE_SHORTCUT;
    return NOERROR;
}

ECode ApplicationInfo::constructor(
    /* [in] */ ILauncherActivityInfo* info,
    /* [in] */ IUserHandle* user,
    /* [in] */ IconCache* iconCache,
    /* [in] */ IHashMap* labelCache)
{
    ItemInfo::constructor();
    info->GetComponentName((IComponentName**)&mComponentName);
    mContainer = ItemInfo::NO_ID;
    SetActivity(mComponentName,
        IIntent::FLAG_ACTIVITY_NEW_TASK | IIntent::FLAG_ACTIVITY_RESET_TASK_IF_NEEDED);

    AutoPtr<Elastos::Droid::Content::Pm::IApplicationInfo> ainpo;
    info->GetApplicationInfo((Elastos::Droid::Content::Pm::IApplicationInfo**)&ainpo);
    Int32 appFlags;
    ainpo->GetFlags(&appFlags);
    if ((appFlags & Elastos::Droid::Content::Pm::IApplicationInfo::FLAG_SYSTEM) == 0) {
        mFlags |= DOWNLOADED_FLAG;
    }
    if ((appFlags & Elastos::Droid::Content::Pm::IApplicationInfo::FLAG_UPDATED_SYSTEM_APP) != 0) {
        mFlags |= UPDATED_SYSTEM_APP_FLAG;
    }
    info->GetFirstInstallTime(&mFirstInstallTime);
    iconCache->GetTitleAndIcon(this, info, labelCache);
    CIntent::New(IIntent::ACTION_MAIN, (IIntent**)&mIntent);
    mIntent->AddCategory(IIntent::CATEGORY_LAUNCHER);
    AutoPtr<IComponentName> name;
    info->GetComponentName((IComponentName**)&name);
    mIntent->SetComponent(name);
    mIntent->PutExtra(EXTRA_PROFILE, IParcelable::Probe(user));
    UpdateUser(mIntent);
    return NOERROR;
}

ECode ApplicationInfo::constructor(
    /* [in] */ ApplicationInfo* info)
{
    ItemInfo::constructor(info);
    mComponentName = info->mComponentName;
    String tmp;
    info->mTitle->ToString(&tmp);
    mTitle = CoreUtils::Convert(tmp);
    CIntent::New(info->mIntent, (IIntent**)&mIntent);
    mFlags = info->mFlags;
    mFirstInstallTime = info->mFirstInstallTime;
    return NOERROR;
}

ECode ApplicationInfo::SetActivity(
    /* [in] */ IComponentName* className,
    /* [in] */ Int32 launchFlags)
{
    CIntent::New(IIntent::ACTION_MAIN, (IIntent**)&mIntent);
    mIntent->AddCategory(IIntent::CATEGORY_LAUNCHER);
    mIntent->SetComponent(className);
    mIntent->SetFlags(launchFlags);
    mItemType = ILauncherSettingsBaseLauncherColumns::ITEM_TYPE_APPLICATION;
    return NOERROR;
}

ECode ApplicationInfo::ToString(
    /* [out] */ String* str)
{
    VALIDATE_NOT_NULL(str);

    String tmp;
    mTitle->ToString(&tmp);
    String tmp2;
    mUser->ToString(&tmp2);

    StringBuilder sb;
    sb += "ApplicationInfo(title=";
    sb += tmp;
    sb += " P=";
    sb += tmp2;
    sb += ")";
    return sb.ToString(str);
}

void ApplicationInfo::DumpApplicationInfoList(
    /* [in] */ const String& tag,
    /* [in] */ const String& label,
    /* [in] */ IArrayList* list)
{
    Int32 size;
    list->GetSize(&size);
    Slogger::D(tag, "%s size= %d", label.string(), size);

    for (Int32 i = 0; i < size; i++) {
        AutoPtr<IInterface> obj;
        list->Get(i, (IInterface**)&obj);
        AutoPtr<ApplicationInfo> info = (ApplicationInfo*)IObject::Probe(obj);
        Slogger::D(tag, "   title=\"%s\" iconBitmap=%s firstInstallTime=%d",
            TO_CSTR(info->mTitle), TO_CSTR(info->mIconBitmap), info->mFirstInstallTime);
    }
    return;
}

ECode ApplicationInfo::MakeShortcut(
    /* [out] */ IShortcutInfo** info)
{
    VALIDATE_NOT_NULL(info);

    AutoPtr<ShortcutInfo> obj = new ShortcutInfo();
    obj->constructor(this);
    *info = (IShortcutInfo*)obj.Get();
    REFCOUNT_ADD(*info);
    return NOERROR;
}

} // namespace Launcher2
} // namespace Droid
} // namespace Elastos