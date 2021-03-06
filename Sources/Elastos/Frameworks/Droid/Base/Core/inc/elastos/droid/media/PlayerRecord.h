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

#ifndef _ELASTOS_DROID_MEDIA_PLAYERRECORD_H__
#define _ELASTOS_DROID_MEDIA_PLAYERRECORD_H__

#include "Elastos.Droid.App.h"
#include "Elastos.Droid.Media.h"
#include "Elastos.Droid.Content.h"
#include "Elastos.Droid.Os.h"
#include <Elastos.CoreLibrary.IO.h>
#include "elastos/droid/ext/frameworkext.h"
#include <elastos/core/Object.h>

using Elastos::Droid::App::IPendingIntent;
using Elastos::Droid::App::IPendingIntentOnFinished;
using Elastos::Droid::Content::IComponentName;
using Elastos::Droid::Os::IBinder;
using Elastos::IO::IPrintWriter;

namespace Elastos{
namespace Droid {
namespace Media {
/**
 * @hide
 * Class to handle all the information about a media player, encapsulating information
 * about its use RemoteControlClient, playback type and volume... The lifecycle of each
 * instance is managed by android.media.MediaFocusControl, from its addition to the player stack
 * stack to its release.
 */
class PlayerRecord
    : public Object
    , public IPlayerRecord
    , public IProxyDeathRecipient
{
public:
    class RccPlaybackState
        : public Object
        , public IPlayerRecordRccPlaybackState
    {
    public:
        RccPlaybackState();

        virtual ~RccPlaybackState();

        CAR_INTERFACE_DECL()

        CARAPI constructor(
            /* [in] */ Int32 state,
            /* [in] */ Int64 positionMs,
            /* [in] */ Float speed);

        CARAPI Reset();

        CARAPI ToString(
            /* [out] */ String* result);

    private:
        CARAPI_(String) PosToString();

        CARAPI_(String) StateToString();

    public:
        Int32 mState;
        Int64 mPositionMs;
        Float mSpeed;
    };

    class RemotePlaybackState
        : public Object
        , public IPlayerRecordRemotePlaybackState
    {
    public:
        RemotePlaybackState();

        virtual ~RemotePlaybackState();

        CAR_INTERFACE_DECL()

        CARAPI constructor(
            /* [in] */ Int32 id,
            /* [in] */ Int32 vol,
            /* [in] */ Int32 volMax);
    public:
        Int32 mRccId;
        Int32 mVolume;
        Int32 mVolumeMax;
        Int32 mVolumeHandling;
    };

private:
    class RcClientDeathHandler
        : public Object
        , public IProxyDeathRecipient
    {
        friend class PlayerRecord;
    public:
        RcClientDeathHandler(
            /* [in] */ PlayerRecord* host,
            /* [in] */ IBinder* cb,
            /* [in] */ IPendingIntent* pi);

        ~RcClientDeathHandler();

        CAR_INTERFACE_DECL()



        CARAPI BinderDied();

        CARAPI GetBinder(
            /* [out] */ IBinder** result);

        CARAPI ProxyDied();

    private:
        AutoPtr<IBinder> mCb;
        AutoPtr<IPendingIntent> mMediaIntent;
        PlayerRecord* mHost;
    };

public:
    PlayerRecord();

    virtual ~PlayerRecord();

    CAR_INTERFACE_DECL()

    CARAPI Dump(
        /* [in] */ IPrintWriter* pw,
        /* [in] */ Boolean registrationInfo);

    CARAPI ResetPlaybackInfo();

    CARAPI UnlinkToRcClientDeath();

    CARAPI Destroy();

    CARAPI ProxyDied();

    CARAPI GetRcc(
        /* [out] */ IIRemoteControlClient** result);

    static CARAPI SetMediaFocusControl(
        /* [in] */ IMediaFocusControl* mfc);

    CARAPI constructor(
        /* [in] */ IPendingIntent* mediaIntent,
        /* [in] */ IComponentName* eventReceiver,
        /* [in] */ IBinder* token);

    CARAPI GetRccId(
        /* [out] */ Int32* result);

    CARAPI GetMediaButtonReceiver(
        /* [out] */ IComponentName** result);

    CARAPI GetMediaButtonIntent(
        /* [out] */ IPendingIntent** result);

    CARAPI HasMatchingMediaButtonIntent(
        /* [in] */ IPendingIntent* pi,
        /* [out] */ Boolean* result);

    CARAPI IsPlaybackActive(
        /* [out] */ Boolean* result);

    CARAPI ResetControllerInfoForRcc(
        /* [in] */ IIRemoteControlClient* rcClient,
        /* [in] */ const String& callingPackageName,
        /* [in] */ Int32 uid);

    CARAPI ResetControllerInfoForNoRcc();

    CARAPI Finalize();

public:
    static AutoPtr<IMediaFocusControl> sController; //MediaFocusControl
    /**
     * Information only used for non-local playback
     */
    //FIXME private?
    Int32 mPlaybackType;
    Int32 mPlaybackVolume;
    Int32 mPlaybackVolumeMax;
    Int32 mPlaybackVolumeHandling;
    Int32 mPlaybackStream;
    AutoPtr<IPlayerRecordRccPlaybackState> mPlaybackState;
    AutoPtr<IIRemoteVolumeObserver> mRemoteVolumeObs;

private:
    // on purpose not using this classe's name, as it will only be used from MediaFocusControl
    static const String TAG;
    static const Boolean DEBUG;

    /**
     * A global counter for RemoteControlClient identifiers
     */
    static Int32 sLastRccId;

    /**
     * The target for the ACTION_MEDIA_BUTTON events.
     * Always non null. //FIXME verify
     */
    AutoPtr<IPendingIntent> mMediaIntent;
    /**
     * The registered media button event receiver.
     */
    AutoPtr<IComponentName> mReceiverComponent;

    Int32 mRccId;

    /**
     * A non-null token implies this record tracks a "live" player whose death is being monitored.
     */
    AutoPtr<IBinder> mToken;
    String mCallingPackageName;
    Int32 mCallingUid;
    /**
     * Provides access to the information to display on the remote control.
     * May be null (when a media button event receiver is registered,
     *     but no remote control client has been registered) */
    AutoPtr<IIRemoteControlClient> mRcClient;
    AutoPtr<RcClientDeathHandler> mRcClientDeathHandler;
};

} // namespace Elastos
} // namespace Droid
} // namespace Media

#endif // _ELASTOS_DROID_MEDIA_PLAYERRECORD_H__
