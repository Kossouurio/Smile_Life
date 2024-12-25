::©2024 Wizurth, tous droits réservés.
::Github link: https://github.com/Wizurth

set PROJECT_NAME=Life
set DIRECTORY_PROJECT=Smile_Life
set bCopySFMLDll=true
set bAutoOpenSLN=true
set bCopyVisualFilters=true

set bDebugMode=false

if not "%bDebugMode%" == "true" (
	@echo off
)
@echo off

:: CopySFMLDlls
if /i "%bCopySFMLDll%" == "true" (
	xcopy /i /c /q /y "src\SFML\bin\*.dll" "ide\vs\%PROJECT_NAME%\Build\Debug\"
	xcopy /i /c /q /y "src\SFML\bin\*.dll" "ide\vs\%PROJECT_NAME%\Build\Release\"
	
	if errorlevel 1 (
		echo .
		echo [Warning] Les ddls de SFML sont introuvables.
		echo .
	)
)

:: Copy Visual Studio filters
if /i "%bCopyVisualFilters%" == "true" (
	if not exist "%PROJECT_NAME%.vcxproj.filters" (
		echo .
		echo [Information] Les filtres personnalisés de Visual Studio sont introuvables, récupération des filtres par défaut.
		echo .
		
		:: Copy Visual Folder => Temp
		xcopy /i /c /q /y "ide\vs\%PROJECT_NAME%\%PROJECT_NAME%.vcxproj.filters"
		
		if errorlevel 1 (
			echo .
			echo [Warning] Les filtres de Visual Studio sont introuvables.
			echo
		)
	)
	
	::Make project
    "SolutionGenerator.exe" -make ../%DIRECTORY_PROJECT%
	
	::Copy Temp => Visual folder
    xcopy /i /c /q /y "%PROJECT_NAME%.vcxproj.filters" "ide\vs\%PROJECT_NAME%\"
	
	if errorlevel 1 (
		echo .
		echo [Warning] Les filtres de Visual Studio n'ont pas pu être copiés.
		echo .
	)
) else ( ::No Visual Studio Filters backup
	"SolutionGenerator.exe" -make ../%DIRECTORY_PROJECT%
)

:: Open the solution
if /i "%bAutoOpenSLN%" == "true" (
	start "" "ide\vs\%PROJECT_NAME%.sln"
)

:: Debug mode
if /i "%bDebugMode%" == "true" (
	echo.
	echo ======[DEBUG MODE]======
	echo PROJECT_NAME=%PROJECT_NAME%
	echo DIRECTORY_PROJECT=%DIRECTORY_PROJECT%
	echo bCopySFMLDll=%bCopySFMLDll%
	echo bAutoOpenSLN=%bAutoOpenSLN%
	echo bCopyVisualFilters=%bCopyVisualFilters%
	echo ========================
	echo.

	pause
)