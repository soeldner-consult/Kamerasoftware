//---------------------------------------------------------------------------
#ifndef InterfaceH
#define InterfaceH
//---------------------------------------------------------------------------

#ifdef _BUILD_INTERFACE_DLL_
  #define DLL_FUNCTION __declspec(dllexport)
#else
  #define DLL_FUNCTION __declspec(dllimport)
#endif

//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
typedef struct
{
	char SerialNumber[32];
	char LensType[255];
	char LensFocalLength[255];

}TPyroCamInfo;


typedef struct
{
  int XStart;
  int YStart;
  int Width;
  int Height;

}TPyroCamFrame;

typedef struct
{
	TPyroCamInfo  CameraInfo;
  TPyroCamFrame CalibrationFrame;
	char CreationDateTime[32];
	char CalibrationInfo[255];
  int TemperatureRangeMin;
  int TemperatureRangeMax;

  }TPyroCamCalibrationInfo;



enum{BACKLIGHT_SUPRESSION_NONE=0, BACKLIGHT_SUPRESSION_AUTO=1, BACKLIGHT_SUPRESSION_MANUAL=2};


enum{TEMPERATURE_CLAMP_MODE_MIN_MIN=0, TEMPERATURE_CLAMP_MODE_MIN_MAX=1, TEMPERATURE_CLAMP_MODE_MAX_MAX=2};
enum{BACKLIGHT_SUPPRESSION_CLAMP_MODE_MIN=0, BACKLIGHT_SUPPRESSION_CLAMP_MODE_MAX=1};


extern "C"
{


	//---- Library Info -----------------------------------
	DLL_FUNCTION const char* GetLibraryVersion(void);

	//---- Camera Settings -----------------------------------
	DLL_FUNCTION int SetFrame(int Width, int Height, int X, int Y);
	DLL_FUNCTION int GetFrame(int *pWidth, int *pHeight, int *pX, int *pY);

	//---- Noise Reduction Setting -----------------------------------
	DLL_FUNCTION int SetDenoising(double Value);
	DLL_FUNCTION int GetDenoising(double *pValue);

	//---- Camera Calibrations Settings -----------------------------------
	DLL_FUNCTION int LoadCalibration(const char *pFileName);
	DLL_FUNCTION int GetCalibrationInfo(TPyroCamCalibrationInfo &Info);

  //---- Temperature limit exceeding( Clamp Value Setting) -----------------------------------
	DLL_FUNCTION int SetTemperatureClampMode(int Mode);
	DLL_FUNCTION int GetTemperatureClampMode(int *pMode);


  //---- Backlight Suppression Settings -----------------------------------
	DLL_FUNCTION int SetBacklightSuppression(int Mode);
	DLL_FUNCTION int GetBacklightSuppression(int *pMode);
	DLL_FUNCTION int SetBacklightSuppressionThreshold(int ThresValue);
	DLL_FUNCTION int GetBacklightSuppressionThreshold(int *pThresValue);

	DLL_FUNCTION int SetBacklightSuppressionClampMode(int Mode);
	DLL_FUNCTION int GetBacklightSuppressionClampMode(int *pMode);


	//---- GigE Device -----------------------------------
	DLL_FUNCTION int ConnectToDevice(const char *pIP_Address);
	DLL_FUNCTION int DeviceInitGUI(void);
	DLL_FUNCTION int DeviceClose(void);

	//---- Data Acquisition Settings -----------------------------------
	DLL_FUNCTION int StartStreaming(void);
	DLL_FUNCTION int StopStreaming(void);

	//---- Image Data -----------------------------------
	DLL_FUNCTION unsigned short* GetThermoImageData(void);
	DLL_FUNCTION unsigned short* GetVisibleImageData(void);

	//---- Miscellaneous Settings -----------------------------------
	DLL_FUNCTION int GetFrameCounter(int &DataProcessingCtr, int &DataStreamingCtr);


}



#endif
