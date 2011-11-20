# Microsoft Developer Studio Generated NMAKE File, Based on gfighter.dsp
!IF "$(CFG)" == ""
CFG=gfighter - Win32 Debug
!MESSAGE No configuration specified. Defaulting to gfighter - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "gfighter - Win32 Release" && "$(CFG)" != "gfighter - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "gfighter.mak" CFG="gfighter - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "gfighter - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "gfighter - Win32 Debug" (based on "Win32 (x86) Console Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "gfighter - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\gfighter.exe"


CLEAN :
	-@erase "$(INTDIR)\gfighter.obj"
	-@erase "$(INTDIR)\GFLevel.obj"
	-@erase "$(INTDIR)\GFLevLayer.obj"
	-@erase "$(INTDIR)\GFSprite.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\gfighter.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /D "WIN32_VOLATILE" /D "__CRYSTAL_SPACE__" /D "CS_RELEASE" /Fp"$(INTDIR)\gfighter.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\gfighter.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=libcssys.lib libcsutil.lib libcsgeom.lib libcsgfx.lib libcstool.lib libcsws.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /incremental:no /pdb:"$(OUTDIR)\gfighter.pdb" /machine:I386 /out:"$(OUTDIR)\gfighter.exe" 
LINK32_OBJS= \
	"$(INTDIR)\gfighter.obj" \
	"$(INTDIR)\GFLevel.obj" \
	"$(INTDIR)\GFSprite.obj" \
	"$(INTDIR)\GFLevLayer.obj"

"$(OUTDIR)\gfighter.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "gfighter - Win32 Debug"

OUTDIR=.\gfighter___Win32_Debug
INTDIR=.\gfighter___Win32_Debug
# Begin Custom Macros
OutDir=.\gfighter___Win32_Debug
# End Custom Macros

ALL : ".\bin\gfighter.exe" "$(OUTDIR)\gfighter.bsc"


CLEAN :
	-@erase "$(INTDIR)\gfighter.obj"
	-@erase "$(INTDIR)\gfighter.sbr"
	-@erase "$(INTDIR)\GFLevel.obj"
	-@erase "$(INTDIR)\GFLevel.sbr"
	-@erase "$(INTDIR)\GFLevLayer.obj"
	-@erase "$(INTDIR)\GFLevLayer.sbr"
	-@erase "$(INTDIR)\GFSprite.obj"
	-@erase "$(INTDIR)\GFSprite.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\gfighter.bsc"
	-@erase "$(OUTDIR)\gfighter.map"
	-@erase "$(OUTDIR)\gfighter.pdb"
	-@erase ".\bin\gfighter.exe"
	-@erase ".\bin\gfighter.ilk"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MD /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /D "WIN32_VOLATILE" /D "__CRYSTAL_SPACE__" /D "CS_DEBUG" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\gfighter.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\gfighter.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\gfighter.sbr" \
	"$(INTDIR)\GFLevel.sbr" \
	"$(INTDIR)\GFSprite.sbr" \
	"$(INTDIR)\GFLevLayer.sbr"

"$(OUTDIR)\gfighter.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=libcssys_d.lib libcsutil_d.lib libcsgeom_d.lib libcsgfx_d.lib libcstool_d.lib libcsws_d.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /incremental:yes /pdb:"$(OUTDIR)\gfighter.pdb" /map:"$(INTDIR)\gfighter.map" /debug /machine:I386 /out:"bin/gfighter.exe" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\gfighter.obj" \
	"$(INTDIR)\GFLevel.obj" \
	"$(INTDIR)\GFSprite.obj" \
	"$(INTDIR)\GFLevLayer.obj"

".\bin\gfighter.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("gfighter.dep")
!INCLUDE "gfighter.dep"
!ELSE 
!MESSAGE Warning: cannot find "gfighter.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "gfighter - Win32 Release" || "$(CFG)" == "gfighter - Win32 Debug"
SOURCE=.\src\gfighter.cpp

!IF  "$(CFG)" == "gfighter - Win32 Release"


"$(INTDIR)\gfighter.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "gfighter - Win32 Debug"


"$(INTDIR)\gfighter.obj"	"$(INTDIR)\gfighter.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=.\src\GFLevel.cpp

!IF  "$(CFG)" == "gfighter - Win32 Release"


"$(INTDIR)\GFLevel.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "gfighter - Win32 Debug"


"$(INTDIR)\GFLevel.obj"	"$(INTDIR)\GFLevel.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=.\src\GFLevLayer.cpp

!IF  "$(CFG)" == "gfighter - Win32 Release"


"$(INTDIR)\GFLevLayer.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "gfighter - Win32 Debug"


"$(INTDIR)\GFLevLayer.obj"	"$(INTDIR)\GFLevLayer.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=.\src\GFSprite.cpp

!IF  "$(CFG)" == "gfighter - Win32 Release"


"$(INTDIR)\GFSprite.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "gfighter - Win32 Debug"


"$(INTDIR)\GFSprite.obj"	"$(INTDIR)\GFSprite.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 


!ENDIF 

