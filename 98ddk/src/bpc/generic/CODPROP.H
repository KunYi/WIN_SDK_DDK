//==========================================================================;
//
//  THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY
//  KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
//  IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR
//  PURPOSE.
//
//  Copyright (c) 1992 - 1998  Microsoft Corporation.  All Rights Reserved.
//
//==========================================================================;

// ------------------------------------------------------------------------
// Property set for the TVTuner
// ------------------------------------------------------------------------

DEFINE_KSPROPERTY_TABLE(DefaultCodecProperties)
{
    DEFINE_KSPROPERTY_ITEM
    (
        KSPROPERTY_VBICODECFILTERING_SCANLINES_REQUESTED_BIT_ARRAY,
        TRUE,                                   // GetSupported or Handler
        sizeof(VBICODECFILTERING_SCANLINES),    // MinProperty
        sizeof(VBICODECFILTERING_SCANLINES),    // MinData
        TRUE,                                   // SetSupported or Handler
        NULL,                                   // Values
        0,                                      // RelationsCount
        NULL,                                   // Relations
        NULL,                                   // SupportHandler
        sizeof(VBICODECFILTERING_SCANLINES)                           // SerializedSize
    ),
    DEFINE_KSPROPERTY_ITEM
    (
        KSPROPERTY_VBICODECFILTERING_SCANLINES_DISCOVERED_BIT_ARRAY,
        TRUE,                                   // GetSupported or Handler
        sizeof(VBICODECFILTERING_SCANLINES),    // MinProperty
        sizeof(VBICODECFILTERING_SCANLINES),    // MinData
        FALSE,                                  // SetSupported or Handler
        NULL,                                   // Values
        0,                                      // RelationsCount
        NULL,                                   // Relations
        NULL,                                   // SupportHandler
        sizeof(VBICODECFILTERING_SCANLINES)     // SerializedSize
    ),
    DEFINE_KSPROPERTY_ITEM
    (
        KSPROPERTY_VBICODECFILTERING_SUBSTREAMS_REQUESTED_BIT_ARRAY,
        TRUE,                                   // GetSupported or Handler
        sizeof(VBICODECFILTERING_NABTS_SUBSTREAMS),// MinProperty
        sizeof(VBICODECFILTERING_NABTS_SUBSTREAMS),// MinData
        TRUE,                                   // SetSupported or Handler
        NULL,                                   // Values
        0,                                      // RelationsCount
        NULL,                                   // Relations
        NULL,                                   // SupportHandler
        sizeof(VBICODECFILTERING_NABTS_SUBSTREAMS) // SerializedSize
    ),
    DEFINE_KSPROPERTY_ITEM
    (
        KSPROPERTY_VBICODECFILTERING_SUBSTREAMS_DISCOVERED_BIT_ARRAY,
        TRUE,                                   // GetSupported or Handler
        sizeof(VBICODECFILTERING_NABTS_SUBSTREAMS),// MinProperty
        sizeof(VBICODECFILTERING_NABTS_SUBSTREAMS),// MinData
        FALSE,                                  // SetSupported or Handler
        NULL,                                   // Values
        0,                                      // RelationsCount
        NULL,                                   // Relations
        NULL,                                   // SupportHandler
        sizeof(VBICODECFILTERING_NABTS_SUBSTREAMS)// SerializedSize
    ),
};



// ------------------------------------------------------------------------
// Array of all of the property sets supported by the codec
// ------------------------------------------------------------------------

DEFINE_KSPROPERTY_SET_TABLE(CodecPropertyTable)
{
    DEFINE_KSPROPERTY_SET
    ( 
        &KSPROPSETID_VBICodecFiltering,
        SIZEOF_ARRAY(DefaultCodecProperties),
        DefaultCodecProperties,
        0, 
        NULL,
    ),
};

#define NUMBER_OF_CODEC_PROPERTY_SETS (SIZEOF_ARRAY (CodecPropertyTable))

