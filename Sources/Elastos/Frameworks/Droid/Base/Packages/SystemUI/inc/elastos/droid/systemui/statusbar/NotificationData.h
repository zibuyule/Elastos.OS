
#ifndef  __ELASTOS_DROID_SYSTEMUI_STATUSBAR_NOTIFICATIONDATA_H__
#define  __ELASTOS_DROID_SYSTEMUI_STATUSBAR_NOTIFICATIONDATA_H__

#include <elastos/droid/ext/frameworkext.h>
#include "_SystemUI.h"
#include "Elastos.Droid.Service.h"
#include <elastos/core/Object.h>

using Elastos::Droid::Os::IBinder;
using Elastos::Droid::View::IView;
using Elastos::Droid::Widget::IImageView;
using Elastos::Droid::Service::Notification::INotificationListenerServiceRanking;
using Elastos::Droid::Service::Notification::INotificationListenerServiceRankingMap;
using Elastos::Droid::Service::Notification::IStatusBarNotification;
using Elastos::Droid::SystemUI::StatusBar::IStatusBarIconView;
using Elastos::Droid::Utility::IArrayMap;
using Elastos::Droid::Utility::IArraySet;
using Elastos::Core::IComparator;
using Elastos::Core::Object;
using Elastos::IO::IPrintWriter;
using Elastos::Utility::IArrayList;

namespace Elastos {
namespace Droid {
namespace SystemUI {
namespace StatusBar {

class NotificationData
    : public Object
    , public INotificationData
{
private:
    class Comparator;

public:
    class Entry
        : public Object
        , public INotificationDataEntry
    {
    public:
        CAR_INTERFACE_DECL();

        Entry();

        Entry(
            /* [in] */ IStatusBarNotification* n,
            /* [in] */ IStatusBarIconView* ic);

        CARAPI SetBigContentView(
            /* [in] */ IView* expandedLarge);

        CARAPI GetBigContentView(
            /* [out] */ IView** view);

        CARAPI GetPublicContentView(
            /* [out] */ IView** view);

        CARAPI SetInterruption();

        CARAPI HasInterrupted(
            /* [out] */ Boolean* has);

        /**
         * Resets the notification entry to be re-used.
         */
        CARAPI Reset();

        CARAPI SetKey(
            /* [in] */ const String& key);

        CARAPI GetKey(
            /* [out] */ String* key);

        CARAPI SetNotification(
            /* [in] */ IStatusBarNotification* sbn);

        CARAPI GetNotification(
            /* [out] */ IStatusBarNotification** sbn);

        CARAPI SetIcon(
            /* [in] */ IStatusBarIconView* view);

        CARAPI GetIcon(
            /* [out] */ IStatusBarIconView** view);

        CARAPI SetRow(
            /* [in] */ IExpandableNotificationRow* row); // the outer expanded view

        CARAPI GetRow(
            /* [out] */ IExpandableNotificationRow** row);

        CARAPI SetExpanded(
            /* [in] */ IView* view); // the inflated RemoteViews

        CARAPI GetExpanded(
            /* [out] */ IView** view);

        CARAPI SetExpandedPublic(
            /* [in] */ IView* view); // for insecure lockscreens

        CARAPI GetExpandedPublic(
            /* [out] */ IView** view);

        CARAPI SetExpandedBig(
            /* [in] */ IView* big);

        CARAPI GetExpandedBig(
            /* [out] */ IView** big);

        CARAPI SetAutoRedacted(
            /* [in] */ Boolean value); // whether the redacted notification was generated by us

        CARAPI GetAutoRedacted(
            /* [out] */ Boolean* value);

        CARAPI SetLegacy(
            /* [in] */ Boolean value); // whether the notification has a legacy, dark background

        CARAPI GetLegacy(
            /* [out] */ Boolean* result);

        CARAPI SetTargetSdk(
            /* [in] */ Int32 sdk);

        CARAPI GetTargetSdk(
            /* [out] */ Int32* sdk);

    public:
        String mKey;
        AutoPtr<IStatusBarNotification> mNotification;
        AutoPtr<IStatusBarIconView> mIcon;
        AutoPtr<IExpandableNotificationRow> mRow; // the outer expanded view
        AutoPtr<IView> mExpanded; // the inflated RemoteViews
        AutoPtr<IView> mExpandedPublic; // for insecure lockscreens
        AutoPtr<IView> mExpandedBig;
        Boolean mAutoRedacted; // whether the redacted notification was generated by us
        Boolean mLegacy; // whether the notification has a legacy, dark background
        Int32 mTargetSdk;

    private:
        Boolean mInterruption;
        friend class Comparator;
    };

private:
    class Comparator
        : public Object
        , public IComparator
    {
    public:
        CAR_INTERFACE_DECL();

        Comparator(
            /* [in] */ NotificationData* host);

        // @Override
        CARAPI Compare(
            /* [in] */ IInterface* a,
            /* [in] */ IInterface* b,
            /* [out] */ Int32* result);

    private:
        NotificationData* mHost;
        AutoPtr<INotificationListenerServiceRanking> mRankingA;
        AutoPtr<INotificationListenerServiceRanking> mRankingB;
    };

public:
    CAR_INTERFACE_DECL();

    NotificationData(
        /* [in] */ INotificationEnvironment* environment);

    /**
     * Returns the sorted list of active notifications (depending on {@link Environment}
     *
     * <p>
     * This call doesn't update the list of active notifications. Call {@link #filterAndSort()}
     * when the environment changes.
     * <p>
     * Don't hold on to or modify the returned list.
     */
    CARAPI GetActiveNotifications(
        /* [out] */ IArrayList** list);

    CARAPI Get(
        /* [in] */ const String& key,
        /* [out] */ INotificationDataEntry** entry);

    CARAPI Add(
        /* [in] */ INotificationDataEntry* entry,
        /* [in] */ INotificationListenerServiceRankingMap* ranking);

    CARAPI Remove(
        /* [in] */ const String& key,
        /* [in] */ INotificationListenerServiceRankingMap* ranking,
        /* [out] */ INotificationDataEntry** entry);

    CARAPI UpdateRanking(
        /* [in] */ INotificationListenerServiceRankingMap* ranking);

    CARAPI IsAmbient(
        /* [in] */ const String& key,
        /* [out] */ Boolean* result);

    CARAPI GetVisibilityOverride(
        /* [in] */ const String& key,
        /* [out] */ Int32* result);

    // TODO: This should not be public. Instead the Environment should notify this class when
    // anything changed, and this class should call back the UI so it updates itself.
    CARAPI FilterAndSort();

    CARAPI IsGroupWithSummary(
        /* [in] */ const String& groupKey,
        /* [out] */ Boolean* result);

    CARAPI_(Boolean) ShouldFilterOut(
        /* [in] */ IStatusBarNotification* sbn);

    /**
     * Return whether there are any clearable notifications (that aren't errors).
     */
    CARAPI HasActiveClearableNotifications(
        /* [out] */ Boolean* result);

    // Q: What kinds of notifications should show during setup?
    // A: Almost none! Only things coming from the system (package is "android") that also
    // have special "kind" tags marking them as relevant for setup (see below).
    static CARAPI_(Boolean) ShowNotificationEvenIfUnprovisioned(
        /* [in] */ IStatusBarNotification* sbn);

    CARAPI_(void) Dump(
        /* [in] */ IPrintWriter* pw,
        /* [in] */ const String& indent);

private:
    CARAPI_(void) UpdateRankingAndSort(
        /* [in] */ INotificationListenerServiceRankingMap* ranking);

    CARAPI_(void) DumpEntry(
        /* [in] */ IPrintWriter* pw,
        /* [in] */ const String& indent,
        /* [in] */ Int32 i,
        /* [in] */ Entry* e);

    static CARAPI_(Boolean) IsSystemNotification(
        /* [in] */ IStatusBarNotification* sbn);

private:
    AutoPtr<INotificationEnvironment> mEnvironment;

    AutoPtr<IArrayMap> mEntries;  /*<String, Entry*/
    AutoPtr<IArrayList> mSortedAndFiltered;  /*<Entry*/
    AutoPtr<IArraySet> mGroupsWithSummaries;  /*<String*/
    AutoPtr<IComparator> mRankingComparator;  /*<Entry*/
    AutoPtr<INotificationListenerServiceRankingMap> mRankingMap;
    AutoPtr<INotificationListenerServiceRanking> mTmpRanking;
};

} // namespace StatusBar
} // namespace SystemUI
} // namespace Droid
} // namespace Elastos

#endif // __ELASTOS_DROID_SYSTEMUI_STATUSBAR_NOTIFICATIONDATA_H__
