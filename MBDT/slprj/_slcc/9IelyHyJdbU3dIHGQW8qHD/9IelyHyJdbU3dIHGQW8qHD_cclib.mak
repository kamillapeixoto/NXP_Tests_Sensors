#------------------------ Tool Specifications & Options ----------------------

COMPILER  =  lcc

CC        =  "C:\Program Files\MATLAB\R2022b\sys\lcc64\lcc64\bin\lcc64.exe"
LD        =  "C:\Program Files\MATLAB\R2022b\sys\lcc64\lcc64\bin\lcclnk64.exe"
LIBCMD    =  "C:\Program Files\MATLAB\R2022b\sys\lcc64\lcc64\bin\lcclib64.exe"
CFLAGS    =  -dll -noregistrylookup  -c -Zp8 -DLCC_WIN64 -DMATLAB_MEX_FILE -nodeclspec
LDFLAGS   =  -s -dll -entry LibMain 9IelyHyJdbU3dIHGQW8qHD_cclib.def -L"C:\Program Files\MATLAB\R2022b\sys\lcc64\lcc64\lib64"

OBJECTS = \
	   bmp3.obj \
	   slcc_interface_9IelyHyJdbU3dIHGQW8qHD.obj \
	   lccstub.obj \

STATICLIBS = \

#------------------------------ Include/Lib Path ------------------------------

INCLUDE_PATH = \
     -I"c:\program files\matlab\r2022b\extern\include" \
     -I"c:\program files\matlab\r2022b\simulink\include" \
     -I"c:\users\kamil\onedrive\documents\github\nxp_tests_scaleo\slprj\_slcc\9ielyhyjdbu3dihgqw8qhd" \
     -I"c:\users\kamil\onedrive\documents\github\nxp_tests_scaleo\testt c function" \
     -I"c:\users\kamil\onedrive\documents\github\nxp_tests_scaleo" \
     -I"c:\program files\matlab\r2022b\sys\lcc64\lcc64\include64" \
     -I"c:\program files\matlab\r2022b\sys\lcc64\lcc64\mex" \

#--------------------------------- Rules --------------------------------------

9IelyHyJdbU3dIHGQW8qHD_cclib.dll : $(MAKEFILE) $(OBJECTS)
	$(LD) $(LDFLAGS) /OUT:9IelyHyJdbU3dIHGQW8qHD_cclib.dll $(OBJECTS)  $(STATICLIBS) "C:\Program Files\MATLAB\R2022b\extern\lib\win64\microsoft\libmex.lib" "C:\Program Files\MATLAB\R2022b\extern\lib\win64\microsoft\libmx.lib"
bmp3.obj :	c:\users\kamil\onedrive\DOCUME~1\github\NXP_TE~1\TESTTC~1\bmp3.c
	$(CC) $(CFLAGS) $(INCLUDE_PATH) "c:\users\kamil\onedrive\documents\github\nxp_tests_scaleo\testt c function\bmp3.c"
slcc_interface_9IelyHyJdbU3dIHGQW8qHD.obj :	C:\Users\kamil\OneDrive\DOCUME~1\GitHub\NXP_TE~1\slprj\_slcc\9IELYH~1\SLCC_I~1.C
	$(CC) $(CFLAGS) $(INCLUDE_PATH) "C:\Users\kamil\OneDrive\Documents\GitHub\NXP_Tests_Scaleo\slprj\_slcc\9IelyHyJdbU3dIHGQW8qHD\slcc_interface_9IelyHyJdbU3dIHGQW8qHD.c"
lccstub.obj :	C:\PROGRA~1\MATLAB\R2022b\sys\lcc64\lcc64\mex\lccstub.c
	$(CC) $(CFLAGS) $(INCLUDE_PATH) "C:\Program Files\MATLAB\R2022b\sys\lcc64\lcc64\mex\lccstub.c"
