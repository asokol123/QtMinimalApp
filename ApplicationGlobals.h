#ifndef APPLICATIONGLOBALS_H
#define APPLICATIONGLOBALS_H
//---------------------------------------------------------------------------
// Include
//---------------------------------------------------------------------------

#include "Qt/MainWindow.h"
//---------------------------------------------------------------------------

namespace NSApplication {
//---------------------------------------------------------------------------
// CApplicationGlobals Declaration
//---------------------------------------------------------------------------
// A part of Application object
// Its purpose is to initialize all application global resources
// for example, timers, loggers, fileWriters etc.
//
// If you need a specific order in creation of the global resources
// please control them by dividing the class in to a sequence of
// inherited classes
// for example, if we need a timer to be initialized first and
// there is no specific order in initialization of other resources
// we may create a sequence like this:
// class CApplicationMainTimer : protected NSQt::CMainWindow {...};
// class CApplicationGlobals : protected CApplicationMainTimer {...};
// Then we instantiate the tiler in CApplicationMainTimer and
// all other resources are initialized in CApplicationGlobals
//---------------------------------------------------------------------------

class CApplicationGlobals : protected NSQt::CMainWindow {
  using CBase = NSQt::CMainWindow;
public:
  CApplicationGlobals();
};
//---------------------------------------------------------------------------
} // NSApplication
//---------------------------------------------------------------------------
#endif // APPLICATIONGLOBALS_H
