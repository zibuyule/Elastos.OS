elog("====PagerAdapter.js====begin====");

module.exports = function(aoElastos, aoActivity){
//--------common definition----begin----
    var CObject = aoElastos.CObject;

    var CString = aoElastos.Core.CString;
    var Droid_New = aoElastos.Droid.New;
    var Core_New = aoElastos.Core.New;

    var R = aoElastos.Application.R;

    var oActivity = aoActivity.ActivityInstance;
    var oHandler = aoActivity.ActivityHandler;

    var IView__VISIBLE = 0x00000000;

//--------common definition----end----

//--------.java----begin----

// /*
//  * Copyright (C) 2011 The Android Open Source Project
//  *
//  * Licensed under the Apache License, Version 2.0 (the "License");
//  * you may not use this file except in compliance with the License.
//  * You may obtain a copy of the License at
//  *
//  *      http://www.apache.org/licenses/LICENSE-2.0
//  *
//  * Unless required by applicable law or agreed to in writing, software
//  * distributed under the License is distributed on an "AS IS" BASIS,
//  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//  * See the License for the specific language governing permissions and
//  * limitations under the License.
//  */

// package android.support.v4.view;

// import android.database.DataSetObservable;
    class DataSetObservable {
        constructor(){
            elog("====DataSetObservable::constructor====TODO====");
            var oRet = Droid_New("Elastos.Droid.Database.CDataSetObservable");
            //Assert(0);
            return oRet;
        }

        // GetCallbackInterfaceInfo(result) {
        //     elog("====DataSetObservable::GetCallbackInterfaceInfo====begin====");
        //     var oMuduleInfo = aoElastos.Droid.Get();
        //     elog("====DataSetObservable::GetCallbackInterfaceInfo====0====");
        //     var oInterfaceInfo = oMuduleInfo.GetInterfaceInfo("Elastos.Droid.Database.IDataSetObserver");
        //     elog("====DataSetObservable::GetCallbackInterfaceInfo====1====");
        //     var oRet = oInterfaceInfo.GetInternalObject();
        //     elog("====DataSetObservable::GetCallbackInterfaceInfo====2====");
        //     result.data = oRet;
        //     elog("====DataSetObservable::GetCallbackInterfaceInfo====end====");
        // }


    }
// import android.database.DataSetObserver;
    //class DataSetObserver {}
// import android.os.Parcelable;
    class Parcelable {}
// import android.view.View;
    class View {}
// import android.view.ViewGroup;
    class ViewGroup {}

// /**
//  * Base class providing the adapter to populate pages inside of
//  * a {@link ViewPager}.  You will most likely want to use a more
//  * specific implementation of this, such as
//  * {@link android.support.v4.app.FragmentPagerAdapter} or
//  * {@link android.support.v4.app.FragmentStatePagerAdapter}.
//  *
//  * <p>When you implement a PagerAdapter, you must override the following methods
//  * at minimum:</p>
//  * <ul>
//  * <li>{@link #instantiateItem(ViewGroup, int)}</li>
//  * <li>{@link #destroyItem(ViewGroup, int, Object)}</li>
//  * <li>{@link #getCount()}</li>
//  * <li>{@link #isViewFromObject(View, Object)}</li>
//  * </ul>
//  *
//  * <p>PagerAdapter is more general than the adapters used for
//  * {@link android.widget.AdapterView AdapterViews}. Instead of providing a
//  * View recycling mechanism directly ViewPager uses callbacks to indicate the
//  * steps taken during an update. A PagerAdapter may implement a form of View
//  * recycling if desired or use a more sophisticated method of managing page
//  * Views such as Fragment transactions where each page is represented by its
//  * own Fragment.</p>
//  *
//  * <p>ViewPager associates each page with a key Object instead of working with
//  * Views directly. This key is used to track and uniquely identify a given page
//  * independent of its position in the adapter. A call to the PagerAdapter method
//  * {@link #startUpdate(ViewGroup)} indicates that the contents of the ViewPager
//  * are about to change. One or more calls to {@link #instantiateItem(ViewGroup, int)}
//  * and/or {@link #destroyItem(ViewGroup, int, Object)} will follow, and the end
//  * of an update will be signaled by a call to {@link #finishUpdate(ViewGroup)}.
//  * By the time {@link #finishUpdate(ViewGroup) finishUpdate} returns the views
//  * associated with the key objects returned by
//  * {@link #instantiateItem(ViewGroup, int) instantiateItem} should be added to
//  * the parent ViewGroup passed to these methods and the views associated with
//  * the keys passed to {@link #destroyItem(ViewGroup, int, Object) destroyItem}
//  * should be removed. The method {@link #isViewFromObject(View, Object)} identifies
//  * whether a page View is associated with a given key object.</p>
//  *
//  * <p>A very simple PagerAdapter may choose to use the page Views themselves
//  * as key objects, returning them from {@link #instantiateItem(ViewGroup, int)}
//  * after creation and adding them to the parent ViewGroup. A matching
//  * {@link #destroyItem(ViewGroup, int, Object)} implementation would remove the
//  * View from the parent ViewGroup and {@link #isViewFromObject(View, Object)}
//  * could be implemented as <code>return view == object;</code>.</p>
//  *
//  * <p>PagerAdapter supports data set changes. Data set changes must occur on the
//  * main thread and must end with a call to {@link #notifyDataSetChanged()} similar
//  * to AdapterView adapters derived from {@link android.widget.BaseAdapter}. A data
//  * set change may involve pages being added, removed, or changing position. The
//  * ViewPager will keep the current page active provided the adapter implements
//  * the method {@link #getItemPosition(Object)}.</p>
//  */
// public abstract class PagerAdapter {
class PagerAdapter {
    constructor() {
        elog("====PagerAdapter::constructor====begin====");
    }

//     private DataSetObservable mObservable = new DataSetObservable();
    get mObservable() {
        if (this._mObservable) return this._mObservable;
        this._mObservable = new DataSetObservable();
        return this._mObservable;
    }

//     public static final int POSITION_UNCHANGED = -1;
    static get POSITION_UNCHANGED() {return -1;}

//     public static final int POSITION_NONE = -2;
    static get POSITION_NONE() {return -2;}

//     /**
//      * Return the number of views available.
//      */
//     public abstract int getCount();
    GetCount(){
        elog("====PagerAdapter::GetCount====TODO====");
        ss.tt();Assert(0);
        return 0;
    };

//     /**
//      * Called when a change in the shown pages is going to start being made.
//      * @param container The containing View which is displaying this adapter's
//      * page views.
//      */
//     public void startUpdate(ViewGroup container) {
//         startUpdate((View) container);
//     }
    StartUpdate(container) {
        startUpdate(container);
    }

//     /**
//      * Create the page for the given position.  The adapter is responsible
//      * for adding the view to the container given here, although it only
//      * must ensure this is done by the time it returns from
//      * {@link #finishUpdate(ViewGroup)}.
//      *
//      * @param container The containing View in which the page will be shown.
//      * @param position The page position to be instantiated.
//      * @return Returns an Object representing the new page.  This does not
//      * need to be a View, but can be some other container of the page.
//      */
//     public Object instantiateItem(ViewGroup container, int position) {
//         return instantiateItem((View) container, position);
//     }
    InstantiateItem(container, position) {
        return instantiateItem(container, position);
    }

//     /**
//      * Remove a page for the given position.  The adapter is responsible
//      * for removing the view from its container, although it only must ensure
//      * this is done by the time it returns from {@link #finishUpdate(ViewGroup)}.
//      *
//      * @param container The containing View from which the page will be removed.
//      * @param position The page position to be removed.
//      * @param object The same object that was returned by
//      * {@link #instantiateItem(View, int)}.
//      */
//     public void destroyItem(ViewGroup container, int position, Object object) {
//         destroyItem((View) container, position, object);
//     }
    DestroyItem(container, position, object) {
        destroyItem(container, position, object);
    }

//     /**
//      * Called to inform the adapter of which item is currently considered to
//      * be the "primary", that is the one show to the user as the current page.
//      *
//      * @param container The containing View from which the page will be removed.
//      * @param position The page position that is now the primary.
//      * @param object The same object that was returned by
//      * {@link #instantiateItem(View, int)}.
//      */
//     public void setPrimaryItem(ViewGroup container, int position, Object object) {
//         setPrimaryItem((View) container, position, object);
//     }
    SetPrimaryItem(container, position, object) {
        setPrimaryItem(container, position, object);
    }

//     /**
//      * Called when the a change in the shown pages has been completed.  At this
//      * point you must ensure that all of the pages have actually been added or
//      * removed from the container as appropriate.
//      * @param container The containing View which is displaying this adapter's
//      * page views.
//      */
//     public void finishUpdate(ViewGroup container) {
//         finishUpdate((View) container);
//     }
    FinishUpdate(container) {
        finishUpdate(container);
    }

//     /**
//      * Called when a change in the shown pages is going to start being made.
//      * @param container The containing View which is displaying this adapter's
//      * page views.
//      *
//      * @deprecated Use {@link #startUpdate(ViewGroup)}
//      */
//     public void startUpdate(View container) {
//     }
    StartUpdate(container) {
        elog("====PagerAdapter::StartUpdate====begin====");
    }

//     /**
//      * Create the page for the given position.  The adapter is responsible
//      * for adding the view to the container given here, although it only
//      * must ensure this is done by the time it returns from
//      * {@link #finishUpdate(ViewGroup)}.
//      *
//      * @param container The containing View in which the page will be shown.
//      * @param position The page position to be instantiated.
//      * @return Returns an Object representing the new page.  This does not
//      * need to be a View, but can be some other container of the page.
//      *
//      * @deprecated Use {@link #instantiateItem(ViewGroup, int)}
//      */
//     public Object instantiateItem(View container, int position) {
//         throw new UnsupportedOperationException(
//                 "Required method instantiateItem was not overridden");
//     }
    InstantiateItem(container, position) {
        throw new UnsupportedOperationException(
                "Required method instantiateItem was not overridden");
    }

//     /**
//      * Remove a page for the given position.  The adapter is responsible
//      * for removing the view from its container, although it only must ensure
//      * this is done by the time it returns from {@link #finishUpdate(View)}.
//      *
//      * @param container The containing View from which the page will be removed.
//      * @param position The page position to be removed.
//      * @param object The same object that was returned by
//      * {@link #instantiateItem(View, int)}.
//      *
//      * @deprecated Use {@link #destroyItem(ViewGroup, int, Object)}
//      */
//     public void destroyItem(View container, int position, Object object) {
//         throw new UnsupportedOperationException("Required method destroyItem was not overridden");
//     }
    DestroyItem(container, position, object) {
        throw new UnsupportedOperationException("Required method destroyItem was not overridden");
    }

//     /**
//      * Called to inform the adapter of which item is currently considered to
//      * be the "primary", that is the one show to the user as the current page.
//      *
//      * @param container The containing View from which the page will be removed.
//      * @param position The page position that is now the primary.
//      * @param object The same object that was returned by
//      * {@link #instantiateItem(View, int)}.
//      *
//      * @deprecated Use {@link #setPrimaryItem(ViewGroup, int, Object)}
//      */
//     public void setPrimaryItem(View container, int position, Object object) {
//     }
    SetPrimaryItem(container, position, object) {
        elog("====PagerAdapter::SetPrimaryItem====TODO====");
    }

//     /**
//      * Called when the a change in the shown pages has been completed.  At this
//      * point you must ensure that all of the pages have actually been added or
//      * removed from the container as appropriate.
//      * @param container The containing View which is displaying this adapter's
//      * page views.
//      *
//      * @deprecated Use {@link #finishUpdate(ViewGroup)}
//      */
//     public void finishUpdate(View container) {
//     }
    FinishUpdate(container) {
        elog("====PagerAdapter::FinishUpdate====TODO====");
    }

//     /**
//      * Determines whether a page View is associated with a specific key object
//      * as returned by {@link #instantiateItem(ViewGroup, int)}. This method is
//      * required for a PagerAdapter to function properly.
//      *
//      * @param view Page View to check for association with <code>object</code>
//      * @param object Object to check for association with <code>view</code>
//      * @return true if <code>view</code> is associated with the key object <code>object</code>
//      */
//     public abstract boolean isViewFromObject(View view, Object object);
    IsViewFromObject(view, object){
        elog("====PagerAdapter::IsViewFromObject====TODO====");
        Assert(0);
    }

//     /**
//      * Save any instance state associated with this adapter and its pages that should be
//      * restored if the current UI state needs to be reconstructed.
//      *
//      * @return Saved state for this adapter
//      */
//     public Parcelable
//         return null;
//     }
    SaveState() {
        return null;
    }

//     /**
//      * Restore any instance state associated with this adapter and its pages
//      * that was previously saved by {@link #saveState()}.
//      *
//      * @param state State previously saved by a call to {@link #saveState()}
//      * @param loader A ClassLoader that should be used to instantiate any restored objects
//      */
//     public void restoreState(Parcelable state, ClassLoader loader) {
//     }
    RestoreState(state, loader) {
        elog("====PagerAdapter::RestoreState====TODO====");
    }

//     /**
//      * Called when the host view is attempting to determine if an item's position
//      * has changed. Returns {@link #POSITION_UNCHANGED} if the position of the given
//      * item has not changed or {@link #POSITION_NONE} if the item is no longer present
//      * in the adapter.
//      *
//      * <p>The default implementation assumes that items will never
//      * change position and always returns {@link #POSITION_UNCHANGED}.
//      *
//      * @param object Object representing an item, previously returned by a call to
//      *               {@link #instantiateItem(View, int)}.
//      * @return object's new position index from [0, {@link #getCount()}),
//      *         {@link #POSITION_UNCHANGED} if the object's position has not changed,
//      *         or {@link #POSITION_NONE} if the item is no longer present.
//      */
//     public int getItemPosition(Object object) {
//         return POSITION_UNCHANGED;
//     }
    GetItemPosition(object) {
        return POSITION_UNCHANGED;
    }

//     /**
//      * This method should be called by the application if the data backing this adapter has changed
//      * and associated views should update.
//      */
//     public void notifyDataSetChanged() {
//         mObservable.notifyChanged();
//     }
    NotifyDataSetChanged() {
        elog("====PagerAdapter::NotifyDataSetChanged====begin====");
        this.mObservable.NotifyChanged();
        elog("====PagerAdapter::NotifyDataSetChanged====end====");
    }

//     /**
//      * Register an observer to receive callbacks related to the adapter's data changing.
//      *
//      * @param observer The {@link android.database.DataSetObserver} which will receive callbacks.
//      */
//     public void registerDataSetObserver(DataSetObserver observer) {
//         mObservable.registerObserver(observer);
//     }
    RegisterDataSetObserver(observer) {
        elog("====PagerAdapter::RegisterDataSetObserver====begin====");

        //var ss = CObject.getObjectMethodProtos(this.mObservable, "RegisterObserver");
        //elog("====PROTO:"+ss);

        this.mObservable.RegisterObserver(observer);
        elog("====PagerAdapter::RegisterDataSetObserver====end====");
    }

//     /**
//      * Unregister an observer from callbacks related to the adapter's data changing.
//      *
//      * @param observer The {@link android.database.DataSetObserver} which will be unregistered.
//      */
//     public void unregisterDataSetObserver(DataSetObserver observer) {
//         mObservable.unregisterObserver(observer);
//     }
    UnregisterDataSetObserver(observer) {
        this.mObservable.UnregisterObserver(observer);
    }

//     /**
//      * This method may be called by the ViewPager to obtain a title string
//      * to describe the specified page. This method may return null
//      * indicating no title for this page. The default implementation returns
//      * null.
//      *
//      * @param position The position of the title requested
//      * @return A title for the requested page
//      */
//     public CharSequence getPageTitle(int position) {
//         return null;
//     }
    GetPageTitle(position) {
        return null;
    }

//     /**
//      * Returns the proportional width of a given page as a percentage of the
//      * ViewPager's measured width from (0.f-1.f]
//      *
//      * @param position The position of the page requested
//      * @return Proportional width for the given page position
//      */
//     public float getPageWidth(int position) {
//         return 1.f;
//     }
    GetPageWidth(position) {
        return 1.0;
    }

}   //class PagerAdapter
//--------.java----end----

    return PagerAdapter;
};  //module.exports

elog("====PagerAdapter.js====end====");