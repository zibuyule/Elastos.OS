#ifndef __ELASTOS_DROID_GOOGLE_MMS_PDU_ENCODEDSTRINGVALUE_H__
#define __ELASTOS_DROID_GOOGLE_MMS_PDU_ENCODEDSTRINGVALUE_H__

#include "elastos/droid/ext/frameworkext.h"
#include "elastos/core/Object.h"

// package com.google.android.mms.pdu;
// import android.util.Log;
// import java.io.ByteArrayOutputStream;
// import java.io.IOException;
// import java.io.UnsupportedEncodingException;
// import java.util.ArrayList;

namespace Elastos {
namespace Droid {
namespace Google {
namespace Mms {
namespace Pdu {

/**
  * Encoded-string-value = Text-string | Value-length Char-set Text-string
  */
class EncodedStringValue
    : public Object
    , public IEncodedStringValue
    , public ICloneable
{
public:
    CAR_INTERFACE_DECL();

    /**
      * Constructor.
      *
      * @param charset the Char-set value
      * @param data the Text-string value
      * @throws NullPointerException if Text-string value is null.
      */
    EncodedStringValue(
        /* [in] */ Int32 charset,
        /* [in] */ ArrayOf<Byte>* data);

    /**
      * Constructor.
      *
      * @param data the Text-string value
      * @throws NullPointerException if Text-string value is null.
      */
    EncodedStringValue(
        /* [in] */ ArrayOf<Byte>* data);

    EncodedStringValue(
        /* [in] */ const String& data);

    /**
      * Get Char-set value.
      *
      * @return the value
      */
    virtual CARAPI GetCharacterSet(
        /* [out] */ Int32* result);

    /**
      * Set Char-set value.
      *
      * @param charset the Char-set value
      */
    virtual CARAPI SetCharacterSet(
        /* [in] */ Int32 charset);

    /**
      * Get Text-string value.
      *
      * @return the value
      */
    virtual CARAPI GetTextString(
        /* [out] */ ArrayOf<Byte>** result);

    /**
      * Set Text-string value.
      *
      * @param textString the Text-string value
      * @throws NullPointerException if Text-string value is null.
      */
    virtual CARAPI SetTextString(
        /* [in] */ ArrayOf<Byte>* textString);

    /**
      * Convert this object to a {@link java.lang.String}. If the encoding of
      * the EncodedStringValue is null or unsupported, it will be
      * treated as iso-8859-1 encoding.
      *
      * @return The decoded String.
      */
    virtual CARAPI GetString(
        /* [out] */ String* result);

    /**
      * Append to Text-string.
      *
      * @param textString the textString to append
      * @throws NullPointerException if the text String is null
      *                      or an IOException occured.
      */
    virtual CARAPI AppendTextString(
        /* [in] */ ArrayOf<Byte>* textString);

    /*
      * (non-Javadoc)
      * @see java.lang.Object#clone()
      */
    // @Override
    CARAPI_(AutoPtr<Object>) Clone();

    /**
      * Split this encoded string around matches of the given pattern.
      *
      * @param pattern the delimiting pattern
      * @return the array of encoded strings computed by splitting this encoded
      *         string around matches of the given pattern
      */
    virtual CARAPI Split(
        /* [in] */ const String& pattern,
        /* [out] */ ArrayOf<EncodedStringValue*>** result);

    /**
      * Extract an EncodedStringValue[] from a given String.
      */
    static CARAPI_(AutoPtr<ArrayOf<EncodedStringValue*> >) Extract(
        /* [in] */ const String& src);

    /**
      * Concatenate an EncodedStringValue[] into a single String.
      */
    static CARAPI_(String) Concat(
        /* [in] */ ArrayOf<EncodedStringValue*>* addr);

    static CARAPI_(AutoPtr<EncodedStringValue>) Copy(
        /* [in] */ EncodedStringValue* value);

    static CARAPI_(AutoPtr<ArrayOf<EncodedStringValue*> >) EncodeStrings(
        /* [in] */ ArrayOf<String>* array);

private:
    static const String TAG;
    static const Boolean DEBUG;
    static const Boolean LOCAL_LOGV;
    /**
      * The Char-set value.
      */
    Int32 mCharacterSet;
    /**
      * The Text-string value.
      */
    AutoPtr<ArrayOf<Byte> > mData;
};

} // namespace Pdu
} // namespace Mms
} // namespace Google
} // namespace Droid
} // namespace Elastos

#endif // __ELASTOS_DROID_GOOGLE_MMS_PDU_ENCODEDSTRINGVALUE_H__
