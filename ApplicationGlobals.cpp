﻿//---------------------------------------------------------------------------
// Include
//---------------------------------------------------------------------------

#include "ApplicationGlobals.h"
//---------------------------------------------------------------------------

namespace NSApplication {
//---------------------------------------------------------------------------
// CApplicationGlobals Definition
//---------------------------------------------------------------------------

CApplicationGlobals::CApplicationGlobals()
    : X11Keylogger(new CX11Keylogger)
{
}

//---------------------------------------------------------------------------
} // NSApplication
//---------------------------------------------------------------------------
