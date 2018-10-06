class World: Managed
{
	//proto private void ~World();
	//proto private void World();

	proto native void	GetPlayerList(out array<Man> players);
	
	/**
	\brief Get actual ingame world time
		\param year
		\param month in range <1, 12>
		\param day in range <1, 31>
		\param hour in range <0, 23>
		\param minute in range <0, 59>
		@code
			int year, month, day, hour, minute;
			GetGame().GetWorld().GetDate(year, month, day, hour, minute);
		@endcode
	*/
	proto void			GetDate(out int year, out int month, out int day, out int hour, out int minute);
	
	/**
	\brief Sets actual ingame world time
		\param year
		\param month in range <1, 12>
		\param day in range <1, 31>
		\param hour in range <0, 23>
		\param minute in range <0, 59>
		@code
			int year = 2016;
			int month = 5;
			int day = 4;
			int hour = 14;
			int minute = 57;
			GetGame().GetWorld().SetDate(year, month, day, hour, minute);
		@endcode
	*/
	proto native void	SetDate(int year, int month, int day, int hour, int minute);
	proto native float	GetLatitude();
	proto native float	GetLongitude();
	proto native float	GetMoonIntensity();
	proto native float	GetSunOrMoon();
		
	proto native float	GetEyeAccom();
	proto native void	SetEyeAccom(float eyeAccom);

	proto native void	StartFpsBenchmark(int sectorsCount, float preloadDistance, float fpsLimitRed, float fpsLimitGreen, float fpsLimitBlue, float minX, float minY, float maxX, float maxY);
	proto native void	StartFpsBenchmarkWithMask(float preloadDistance, float fpsLimitRed, float fpsLimitGreen, float fpsLimitBlue);
	proto native void	StartFpsBenchmarkViews(string xmlFileName, float preloadDistance);
	proto native void	SetBuldozerWaterEnabled(bool enable);
	/**
	\brief Sets preferred view distance, which persists between game sessions
		\param distance
	*/
	proto native void SetPreferredViewDistance(float distance);

	proto native void SetViewDistance(float distance);

	proto native void SetObjectViewDistance(float distance);

	proto native void	LoadNewLightingCfg(string path);
	
	/*!
	@code
	Material matColors = GetGame().GetWorld().GetMaterial("postprocess/glow");
	SetMaterialParam(matColors, "Saturation", 0.8);
	float color[4];
	color[0] = 0.5;
	color[1] = 0.8;
	color[2] = 0.7;
	color[3] = 0.6;
	SetMaterialParam(matColors, "OverlayColor", color);
	@endcode
	*/
	proto native Material GetMaterial(string materialName);

	/*!
	set new PP effect and its material
	\param camera					number of camera
	\param effectIndex		index of effect
	\param effectName			name of effect
	\param matName				name of material
	*/
	proto native void		SetCameraPostProcessEffect(int cam, int ppEffect, string effectName, string materialName);
	
	void SetAperture(float invDiameter)
	{
		if (invDiameter <= 0)
		{
			SetEyeAccom(-1);
		}
		else
		{
			float apertureArea = 1.0 / invDiameter;
			SetEyeAccom(apertureArea * apertureArea);
		}
	}
	
	/*!
	checks if 3rd person camera is disabled from server
	*/
	proto native bool Is3rdPersonDisabled();
	
	/*!
	checks if crosshair is disabled from server
	*/
	proto native bool IsCrosshairDisabled();
	
	/*!
	enables/disables player's voice communication
	\param on					enable or disable voice
	*/
	proto native void SetVoiceOn(bool on);

	/*!
	create sphere
	\param worldX		world X of touch with ground
	\param worldZ		world X of touch with ground
	\param radius		radius
	\param centerLerp01	lerp of values inside rasterization
	\param timeDown01	relative speed of going down, 1 is usually 0.5secs
	\param maxHeight01	maximum relative height of flattening, 0 = no flatten
	*/
	proto native void FlattenGrassSphere(float x, float z, float radius, float centerLerp01, float timeDown01, float maxHeight01);

	/*!
	create ellipse
	\param worldX		world X of touch with ground
	\param worldZ		world X of touch with ground
	\param radiusX		radius in X coord before rotate
	\param radiusZ		radius in Z coord before rotate
	\param offset		offset, 0 = default center, <-1, 1>
	\param angleRAD		rotation
	\param centerLerp01	lerp of values inside rasterization
	\param timeDown01	relative speed of going down, 1 is usually 0.5secs
	\param maxHeight01	maximum relative height of flattening, 0 = no flatten
	*/
	proto native void FlattenGrassEllipse(float x, float z, float sideX, float sideZ, float offset, float angleRAD, float centerLerp01, float timeDown01, float maxHeight01);

	/*!
	create box
	\param worldX		world X of touch with ground
	\param worldZ		world X of touch with ground
	\param sideSize		size of side
	\param angleRAD		rotation
	\param centerLerp01	lerp of values inside rasterization
	\param timeDown01	relative speed of going down, 1 is usually 0.5secs
	\param maxHeight01	maximum relative height of flattening, 0 = no flatten
	*/
	proto native void FlattenGrassBox(float x, float z, float side, float angleRAD, float centerLerp01, float timeDown01, float maxHeight01);

	/*!
	create rectangle
	\param worldX		world X of touch with ground
	\param worldZ		world X of touch with ground
	\param sideXSize	size of side in X
	\param sideZSize	size of side in Z
	\param offset		offset, 0 = default center, <-1, 1>
	\param angleRAD		rotation
	\param centerLerp01	lerp of values inside rasterization
	\param timeDown01	relative speed of going down, 1 is usually 0.5secs
	\param maxHeight01	maximum relative height of flattening, 0 = no flatten
	*/
	proto native void FlattenGrassRect(float x, float z, float sideX, float sideZ, float offset, float angleRAD, float centerLerp01, float timeDown01, float maxHeight01);
};
